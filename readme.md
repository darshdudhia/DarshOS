
# DarshOS
## Features

- Shell/Command Line 

- Keyboard Input

- IDT
## Might add in the future
 
 - File System and Commands for File  System

 - IDT [DONE]

 - Networking
 
 - GUI


## Setup / dependencies 
You will need these to run "compile.sh".

### Windows
For Windows you will have to Install WSL (Windows Subsystem for Linux) then you can follow the guide for Linux by typing the commands in the WSL terminal.

- How to setup WSL on Windows:

    1. Go to https://ubuntu.com/wsl
    2. Download Ubuntu WSL from Microsoft Store
    3. Open StartMenu and search "Turn Windows Features on or off" without the double quotes
    4. Click on Turn Windows Features on or off
    5. Scroll down and tick Windows Subsystem For Linux then press ok
    6. Press Windows Key and in "The Recently Added" section click Ubuntu
    7. Then You Will see a Terminal Window saying that ubuntu is Installing
    8. It will ask you to make a Unix account (It will not show the password)
    9. run the command "sudo apt update && sudo apt upgrade" without the double quotes
    10. It will ask for your unix account's password type it and press enter (it wont show the password on screen)
    11. Follow the Guide for Linux By typing the commands in the terminal.

### Linux

- Qemu VM : 
```bash
 sudo apt install qemu && sudo apt-get install qemu-kvm
```
- Nasm (Asm Compiler) :
```bash
 sudo apt install nasm
```
- GCC cross compiler for i386 systems (might take quite some time).
```bash
cd os
sh cross_compilei32.sh
```
### Now you will have to do the following to run compile.sh :

- Make sure that you are in the OS folder to go in the folder run :
```bash
 cd os 
```
- run this command inside the os folder.
```bash
 export PATH=$PATH:/usr/local/i386elfgcc/bin
```
- then to compile the compile.sh file run this command.
```bash
 sh compile.sh
```

- Now there sholud be a popup window with DarshOS running
 
- If there is no popup Do this:

    1. Press Crtl + C together in the WSL terminal
    2. Go to The Microsoft Store
    3. Search GWSL in The Microsoft Store
    4. Install GWSL
    5. Run GWSL
    6. Go into the WSL terminal Again and Run these commands again after going in the os directory.
    ```bash
     export PATH=$PATH:/usr/local/i386elfgcc/bin
     sh compile.sh
    ```
    7. You Have successfully ran DarshOS.



## Resources Used
 - [Osdev Wiki](https://wiki.osdev.org/Main_Page)
 - [Daedalus Community - OS dev Series](https://www.youtube.com/watch?v=MwPjvJ9ulSc&list=PLm3B56ql_akNcvH8vvJRYOc7TbYhRs19M)
 - [Poncho - OS dev series (Season 1)](https://www.youtube.com/watch?v=7LTB4aLI7r0&list=PLxN4E629pPnKKqYsNVXpmCza8l0Jb6l8-)
  - [Poncho - OS dev series (Season 2)](https://www.youtube.com/watch?v=mpPbKEeWIHU&list=PLxN4E629pPnJxCQCLy7E0SQY_zuumOVyZ)
