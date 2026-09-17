#include<stdio.h>
void insert_linklist (int capacity,int *length,int insert_number,int insert_location,int * arr)
{
    int* a=arr;
    if((*length)<capacity)
    {
      for(int i=0;i<(*length)-insert_location;i++)
      {
        *(a+(*length)-i)=*(a+(*length)-i-1);
      }
      (*length)++;
      a[insert_location]=insert_number;
    }
    else
    printf("No space to insert in\n");

}
int main()
{
    int a[6] = {1,2,3,4};
    int capacity = sizeof(a)/sizeof(a[0]);
    int length= 4;
    insert_linklist(capacity,&length,9,1,a);
    printf("%d %d\n",a[1],length);
 
    return 0;

}