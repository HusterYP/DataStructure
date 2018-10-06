#include<stdio.h>
#include<stdlib.h>
#include<ctime>

#define status int
#define MAX_COUNT 1000 // 默认对1000个数据进行排序操作

typedef struct Node
{
    int data;
    struct Node* next;
}Node,*PNode;

// 函数声明
void CreateRandom();
void ReadFromFile(int* num);
void WriteToFile(int* num);
void BaseSort(int* num);
void InsertQueue(int origin, Node nodes, PNode rear);
void ReOrderData(int* target, Node nodes[], PNode rears[]);
void InitRear(PNode rears[], Node head[]);

/*********************************************** 
 * 基数排序
 * 为了保证稳定性,需要使用队列
 **********************************************/
int main()
{
    CreateRandom();
    int num[MAX_COUNT];
    ReadFromFile(num);
    BaseSort(num);
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

void BaseSort(int* num)
{
    Node nodes[10];
    PNode rears[10]; // 记录10个队列的队尾信息
    InitRear(rears,nodes);
    int temp;
    int base = 1;
    bool flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i = 0; i < MAX_COUNT; i++)
        {
            if(base == 1)
                temp = num[0] % (base * 10);
            else
                temp = num[0] % (base * 10) / ((base - 1) * 10);
            if(temp != 0)
                flag = 1;
            InsertQueue(num[i], nodes[temp], rears[temp]);
        }
        base++;
        ReOrderData(num, nodes, rears);
    }
}

// 插入数据
void InsertQueue(int origin, Node nodes, PNode rear)
{
    PNode temp = (PNode)malloc(sizeof(Node));
    temp->data = origin;
    temp->next = NULL;
    rear->next = temp;
    rear = temp;
}

// 将10个队列中的数据重新组织
void ReOrderData(int* target, Node nodes[], PNode rears[])
{
    PNode temp = NULL;
    PNode pre = NULL;
    int cur = 0;
    for(int i = 0; i < 10; i++) 
    {
        temp = &nodes[i];
        pre = temp->next;
        while(temp != rears[i] && temp != NULL)   
        {
            temp = temp->next;
            pre = temp;
            target[cur++] = temp->data;

            if(i == 4)
                printf("data= %d\n",temp->data);

            free(pre);
        }
        rears[i] = &nodes[i];
        rears[i]->next = NULL;
    }
}

// 初始化队尾巴
void InitRear(PNode rears[], Node head[])
{
    for(int i = 0; i < 10; i++)
    {
        rears[i] = &head[i];
        head[i].next = NULL;
    }
}
