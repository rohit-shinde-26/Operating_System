#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
int pid=fork();
if(pid>0)
{
printf("parent process:");
printf("id:%d\n\n",getpid());
}
else if(pid==0)
{
printf("child process:");
printf("id:%d\n",getpid());
printf("parent id:%d\n\n",getppid());
sleep(5);
printf("child process:");
printf("id:%d\n",getpid());
printf("parent id:%d\n\n",getppid());
}
else
{
printf("failed to create child process");
}
return 0;
}
