#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./mvx    SourcePath      DestPath
//  argv[0]     argv[1]         argv[3]

// argc = 3


/*

    Open Source File for reading 
    Create Destination file
    Read the Data from Source
    Write it into destaination
    close both files

*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Error : Invalid Command Line Argument...\n");
        printf("Use as: ./mvx SourcePath DestinationPath\n");
        return -1;
    }

    if(rename(argv[1], argv[2]) == -1)
    {
        return -1;
    }

    printf("File moved successfully.\n");
    return 0;
}
