#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void swap(int *xp,int *yp)
{
int temp=*xp;
*xp=*yp;
*yp=temp;
}
void bubblesort(int arr[],int n)
{
int i,j;
for(i=0;i<=n-1;i++)
{
for(j=0;j<=n-i-1;j++)
{
if(arr[j]>arr[j+1])
swap(&arr[j],&arr[j+1]);
}
}
}
void display(int arr[],int size)
{
int i;
for(i=0;i<size;i++)
printf("%d",arr[i]);
printf("\n");
}
void insertionsort(int arr[],int n)
{
int i,key,j;
for(i=0;i<=n;i++)
{
key=arr[i];
j=i-1;
while(j>=0&& arr[j]>key)
{
arr[j+1]=arr[j];
j=j-1;
}
arr[j+1]=key;
}
}
int main()
{
int pid,child_pid;
int size=10,i,status;
int arr[size];
int pArr[size];
int cArr[size];
printf("enter number of integer to the sort:\t");
scanf("%d",&size);
for(i=0;i<size;i++)
{
printf("enter number %d:",(i+1));
scanf("%d",&arr[i]);
pArr[i]=arr[i];
cArr[i]=arr[i];
}
printf("\tyour enter integers for sorting\n");
display(arr,size);
printf("\n parent proces id is:d\n",getpid());
printf("\n[forking child process..]");
child_pid=fork();
if(child_pid<0)
{
printf("child process creation faild\n");
exit(-1);
}
else if(child_pid=0)
{
printf("\n the child process\n");
printf("\n child process id is%d\n",getpid());
printf("\nchild is sorting the list of integers by insertion sort:\n");
insertionsort(cArr,size);
printf("\t the sorted list by child:\n");
display(cArr,size);
printf("\nchild process complited\n");
sleep(7);
printf("\nparent of child process is %d",getpid());
}
else
{
printf("\nchild process id is%d\n",getpid());
sleep(7);
printf("\nthe parent process\n");
printf("\n parent %d is sorting the list of interger ny bubble sort\n",getpid());
bubblesort(pArr,size);
display(pArr,size);
printf("\n parent process completed  \n");
}
return 0;
}




