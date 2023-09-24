#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_TOKENS 10
#define MAX_TOKEN_LENGTH 20
void execute_command(char*command)
{
char*args[MAX_TOKENS];
int arg_count=0;
args[arg_count]=strtok(command,"\n");
while(args[arg_count]!=NULL)
{
arg_count++;
args[arg_count]=strtok(NULL,"\n");
args[arg_count]=NULL;
pid_t pid=fork();
if(pid==0)
{
execvp(args[0],args);
perror("command execution failed");
exit(1);
}else if(pid>0){
wait(NULL);
}
else{
perror("fork failed");
}
}
void typeline_command(char *command)
{
char*tokens[MAX_TOKENS];
int token_count=0;
tokens[token_count]=strtok(command,"\n");
while(tokens[token_count]!=NULL)
{
token_count++;
tokens[token_count]=strtok(NULL,"\n");
}
if(token_count<3)
{
printf("invalid typeline command\n");
return;
}
int n=atoi(tokens[1]);
char *filename=tokens[2];
FILE *file=fopen(filename,"r");
if(file==NULL){
perror("file open failed");
return;
}
char line[256];
int line_count=0;
if(strcmp(tokens[0],"typeline")==0){
while(read(line,sizeof(line),file)!=NULL&&line_count<n)
{
printf("%s",line);
line_count++;
}
}
else if(strcmp(tokens[0],"typeline")==0&&tokens[1][0]=='-')
{
fseek(file,0,SEEK_END);
long file_size=ftell(file);
long offset=0;
int lines_read=0;
int back_lines=atoi(tokens[1]+1);
while(offset<file_size&&lines_read<back_lines)
{
offset++;
fseek(file,-offset,SEEK_END);
if(fgetc(file)=='\n')
{
lines_read++;
}
}
while(read(line,sizeof(line),file)!=NULL)
{
printf("%s",line);
}
}
else{
while(read(line,sizeof(line),file)!=NULL)
{
printf("%s",line);
}
}
fclose(file);
}
int main(){
char command[MAX_COMMAND_LENGTH];
while(1){
printf("myshell$");
fgets(command,sizeof(command),stdin);
if(strncmp(command,"typeline",8)==0)
{
typeline_command(command+8);
}
else{
execute_command(command);
}
}
return 0;
}
}

