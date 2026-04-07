#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//  ./rmX     FileName
//  argv[0]   argv[1]

//  argc = 2

/*
    Call the system call unlink
*/

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./rmX  FileName\n");
        return -1;
    }

    if(access(argv[1], F_OK) == 0)
    {
        if(unlink(argv[1]) == -1)
        {
            printf("Error : Unable to remove file\n");
            return -1;
        }
        else
        {
            printf("Success : File gest successfullt removed\n");
        }
    }
    else
    {
        printf("Error : Unable to remove as file is not present\n");
        return -1;
    }
     
    return 0;
}