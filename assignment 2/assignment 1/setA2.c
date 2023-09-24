#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
pid_t pid;
int retnice;
printf("press DEL to stop the process:\n");
pid=fork();
for(;;){
if(pid==0){
retnice=nice(-5);
printf("child get higher cpu priority %d\n",retnice);
sleep(1);
}
else{
retnice=nice(4);
printf("parent get lower cpu priority %d\n",retnice);
sleep(1);
}
exit (0);
}
}
