#include<stdio.h>
int main()
{
    int a[6] = {1,2,3,4};
    int capacity = sizeof(a)/sizeof(a[0]);
    int length= 4;
    if(length < capacity)
    printf("There is some free space\n");
    else
    printf("There is no free space");
    return 0;

}