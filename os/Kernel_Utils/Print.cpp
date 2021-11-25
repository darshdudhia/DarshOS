#pragma once
#include "IO_bus.cpp"
#include "typedefs.h"
#include "ColorCodes.h"
#define VGA_MEMORY (unsigned char*)0xb8000
#define VGA_WIDTH 80

uint_16 CursorPosition;

void SetCursorPos(uint_16 position){
  outb(0x3D4, 0x0F);
  outb(0x3D5, (uint_8)(position & 0xFF));
  outb(0x3D4, 0x0E);
  outb(0x3D5, (uint_8)((position >> 8) & 0xFF));

  CursorPosition = position;
}

uint_16 PositionFromCoords(uint_8 x, uint_8 y){
  return y * VGA_WIDTH + x;
}

void PrintString(const char* str, uint_8 color = BACKGROUND_BLUE | FOREGROUND_WHITE){
	uint_8* charPtr = (uint_8*)str;
	uint_16 index = CursorPosition;
	while(*charPtr != 0){
		
		switch(*charPtr){
			case 10:
				index += VGA_WIDTH;
			break;
			case 13:
				index -= index % VGA_WIDTH;
			break;
		default:

			*(VGA_MEMORY + index * 2 ) = *charPtr;
			*(VGA_MEMORY + index * 2 + 1 ) = color;

			index++;
		}

		charPtr++;	
	}
	SetCursorPos(index);
}


void PrintChar(char chr, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE)
{
  *(VGA_MEMORY + CursorPosition * 2) = chr;
  *(VGA_MEMORY + CursorPosition * 2 + 1) = color;

  SetCursorPos(CursorPosition + 1);
}

char hexToStringOutput[128];
template<typename T>
const char* HexToString(T value){
  T* valPtr = &value;
  uint_8* ptr;
  uint_8 temp;
  uint_8 size = (sizeof(T)) * 2 - 1;
  uint_8 i;
  for (i = 0; i < size; i++){
    ptr = ((uint_8*)valPtr + i);
    temp = ((*ptr & 0xF0) >> 4);
    hexToStringOutput[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
    temp = ((*ptr & 0x0F));
    hexToStringOutput[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
  }
  hexToStringOutput[size + 1] = 0;
  return hexToStringOutput;
}

void ClearScreen(uint_64 ClearColor = BACKGROUND_BLUE | FOREGROUND_WHITE)
{
  uint_64 value =0;
  value += ClearColor << 8;
  value += ClearColor << 24;
  value += ClearColor << 40;
  value += ClearColor << 56;
  for (uint_64* i = (uint_64*)VGA_MEMORY; i < (uint_64*)(VGA_MEMORY + 4000); i++){
      *i = value;
  }
}
void disable_cursor()
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

char int_to_char(int i){
  const char char_max = (char)(((unsigned char) char(-1)) / 2);
  char c = (i & char_max);
  return c;
}
char *tochar(int i, char *p)
{
    if (i / 10 == 0) {
        // No more digits.
        *p++ = i + '0';
        *p = '\0';
        return p;
    }

    p = tochar(i / 10, p);
    *p++ = i % 10 + '0';
    *p = '\0';
    return p;
}
