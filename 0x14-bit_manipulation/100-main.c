#include <stdio.h>
int get_endianness(void);
int main(void)
{

    int n = get_endianness();
    if (n != 0)
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
    return (0);
}
