#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
#define State int 
#define ERROR 0
#define OK 1
#define TreeNode int
#define ElemType int

/******************************************************************
 * 二叉树
 * 采用顺序存储结构
 * 顺序存储时,父节点序号为i,左子节点序号为i*2,右边子节点序号为i*2+1
 * (当节点序号从1开始时)
 ******************************************************************/

// 函数声明
TreeNode* Init();
State Destroy(TreeNode* T);
void PrintAll(TreeNode* T);
int GetElemDeepth(const TreeNode* T, ElemType elem);
int GetElemDgree(const TreeNode* T, ElemType elem);
int GetTreeDeepth(const TreeNode* T);
State InsertElem(TreeNode* T, ElemType elem);
State DeleteElem(TreeNode* T, ElemType &elem); // 二叉树的删除节点操作,只能删除最后一个节点
ElemType* GetLeafNode(const TreeNode* T);
ElemType* GetNonLeafNode(const TreeNode* T);

int main()
{
    int option;
    while(1)
    {
        system("clear");
        printf("Welcome to use !\n");
        printf("1. Init                         2. Destroy\n");
        printf("3. PrintAll                     4. GetElemDeepth\n");
        printf("5. GetElemDgree                 6. GetTreeDeepth\n");
        printf("7. InsertElem                   8. DeleteElem\n");
        printf("9. GetLeafNode                  10. GetNonLeafNode\n");
        printf("0. Exit\n");
        
        printf("Please input the option:\n ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                getchar();
                getchar();
                break;
            case 2:
                getchar();
                getchar();
                break;
            case 3:
                getchar();
                getchar();
                break;
            case 4:
                getchar();
                getchar();
                break;
            case 5:
                getchar();
                getchar();
                break;
            case 6:
                getchar();
                getchar();
                break;
            case 7:
                getchar();
                getchar();
                break;
            case 8:
                getchar();
                getchar();
                break;
            case 9:
                getchar();
                getchar();
                break;
            case 10:
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
}
