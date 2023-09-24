#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
int n,i;
printf("enter the no.of array\n");
scanf("%d",&n);
int a[n];
printf("enter the array element\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
void ascending(int *a,int n);
void descending(int *a,int n);
pid_t pid;
pid=fork();
if(pid<0)
{
printf("fork() error\n");
exit(-1);
}
else if(pid==0)
{
printf("\n child process\n");
descending(a,n);
printf("\n array element in descending order\n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
printf("\n");
exit(0);
}
else
{
int status;
wait(NULL);
printf("\n parent process\n");
if(WIFEXITED(status))
{
printf("\nchild process exit\n");
}
ascending(a,n);
printf("\n array element in sort\n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
printf("\n");
exit(0);
}
}
void ascending(int *a,int n)
{
int i,j,temp;
for(i=0;i<n;i++)
{
for(j=0;j<n-1-i;j++)
{
if(a[j+1]<a[j])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}
void descending(int *a,int n)
{
int i,j,temp;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[j+1]>a[j])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}





























































































































































































































































































































































































































































































































































































































































































