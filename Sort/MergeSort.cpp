#include<stdio.h>
#include<stdlib.h>

#define status int
#define MAX_COUNT 1000 // 默认对1000个数据进行排序操作

// 函数声明
void CreateRandom();
void ReadFromFile(int* num);
void WriteToFile(int* num);
void MergeSort(int* num);
void MergePass(int* origin,int* target,int s);

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

void MergePass(int* origin,int* target,int s)
{
    int count = MAX_COUNT / s;
    int i = 0;
    int k = 0;
    int m = 0;
    if(count <= 0)
        return;
    if(count == 1)
    {
        for(int n = 0;n < MAX_COUNT;n++)
            printf("%d\t",origin[n]);
        
        i = 0;
        k = MAX_COUNT-s;
        while(1)
        {
            if(origin[i] < origin[k])
                target[m++] = origin[i++];
            else
                target[m++] = origin[k++];
            if(i == s || k == MAX_COUNT)
                break;
//            printf("i= %d\tk= %d\tm= %d\n",i,k,m);
        }
        if(i >= s)
            for(k;k < MAX_COUNT;k++)
                target[m++] = origin[k];
        else
            for(i;i < s;i++)
                target[m++] = origin[i];
  //      printf("Done !!\ni= %d\tk =%d\tm= %d\n",i,k,m);
   //     printf("s= %d\tMAX_COUNT= %d\n",s,MAX_COUNT);
        return;
    }
    for(int j = 0;j < count;j = j+2)
    {
        for(i = 0,k = 0;i < s && k < s;)
        {
            if(origin[j*s+i] < origin[(j+1)*s+k])
            {
                target[m++] = origin[j*s+i];
                i++;
            }
            else
            {
                target[m++] = origin[(j+1)*s+k];
                k++;
            }
        }
        if(i >= s)
            for(k;k < s;k++)
                target[m++] = origin[(j+1)*s+k];
        else
            for(i;i < s;i++)
                target[m++] = origin[j*s+i];
    }
}
