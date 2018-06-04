#include<stdio.h>
#include<stdlib.h>

#define state int
#define ERROR -1
#define OK 1
#define ElemType int
#define MAX_SIZE 100
#define INCREAMENT_SIZE 10

/****************
栈，使用动态分配
*****************/
typedef struct Node
{
	ElemType* data;
	int size;  // 数据长度
	int top; //top指针，约定指向栈顶元素
}SqStack;

// 函数声明
state InitStack(SqStack& S);
state DestroyStack(SqStack& S);
state Push(SqStack& S,ElemType elem);
state Pop(SqStack& S,ElemType& elem);
state GetElem(SqStack S,int index,ElemType& elem);
int LocateElem(SqStack S,ElemType elem);
state PriorElem(SqStack S,ElemType origin,ElemType& target);
state NextElem(SqStack S,ElemType origin,ElemType& target);
int GetLength(SqStack S);
void PrintAll(SqStack S);
int Compare(ElemType origin, ElemType target);

int main()
{
    int option;
	SqStack S;
	S.data = NULL;
	S.size = 0;
	S.top = -1;
    while(1)
    {
        system("clear");
        printf("Welcome to use !\n");
        printf("1. Init                         2. Destroy\n");
        printf("3. Length                       4. GetElem\n");
        printf("5. PriorElem                    6. NextElem\n");
        printf("7. InsertElem                   8. DeleteElem\n");
        printf("9. LocateElem                  10. PrintAll\n");
        printf("0. Exit\n");
        printf("Please input the option:\n ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
				if(InitStack(S) == OK)
					printf("Init Succeed\n");
				else
					printf("Init ERROR\n");
                getchar();
                getchar();
                break;
            case 2:
				if(DestroyStack(S) == OK)
					printf("DestroyStack OK\n");
				else
					printf("DestroyStack ERROR\n");
                getchar();
                getchar();
                break;
            case 3:
				int length;
				length = GetLength(S);
				if(length < 0)
					printf("GetLength ERROR\n");
				else
					printf("The length of the stack is : %d\n",length);
                getchar();
                getchar();
                break;
            case 4:
				ElemType elem1;
				printf("Please input the index :\n");
				int index1;
				scanf("%d",&index1);
				if(GetElem(S,index1,elem1) == OK)
					printf("The elem at %d is %d\n",index1,elem1);
				else
					printf("GetElem ERROR\n");
                getchar();
                getchar();
                break;
            case 5:
				ElemType origin1;
				ElemType target1;
				printf("Please input the origin elem:\n");
				scanf("%d",&origin1);
				if(PriorElem(S,origin1,target1) == OK)
					printf("The prior of %d is %d\n",origin1,target1);
				else
					printf("Get Prior ERROR\n");
                getchar();
                getchar();
                break;
            case 6:
				ElemType origin2;
				ElemType target2;
				printf("Please input the origin elem:\n");
				scanf("%d",&origin2);
				if(NextElem(S,origin2,target2) == OK)
					printf("The prior of %d is %d\n",origin2,target2);
				else
					printf("Get Prior ERROR\n");
                getchar();
                getchar();
                break;
            case 7:
				ElemType elem2;
				printf("Please input the origin elem: \n");
				scanf("%d",&elem2);
				if(Push(S,elem2) == OK)
					printf("Insert Elem OK\n");
				else
					printf("Insert ERROR\n");
                getchar();
                getchar();
                break;
            case 8:
				ElemType elem3;
				if(Pop(S,elem3) == OK)
					printf("Delete Elem OK ! The elem is :%d\n",elem3);
				else
					printf("Delete ERROR\n");
                getchar();
                getchar();
                break;
            case 9:
				ElemType elem4;
				printf("Please input the origin elem: \n");
				scanf("%d",&elem4);
				int index2;
				index2 = LocateElem(S,elem4);
				if(index2 <= 0)
					printf("There is no %d\n",elem4);
				else
					printf("The index of %d is %d\n",elem4,index2);
                getchar();
                getchar();
                break;
            case 10:
				PrintAll(S);
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
state InitStack(SqStack& S)
{
	if(S.data != NULL)
	{
		printf("The Stack has initialized!\n");
		return ERROR;
	}
	S.data = (ElemType*)malloc(sizeof(ElemType)*MAX_SIZE);
	if(S.data == NULL)
		return ERROR;
	S.size = 0;
	S.top = -1;
	return OK;
}

// 栈销毁
state DestroyStack(SqStack& S)
{
	if(S.data == NULL)
		return ERROR;
	free(S.data);
	S.size = 0;
	S.top = 0;
	return OK;
}

// 压栈
state Push(SqStack& S,ElemType elem)
{
	if(S.data == NULL || S.size < 0)
		return ERROR;
	if(S.top >= S.size-1)
	{
		S.data = (ElemType*)realloc(S.data,(MAX_SIZE+INCREAMENT_SIZE)*sizeof(ElemType));
		if(S.data == NULL)
			return ERROR;
	}
	S.top++;
	S.data[S.top] = elem;
	S.size++;
	return OK;
}

// 出栈
state Pop(SqStack& S,ElemType& elem)
{
	if(S.data == NULL || S.size <= 0)
		return ERROR;
	elem = S.data[S.top];
	S.top--;
	S.size--;
	return OK;
}

// 获得从栈顶开始第i个位置的数据
state GetElem(SqStack S,int index,ElemType& elem)
{
	if(S.data == NULL || S.size <= 0 || index <= 0 || index > S.size)
		return ERROR;
	elem = S.data[S.size-index];
	return OK;
}

// 返回指定元素的索引(即从栈顶开始第几个)
int LocateElem(SqStack S,ElemType elem)
{
	if(S.data == NULL || S.size <= 0)
		return ERROR;
	int index = S.top;
	while(index >= 0&&Compare(S.data[index],elem) != 0)
	{
		index--;
	}
	if(index < 0)
		return ERROR;
	return index+1;
}

// 返回元素前驱
state PriorElem(SqStack S,ElemType origin,ElemType& target)
{
	if(S.data == NULL || S.size <= 0)
		return ERROR;
	int index = LocateElem(S,origin);
	if(index < 0 || index >= S.top+1)
		return ERROR;
	target = S.data[index];
	return OK;
}

// 返回元素后继
state NextElem(SqStack S,ElemType origin,ElemType& target)
{
	if(S.data == NULL || S.size <= 0)
		return ERROR;
	int index = LocateElem(S,origin);
	if(index <= 1)
		return ERROR;
	target = S.data[index-2];
	return OK;
}

// 返回栈长度
int GetLength(SqStack S)
{
	return S.size;
}

// 打印所有元素
void PrintAll(SqStack S)
{
	if(S.data == NULL || S.size <= 0)
		return;
	for(int i=S.top;i>=0;i--)
		printf("%d\t",S.data[i]);
	printf("\n");
}

// 元素大小比较
int Compare(ElemType origin, ElemType target)
{
	return origin - target;
}












