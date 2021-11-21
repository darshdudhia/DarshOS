section .text
    [bits 32]
    [extern keyboard]
    global isr1

isr1:
    pusha
    call keyboard
    popa
    iretd