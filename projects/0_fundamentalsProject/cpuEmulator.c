/*
CPU Specifications:
256 bytes of RAM, zero-initialized
4 general purpose 8-bit registers: R0, R1, R2, R3
Program Counter (PC)
Instruction Register (IR)
Flag register (Zero Flag)
Opcodes: 1 byte

ISA:
LOAD Rx, IMM (0x01): load immediate to register

MOV Rx, Ry (0x02): copy register to register

ADD Rx, Ry (0x03): add Ry to Rx

SUB Rx, Ry (0x04): subtract Ry from Rx

STORE Rx, addr (0x05): store Rx to memory address

LOADM Rx, addr (0x06): load memory to Rx

JMP addr (0x07): unconditional jump

JZ addr (0x08): jump if zero flag set

HALT (0xFF): stop execution
*/

#include <stdio.h>
#include <stdint.h>
#include "cpuEmulator.h"

uint8_t memory[256];
uint8_t registers[4];
uint8_t pc;
uint8_t zf;
uint8_t halt = 0;

uint8_t program[128] = {
	LOAD, 0x00, 0x05,      // LOAD R0, 5
    LOAD, 0x01, 0x03,      // LOAD R1, 3
    ADD, 0x00, 0x01,       // ADD R1 to R0  (R0 = 8)
    STORE, 0x00, 0x10,     // STORE R0 to memory[0x10]
    LOADM, 0x02, 0x10,     // LOADM R2 from memory[0x10] (R2 = 8)
    SUB, 0x02, 0x01,       // SUB R1 from R2 (R2 = 5)
    JZ, 0x1F,              // If zero flag set, jump to addr 0x1F (not taken here)
    HALT                   // HALT
};


int main(int argc, char *argv[]) {

	initCPU();
	while(!halt) {
		cycle();
	}	
	

	return 0;
}

void initCPU() {

	for (int i = 0; i < 256; i++) {
		memory[i] = 0;
	}

	for (int i = 0; i < 4; i++) {
		registers[i] = 0;
	}

	pc = 0;
	zf = 0;

	for (int i = 0; i < 128; i++) {
		memory[i] = program[i];
	}
}

void cycle() {
	uint8_t opcode = memory[pc];
	uint8_t registerOne;
	uint8_t registerTwo;
	uint8_t addr;
	uint8_t imm;
	switch(opcode) {
	case LOAD:
		registerOne = memory[pc + 1];
		imm = memory[pc + 2];
		registers[registerOne] = imm;
		if (registers[registerOne] == 0) {
			zf = 1;
		} else {
			zf = 0;
		}
		pc += 3;
		printf("Executed LOAD: R%d <- 0x%02X\n", registerOne, imm);
		break;
	case MOV:
		registerOne = memory[pc + 1];
		registerTwo = memory[pc + 2];
		registers[registerTwo] = registers[registerOne];
		if (registers[registerOne] == 0) {
			zf = 1;
		} else {
			zf = 0;
		}		
		pc += 3;
		printf("Executed MOV: R%d <- R%d (0x%02X)\n", registerTwo, registerOne, registers[registerOne]);
		break;
	case ADD:
		registerOne = memory[pc + 1];
		registerTwo = memory[pc + 2];
		registers[registerOne] += registers[registerTwo];
		if (registers[registerOne] == 0) {
			zf = 1;
		} else {
			zf = 0;
		}
		printf("Executed ADD: R%d += R%d (Result: 0x%02X)\n", registerOne, registerTwo, registers[registerOne]);
		pc += 3;
		break;
	case SUB:
		registerOne = memory[pc + 1];
		registerTwo = memory[pc + 2];
		registers[registerOne] -= registers[registerTwo];
		if (registers[registerOne] == 0) {
			zf = 1;
		} else {
			zf = 0;
		}
		printf("Executed SUB: R%d -= R%d (Result: 0x%02X)\n", registerOne, registerTwo, registers[registerOne]);		
		pc += 3;
		break;
	case STORE:
		registerOne = memory[pc + 1];
		addr = memory[pc + 2];
		memory[addr] = registers[registerOne];
		printf("Executed STORE: memory[0x%02X] <- R%d (0x%02X)\n", addr, registerOne, registers[registerOne]);
		pc += 3;
		break;
	case LOADM:
		registerOne = memory[pc + 1];
		addr = memory[pc + 2];
		registers[registerOne] = memory[addr];
		if (registers[registerOne] == 0) {
			zf = 1;
		} else {
			zf = 0;
		}
		printf("Executed LOADM: R%d <- memory[0x%02X] (0x%02X)\n", registerOne, addr, registers[registerOne]);
		pc += 3;
		break;
	case JMP:
		addr = memory[pc + 1];
		pc = addr;
		printf("Executed JMP to 0x%02X\n", addr);
		break;
	case JZ:
		addr = memory[pc + 1];
		if (zf == 1) {
			pc = addr;
			printf("Executed JZ: zero flag set, jumping to 0x%02X\n", addr);
		} else {
			pc += 2;
		}
		printf("Executed JZ: zero flag not set, continuing\n");
		break;
	case HALT:
		halt = 1;
		printf("Executed HALT\n");
		return;
		break;
	default:
		printf("Invalid opcode 0x%02X, exiting\n", opcode);
		halt = 1;
		return;
		break;
	}
}