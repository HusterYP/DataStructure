#include<stdio.h>
#include<stdlib.h>
#include<ctime>

#define status int
#define MAX_COUNT 1000 // 默认对1000个数据进行排序操作

// 函数声明
void CreateRandom();
void ReadFromFile(int* num);
void WriteToFile(int* num);
void BubbleSort(int* num);

/*********************************************** 
 * 冒泡排序
 **********************************************/
int main()
{
    CreateRandom();
    int num[MAX_COUNT];
    ReadFromFile(num);
    BubbleSort(num);
    WriteToFile(num);
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
    srand(time(0));
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

// 改进的冒泡排序
void BubbleSort(int* num)
{
    bool flag = 0;
    for(int i = MAX_COUNT - 1; i > 0; i--)
    {
        flag = 0;
        for(int j = 0; j < i; j++)
        {
            if(num[j] > num[j+1])
            {
                flag = 1;
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
        if(!flag)
            return;
    }
}
