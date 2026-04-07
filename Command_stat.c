#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

// ./statx    FileName
//  argv[0]     argv[1]
// argc = 2


/*
    Accept the file name commend line
    Call access to check extstance of file
    Call stat system to get files mate data
    Dispaly the matedata
*/

#define MAX_BUFFER_SIZE 1024

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invalide Command Line Aggument...\n");
        printf("Use as: ./statx FileName\n");
        return -1;
    }

    if(access(argv[1],F_OK) == 0)
    {
        struct stat sobj;
        int iRet = 0;

        iRet = stat(argv[1],&sobj);

        if(iRet == -1)
        {
            printf("Error : Unavle to fetch the statistical Information\n");
            return -1;
        }

        printf("File Nmae : %s\n",argv[1]);
        printf("File Size : %ld",(long)sobj.st_size);
        printf("Inode Number : %ld\n",(long)sobj.st_ino);

    }
    else
    {
        printf("Error : File not found\n");
    }

    return 0;
}