#include<stdio.h>
#include<stdlib.h>
#include<ctime>

#define status int
#define MAX_COUNT 1000 // 默认对1000个数据进行排序操作

// 函数声明
void CreateRandom();
void ReadFromFile(int* num);
void WriteToFile(int* num);
void FastSort(int* num, int low, int high);
int FastPass(int* num, int low, int high);

/*********************************************** 
 * 快排
 **********************************************/
int main()
{
    CreateRandom();
    int num[MAX_COUNT];
    ReadFromFile(num);
    FastSort(num, 0, MAX_COUNT-1);
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

void FastSort(int* num, int low, int high)
{
    if(low >= high)
        return;
    int temp = FastPass(num, low, high);
    FastSort(num, low, temp-1);
    FastSort(num, temp+1, high);
}

int FastPass(int* num, int low, int high)
{
    int temp = num[low];
    bool move_high = 1;
    for(low,high; low != high;)
    {
        if(move_high)
        {
            if(num[high] < temp)
            {
                num[low++] = num[high];
                move_high = 0;
            }
            else
                high--;
        }
        else
        {
            if(num[low] > temp)
            {
                num[high--] = num[low];
                move_high = 1;
            }
            else 
                low++;
        }
    }
    num[low] = temp;
    return low;
}
