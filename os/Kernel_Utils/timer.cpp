char sleep(int microsecond){
    int a = 0;
    while(a != microsecond * 10){
    int b = 0;
    while (b != 10000) {
        asm("nop");
        b++;
    }
    a++;
    }
    return 0;
}