# Assembly Intro

"Assembly Language" can refer to any low level programming language that has a very strong correspondence between the language's instructions and the computer's machine code instructions.  

Rather than writing instructions in binary, assembly is a more human-readable way to write machine code that is very easy to translate between assembly.  

There isn't just one assembly language. Due to the unique nature of different CPUs' ISA, every processor will have its own assembly language as well. But, they have much in common.

## Mnemonics and Opcodes
To the CPU, instructions are just binary values, often represented in hexadecimal. The opcode mnemonic is just a human-readable label for those instructions. The hexadecimal number is the opcode itself.

```
CLC (Clear carry flag, mnemonic) → 0xF8 (x86 architecture, opcode)
```

## Common Instruction Types

**Data Movement**  
A common instruction for this is `MOV`. These instructions tell CPU to move data somewhere, whether it be in registers or in memory.

**Arithmetic**  
Common instructions: `ADD`, `SUB`. Logically, these instructions are routed to the ALU, performs the calculation, and the output can be written back to a register or flag.

**Control Flow**
Common instructions: `JMP`, `CALL`, `RET`. Instead of sequentially executing instructions, these mnemonics can cause the CPU to interrupt behaivor and execute things like loops and functions.

## Registers and Memory Access
In Assembly, registers have predefined names, such as `EAX`. For reading memory bytes, the square brackets `[]` are used, and the address is put in those brackets.

## Assembly Syntax
There are many different types of assembly syntax, but this section will briefly cover Intel syntax.  

There are no register prefixes.

```
mov eax, 1
```

The first operand is the destination, and the second is the source. So, the line above says, "move into eax, 1." Or more simply, "move 1 into eax."

An assembly program can be divided into three sections:
```
section.data (declaring initialized data or constants)
section.bss (declaring variables)
section.text (stores the actual code)
```

Assembly statements generally follow this format:
```
[label]   mnemonic   [operands]   [;comment]
```

Fields in square brackets are optional.

Example:  
```
MOV TOTAL, 48    ; Transfer the value 48 in the 
                 ; memory variable TOTAL
```

## Assemble and Linker
An assembler takes assembly code and translates it to machine code. This is then stored in an object file containing the binary representation of the program.  


The linker module combines external programs like libraries and shared components to create the final executable.