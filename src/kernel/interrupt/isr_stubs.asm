; SPDX-License-Identifier: GPL-3.0-or-later
; Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
extern _gos_interrupt_handler

global _gos_isr_stub
_gos_isr_stub:
	mov rdi, -1
    mov rsi, rax
    call _gos_interrupt_handler
    iretq

global _gos_isr_syscall
_gos_isr_syscall:
	mov rdi, 80
    mov rsi, rax
    call _gos_interrupt_handler
    iretq

global _gos_isr0
_gos_isr0:
	mov rdi, 0
    mov rsi, rax
	call _gos_interrupt_handler
    iretq
global _gos_isr1
_gos_isr1:
	mov rdi, 1
    mov rsi, rax
	call _gos_interrupt_handler
    iretq
global _gos_isr2
_gos_isr2:
	mov rdi, 2
    mov rsi, rax
	call _gos_interrupt_handler
    iretq
global _gos_isr3
_gos_isr3:
	mov rdi, 3
    mov rsi, rax
	call _gos_interrupt_handler
    iretq
global _gos_isr4
_gos_isr4:
	mov rdi, 4
    mov rsi, rax
	call _gos_interrupt_handler
    iretq
global _gos_isr5
_gos_isr5:
	mov rdi, 5
    mov rsi, rax
	call _gos_interrupt_handler
    iretq
global _gos_isr6
_gos_isr6:
	mov rdi, 6
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr7
_gos_isr7:
	mov rdi, 7
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr8
_gos_isr8:
	mov rdi, 8
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr9
_gos_isr9:
	mov rdi, 9
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr10
_gos_isr10:
	mov rdi, 10
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr11
_gos_isr11:
	mov rdi, 11
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr12
_gos_isr12:
	mov rdi, 12
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr13
_gos_isr13:
	mov rdi, 13
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr14
_gos_isr14:
	mov rdi, 14
    mov rsi, rax
    call _gos_interrupt_handler
    iretq

; 15 Reserved

global _gos_isr16
_gos_isr16:
	mov rdi, 16
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr17
_gos_isr17:
	mov rdi, 17
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr18
_gos_isr18:
	mov rdi, 18
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr19
_gos_isr19:
	mov rdi, 19
    mov rsi, rax
    call _gos_interrupt_handler
    iretq

; 20 Reserved

global _gos_isr21
_gos_isr21:
	mov rdi, 21
    mov rsi, rax
    call _gos_interrupt_handler
    iretq

; 22 Reserved
; 23 Reserved
; 24 Reserved
; 25 Reserved
; 26 Reserved
; 27 Reserved

global _gos_isr28
_gos_isr28:
	mov rdi, 28
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr29
_gos_isr29:
	mov rdi, 29
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_isr30
_gos_isr30:
	mov rdi, 30
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
