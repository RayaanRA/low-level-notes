# CPU Basics
The Central Processing Unit (CPU) is responsible for the execution of instructions and performing calculations. To carry out its instructions, it fetches data from memory and controls all operations within the system.

## Fetch-Decode-Execute Cycle
The fundamental operation of the CPU. Every program is made up of instructions, which must be fetched, decoded, and executed by the CPU.

## Core CPU Components
### Registers
Registers are computer memory built directly into the CPU itself to be used for various purposes in the fetch-decode-execute cycle

**General-Purpose**  
These registers are used to store data during calculations and manipulation.

**Program Counter (PC)**  
This register holds the memory address of the next instruction to be fetched and executed.

**Instruction Register (IR)**  
This register holds the currently fetched instruction being executed in binary representation.

### Arithmetic Logic Unit (ALU)
The circuitry in the CPU that performs mathematical and logical operations made up of transistors. It executes these functions on integer binary values. The input to the ALU consists of the data to be operated on, and a code indicating the operation to perform (opcode).

### Control Unit (CU)
The part of the CPU that directs the operation of the processor. This unit tells the computer's memory, ALU, and I/O devices how to respond to instructions. The CU manages instruction decoding, and from this the CU generates a control signal to the execution of instructions.

## Instruction Set Architecture (ISA)
An abstract model that defines how software controls the CPU. A CPU is an implementation of an ISA. The ISA defines supported instructions, data types, registers, hardware support, etc. The ISA acts as a contract between hardware and software, specifying how programs interact with the CPU.

## Clock and Timing
Clock, or clock speed, refers the frequency of cycles a CPU executes per second. This is typically measured in GHz. One GHz is one billion clock cycles per second, or instructions per second. However, instructions don't always take once cycle, and sometimes they take more than one cycle. Modern CPUs are much more complex in this regard. Essentially, clock speed governs how quickly a CPU can process operations, but actual instruction throughput depends on architecture.

## Pipelining
A technique used in modern processors to improve performance by executing instructions simultaneously. The execution of instructions is broken down into several stages, which can overlap.

## Interrupts
Signals from a device, such as a keyboard or hard drive, that tell the CPU to immediately stop what it is doing and do something else. The CPU gets the address and jumps to it in this interrupt. 