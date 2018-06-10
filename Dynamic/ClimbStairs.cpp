#include<stdio.h>
#include<stdlib.h>

int ClimbStairs(int n);
int ClimbStairsImp(int n);

/**************************************************
 * 1. 问题描述:
 * 爬楼梯问题;假设有n级台阶,每次只能爬一级或者两级,
 * 问爬到第n层一共有多少种方法
 * 2. 解法:
 * 该问题实际上是一个Fibonacci问题;假设爬到第i级有
 * F(i)种方法,那么应该有F(i) = F(i-1)+F(i-2);(因为
 * 每次只能爬一级或者两级)
 *************************************************/
int main()
{
    int n = 12;
    int result = ClimbStairs(n);
    int resultImp = ClimbStairsImp(n);
    printf("Climbing To %d Stairs has %d methods\n",n,result);
    printf("Climbing To %d Stairs has %d methods\n",n,resultImp);
    return 0;
}

// 递归求解
int ClimbStairs(int n)
{
    if(n < 0)
        return 0;
    if(n == 1 || n == 0)
        return 1;
    return ClimbStairs(n-1) + ClimbStairs(n-2);
}

// 迭代求解
int ClimbStairsImp(int n)
{
    int prev = 0;
    int cur = 1;
    for(int i=1; i<=n; i++)
    {
        int tmp = cur;
        cur += prev;
        prev = tmp;
    }
    return cur;
}
