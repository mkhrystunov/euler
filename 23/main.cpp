#include <stdio.h>


// 0 -perfect
// >0 - abundant
// <0 - deficient
int checkAbundant(int n)
{
    int sum = 0;
    for(int i=1; i<=n/2; i++)
	sum += n%i==0 ? i : 0;
    return sum - n;
}

int main(int argc, char*argv[])
{
    int sum = 0;
    for(int i=12; i<28123; i+=2)
    {
	if(checkAbundant(i/2) <= 0)
	    sum += i;
    }

    printf("\033[1;33m%d\033[0m", sum);

    printf("\n");
    return 1;
}