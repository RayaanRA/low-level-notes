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