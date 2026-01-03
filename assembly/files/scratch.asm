global _start

section .text
_start:
		call hello_world
		mov rax, 60
		mov rdi, 0
		syscall

hello_world:
	mov rax, 1
	mov rdi, 1
	lea rsi, string
	mov rdx, string_len
	syscall
	ret

section .data
string db `Hello World`, 0
string_len equ $ - string