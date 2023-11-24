
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
char com[80],ch,pos[10],s1[20],s2[20],s3[20],s4[20];
void count();
void typeline();
void list();
DIR *d1;
struct dirent *dirp;

void main()
{
int i,flag=0,j,ff=0;
do
{
printf("\n myshell$");
for(i=0;i<20;i++)
s1[i]=s2[i]=s3[i]=s4[i]='\0';
ch=fgetc(stdin);
for(i=0;ch!='\n';i++)
{
com[i]=ch;
ch=fgetc(stdin);
}
com[i]='\0';
sscanf(com,"%s%s%s%s",s1,s2,s3,s4);
if(strcmp(s1,"count")==0)
count();
if(strcmp(s1,"typeline")==0)
typeline();
if(strcmp(s1,"list")==0)
list();
if(strcmp(s1,"exit")==0)
flag=1;
}while(flag==0);
}


void count()
{
int cnt=0,wcnt=0,lcnt=0;
char a;
FILE *fp;
fp=fopen(s3,"r");
if(fp==NULL)
{
printf("\n File not found....");
exit(0);
}
else
{
while(fscanf(fp,"%c",&a)!=EOF)
{
cnt++;
if(a==' ')
wcnt++;
if(a=='\n')
{
lcnt++;
wcnt++;
 }
}
fclose(fp);
if(s2[0]=='c')
printf("\n Number of characters= %d",cnt-lcnt);

if(s2[0]=='w')
printf("\n Number of words=  %d",wcnt);

if(s2[0]=='l')
printf("\n Number of lines= %d",lcnt);
}
}


void typeline()
{
int cnt=0,wcnt=0,lcnt=0,a2,ans=0,m2=1,i,l1=0,p,p1;
char a;
FILE *fp;
if(s2[0]!='a')
{
fp=fopen(s3,"r");
if(fp==NULL)
{
printf("\nFile not found....");
exit(0);
}
else
{
while(fscanf(fp,"%c",&a)!=EOF)
{
if(a=='\n')
lcnt++;
}
fclose(fp);
i=1;
while(s2[i]!='\0')
{
a2=s2[i]-48;
ans=ans*m2+a2;
m2=m2*10;
i++;
}
fp=fopen(s3,"r");
if(s2[0]=='+')
{
while(fscanf(fp,"%c",&a)!=EOF)
{
if(a!='\n')
printf("%c",a);
if(a=='\n')
{
printf("\n");
l1;
}
if(l1==ans)
break;
}
}
if(s2[0]=='-')
{
p=lcnt-ans-1;
while(fscanf(fp,"%c",&a)!=EOF)
{
if(a=='\n')
l1++;
if(l1>p)
printf("%c",a);
}
}
fclose(fp);
}
}
if(s2[0]=='a')
{
 fp=fopen(s3,"r");
if(fp==NULL)
{
printf("\n File not found..");
exit(0);
}
else
{
while(fscanf(fp,"%c",&a)!=EOF)
printf("%c",a);
}
}
}


void list()
{
int c=0;
d1=opendir(s3);
while((dirp=readdir(d1))!=NULL)
{
c++;
if(s2[0]=='f')
puts(dirp->d_name);
if(s2[0]=='i')
printf("\n Inode no of %s :: %ld",dirp->d_name,dirp->d_ino);
}
if(s2[0]=='n')
printf("\n Total no of files :: %d",c);
} 


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 100

void execute_command(char *tokens[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execvp(tokens[0], tokens);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}

void list_files(char *dirname) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;

    while (1) {
        printf("myshell$ ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command
        int token_count = 0;
        token = strtok(command, " ");

        while (token != NULL) {
            tokens[token_count++] = token;
            token = strtok(NULL, " ");
        }

        // Check if the 'list' command is used
        if (token_count >= 3 && strcmp(tokens[0], "list") == 0 && strcmp(tokens[1], "f") == 0) {
            // 'list f dirname'
            list_files(tokens[2]);
        } else {
            // Execute the command
            tokens[token_count] = NULL; // Null-terminate the array
            execute_command(tokens);
        }
    }

    return 0;
}
*/
