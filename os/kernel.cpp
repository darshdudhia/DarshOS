#include "Kernel_Utils/Print.cpp"
#include "Kernel_Utils/Keyboard&&Shell.cpp"
#include "Kernel_Utils/sound.cpp"
#include "interrupts/idt.h"
#include "interrupts/exceptions.h"
#include "interrupts/syscalls.h"
#include "interrupts/pic.h"

extern "C" void isr1(void);

extern "C" void _start(void){
    ClearScreen(BACKGROUND_BLUE | FOREGROUND_WHITE);
    SetCursorPos(996);
    PrintString("DarshOS\n\n\r                                       ");
    ClearScreen(BACKGROUND_BLUE | FOREGROUND_WHITE);
    //set up IDT
    init_idt_32();
    //set up exceptions
    set_idt_descriptor_32(0, (void*)div_by_0_handler, TRAP_GATE_FLAGS);
    //syscalls
    set_idt_descriptor_32(0x80, (void*)syscall_dispatcher, INT_GATE_USER_FLAGS);
    //interrupts
    disable_pic();
    remap_pic();
    //keyboard
    set_idt_descriptor_32(0x21, (void*)isr1, INT_FLAGS);
    clear_irq_mask(1);
    __asm__ __volatile__("sti");

    /*
    beep(261.63);
    beep(293.66);
    beep(329.63);
    */
    SetCursorPos(0);
    enable_cursor(11, 13);
    PrintString("Welcome to DarshOS\n\r", BACKGROUND_BLUE | FOREGROUND_WHITE);
    PrintString("Made by Darsh Dudhia\n\r", BACKGROUND_BLUE | FOREGROUND_WHITE);
    PrintString("Shell CodeName: Clam \n\rShell Version: 1.8\n\rFeatures:\n\rBasic Shell with a few commands.\n\rType \"help\" or \"?\" without the double quotation marks for more info.\n\r", BACKGROUND_BLUE | FOREGROUND_WHITE);
    PrintString("\n\n\r");
    INIT();
    sleep(500);
    return;
}

