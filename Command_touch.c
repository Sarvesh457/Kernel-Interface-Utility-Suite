#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./touchx    FileName
//  argv[0]     argv[1]
// argc = 2


/*
    Accept the file name commend line
    check whether file is existing or not
    If ie is existing return
    If Not
    Create

*/

#define MAX_BUFFER_SIZE 1024

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invalide Command Line Aggument...\n");
        printf("Use as: ./x touchFileName\n");
        return -1;
    }

    if(access(argv[1],F_OK) == 0)
    {
        return 0;
    }
    else
    {
        creat(argv[1],0777);
    }


    return 0;
}