#include "Kernel_Utils/Print.cpp"
#include "Kernel_Utils/Keyboard&&Shell.cpp"

extern "C" void _start(void){
    ClearScreen(BACKGROUND_BLUE | FOREGROUND_WHITE);
    SetCursorPos(996);
    PrintString("DarshOS\n\n\r                                       ");
    disable_cursor();
    int repeat_load_animation = 2;
    int num0 = 0;
    while (num0 != repeat_load_animation) {
    PrintString("-");
    SetCursorPos(CursorPosition - 1);
    sleep(150);
    PrintString("\\");
    SetCursorPos(CursorPosition - 1);
    sleep(150);
    PrintString("|");
    SetCursorPos(CursorPosition - 1);
    sleep(150);
    PrintString("/");
    SetCursorPos(CursorPosition - 1);
    sleep(150);
    PrintString("-");
    SetCursorPos(CursorPosition - 1);
    sleep(150);
    num0++;
    }
    sleep(300);
    ClearScreen(BACKGROUND_BLUE | FOREGROUND_WHITE);
    SetCursorPos(0);
    enable_cursor(11, 13);
    PrintString("Welcome to DarshOS\n\r", BACKGROUND_BLUE | FOREGROUND_WHITE);
    PrintString("Made by Darsh Dudhia\n\r", BACKGROUND_BLUE | FOREGROUND_WHITE);
    PrintString("Shell Version: 1.7\n\rFeatures:\n\rBasic Shell with a few commands.\n\rType \"help\" without the double quotation marks for more info.\n\r", BACKGROUND_BLUE | FOREGROUND_WHITE);
    PrintString("\n\n\r");
    sleep(500);
    getChar();
    return;
}

