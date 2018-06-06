#include<stdio.h>
#include<stdlib.h>

#define ORIGIN_MAX_SIZE 201  // 默认最大目标串长度
#define TARGET_MAX_SIZE 100  // 默认模式串长度
#define NO_FOUND -1          // 没有找到

/***************************************
 * 子串查找
 * 暴力搜索
 * 目标串为从文本文件中读取,模式串为输入
 ***************************************/

// 函数声明
void readFromFile(char* origin);
int StringSearch(char* origin,char* target);

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
    int index = StringSearch(origin,target);
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

// 子串搜索,如果找到,,返回第一个字母出现的索引
// 如果没有找到,默认返回-1
int StringSearch(char* origin,char* target)
{
    int i = 0;
    int j = 0;
    int originCurIndex = 0;
    while(origin[j]!='\0' && target[i]!= '\0')
    {
        if(target[i] == origin[j])
        {
            i++;
            j++;
        }
        else
        {
            i = 0;
            originCurIndex++;
            j = originCurIndex;
        }
    }
    if(origin[originCurIndex] == '\0')
        return NO_FOUND;
    return originCurIndex;
}
