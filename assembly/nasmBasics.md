# NASM Basics

The Netwide Assembler (NASM) is an assembler for the x86 CPU architecture. It is considered one of the most popular assemblers for Linux and x86 chips. NASM will be installed in WSL here.  

Assembly files generally have the file extension `.asm`.  

Assembly language files are assembled into object files, which are then linked with other object files to make an executable. There are many object file formats. Here, ELF64 will be used.

## Writing an Assembly Program

```
          global    _start

          section   .text
_start:   mov       rax, 60
          mov       rdi, 0
          syscall
```

This is the most basic assembly program which translates to  

```
int main() {
    return 0;
}
```
in C.  

The line `global    _start` tells the linker the entry point for the program. This is the label and is used to mark its beginning later.   
`section   .text` marks all text underneath as being part of the actual code for the program.  

Unlike C, you cannot simply return from the `main` function to end the program. Instead, you must make use of `syscall`, which tells the Linux kernel to do various things. You do this with the system call number (NR) that is put into the `rax` register. Arguments for system calls are put in other registers, the first of which being `rdi`. A table for syscall numbers and arguments can be found [here](https://syscall.sh/).  

The syscall number for `exit` is 60, which is seen to be moved into the register `rax`. The table shows the first and only argument for `exit` is the error code, which should be placed into register `rdi`. 0 is commonly used as an error code to indicate success on exit. Finally, we type `syscall` to initiate the program exit. Note that the return value of syscalls are put into register `rax`.

## `.data` and `.bss`

These are two other important sections of an Assembly program.

### `.data`
This section holds constants and variables. This section's data declarations generally follow this format:  

```
<variableName>         <dataType>         <initialValue>
```

Directives are used to define the data type, which are different sizes of bytes. The commonly used ones are:

`db`: 8 bits (define byte)
`dw`: 16 bits (define word)
`dd`: 32 bits (define double word)
`dq`: 64 bits (define quad word)
`dt`: 80 bits (define 10 bytes)  

Now we can define strings in Assembly:

```
section .data

str    db    "Hello World", 0
```

The `, 0` appends the null terminating character. However, looking at the table for writing, the size, or length of the string is needed. This is done with this statement:  

```
len    equ    $ - str
```

`$` marks the current location counter (just after the string), and `$ - str` calculates the difference between the start and end of the string, giving the length of string. `equ` sets a value to constant symbol `len`. Now, a "Hello World" program can be written.  


```
global _start


section .text

_start: mov rax, 1
        mov rdi, 1
        mov rsi, strng
        mov rdx, len
        syscall
        mov rax, 60
        mov rdi, 0
        syscall


section .data

strng: db "Hello World", 0xA, 0
len: equ $ - strng


```

`0xA` indicates a new line.  


### `.bin` (Flat Binary) and `.elf`

These are two executable files outputted by the linker (`ld`). `.bin` is pure binary, with no fixes or relocations. `.elf` also contains binary information but also other information like debug info and symbols.

