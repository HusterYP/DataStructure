* 断言
> 1. 可以在程序中使用assertion, 帮助debug, 同是在发布产品的时候, 可以通过选择禁用或者启动assertion检查(enable: `java -ea MyProgram`)(disable: `java -da MyProgram`)
## 归并排序
* 基本思想: 对于两个已经有序的部分, 比较合并; 用在一个无序的数组中, 即递归细分
* 不要将辅助数组放在递归函数中创建, 因为那会多出很多小数组, 会造成运行比较慢
* 复杂度: O(nlogn)
* 改进: 当切分到比较小的时候,可以使用插入排序(快大约20%)
* 改进: 当归并时, 当前半部分的最大值小于后半部分的最小值的时候, 可以不进行归并
* 改进: 交替使用原数组和辅助数组, 使得递归函数同时也完成了数据的拷贝
* Comparable和Comparator区别: https://blog.csdn.net/u011240877/article/details/53399019
* 凸包算法: Graham-Scan算法
* 使用归并排序实现洗牌算法, 即merge时, 随机选择应该选择哪一个

## 快排
* 快排比归并更快
* 不稳定
* 参见<<算法4>>, 其中所说的随机切分是什么意思?课程中说的性能依赖与随机切分是什么意思?
* 改进
> 1. 对小数组或者基本有序的时候进行插入排序
* 给定一组数据, 找到第K个最大值
> 1. 利用快排的思想, 假设N个数存储在数组S中，从数组中随机找一个元素X，将数组分成两部分Sa和Sb.Sa中的元素大于等于X,Sb中的元素小于X
> 2. 若Sa组的个数大于或等于K，则继续在sa分组中找取最大的K个数字
> 3. 若Sa组中的数字小于K ，其个数为T，则继续在sb中找取 K-T个数字
> 4. 时间复杂度为NlogK (或者说线性的)
* 荷兰国旗问题: 将乱序的红蓝白三色小球排成有序的红蓝白三色的同颜色在一起的小球
> 1. 解决: https://selfboot.cn/2016/09/01/lost_partition/
> 2. 实际上是参照快排思想, 用三个指针 
* Arrays.sort()在排序引用类型的时候, 使用MergeSort而不是QuickSort, 是因为其稳定性和对NlogN的时间复杂度的保障
> 1. 对原始数据类型使用快排
> 2. 对引用数据类型使用归并


## 稳定性
* 插入排序和归并排序是稳定的, 但是选择排序和希尔排序不是稳定的
