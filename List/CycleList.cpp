#include<stdio.h>
#include<stdlib.h>

#define state int
#define ERROR -1
#define OK 1
#define ElemType int

/**********************
 *双向循环链表,带头结点
 **********************/
typedef struct Node
{
    struct Node* prior;
    struct Node* next;
    ElemType data;
} *CyclePtr,CycleList;

// 函数声明
state InitCycleList(CyclePtr& L);
state DestroyCycleList(CyclePtr& L);
state Insert(CyclePtr& L,ElemType elem);
state Delete(CyclePtr& L,ElemType elem);
state GetElem(CyclePtr L,int index,ElemType & elem);
int LocateElem(CyclePtr L,ElemType target);
int ListLength(CyclePtr L);
void PrintAll(CyclePtr L);
int Compare(ElemType target,ElemType origin);
state PriorElem(CyclePtr L,ElemType origin,ElemType &target);
state NextElem(CyclePtr L,ElemType origin,ElemType &target);

int main()
{
    CyclePtr L = NULL;
    int option;
    while(1)
    {
        system("clear");
        printf("Welcome to use !\n");
        printf("1. InitList                     2. DestroyList\n");
        printf("3. ListLength                   4. GetElem\n");
        printf("5. PriorElem                    6. NextElem\n");
        printf("7. InsertElem                   8. DeleteElem\n");
        printf("9. LocateElem                  10. PrintAll\n");
        printf("0. Exit\n");
        printf("Please input the option:\n ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                if(InitCycleList(L) == OK)
                    printf("Init Successfully\n");
                else
                    printf("Init ERROR !\n");
                getchar();
                getchar();
                break;
            case 2:
                if(DestroyCycleList(L) == OK) 
                    printf("DestroyList OK\n");
                else
                    printf("DestroyList ERROR\n");
                getchar();
                getchar();
                break;
            case 3:
                int length ;
                length  = ListLength(L);
                if(length < 0)
                    printf("Get List Length ERROR\n");
                else
                    printf("The length of the list is : %d\n",length);
                getchar();
                getchar();
                break;
            case 4:
                ElemType elme1;
                printf("Please input the index of the target elem :\n");
                int index1;
                scanf("%d",&index1);
                if(GetElem(L,index1,elme1) == OK)
                    printf("The elem at %d is %d\n",index1,elme1);
                else
                    printf("Get Element ERROR\n");
                getchar();
                getchar();
                break;
            case 5:
                ElemType elem2;
                ElemType elem3;
                printf("Please input the orgin elem: \n");
                scanf("%d",&elem2);
                if(PriorElem(L,elem2,elem3) == OK)
                    printf("The Prior of %d is %d\n",elem2,elem3);
                else
                    printf("Get Prior ERROR\n");
                getchar();
                getchar();
                break;
            case 6:
                ElemType elem4;
                ElemType elem5;
                printf("Please input the orgin elem: \n");
                scanf("%d",&elem4);
                if(NextElem(L,elem4,elem5) == OK)
                    printf("The Next of %d is %d\n",elem4,elem5);
                else
                    printf("Get NextElem ERROR \n");
                getchar();
                getchar();
                break;
            case 7:
                ElemType elem6;
                printf("Please input the target Elem :\n");
                scanf("%d",&elem6);
                if(Insert(L,elem6) == OK)
                    printf("Insert Elem OK\n");
                else
                    printf("Insert Elem ERROR\n");
                getchar();
                getchar();
                break;
            case 8:
                ElemType elem7;
                printf("Please input the target Elem :\n");
                scanf("%d",&elem7);
                if(Delete(L,elem7) == OK)
                    printf("Delete Elem OK\n");
                else
                    printf("Delete Elem ERROR\n");
                getchar();
                getchar();
                break;
            case 9:
                ElemType elem8;
                printf("Please input the target elem :\n");
                scanf("%d",&elem8);
                int index2 ;
                index2= LocateElem(L,elem8);
                if(index2 >= 0)
                    printf("The index of %d is %d \n",elem8,index2);
                else
                    printf("LocateElem ERROR\n");
                getchar();
                getchar();
                break;
            case 10:
                PrintAll(L);
                getchar();
                getchar();
                break;
            case 0:
                printf("Bye Bye !\n");
                getchar();
                getchar();
                return 0;
            default:
                getchar();
                getchar();
                break;
        }
    }
    return 0;
}

