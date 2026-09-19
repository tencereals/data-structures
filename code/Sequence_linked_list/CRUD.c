#include "Sequencelist.h"
//3.2.2初始化顺序表
void SqListInit(SqList* ps)
{
    assert(ps != NULL);
    //int * 
    ps->arr =(SqDataType*)malloc(sizeof(SqDataType)*4);
    //检查是否失败
    if(ps->arr == NULL)
    {
        //申请应退出
        printf("InitSqlist:初始化申请内存空间失效\n");
        //exit(-1)
        return ;
    }
    ps->size = 0;
    ps->capacity = 4;
}

//3.2.3销毁顺序表
void SqListDestroy(SqList* ps)
{
    free(ps->arr);
    ps->arr = NULL;
    ps->capacity = ps->size = 0;
}

//3.2.4 返回顺序表中第i个下标位置元素的值
SqDataType GetElem(SqList* ps, int i)
{
    assert(ps);
    assert(i < ps->size);


    return ps->arr[i];
    //位序的话应该使用i-1
    //Why arr从零开始？表示地址的偏移量

}
//3.2.5返回第⼀个等于x的数据元素的下标，若不存在返回-1
int LocateElem(SqList* ps, SqDataType x)
{
     assert(ps);

     for(int i=0;i < ps->size ; i++)
     {
        if(ps->arr[i] == x)   //可以进行蛇头碰撞辅助操作
        {
             return i;
        }
     }
     return -1;
}
//3.2.6 在顺序表的第i个位置插⼊元素x
void SqListInsert(SqList* ps, int i, SqDataType x)
{
    assert(ps);
    assert(i <= ps->size);// = 是保证可以进行尾插
    //扩容->1.原地扩容:检测后面空间是否分配给别人，因此返回给你  2.异地扩容；后面空间已经分配给了别人，因此另开辟一段空间copy到新空间
    //使用realloc扩容realloc(void* ptr,size_t size) ptr旧空间的指针，size是新空间的字节数
    if(ps->size == ps->capacity)
    {
        SqDataType* tmp =(SqDataType*)realloc(ps->arr,sizeof(SqDataType)* ps->capacity*2);
        if(tmp == NULL)
        {
            printf("SqListInsert:内存申请空间失败！\n");
            return;
        }
        ps->arr = tmp;
        ps->capacity*=2;
    }
    //挪动数据
    int j = ps->size -1;
    while(j >= i)
    {
        ps->arr[j+1]=ps->arr[j];
        --j;
    }
    ps->arr[i] = x;
    ps->size ++;


}
//3.2.7 删除顺序表中第i个元素，并返回删除的值
SqDataType SqListDelete(SqList* ps, int i)
{
    assert(ps);
    assert(i < ps->size);
    int j = ps->size -1;
    int tmp = ps->arr[i];
    while(j >= i)
    {
        ps->arr[i]=ps->arr[i+1];
        i++;
    }
    ps->size --;
    return tmp;
} 
//3.2.8 打印顺序表中的元素。               
void SqListPrint(SqList* ps)
{
   assert(ps);
   for(int i=0;i<ps->size;i++)
   {
    printf("%d ",ps->arr[i]);
   }
   printf("\n");
}
// 检测顺序表是否为空，空返回true，否则返回false
bool EmptySqList(SqList* ps)
{
    assert(ps);
    return ps->size == 0;
}
// 获取顺序表中有效元素个数
int SqListSize(SqList* ps)
{
    assert(ps);
    return ps->size;
}
// 以下接⼝复⽤上⾯的Insert和Delete即可完成
// 头插尾插
// 尾插
void SqListPushBack(SqList* ps, SqDataType x)
{
  assert(ps);
  SqListInsert(ps,ps->size,x);
}
void SqListPushFront(SqList* ps, SqDataType x)
{
  assert(ps);
  SqListInsert(ps,0,x);
}
// 头删尾删
void SqListPopBack(SqList* ps)
{
    assert(ps);
    SqListDelete(ps,ps->size);
}
void SqListPopFront(SqList* ps)
{
    assert(ps);
    SqListDelete(ps,0);
}