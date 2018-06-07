#include<stdio.h>
#include<stdlib.h>

#define ORIGIN_MAX_SIZE 201  // 默认最大目标串长度
#define TARGET_MAX_SIZE 100  // 默认模式串长度
#define NO_FOUND -1          // 没有找到

/***************************************
 * 子串查找
 * KMP算法对next的改进,参考博文: https://blog.csdn.net/v_july_v/article/details/7041827
 * 主串为从文本文件中读取,模式串为输入
 ***************************************/

// 函数声明
void readFromFile(char* origin);
int StringSearchKMP(char* origin,char* target);
void get_next(char* target, int* next);

int main()
{
    char origin[ORIGIN_MAX_SIZE];
    readFromFile(origin);
    printf("===================================\n");
    printf("%s\n",origin);
    printf("===================================\n");
    char target[TARGET_MAX_SIZE];
    printf("Please input the pattern string : \n");
    scanf("%s",target);
    int index = StringSearchKMP(origin,target);
    if(index != NO_FOUND)
    {
        printf("******************************\n");
        printf("Found !! The Index Is : %d \n",index);
        printf("******************************\n");
    }
    else
    {
        printf("******************************\n");
        printf("Sorry Not Found !! \n");
        printf("******************************\n");
    }
    return 0;
}

void readFromFile(char* origin)
{
    FILE* fp = fopen("data","r");
    fgets(origin,ORIGIN_MAX_SIZE,fp);
}

int StringSearchKMP(char* origin,char* target)
{
    int next[TARGET_MAX_SIZE];
    get_next(target,next);
    int i = 0;
    int j = 0;
    while(origin[i]!='\0' && target[j]!='\0')
    {
        if(origin[i]==target[j] || (origin[i]!=target[j] && j==0))
        {
            i++;
            j++;
        }        
        else
        {
            j = (next[j] > 0 ? next[j] : 0);
        }
    }
    if(origin[i]!='\0')
        return i-j;
    return NO_FOUND;
}

void get_next(char* target, int* next)
{
    int i = 0;
    int k = -1;
    next[0] = -1;
    while(target[i] != '\0')
    {
        if(k==-1 || target[k] == target[i])
        {
            i++;
            k++;
            // 对next的改进,参考博客: https://blog.csdn.net/v_july_v/article/details/7041827
            if(target[i] != target[k])
                next[i] = k;
            else
                next[i] = next[k];
        }
        else
        {
            k = next[k];
        }
    }


    //Print
    for(int m=0;target[m]!='\0';m++)
    {
        printf("%c\t",target[m]);
    }
    printf("\n");
    for(int n=0;target[n] != '\0';n++)
    {
        printf("%d\t",next[n]);
    }
    printf("\n");
}
