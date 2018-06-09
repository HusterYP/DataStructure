#include<stdio.h>
#include<stdlib.h>

#define status int
#define MAX_COUNT 1000 // 默认对1000个数据进行排序操作

// 函数声明
void CreateRandom();
void ReadFromFile(int* num);
void WriteToFile(int* num);
void InsertSort(int* num);

/***********************************************
 * 插入排序
 * 将第一个位置作为哨兵,注意体会哨兵的好处和作用
 ***********************************************/
int main()
{
    CreateRandom();
    int* num = (int*)malloc(sizeof(int)*(MAX_COUNT+1));
    ReadFromFile(num);
    InsertSort(num);
    WriteToFile(num);
    free(num);
    return 0;
}

// 生成随机数存入文件
void CreateRandom()
{
    FILE* fp;
    if((fp = fopen("data.txt","w")) == NULL)
    {
        printf("Open File Error !\n");
        return;
    }
    for(int i=0;i<MAX_COUNT;i++)
    { 
        fprintf(fp,"%d\t",rand() % 10000);
    }
    fclose(fp);
}

// 从文件读取数据
void ReadFromFile(int* num)
{
    FILE* fp;
    if((fp = fopen("data.txt","r")) == NULL)
    {
        printf("Open File Error !\n");
        return;
    }
    for(int i=1;i<=MAX_COUNT;i++)
    {
        fscanf(fp,"%d",&num[i]);
    }
    fclose(fp);
}

// 将排好序的数据写入文件
void WriteToFile(int* num)
{
    FILE* fp;
    if((fp = fopen("result.txt","w")) == NULL)
    {
        printf("Open File Error !\n");
        return;
    }
    for(int i=1;i<=MAX_COUNT;i++)
    {
        fprintf(fp,"%d\t",num[i]);
    }
    fclose(fp);
}

void InsertSort(int* num)
{
    int i = 2;
    int j = 0;
    while(i <= MAX_COUNT)        
    {
        num[0] = num[i];
        j = i-1;
        if(num[0] < num[j])
        {
            while(num[0] < num[j])
            {
                num[j+1] = num[j];
                j--;
            }
            num[j+1] = num[0];
        }
        i++;
    }
}
