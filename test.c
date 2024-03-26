#include <stdio.h>
int main()
{
    int t = 0;
    do
    {
        printf("%d", t);
        t++;
        if (t == 10)
        {
            break;
        }
    } while (3 >= 2);
}