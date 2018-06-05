#include<stdio.h>
#include<stdlib.h>

#define state int
#define ElemType int 
#define ERROR -1
#define OK 1
#define MAX_SIZE 6

/***********************************************
 *队列,采用静态数组实现,需要注意的是假溢出的解决,
 *此处采用最后一个位置不使用来解决
************************************************/
typedef struct Queue
{
    ElemType elem[MAX_SIZE];
    int front,rear;
}Queue;

// 函数声明
state InitQueue(Queue& Q);
state ClearQueue(Queue& Q);
state QueueEmpty(Queue Q);
int QueueLength(Queue Q);
state GetHead(Queue Q,ElemType& elem);
state EnQueue(Queue& Q,ElemType elem);
state DeQueue(Queue& Q,ElemType& elem);
void PrintAll(Queue Q);

int main()
{
    Queue Q;
    int option;
    while(1)
    {
        system("clear");
        printf("Welcome to use !\n");
        printf("1. Init                 2. Clear\n");
        printf("3. QueueEmpty           4. QueueLength\n");
        printf("5. GetHead              6. EnQueue\n");
        printf("7. DeQueue              8. PrintAll\n");
        printf("0. Exit\n");

        printf("Please input the option:\n ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                if(InitQueue(Q) == OK)
                    printf("Init Succeed !\n");
                else
                    printf("Init ERROR\n");
                getchar();
                getchar();
                break;
            case 2:
                if(ClearQueue(Q) == OK)
                    printf("Clear Succeed !\n");
                else
                    printf("Clear ERROR !\n");
                getchar();
                getchar();
                break;
            case 3:
                if(QueueEmpty(Q) == OK)
                    printf("The Queue is Empty\n");
                else
                    printf("The Queue is not Empty\n");
                getchar();
                getchar();
                break;
            case 4:
                int length;
                length = QueueLength(Q);
                printf("The length of the Queue is : %d\n",length);
                getchar();
                getchar();
                break;
            case 5:
                ElemType elem1;
                if(GetHead(Q,elem1) == OK)
                    printf("The head elem is : %d\n",elem1);
                else
                    printf("There is no head elem! \n");
                getchar();
                getchar();
                break;
            case 6:
                ElemType elem2;
                printf("Please input the elem :\n");
                scanf("%d",&elem2);
                if(EnQueue(Q,elem2) == OK)
                    printf("EnQueue Succeed\n");
                else 
                    printf("EnQueue ERROR\n");
                getchar();
                getchar();
                break;
            case 7:
                ElemType  elem3;
                if(DeQueue(Q,elem3))
                    printf("The DeQueue elem is : %d\n",elem3);
                else 
                    printf("DeQueue ERROR\n");
                getchar();
                getchar();
                break;
            case 8:
                PrintAll(Q);
                getchar();
                getchar();
                break;
            case 0:
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
state InitQueue(Queue& Q)
{
    Q.front = Q.rear = 0;   
    return OK;
}

// 清空队列
state ClearQueue(Queue& Q)
{
    Q.front = Q.rear = 0;
    return OK;
}

// 队列是否为空
state QueueEmpty(Queue Q)
{
    return Q.front == Q.rear ? OK : ERROR;
}

// 返回队列长度
int QueueLength(Queue Q)
{
    return (MAX_SIZE + Q.rear - Q.front) % MAX_SIZE;
}

// 返回头结点
state GetHead(Queue Q,ElemType& elem)
{
    if(Q.front != Q.rear)
    {    
        elem = Q.elem[Q.front];
        return OK;
    }
    return ERROR;
}

// 入队
state EnQueue(Queue& Q,ElemType elem)
{
    if(Q.rear+1 != Q.front)
    {
        Q.elem[Q.rear] = elem;
        Q.rear = (Q.rear+1) % MAX_SIZE;
        return OK;
    }
    return ERROR;
}

// 出队
state DeQueue(Queue& Q,ElemType& elem)
{
    if(Q.front != Q.rear)
    {
        elem = Q.elem[Q.front];
        Q.front = (Q.front + 1) % MAX_SIZE;
        return OK;
    }
    return ERROR;
}

// 打印全部
void PrintAll(Queue Q)
{
    int index = Q.front;
    while(index != Q.rear)
    {
        printf("%d\t",Q.elem[index]);
        index = (index + 1) % MAX_SIZE;
    }
    printf("\n");
}
