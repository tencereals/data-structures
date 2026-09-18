#include "Sequencelist.h"
// int main()
// {
//     SqList s;
//     SqListInit(&s);
//     //越界不一定报错，故我们assert两次
//     printf("%d\n",GetElem(&s,1));

//     //动态开辟空间——>在堆上，main结束时不会销毁栈帧
//     //静态数组程序结束会自动销毁，包括变量均在栈帧，只有malloc的动态数组会占据堆空间
//     SqListDestroy(&s);

// }
int main()
{
    SqList s1;
    SqListInit(&s1);
    SqListInsert(&s1,0,1);
    SqListInsert(&s1,1,2);
    SqListInsert(&s1,2,3);
    SqListInsert(&s1,0,100);
    SqListInsert(&s1,0,200);

    SqListPrint(&s1);
    SqListDestroy(&s1);
}