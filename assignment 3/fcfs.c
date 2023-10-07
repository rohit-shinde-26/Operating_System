#include<stdio.h>
#include<string.h>
struct process
{
char pname[10];
int AT,BT,ST,FT,TT,WT;
}p[15];
struct process t;
int i,n,j,k,bt;
char GC[50];
void get_data()
{
printf("enter number of process");
scanf("%d",&n);
printf("enter process details for %d processes",n);
for(i=0;i<n;i++)
{
printf("\n enter process name,arival time,cpu burst time");
scanf("%s %d %d",&p[i].pname,&p[i].AT,&p[i].BT);
}
}
void put_data()
{
printf("\n process are  as below");
printf("\nprocess name\t arival time\tcpu burst time\tfinish time\tstart time");
for(i=0;i<n;i++)
{
printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].FT,p[i].ST);
}
}
void arrivalsort()
{
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(p[i].AT>p[j].AT)
{
t=p[i];
p[i]=p[j];
p[j]=t;
}
}
}
}
void burstsort()
{
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{if(p[i].BT>p[j].BT)
{
t=p[i];
p[i]=p[j];
p[j]=t;
}
}
}
}
void avgTTWT()
{
int sumtt=0,sumwt=0;
for(i=0;i<n;i++)
{
p[i].TT=p[i].FT-p[i].AT;
p[i].WT=p[i].ST-p[i].AT;
sumtt=sumtt+p[i].TT;
sumwt=sumwt+p[i].WT;
}
printf("n process\tAT\tBT\tTT\tWT\tST\tFT\n");
for(i=0;i<n;i++)
{
printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].TT,p[i].WT,p[i].ST,p[i].FT);
}
printf("\n Average turn around time:%d/%d",sumtt,n);
printf("\nAverage wait time:%d/%d\n",sumwt,n);
}
void fcfs()
{
char str[5];
int time=0;
strcat(GC,"0");
for(i=0;i<n;i++)
{
strcat(GC,"|");
if(p[i].AT>time)
{
strcat(GC,"CPUIDLE");
time=p[i].AT;
sprintf(str,"%d",time);
strcat(GC,str);
strcat(GC,"|");
}
p[i].ST=time;
strcat(GC,p[i].pname);
bt=p[i].BT;
k=0;
while(bt!=0)
{
strcat(GC," ");
bt--;
k++;
}
time=time+k;
p[i].FT=time;
sprintf(str,"%d",time);
strcat(GC,str);
}
printf("\nGantt chart\n");
puts(GC);
avgTTWT();
}
int main()
{
get_data();
put_data();
arrivalsort();
printf("\n processes after sorting on arrival time\n");
put_data();
fcfs();
}

