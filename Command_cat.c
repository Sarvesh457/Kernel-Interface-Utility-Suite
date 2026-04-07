#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./catx      FileName
//  argv[0]     argv[1]
// argc = 2


/*
    Accept the file name commend line
    check whether file is existing or not
    If ie is existing than print of console
    If Not
    Dispaly no such file or directory

*/

#define MAX_BUFFER_SIZE 1024

int main(int argc,char *argv[])
{
    int fd = 0;
    int iRet = 0;
    char *Buffer[MAX_BUFFER_SIZE] = {'\0'};

    if(argc != 2)
    {
        printf("Invalide Command Line Aggument...\n");
        printf("Use as: ./xcat FileName\n");
        return -1;
    }

    if(access(argv[1],F_OK) != 0)
    {
        printf("catx : %s: No such file or directory\n",argv[1]);
        return -1;
    }
    else
    {
        fd = open(argv[1],O_RDONLY);

        if(fd < 0)
        {
            printf("Error : Unable to open file");
        }

        while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
        {
            write(1,Buffer,iRet);
        }
        printf("\n");

        close(fd);

    }

    return 0;
}