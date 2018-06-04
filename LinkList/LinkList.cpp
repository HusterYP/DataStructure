#include<stdio.h>
#include<stdlib.h>

#define State int
#define ElemType int
#define ERROR -1
#define OK 1
#define MAXSIZE 100 // 默认最大存储空间
#define INCREAMENT_SIZE 10 // 默认增量

/*************************
 *线性表的顺序存储结构
 ************************/

// 结构体声明
typedef struct{
    ElemType* elem;
    int size; // 总存储空间
    int length; // 当前元素长度
}List;

// 函数声明
State InitList(List & L);
State DestroyList(List & L);
State ClearList(List & L);
State ListEmpty(List L);
State ListLength(List L);
State GetElem(List L,int index, ElemType &  e);
State PriorElem(List L, ElemType target,ElemType &origin);
State NextElem(List L, ElemType target, ElemType &origin);
State InsertElem(List & L, int index, ElemType e);
State DeleteElem(List & L, int index, ElemType & elem);
int LocateElem(List L, ElemType elem);

int main()
{
    List L;
    L.elem = NULL;
    int option;
    printf("Welcome to use !\n");
    printf("1. InitList                     2. DestroyList\n");
    printf("3. ClearList                    4. ListEmpty\n");
    printf("5. ListLength                   6. GetElem\n");
    printf("7. PriorElem                    8. NextElem\n");
    printf("9. InsertElem                   10. DeleteElem\n");
    printf("11. LocateElem                  13. PrintAll\n");
    printf("0. Exit\n");
    printf("Please input the option:\n ");
    while(1)
    {
       scanf("%d",&option);        
       switch(option)
       {
           case 1:
               getchar();
               getchar();
           case 2:
               getchar();
               getchar();
           case 3:
               getchar();
               getchar();
           case 4:
               getchar();
               getchar();
           case 5:
               getchar();
               getchar();
           case 6:
               getchar();
               getchar();
           case 7:
               getchar();
               getchar();
           case 8:
               getchar();
               getchar();
           case 9:
               getchar();
               getchar();
           case 10:
               getchar();
               getchar();
           case 11:
               getchar();
               getchar();
           case 12:
               getchar();
               getchar();
           case 13:
               getchar();
               getchar();
           case 0:
               printf("Bye Bye ! \n");
               getchar();
               getchar();
               break;
           default:
               getchar();
               getchar();
       }
    }
    return 0;
}


// 初始化
State InitList(List & L)
{
    if(L.elem != NULL)
    {
        printf("The List has been initialized !\n");
        return ERROR;
    }
    L.elem = (ElemType*)malloc(MAXSIZE*sizeof(int));
    if(L.elem == NULL)
    {
        printf("The List malloc error !\n");
        return ERROR;
    }
    L.size = MAXSIZE;
    L.length = 0;
    return OK;
}

// 销毁线性表
State DestroyList(List & L)
{
    if(L.elem == NULL)
    {
        printf("The List has been destroyed !\n");
        return ERROR;
    }
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.size = 0;
    return OK;
}

// 清空List
State ClearList(List & L)
{
    if(L.elem == NULL)
    {   
        printf("List has not been initialized \n");
        return ERROR;
    }
    L.length = 0;
    return OK;
}

// List是否为空
State ListEmpty(List L)
{
   return  L.length == 0 ? OK : ERROR;
}

// 返回List长度
State ListLength(List L)
{
    return L.length;
}

// 获取第i个元素
State GetElem(List L,int index, ElemType & e)
{
    if(L.elem == NULL || L.length == 0 || index <= 0 || index > L.length)
        return ERROR;
    e = L.elem[index-1];
    return OK;
}

// 获取元素前驱
State PriorElem(List L, ElemType target,ElemType &origin)
{
    if(L.elem == NULL || L.length <= 0)
        return ERROR;
    int index = LocateElem(L,target);
    if(index <= 0)
    {
        printf("The Elem of %d has no Prior !\n",target);
        return ERROR;
    }
    origin = L.elem[index-1];
    return OK;
}

// 返回元素后继
State NextElem(List L, ElemType target, ElemType &origin)
{
    if(L.elem == NULL || L.length <= 0)
    {
        return ERROR;    
    }
    int index = LocateElem(L,target);
    if(index >= L.length - 1)
    {
        printf("The Elem of %d has no next elem !\n",target);
        return ERROR;
    }
    origin = L.elem[index+1];
    return OK;
}

// 在第i个位置插入元素
State InsertElem(List & L, int index, ElemType e)
{
   if(L.elem == NULL || index <= 0 || index > L.length+1)
       return ERROR;
    if(L.length >= L.size)
        L.elem = (ElemType*)realloc(L.elem,( MAXSIZE+INCREAMENT_SIZE)*sizeof(ElemType));
    if(L.elem == NULL)
        return ERROR;
    L.size += INCREAMENT_SIZE;
    L.elem[index-1] = e;
    L.length ++;
    return OK;
}

// 获取元素位置,返回元素索引,否则返回-1
int LocateElem(List L, ElemType elem)
{
    if(L.elem == NULL || L.length == 0)
        return ERROR;
    int index = 0;
    while(L.elem[index] != elem && index < L.length)
        index++;
    if(L.elem[index] != elem)
        return ERROR;
    return index;
}
