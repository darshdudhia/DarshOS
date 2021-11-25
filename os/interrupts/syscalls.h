void syscall_test0(void)
{
    PrintString("Syscall 0 successfully dispatched\n\r");
}

// Test syscall 1
void syscall_test1(void)
{
   PrintString("Syscall 1 successfully dispatched\n\r");
}

// Syscall table
void *syscalls[2] = {
    (void*)syscall_test0,
    (void*)syscall_test1
};

// Syscall dispatcher
// naked attribute means no function prologue/epilogue, and only allows inline asm
__attribute__ ((naked)) void syscall_dispatcher(void)
{
    __asm__ __volatile__ (".intel_syntax noprefix\n"

                          ".equ MAX_SYSCALLS, 2\n"  // Have to define again, inline asm does not see the #define

                          "cmp eax, MAX_SYSCALLS-1\n"   // syscalls table is 0-based
                          "ja invalid_syscall\n"        // invalid syscall number, skip and return

                          "push eax\n"
                          "push gs\n"
                          "push fs\n"
                          "push es\n"
                          "push ds\n"
                          "push ebp\n"
                          "push edi\n"
                          "push esi\n"
                          "push edx\n"
                          "push ecx\n"
                          "push ebx\n"
                          "push esp\n"
                          "call [syscalls+eax*4]\n"
                          "add esp, 4\n"
                          "pop ebx\n"
                          "pop ecx\n"
                          "pop edx\n"
                          "pop esi\n"
                          "pop edi\n"
                          "pop ebp\n"
                          "pop ds\n"
                          "pop es\n"
                          "pop fs\n"
                          "pop gs\n"
                          "add esp, 4\n"    // Save eax value in case
                          "iretd\n"         // Need interrupt return here! iret, NOT ret

                          "invalid_syscall:\n"
                          "iretd\n"

                          ".att_syntax");
}