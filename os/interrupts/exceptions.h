/*
exceptions.h: Fuction/ISRs for exceptions (interrupts 0-31)
*/
#pragma once

#include "../interrupts/idt.h"
#include "../Kernel_Utils/Print.cpp"

__attribute__ ((interrupt)) void div_by_0_handler(int_frame_32_t *frame)
{
    PrintString("DIVIDE BY 0 ERROR - EXCEPTION HANDLED");
    frame->eip++;
}