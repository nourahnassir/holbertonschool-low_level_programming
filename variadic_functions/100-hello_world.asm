global main
section .text

main:
    ; write(1, hello, 13)
    mov rax, 1          ; system call 1 is write
    mov rdi, 1          ; file descriptor 1 is stdout
    mov rsi, hello      ; pointer to the string
    mov rdx, 13         ; number of bytes (length of "Hello, World\n")
    syscall             ; invoke operating system to do the write

    ; exit(0)
    mov rax, 60         ; system call 60 is exit
    xor rdi, rdi        ; exit code 0
    syscall

section .data
    hello: db "Hello, World", 10
