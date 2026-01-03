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

