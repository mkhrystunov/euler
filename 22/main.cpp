#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>

#define BUF_SIZE 8192

using namespace std;

int main(int argc, char* argv[])
{
    int input_fd; // input file descriptor
    ssize_t ret_in; // number of bytes returned by read()
    char buff; // character buffer
    int amount = 0;

    if(argc != 2)
    {
	printf("Error input\n");
	return 1;
    }

    input_fd = open(argv[1], O_RDONLY);
    if(input_fd == -1)
    {
	perror("open");
	return 2;
    }

    while((ret_in = read(input_fd, &buff, 1)) > 0)
    {
	if(buff == ',')
	    amount += 1;
    }
    printf("\033[1;33mtotal: %d\n\033[0m", amount);
    string names[amount];

    lseek(input_fd, 0, SEEK_SET); // change file offset to the start
    int n = 0;
    while((ret_in = read(input_fd, &buff, 1)) > 0)
    {
	if(buff == ',')
	{
	    n++;
	    printf("%d ", n);
	    continue;
	}
	if(buff != '"')
	{
	    names[n] += buff;
	}
    }

    for(int i=0; i<amount; i++)
	printf("%s ", names[i].c_str());

    printf("\n\n");


    close(input_fd);
    return 0;
}