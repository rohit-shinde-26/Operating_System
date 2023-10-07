 
#include<stdio.h>
#include<string.h>
struct process
{
char pname[10];
int AT,BT,ST,FT,TT,WT;
}p[15];
struct process t;
int i,j,n,k,bt;
char GC[50];
void get_data()
{
printf("enter the number of processes");
scanf("%d",&n);
printf("enter process details for %d process",n);
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
printf("\n%s\t\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].TT,p[i].WT,p[i].ST,p[i].FT);
}
printf("\n Average turn around time:%d/%d",sumtt,n);
printf("\nAverage wait time:%d/%d\n",sumwt,n);
}


void sjf()
{
char str[5];
int t,time=0;
strcat(GC,"0|");
if(p[0].AT>time)
{
strcat(GC,"CPUIDLE");
time=p[0].AT;
t=p[0].AT;
sprintf(str,"%d",time);
strcat(GC,str);
strcat(GC,"|");
}
p[0].ST=time;
strcat(GC,p[0].pname);
bt=p[0].BT;
k=0;
while(bt!=0)
{
strcat(GC," ");
bt--;
k++;
}
time=time+k;
p[0].FT=time;
sprintf(str,"%d",time);
strcat(GC,str);
burstsort();
for(i=0;i<n;i++)
{
if(p[i].FT>0)
continue;
strcat(GC,"|");
if(p[i].AT>time)
{
strcat(GC,"CPUIDLE");
time=p[i].BT;
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

sjf();
}

/*output:-
enter the number of processes3
enter process details for 3 process
 enter process name,arival time,cpu burst timep1 0 2

 enter process name,arival time,cpu burst timep2 0 3

 enter process name,arival time,cpu burst timep3 0 4

 process are  as below
process name	 arival time	cpu burst time	finish time	start time
p1		            0		            2          		0  		0
p2		            0		            3		         0		   0
p3		            0		            4		         0		   0
 processes after sorting on arrival time

 process are  as below
process name	 arival time	cpu burst time	finish time	start time
p1	               	0		         2		      0		      0
p2		               0		         3		      0		      0
p3		               0		         4	  	      0		      0
Gantt chart
0|p1  2|p2   5|p3    9
n process	AT	BT	TT	WT	ST	FT

p1		      0	2	2	0	0	2
p2	        	0	3	5	2	2	5
p3	      	0	4	9	5	5	9
 Average turn around time:16/3
Average wait time:7/3
*/

