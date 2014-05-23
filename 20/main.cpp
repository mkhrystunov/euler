#include <stdio.h>

int fact(int n)
{
    int res = n;
    if(n == 1)
	return 1;
    return res * fact(n-1);
}

int main(int argc, char* argv[])
{
    printf("100! = %d\n", fact(100));




    printf("\n");
    return 0;
}