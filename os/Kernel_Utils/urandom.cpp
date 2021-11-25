#include "Print.cpp"
static unsigned long int next = 5;

int rand_ret(void)
{
    int max_val = 1000;
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % max_val + 1;
}
 
int srand(unsigned int seed)
{
    next = seed;
    return 0;
}

int random;

int rand_print()
{
    int random = rand_ret();
    char buffer[100];
    tochar(random, buffer);
    PrintString(buffer);
    return 0;
}
