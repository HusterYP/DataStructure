#include <stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef int status;
typedef int ElemType;

/* ********************
 * 线性表的顺序存储结构
 * ********************/

typedef struct SqList{
    ElemType elem;
    struct SqList * next;
} SqList,*SqlPtr;

/*-----page 19 on textbook ---------*/
status InitiaList(SqlPtr& L);
status DestroyList(SqlPtr& L);
status ClearList(SqlPtr& L);
status ListEmpty(SqlPtr L);
int ListLength(SqlPtr L);
status GetElem(SqlPtr L,int i,ElemType & e);
status LocateElem(SqlPtr L,ElemType e); //简化过
status Compare(ElemType origin,ElemType target);
status PriorElem(SqlPtr L,ElemType cur,ElemType & pre_e);
status NextElem(SqlPtr L,ElemType cur,ElemType & next_e);
status ListInsert(SqlPtr& L,int i,ElemType e);
status ListDelete(SqlPtr& L,int i,ElemType & e);
status ListTrabverse(SqlPtr L);  //简化过
status readFile(SqlPtr& L);
status writeToFile(SqlPtr& L);

int main(void)
{
    SqlPtr L = NULL;
    int op=1;
    while(op)
    {
        system("clear");
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitiaList       7. LocateElem\n");
        printf("    	  2. DestroyList     8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty     10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem       12. ListTrabverse\n");
        printf("    	  13. SaveToFile        14. ReadFromFile\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~12]:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            if(InitiaList(L)==OK)
                printf("线性表创建成功！\n");
            else
                printf("线性表创建失败！\n");
            getchar();
            getchar();
            break;
        case 2:
            //printf("\n----DestroyList功能待实现！\n");
            if(DestroyList(L) == OK)
            {
                printf("DestroyList成功！");
            }
            else
            {
                printf("DestroyList失败！");
            }
            getchar();
            getchar();
            break;
        case 3:
            //printf("\n----ClearList功能待实现！\n");
            if(ClearList(L) == OK)
            {
                printf("ClearList成功！");
            }
            else
            {
                printf("ClearList失败！");
            }
            getchar();
            getchar();
            break;
        case 4:
            //printf("\n----ListEmpty功能待实现！\n");
            if(ListEmpty(L) == OK)
            {
                printf("List is Empty!");
            }
            else
            {
                printf("List is not Empty!");
            }
            getchar();
            getchar();
            break;
        case 5:
            //printf("\n----ListLength功能待实现！\n");
            printf("The length of the List : %d\n",ListLength(L));
            getchar();
            getchar();
            break;
        case 6:
            //printf("\n----GetElem功能待实现！\n");
            ElemType e;
            int index;
            printf("Please input the index of the List:\n");
            scanf("%d",&index);
            if(GetElem(L,index,e) == OK)
            {
                printf("The Elem of %d is %d \n",index,e);
            }
            else
            {
                printf("GetElem Error ！\n");
            }
            getchar();
            getchar();
            break;
        case 7:
            //printf("\n----LocateElem功能待实现！\n");
            printf("Please input the Elem: \n");
            ElemType target;
            scanf("%d",&target);
            int targetIndex;
            targetIndex= LocateElem(L,target);
            if(targetIndex > 0)
            {
                printf("The index of the target Elem is : %d\n",targetIndex);
            }
            else
            {
                printf("The target Elem does not exist !\n");
            }
            getchar();
            getchar();
            break;
        case 8:
            //printf("\n----PriorElem功能待实现！\n");
            ElemType pre_e;
            ElemType targetCurPre;
            printf("Please input the target Elem: \n");
            scanf("%d",&targetCurPre);
            if(PriorElem(L,targetCurPre,pre_e) == OK)
            {
                printf("The prior of %d is : %d\n",targetCurPre,pre_e);
            }
            else
            {
                printf("The prior of %d does not exist ! \n",targetCurPre);
            }
            getchar();
            getchar();
            break;
        case 9:
            //printf("\n----NextElem功能待实现！\n");
            ElemType targetCurNext;
            ElemType next_e;
            printf("Please input the target Elem:\n");
            scanf("%d",&targetCurNext);
            if(NextElem(L,targetCurNext,next_e) == OK)
            {
                printf("The next of %d is : %d\n",targetCurNext,next_e);
            }
            else
            {
                printf("The next of %d does not exist!\n",targetCurNext);
            }
            getchar();
            getchar();
            break;
        case 10:
            //printf("\n----ListInsert功能待实现！\n");
            printf("Please input the target Elem: \n");
            ElemType insertElem;
            scanf("%d",&insertElem);
            printf("Please input the indext of the insert Elem :\n");
            int insertIndex;
            scanf("%d",&insertIndex);
            if(ListInsert(L,insertIndex,insertElem) == OK)
            {
                printf("Insert Successfully !\n");
            }
            else
            {
                printf("Insert Error !\n");
            }
            getchar();
            getchar();
            break;
        case 11:
            //printf("\n----ListDelete功能待实现！\n");
            ElemType targetDelete;
            int deleteIndex;
            printf("Please input the index of the delete Elem :\n");
            scanf("%d",&deleteIndex);
            if(ListDelete(L,deleteIndex,targetDelete) == OK)
            {
                printf("Delete Successfully ! The Delete Elem is : %d\n",targetDelete);
            }
            else
            {
                printf("Delete Error !\n");
            }
            getchar();
            getchar();
            break;
        case 12:
            //printf("\n----ListTrabverse功能待实现！\n");
            if(!ListTrabverse(L))
                printf("线性表是空表！\n");
            getchar();
            getchar();
            break;
        case 13:
            if(writeToFile(L) == OK)
            {
                printf("Write to file Successfully!\n");
            }
            else
            {
                printf("Write to file Error!\n");
            }
            getchar();
            getchar();
            break;
        case 14:
            if(readFile(L) == OK)
            {
                printf("Create OK\n");
            }
            else
            {
                printf("Create Error\n");
            }
            getchar();
            getchar();
            break;
        case 0:
            break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
    return 0;
}//end of main()


/*
单链表，带头结点
*/

// 链表节点初始化
status InitiaList(SqlPtr& L)
{
    if(L != NULL && L->next != NULL)
    {
        return ERROR;
    }
    L = (SqlPtr)malloc(sizeof(SqList));
    L->next = NULL;
    return OK;
}

// 销毁链表
status DestroyList(SqlPtr& L)
{
    if(L == NULL)
    {
        return ERROR;
    }
    SqlPtr temp1 = L;
    SqlPtr temp2 = L->next;
    while(temp2 != NULL)
    {
        free(temp1);
        temp1 = temp2;
        temp2 = temp2->next;
    }
    free(temp1);
    L = NULL;
    return OK;
}

// 清空链表
status ClearList(SqlPtr& L)
{
    if(L == NULL || L->next == NULL)
    {
        return ERROR;
    }
    SqlPtr temp1 = L->next;
    SqlPtr temp2 = L->next;
    while(temp1 != NULL)
    {
        temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    L->next = NULL;
    return OK;
}

// 链表是否为空
status ListEmpty(SqlPtr L)
{
    if(L == NULL || L->next == NULL)
        return OK;
    return ERROR;
}

// 链表长度
int ListLength(SqlPtr L)
{
    if(L == NULL)
        return -1;
    SqlPtr temp = L->next;
    int total = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        total++;
    }
    return total;
}

// 返回第i个位置元素
status GetElem(SqlPtr L,int i,ElemType & e)
{
    if(L == NULL || L->next == NULL || i<=0)
        return ERROR;
    SqlPtr pre = L->next;
    int j = 0;
    while(j < i-1 && pre != NULL)
    {
        pre = pre->next;
        j++;
    }
    if(pre == NULL)
        return ERROR;
    e = pre->elem;
    return OK;
}

// 返回给定元素的索引
status LocateElem(SqlPtr L,ElemType e) //简化过
{
    if(L == NULL || L->next == NULL)
        return -1;
    SqlPtr temp = L->next;
    int index = 1;
    while(temp != NULL && Compare(temp->elem,e)!=0)
    {
        index++;
        temp = temp->next;
    }
    if(temp == NULL)
        return -1;
    return index;
}

// 元素比较
status Compare(ElemType origin,ElemType target)
{
    return origin - target;
}

// 元素前驱元素
status PriorElem(SqlPtr L,ElemType cur,ElemType & pre_e)
{
    if(L == NULL || L->next == NULL || Compare(L->next->elem,cur) == 0)
        return ERROR;
    SqlPtr temp = L->next;
    SqlPtr pre = L->next;
    while(temp != NULL && Compare(temp->elem,cur) != 0)
    {
        pre = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        return ERROR;
    pre_e = pre->elem;
    return OK;
}

// 返回元素后继
status NextElem(SqlPtr L,ElemType cur,ElemType & next_e)
{
    if(L == NULL || L->next == NULL)
        return ERROR;
    SqlPtr temp = L->next;
    while(temp != NULL && Compare(temp->elem,cur) != 0)
    {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL)
        return ERROR;
    next_e = temp->next->elem;
    return OK;
}

// 在第i个位置插入
status ListInsert(SqlPtr& L,int i,ElemType e)
{
    if(L == NULL || i<=0)
        return ERROR;
    int index = 1;
    SqlPtr temp = L;
    while(temp != NULL && index < i)
    {
        temp = temp->next;
        index++;
    }
    if(index < i || temp == NULL)
        return ERROR;
    SqlPtr insertNode = (SqlPtr)malloc(sizeof(SqList));
    if(insertNode == NULL)
        return ERROR;
    insertNode->next = temp->next;
    insertNode->elem = e;
    temp->next = insertNode;
    return OK;
}

// 删除指定第i个位置的元素
status ListDelete(SqlPtr& L,int i,ElemType & e)
{
    if(L == NULL || L->next == NULL  || i<=0)
        return ERROR;
    SqlPtr temp = L->next;
    SqlPtr pre = temp;
    int index = 1;
    while(temp !=  NULL && index < i)
    {
        pre = temp;
        temp = temp->next;
        index++;
    }
    if(temp == NULL)
        return ERROR;
    pre->next = temp->next;
    e = temp->elem;
    free(temp);
    return OK;
}

// 遍历链表
status ListTrabverse(SqlPtr L)  //简化过
{
    if(L == NULL)
        return ERROR;
    printf("The Data is : \n");
    SqlPtr temp = L->next;
    while(temp != NULL)
    {
        printf("%d\t",temp->elem);
        temp = temp->next;
    }
    printf("\n");
    return OK;
}

status readFile(SqlPtr& L)
{
    if(L == NULL)
        InitiaList(L);
    FILE *fp;
    printf("The data source file name is: data.txt\n");
    if((fp=fopen("data.txt","r"))==NULL)
    {
        printf("File Open Error!\n");
    }
    int a[1] = {0};
    int i = 1;
    while(fscanf(fp,"%d",&a[0]) == 1)
    {
        ListInsert(L,i,a[0]);
        i++;
        a[0] = 0;
    }
    fclose(fp);
    return OK;
}
status writeToFile(SqlPtr& L)
{
    if(L == NULL)
        return ERROR;
    FILE  *fp;
    if ((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error!\n ");
        return ERROR;
    }
    printf("The save file is data.txt!\n");
    SqlPtr temp = L->next;
    while(temp != NULL)
    {
        fprintf(fp,"%d\t",temp->elem);
        temp = temp->next;
    }
    fclose(fp);
    return OK;
}
