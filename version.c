#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NVVERSION_HEADER "VERSION_"
#define NVVERSION 4 //change this version

#define TEST_VERSION "VERSION_0000"

int main()
{
    char ver_nv[] = "VERSION_0000000003";
    char ver_new[] = NVVERSION_HEADER;
    int resz, memrz = 0;

    memrz = memcmp(ver_nv, ver_new, 8);    

    if (!memrz)
    {
        resz = atoi (&ver_nv[8]);
        
        switch (resz){
            case 1: //version 1
                printf("version 1 migration routine\n");
            break;
            case 2: //version 2
                printf("version 2 migration routine\n");
            break;
            case 3: //version 3
                printf("version 3 migration routine\n");
            break;
            case 4: //version 4
                printf("version 4 this version: do nothing\n");
            break;
            default:
                printf("delete eveything\n");
            break;
        }
    }

    return 0;
}
