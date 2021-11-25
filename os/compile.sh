nasm "bootloader.asm" -f bin -o "Bin/bootloader.bin"
nasm "kernel_starter.asm" -f elf -o "Bin/kernel_starter.o"
nasm "interrupts/idt.asm" -f elf -o "Bin/idt.o"
i386-elf-gcc -ffreestanding -m32 -mgeneral-regs-only -g -c -lgcc -lc "kernel.cpp" -o "Bin/kernel.o"
nasm "zero.asm" -f bin -o "Bin/zero.bin"
i386-elf-ld -o "Bin/full_kernel.bin" -Ttext 0x1000 -Trodata 0x1000 "Bin/kernel_starter.o" "Bin/kernel.o" "Bin/idt.o" --oformat binary

cat "Bin/bootloader.bin" "Bin/full_kernel.bin" "Bin/zero.bin" > "Bin/OS.bin"

qemu-system-x86_64 --soundhw pcspk -drive format=raw,file="Bin/OS.bin",index=0,if=floppy,  -m 128M