// 初始化
state InitCycleList(CyclePtr& L)
{
    if(L != NULL)
        return ERROR;
    L = (CyclePtr)malloc(sizeof(CycleList));
    if(L == NULL)
        return ERROR;
    L->next = L;
    L->prior = L;
    return OK;
}

state DestroyCycleList(CyclePtr& L)
{
    if(L == NULL)
        return ERROR;
    CyclePtr temp = L->next;
    CyclePtr cur = L->next;
    while(temp != L)
    {
        cur = temp->next;
        free(temp);
        temp = cur;
    }
    free(L);
    L->next = L;
    L->prior= L;
    L = NULL;
    return OK;
}

// 插入数据,采用头插法
state Insert(CyclePtr& L,ElemType elem)
{
    if(L == NULL)
        return ERROR;
    CyclePtr temp = (CyclePtr)malloc(sizeof(CycleList));
    if(temp == NULL)
        return ERROR;
    temp->data = elem;
    temp->next = L->next;
    temp->prior = L;
    L->next->prior = temp;
    L->next = temp;
    return OK;
}

// 删除数据
state Delete(CyclePtr& L,ElemType elem)
{
    if(L == NULL || L->next == L)
        return ERROR;
    CyclePtr temp = L->next;
    while(temp != L && Compare(temp->data,elem) !=0)
    {
        temp = temp->next;
    }
    if(temp == L)
        return ERROR;
    temp->next->prior = temp->prior;
    temp->prior->next = temp->next;
    free(temp);
    return OK;
}

// 得到第i个位置数据
state GetElem(CyclePtr L,int index,ElemType & elem)
{
   if(L==NULL || index <= 0 || index > ListLength(L))
       return ERROR;
   CyclePtr temp = L->next;
   int i = 1;
   while(temp != L && i<index)
   {
       i++;
       temp = temp->next;
   }
   if(i<index)
       return ERROR;
   elem = temp->data;
   return OK;
}

// 数据定位,返回指定数据索引
int LocateElem(CyclePtr L,ElemType target)
{
    if(L == NULL)
        return ERROR;
    CyclePtr temp = L->next;
    int index = 0;
    while(temp != L && Compare(temp->data,target) != 0)
    {
        temp = temp->next;
        index++;
    }
    if(temp == L)
        return ERROR;
    return index;
}

// 返回数据长度
int ListLength(CyclePtr L)
{
    if(L == NULL)    
        return ERROR;
    int sum = 0;
    CyclePtr temp = L->next;
    while(temp != L)
    {
        sum++;
        temp = temp->next;
    }
    return sum;
}

// 打印所有数据
void PrintAll(CyclePtr L)
{
    if(L == NULL)
        return;
    CyclePtr temp = L->next;
    while(temp != L)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 数据比较
int Compare(ElemType target,ElemType origin)
{
    return target - origin;
}

// 得到元素前驱
state PriorElem(CyclePtr L,ElemType origin,ElemType &target)
{
    if(L == NULL)
        return ERROR;
    CyclePtr temp = L->next;
    while(temp != L && Compare(origin,temp->data) != 0)
    {
        temp = temp->next;
    }
    if(Compare(origin,temp->data)==0)
    {
        if(temp->prior != L)
            target = temp->prior->data;
        else
            target = L->prior->data;
        return OK;
    }
    return ERROR;
}

// 得到元素后继
state NextElem(CyclePtr L,ElemType origin,ElemType &target)
{
    if(L == NULL)
        return ERROR;
    CyclePtr temp = L->next;
    while(temp != L && Compare(origin,temp->data) != 0)
    {
        temp  =temp->next;
    }
    if(Compare(origin,temp->data) == 0)
    {
        if(temp->next != L)
            target = temp->next->data;
        else
            target = L->next->data;
        return OK;
    }
    return ERROR;
}





