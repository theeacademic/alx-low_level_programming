section .data
    hello db "Hello, Holberton,",0
    format db "%s",0
    newline db 10,0  ; Newline character

section .text
    global main
    extern printf

main:
    push rbp
    mov rdi, format
    lea rsi, [hello]
    call printf

    ; Print a newline
    mov rdi, format
    lea rsi, [newline]
    call printf

    pop rbp
    ret
