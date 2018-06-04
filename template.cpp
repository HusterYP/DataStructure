#include<stdio.h>
#include<stdlib.h>

int main()
{
    int option;
    while(1)
    {
        system("clear");
        printf("Welcome to use !\n");
        printf("1. InitList                     2. DestroyList\n");
        printf("3. ListLength                   4. GetElem\n");
        printf("5. PriorElem                    6. NextElem\n");
        printf("7. InsertElem                   8. DeleteElem\n");
        printf("9. LocateElem                  10. PrintAll\n");
        printf("0. Exit\n");
        printf("Please input the option:\n ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                getchar();
                getchar();
                break;
            case 2:
                getchar();
                getchar();
                break;
            case 3:
                getchar();
                getchar();
                break;
            case 4:
                getchar();
                getchar();
                break;
            case 5:
                getchar();
                getchar();
                break;
            case 6:
                getchar();
                getchar();
                break;
            case 7:
                getchar();
                getchar();
                break;
            case 8:
                getchar();
                getchar();
                break;
            case 9:
                getchar();
                getchar();
                break;
            case 10:
                getchar();
                getchar();
                break;
            case 0:
                getchar();
                getchar();
                return 0;
            default:
                getchar();
                getchar();
                break;
        }
    }
    return 0;
}
