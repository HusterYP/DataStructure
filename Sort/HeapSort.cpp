#include<stdio.h>
#include<stdlib.h>
#include<ctime>

#define status int
#define MAX_COUNT 1000 // 默认对1000个数据进行排序操作

// 函数声明
void CreateRandom();
void ReadFromFile(int* num);
void WriteToFile(int* num);
void HeapSort(int* num);
void InitHeap(int* num);
void CreateBigHeap(int* num,int count);
void ExchangeValue(int& a,int& b);

/*********************************************** 
 * 堆排序
 * 这里采用大顶堆,注意初始大顶堆的构建
 ***********************************************/
int main()
{
    CreateRandom();
    int* num = (int*)malloc(sizeof(int)*MAX_COUNT);
    ReadFromFile(num);
    HeapSort(num);
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

void HeapSort(int* num)
{
   InitHeap(num);
   int cur = MAX_COUNT-1;
   int temp;
   while(cur > 0) 
   {
       temp = num[cur];
       num[cur] = num[0];
       num[0] = temp;
       cur--;
       CreateBigHeap(num,cur+1);
   }
}

// 重新创建大顶堆
// count: 表示对num中的前count个元素进行大顶堆调整
void CreateBigHeap(int* num,int count)
{
    int i = 1;
    while(i*2 < count)
    {
        if(i*2+1 <= count)
        {
            if(num[i*2-1] >  num[i*2] && num[i*2-1] > num[i-1])
            {
                ExchangeValue(num[i-1],num[i*2-1]);
                i = i*2;
            }
            else if(num[i*2-1] <= num[i*2] && num[i*2] > num[i-1])
            {
                ExchangeValue(num[i-1],num[i*2]);
                i = i*2+1;
            }
            else
                break;
        }
        else
        {
            if(num[i*2-1] > num[i-1])
                ExchangeValue(num[i-1],num[i*2-1]);
            i = i*2;
        }
    }
}

void ExchangeValue(int& a,int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 初始化大顶堆
void InitHeap(int* num)
{
    int i = MAX_COUNT / 2;
    int j = i;
    while(i > 0)
    {
        // 当最后一个元素为单节点时(即没有兄弟节点)
        if(i == MAX_COUNT / 2 && MAX_COUNT % 2 == 0)
        {
            if(num[i-1] < num[i*2-1])
                ExchangeValue(num[i-1],num[i*2-1]);
        }
        else
        {
            j = i;
            while(j*2 < MAX_COUNT)
            {
                if(num[j*2-1] > num[j*2] && num[j*2-1] > num[j-1])
                {
                    ExchangeValue(num[j*2-1],num[j-1]);
                    j = j*2;
                }
                else if(num[j*2-1] < num[j*2] && num[j*2] > num[j-1])
                {
                    ExchangeValue(num[j*2],num[j-1]);
                    j = j*2+1;
                }
                else
                    break;
            }
        }
        i--;
    }
}
