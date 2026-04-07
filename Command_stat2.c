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

void DisplayPremission(mode_t m)
{
    char Arr[11] = "---------";

    if(m & S_ISDIR(m)) Arr[0] = 'd';
    if(m & S_ISLNK(m)) Arr[0] = 'l';


    // Regluar file Premission 
    if(m & S_IRUSR) Arr[1] = 'r';
    if(m & S_IWUSR) Arr[2] = 'w';
    if(m & S_IXUSR) Arr[3] = 'x';

    if(m & S_IRGRP) Arr[4] = 'r';
    if(m & S_IWGRP) Arr[5] = 'w';
    if(m & S_IXGRP) Arr[6] = 'x';

    if(m & S_IROTH) Arr[7] = 'r';
    if(m & S_IWOTH) Arr[8] = 'w';
    if(m & S_IXOTH) Arr[9] = 'x';

    printf("File Premission : %s\n",Arr);


}

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
        DisplayPremission(sobj.st_mode);
    }
    else
    {
        printf("Error : File not found\n");
    }

    return 0;
}