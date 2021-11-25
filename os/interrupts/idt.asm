section .text
    [bits 32]
    [extern keyboard]
    global isr1
    [extern mouse]
    global isr12
isr12:
    pusha
    call mouse
    popa
    iretd
isr1:
    pusha
    call keyboard
    popa
    iretd