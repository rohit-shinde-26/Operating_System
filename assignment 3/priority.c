#include<stdio.h>
#include<string.h>

struct process
{
      char pname[10];
      int AT,BT,ST,FT,TT,WT,BT1,PR;
}p[15];

struct process t;
//         struct process t;
         int i,n,j,k,bt,tq,time;
         char GC[150];

         void get_data()
         {
         printf("enter number of process:");
         scanf("%d",&n);
         printf("enter process details for %d process:",n);
         for(i=0;i<n;i++)
         {
            printf("enter process name,arrival time,burst time,priority:");
            scanf("%s %d %d %d",&p[i].pname,&p[i].AT,&p[i].BT,&p[i].PR);
            p[i].BT1=p[i].BT;
            }
         }
void put_data()
      {
         printf("\n\nprocess are as below:\n");
         printf("\n\nprocess name\tarival time\tcpu burst time\tprority");
         for(i=0;i<n;i++)
         {
         printf("\n\t%s\t\t%d\t\t%d\t\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].PR);
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
void avgTTWT()
{
float sumtt=0,sumwt=0;
for(i=0;i<n;i++)
{
p[i].TT=p[i].FT-p[i].AT;
p[i].WT=p[i].ST-p[i].BT1;
sumtt=sumtt+p[i].TT;
sumwt=sumwt+p[i].WT;
}
printf("n process\tAT\tBT\tTT\tWT\tST\tFT\n");
for(i=0;i<n;i++)
{
printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pname,p[i].AT,p[i].BT1,p[i].TT,p[i].WT,p[i].ST,p[i].FT);
}
printf("\n Average turn around time:%0.2f/%d=%0.2f",sumtt,n,sumtt/n);
printf("\nAverage wait time:%0.2f/%d=%0.2f\n",sumwt,n,sumwt/n);
}
void priority_sort()
{
 for(i=0;i<n;i++)
            {
               for(j=i+1;j<n;j++)
                  {
                  if(p[i].PR>p[j].PR)
                     {
                     t=p[i];
                     p[i]=p[j];
                     p[j]=t;
               }
}
}
}
void pr()
{
char str[5];
i=0;
int time=0;
tq=1;
strcpy(GC,"0|");
aaa:
if(p[i].BT !=0)
{
if(p[i].AT>time)
{
for(j=i+1;j<n;j++)
{
if(p[i].AT>p[j].AT&&p[j].BT!=0)
{
time=p[i].AT;
sprintf(str,"%d",time);
strcat(GC,str);
strcat(GC,"|");
p[j].ST=time;
strcat(GC,p[j].pname);
p[j].BT=p[j].BT-tq;
strcat(GC," ");
time=time+tq;
sprintf(str,"%d",time);
strcat(GC,str);
p[j].FT=time;
}
}
}
p[i].ST=time;
strcat(GC,p[i].pname);
time=time+tq;
strcat(GC," ");
p[i].FT=time;
sprintf(str,"%d",time);
strcat(GC,str);
strcat(GC,"|");
p[i].BT=p[i].BT-tq;
priority_sort();
}
for(i=0;i<n;i++)
{
if(p[i].BT!=0)
goto aaa;
}
printf("\n\n\t\tGantt chart\n\n");
puts(GC);
avgTTWT();
}
int main()
{
get_data();
put_data();
arrivalsort();
put_data();
pr();
}


