#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t pid=fork();
if(pid<0)
{
fprintf(stderr,"fork failed\n");
}
else if(pid==0)
{
printf("i am child process,my id is %d\n",getpid());
}
else
{
printf("i am parent process,my id is %d\n",getpid());
}
return 0;
}



























