#include "IO_bus.cpp"
#include "Print.cpp"
#include "ColorCodes.h"
#include "shell.h"
#include "timer.cpp"
#include "urandom.cpp"

const char ASCIITable[] = {
     0 ,  0 , '1', '2',
    '3', '4', '5', '6',
    '7', '8', '9', '0',
    '-', '=',  0 ,  0 ,
    'q', 'w', 'e', 'r',
    't', 'y', 'u', 'i',
    'o', 'p', '[', ']',
    '~' ,  0 , 'a', 's',
    'd', 'f', 'g', 'h',
    'j', 'k', 'l', ';',
    '\'','`',  0 , '\\',
    'z', 'x', 'c', 'v',
    'b', 'n', 'm', ',',
    '.', '/',  0 , '*',
     0 , ' ', 0
    };

char Translate(uint_8 scancode){
    if (scancode > 58) return 0;
        return ASCIITable[scancode];
}
char input[1000];
int i = 0;
int tempvar = 0;
char getChar(void){
    PrintString("user@darshOS:~$ ");
    int running = 1;
    char out = 0;
    while(running = 1) {
        if(inb(0x64)&1) {
            out = inb(0x60);
            char test = out;
            char ascii = Translate(test);
            if (ascii != 0){
                if (ascii == '~'){
                    int before = CursorPosition / 80;
                    SetCursorPos(before * 80 + 80);
                    //SHELL
                    //help
                    while (tempvar != i+1) {
                    if (input[tempvar] != command_help[tempvar]){
                        tempvar = 0;
                        while (tempvar != i+1) {
                        if (input[tempvar] != command_Admin[tempvar]){
                            tempvar = 0;
                            while (tempvar != i+1) {
                                if (input[tempvar] != command_reboot[tempvar]){
                                tempvar = 0;
                                while (tempvar != i+1) {
                                if (input[tempvar] != command_random[tempvar]){
                                    tempvar = 0;
                                    while (tempvar != i+1) {
                                    if (input[tempvar] != command_cls[tempvar]){
                                        sleep(200);
                                        PrintString("Invalid Command");
                                        tempvar = i+1;
                                        break;
                                    }
                                    else{
                                        if (tempvar == i){
                                            ClearScreen();
                                            SetCursorPos(0);
                                        }
                                        tempvar++;
                                    }
                                    }
                                }
                                else{
                                    if (tempvar == i){
                                        rand_print();
                                        PrintString("\n\r");
                                    }
                                    tempvar++;
                                }
                                }
                                }
                            else{
                                    if (tempvar == i){
                                        uint_8 good = 0x02;
                                        while (good & 0x02)
                                        good = inb(0x64);
                                        outb(0x64, 0xFE);
                                        asm("hlt");
                                    }
                                    tempvar++;
                            }
                        }
                        }
                        else{
                        if (tempvar == i){
                            sleep(200);
                            PrintString("user@DarshOS has Gained Admin Privilages\n\r");
                            PrintString("Note: This Command Does Not Do anything right now.")
                        }
                        tempvar++;
                        }
                        }

                    }
                    else {
                        if (tempvar == i){
                            sleep(200);
                            PrintString("help - Shows this message\n\r");
                            PrintString("reboot - Restarts/Reboots The System\n\r");
                            PrintString("urandom - Prints a random number from 1-10 using a pseudo random number genrator");
                            PrintString("cls - Clears the Screen")
                        }
                        tempvar++;
                    }
                    }

                    //End
                    for (int a = 0; a < 1000; a++){
                    input[a] = 0;
                    }
                    int after = CursorPosition / 80;
                    SetCursorPos(after * 80 + 80);
                    PrintString("user@darshOS:~$ ");
                    tempvar = 0;
                    i = 0;

                }
                else{
                    PrintChar(ascii, BACKGROUND_BLUE | FOREGROUND_WHITE);
                    input[i] = {ascii};
                    i++;
                }
}
}

}
return 0;
}

