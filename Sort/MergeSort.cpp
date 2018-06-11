#include<stdio.h>
#include<stdlib.h>
#include<ctime>

#define status int
#define MAX_COUNT 1000 // 默认对1000个数据进行排序操作

// 函数声明
void CreateRandom();
void ReadFromFile(int* num);
void WriteToFile(int* num);
void MergeSort(int* num);
void Merge(int* origin, int* target, int low, int mid, int high);
void MergePass(int* origin, int* target, int s);

/*********************************************** 
 * 归并排序
 * 采用二路归并
 **********************************************/
int main()
{
    CreateRandom();
    int num[MAX_COUNT];
    ReadFromFile(num);
    MergeSort(num);
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

void MergeSort(int* num)
{
    int result[MAX_COUNT];
    int s = 1; // 归并长度
    while(s < MAX_COUNT)
    {
        MergePass(num,result,s); 
        s *= 2;
        MergePass(result,num,s);
        s *= 2;
    }
}

void MergePass(int* origin, int* target, int s)
{
   int low = 0;
   int high = 0;
   int mid = 0;
   int i = 0;
   while(high < MAX_COUNT - 1)
   {
        low = i * s;
        mid = (i + 1) * s - 1;
        int temp = (i + 2) * s - 1;
        high = temp > MAX_COUNT - 1 ? MAX_COUNT - 1 : temp;
        Merge(origin, target, low, mid, high);
        i += 2;
   }
}

// 对给定的两个部分数据进行归并
void Merge(int* origin, int* target, int low, int mid, int high)
{
    int temp = mid + 1;
    int cur = low;
    for(low,temp; low <= mid && temp <= high;)
    {
        if(origin[low] < origin[temp])
            target[cur++] = origin[low++];
        else
            target[cur++] = origin[temp++];
    }
    if(temp == high + 1)
        for(low; low <= mid; low++)
            target[cur++] = origin[low];
    else if(low == mid + 1)
        for(temp; temp <= high; temp++)
            target[cur++] = origin[temp];
}
