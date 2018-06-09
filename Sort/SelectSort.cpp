#include<stdio.h>
#include<stdlib.h>

#define status int
#define MAX_COUNT 1000 // 默认对1000个数据进行排序操作

// 函数声明
void CreateRandom();
void ReadFromFile(int* num);
void WriteToFile(int* num);
void SelectSort(int* num);

/*********************************************** 
 * 选择排序
 ***********************************************/
int main()
{
    CreateRandom();
    int* num = (int*)malloc(sizeof(int)*MAX_COUNT);
    ReadFromFile(num);
    SelectSort(num);
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
    for(int i=0;i<MAX_COUNT;i++)
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
    for(int i=0;i<MAX_COUNT;i++)
    {
        fprintf(fp,"%d\t",num[i]);
    }
    fclose(fp);
}

void SelectSort(int* num)
{
    int temp;
    for(int i=0;i<MAX_COUNT;i++)    
    {
        int min = i;
        for(int j=i+1;j<MAX_COUNT;j++)
        {
            if(num[j] < num[min])
                min = j;
        }
        if(min != i)
        {
            temp = num[i];
            num[i] = num[min];
            num[min] = temp;
        }
    }
}
