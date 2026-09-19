/*
1.线性表的两种实现方式
顺序存储 OR 链式存储（指针）
linear list L={a1,a2...,an}
a1没有前驱an没有后继
eg. 贪吃蛇--{坐标，颜色}<-线性表的数据元素
本质：头部插入一个数据，尾部删除一个数据（头插尾删）->不吃
头插不尾删---->吃到食物
贪吃蛇使用链式存储，WHY？
顺序存储：静态数组，动态数组，只能挪动数组，头插不方便 O(n)
链表：任意位置申请空间，变成新的表头，再指向即可 O(1)
程序=数据结构(链表)+算法
2.C++引用补充
2.1 类型& 引用别名=引用变量
//test.cpp
int & b = a;
int & c = a;
int & d = b;
//b c d 都是a 的别名
printf("%p %p\n",&a,&b);//一样的
2.2引用的特性
//必须初始化引用
//int& ra XNO!X
引用一个实体，就不能再引用别的名字，但一个实体可以有多个别名
//test1.cpp
//rx 即是 x 的别名，ry 即是 y 的别名
void swap(int& rx,int& ry)
{
    int tmp = rx;
    rx = ry;
    ry = tmp;
}
int ....{
    ...;
    swap(x,y)
}
3.Sequence list（顺序表）
3.1静态顺序表和动态顺序表
静态顺序表就是固定大小的静态数组
优点实现简单，缺点是场景局限（只适用于知道自己存放多少数据的场景）

*/
// #include<stdio.h>
// typedef int SqDataType;
// #define Sq_MAX_SIZE 10
// // 静态顺序表结构定义
// typedef struct SequenceList{
// SqDataType arr[Sq_MAX_SIZE]; // 存储数据的静态数组
// int size; // 记录顺序表中已经存⼊的数据个数
// }SqList;
// // C语⾔中上述结构体类型为struct SequenceList，太⻓了，所以⼀般都会tyepdef定⼀个短的别名，如：SqList
// // 上述代码把结构体定义和typedef嵌套在⼀起，也可以单独定义typedef struct SequenceList SqList;
// // 有些地⽅简化⼀下，也可以直接定义匿名结构体，再typedef⼀个名称，如下：
// typedef struct{
// SqDataType arr[Sq_MAX_SIZE]; // 存储数据的静态数组
// int size; // 记录顺序表中已经存⼊的数据个数
// }SqList;


// // 动态顺序表结构定义
// typedef struct SequenceList{
// SqDataType* arr; // 存储数据的动态数组的指针
// int size; // 记录顺序表中已经存⼊的数据个数
// int capacity; // 动态数组的容量空间的⼤⼩
// }SqList;
// // C语⾔中上述结构体类型为struct SequenceList，太⻓了，所以⼀般都会tyepdef定⼀个短的别名，如：SqList
// // 上述代码把结构体定义和typedef嵌套在⼀起，也可以单独定义typedef structSequenceList SqList;
// // **有些地⽅简化⼀下，也可以直接定义匿名结构体，再typedef⼀个名称，如下：
// typedef struct{
// SqDataType* arr; // 存储数据的动态数组的指针
// int size; // 记录顺序表中已经存⼊的数据个数
// int capacity; // 动态数组的容量空间的⼤⼩
// }SqList;
// //-->Sequencelist.h
/*3.2.8 复杂度分析
插入的时间复杂度
a:best situation: i = n+1在表尾插入且无需扩容不需要移动元素，时间复杂度为O（n）
b:bad situation：i = 1 在表头插入需要将所有元素整体向后移动一步，执行n次，时间复杂度为O（n），并且需要进行扩容处理
c：average situation： p = 1/n+1； 故平均情况为n/2，整体时间复杂度为o（n）
同理删除中 best situation：i = n->O（1） bad situation : i = 1 -> O(n) average situation: (n-1)/2 



*/
