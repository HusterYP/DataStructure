#include<stdio.h>
#include<stdlib.h>
#include<cstring>

#define ORIGIN_MAX_SIZE 201  // 默认最大目标串长度
#define TARGET_MAX_SIZE 100  // 默认模式串长度
#define NO_FOUND -1          // 没有找到
#define ASCII_SIZE 256       // ASCII 字符数

/***************************************
 * 子串查找
 * BM算法 
 * 主串为从文本文件中读取,模式串为输入
 ***************************************/

// 函数声明
void readFromFile(char* origin);
int StringSearchBM(char* origin,char* target);
void CreateBadIndex(char* target,int* index);
void CreateGoodIndex(char* target,int* index);

int main()
{
    char origin[ORIGIN_MAX_SIZE];
    readFromFile(origin);
    printf("===================================\n");
    printf("%s\n",origin);
    printf("===================================\n");
    char target[TARGET_MAX_SIZE];
    printf("Please input the pattern string : \n");
    scanf("%[^\n]",target);
    int index = StringSearchBM(origin,target);
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

int StringSearchBM(char* origin,char* target)
{
    int bad_index[ASCII_SIZE] = {0};
    int target_length = strlen(target);
    int origin_length = strlen(origin);
    int* good_index = (int*)malloc(sizeof(int)*target_length);
    CreateBadIndex(target,bad_index);
    CreateGoodIndex(target,good_index);
    int i = target_length - 1;
    int cur = target_length - 1;
    int j = target_length - 1;
    while(cur < origin_length && i >= 0)
    {
        if(target[i] == origin[j])
        {
            i--;
            j--;
        }
        else
        {
            int bad = bad_index[(int)origin[j]]; 
            int good = good_index[i];
            int max = bad > good ? bad : good;
            cur += max;
            i = target_length-1;
            j = cur;
        }
    }
    printf("%d\t%d\n",i,j);
    if(i < 0)
        return j+1;
    free(good_index);
    return NO_FOUND;
}

// 创建坏字符索引
void CreateBadIndex(char* target,int* index)
{
    int length;
    length= strlen(target);
    for(int i=0;i<ASCII_SIZE;i++)
    {
        index[i] = length;
    }
    for(int i=0;i<length;i++)
    {
        index[(int)target[i]] = length-i-1;
    }
}

// 创建好字符索引
void CreateGoodIndex(char* target,int* index)
{
    int length;
    length = strlen(target);
    int j = 0;
    int cur = 0;
    for(int i=1;i<length;i++) 
    {
        if(target[j] == target[i])
        {
            int k = i;
            cur = i;
            for(k;k<length;k++)
            {
                printf("k=%d\t%d\n",k,j);
                if(target[k] != target[j])
                    break;
                j++;
            }
            j = 0;
            if(k >= length)
                index[cur] = cur;
        }
    }
}
