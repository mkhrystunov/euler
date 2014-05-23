#include <stdio.h>
#include <string>

using namespace std;

int pow(int n, int p)
{
    int res = 1;
    for(int i=0; i<p; i++)
	res *= n;
    return res;
}

int checkPow(int n, int p)
{
    int sum = 0;
    int num = n;
    while(n > 0)
    {
	sum += pow(n%10, p);
	n /= 10;
    }
    return sum == num;
}

int main(int argc, char* argv[])
{
    int sum = 0;
    for(int i=2; i<355000; i++)
    {
	if(checkPow(i, 5))
	{
	    printf("%d\n", i);
	    sum += i;
	}
    }
    printf("\033[1;33m%d\n\033[0m", sum);


    printf("\n");
    return 0;
}