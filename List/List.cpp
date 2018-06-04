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
void PrintAll(List L);

int main()
{
    List L;
    L.elem = NULL;
    int option;
    while(1)
    {
        system("clear");
        printf("Welcome to use !\n");
        printf("1. InitList                     2. DestroyList\n");
        printf("3. ClearList                    4. ListEmpty\n");
        printf("5. ListLength                   6. GetElem\n");
        printf("7. PriorElem                    8. NextElem\n");
        printf("9. InsertElem                   10. DeleteElem\n");
        printf("11. LocateElem                  12. PrintAll\n");
        printf("0. Exit\n");
        printf("Please input the option:\n ");
        scanf("%d",&option);        
       switch(option)
       {
           case 1:
               if(InitList(L) == ERROR)
                   printf("InitList Error !\n");
               else
                   printf("InitList Succeed\n");
               getchar();
               getchar();
               break;
           case 2:
               if(DestroyList(L) == ERROR)
                    printf("DestroyList Error!\n");
               else
                   printf("DestroyList Succeed\n");
               getchar();
               getchar();
               break;
           case 3:
               if(ClearList(L) == ERROR)
                   printf("ClearList ERROR");
               else
                   printf("ClearList Succeed \n");
               getchar();
               getchar();
               break;
           case 4:
               if(ListEmpty(L) == ERROR)
                   printf("List is Not Empty\n");
               else
                   printf("List is Empty\n");
               getchar();
               getchar();
               break;
           case 5:
               int length;
               length = ListLength(L);
               printf("The length of the list is %d\n",length);
               getchar();
               getchar();
               break;
           case 6:
               printf("Please input the target index of the elem : \n");
               int index;
               scanf("%d",&index);
               ElemType e1;
               if(GetElem(L,index,e1)==ERROR)
                   printf("GetElem ERROR\n"); 
               else
                   printf("The Elem of at %d is %d",index,e1);
               getchar();
               getchar();
               break;
           case 7:
               printf("Please input the target elem :\n");
               ElemType e2;
               ElemType e3;
               scanf("%d",&e2);
               if(PriorElem(L,e2,e3) == ERROR)
                   printf("The %d does not have a Prior\n",e2);
               else
                   printf("The Prior of %d is %d\n",e2,e3);
               getchar();
               getchar();
               break;
           case 8:
               printf("Please input the target elem :\n");
               ElemType e4;
               ElemType e5;
               scanf("%d",&e4);
               if(NextElem(L,e4,e5) == ERROR)
                   printf("The %d does not have a Next \n",e4);
               else
                   printf("The Next of %d is %d\n",e4,e5);
               getchar();
               getchar();
               break;
           case 9:
               printf("Please input the target elem :\n");
               ElemType e6;
               int index2;
               scanf("%d",&e6);
               printf("Please input the index : \n");
               scanf("%d",&index2);
                if(InsertElem(L,index2,e6) == ERROR)
                    printf("InsertElem ERROR\n");
                else
                    printf("InsertElem Succeed\n");
               getchar();
               getchar();
               break;
           case 10:
               printf("Please input the index :\n");
               int index3;
               ElemType e7;
               scanf("%d",&index3);
               if(DeleteElem(L,index3,e7) == ERROR)
                   printf("DeleteElem Error\n");
               else
                   printf("DeleteElem Succeed ! The DeleteElem is %d\n",e7);
               getchar();
               getchar();
               break;
           case 11:
               printf("Please input the target elem:\n");
               ElemType e8;
               scanf("%d",&e8);
               int index4;
               index4 = LocateElem(L,e8);
               if(index4>=0)
                   printf("The index of %d is %d:\n",e8,index4);
               else
                   printf("LocateElem ERROR !\n");
               getchar();
               getchar();
               break;
           case 12:
               printf("The Elem is :\n");
               PrintAll(L);
               getchar();
               getchar();
               break;
           case 0:
               printf("Bye Bye ! \n");
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
    {
        L.elem = (ElemType*)realloc(L.elem,( MAXSIZE+INCREAMENT_SIZE)*sizeof(ElemType));
        if(L.elem == NULL)
            return ERROR;
        else
            L.size += INCREAMENT_SIZE;
    }
    for(int i=L.length;i>=index;i--)
        L.elem[i] = L.elem[i-1];
    L.elem[index-1] = e;
    L.length++;
    return OK;
}

// 删除第i个元素
State DeleteElem(List &L, int index,ElemType & elem)
{
    if(L.elem == NULL || L.length <= 0 || index <= 0 || index > L.length)
        return ERROR;
    for(int i=index-1;i<L.length-1;i++)
        L.elem[i] = L.elem[i+1];
    L.length--;
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
    if(index>=L.length || L.elem[index] != elem)
        return ERROR;
    return index;
}

// 打印所有元素
void PrintAll(List L)
{
    if(L.elem != NULL && L.length > 0)   
        for(int i=0;i<L.length;i++)
            printf("%d\t",L.elem[i]);
    printf("\n");
}
