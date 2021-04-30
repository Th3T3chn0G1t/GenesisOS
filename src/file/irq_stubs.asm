; SPDX-License-Identifier: GPL-3.0-or-later
; Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
extern _gos_interrupt_handler

global _gos_irq0
_gos_irq0:
	mov rdi, 32
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq1
_gos_irq1:
	mov rdi, 33
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq2
_gos_irq2:
	mov rdi, 34
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq3
_gos_irq3:
	mov rdi, 35
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq4
_gos_irq4:
	mov rdi, 36
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq5
_gos_irq5:
	mov rdi, 37
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq6
_gos_irq6:
	mov rdi, 38
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq7
_gos_irq7:
	mov rdi, 39
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq8
_gos_irq8:
	mov rdi, 40
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq9
_gos_irq9:
	mov rdi, 41
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq10
_gos_irq10:
	mov rdi, 42
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq11
_gos_irq11:
	mov rdi, 43
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq12
_gos_irq12:
	mov rdi, 44
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq13
_gos_irq13:
	mov rdi, 45
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq14
_gos_irq14:
	mov rdi, 46
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
global _gos_irq15
_gos_irq15:
	mov rdi, 47
    mov rsi, rax
    call _gos_interrupt_handler
    iretq
