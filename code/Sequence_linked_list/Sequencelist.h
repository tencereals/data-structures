/*
3.2动态顺序表的实现
3.2.1 接口函数的定义
*/
#pragma once
// SqList.h ⼀般这些接⼝函数声明放到.h中
// 下⾯的接⼝函数的实现放到SqList.cpp中
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
//若要实现贪吃蛇
struct SnakeData
{
    int row;
    int col;
    //...
};
//typedef SnakeData SqDataType; // 数据元素类型
// typedef是为了⽅便类型替换
typedef int SqDataType; // 数据元素类型
typedef struct {
SqDataType* arr; // 存储数据的动态数组的指针
int size; // 记录顺序表中已经存⼊的数据个数
int capacity; // 动态数组的容量空间的⼤⼩
}SqList;
// 初始化顺序表
void SqListInit(SqList* ps);
// 有些书本上的⽤法
// void SqListInit(SqList& s);
// 销毁顺序表
void SqListDestroy(SqList* ps);
// 返回顺序表中第i个下标位置元素的值
SqDataType GetElem(SqList* ps, int i);
// 返回第⼀个等于x的数据元素的下标，若不存在返回-1
int LocateElem(SqList* ps, SqDataType x);
// 在顺序表的第i个位置插⼊元素x
void SqListInsert(SqList* ps, int i, SqDataType x);
// 删除顺序表中第i个元素，并返回删除的值
SqDataType SqListDelete(SqList* ps, int i);  //书本上给出的i通常是位序
// 打印顺序表中的元素。               //我们用的就是i下标
void SqListPrint(SqList* ps);
// 检测顺序表是否为空，空返回true，否则返回false
bool EmptySqList(SqList* ps);
// 获取顺序表中有效元素个数
int SqListSize(SqList* ps);
// 以下接⼝复⽤上⾯的Insert和Delete即可完成
// 头插尾插
void SqListPushBack(SqList* ps, SqDataType x);
void SqListPushFront(SqList* ps, SqDataType x);
// 头删尾删
void SqListPopBack(SqList* ps);
void SqListPopFront(SqList* ps);