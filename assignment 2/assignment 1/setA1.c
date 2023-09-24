#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void ChildProcess();
void ParentProcess();
int main()
{
pid_t pid;
pid=fork();
if(pid==0)
{
ChildProcess();
}
else
{
ParentProcess();
return 0;
}
}
void ChildProcess()
{
printf("child process id-%d",getpid());
printf("\n i am child process\n");
}
void ParentProcess()
{
printf("parent process id-%d",getpid());
printf("\n i am parent process\n");
}

