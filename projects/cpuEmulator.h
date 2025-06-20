#ifndef __CPUEMULATOR__
#define __CPUEMULATOR__

void initCPU();
void cycle();
void printRegisters();

enum opcode {
	LOAD = 0x01,
	MOV = 0x02,
	ADD = 0x03,
	SUB = 0x04,
	STORE = 0x05,
	LOADM = 0x06,
	JMP = 0x07,
	JZ = 0x08,
	HALT = 0xFF
};



#endif