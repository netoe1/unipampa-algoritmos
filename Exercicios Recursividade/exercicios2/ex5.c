#include <stdio.h>
#include <stdlib.h>

int pell(int n)
{
    if (n == 0)
    {
        return 0;
    }

    else if (n == 1)
    {
        return 1;
    }

    else if (n > 2)
    {
        return 2 * pell(n - 1) + pell(n - 2);
    }
}
int main(void)
{
    int n = 2;
    printf("\n%d", pell(n));
    return 0;
}