#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <fstream>
int main()
{
int pid1, pid2, st;
printf("Double process \n");
pid1=fork();
if(pid1 == 0)
{
     sleep(3);
pid2 = fork();
pid2 = getpid();
if(pid2 == 0) 
 {
 sleep(5);
 printf("New_2, pid1=%d, pid2=%d \n", getppid(), getpid());

 }
else if (pid2 < 0) printf("Fork error\n");
 else
 {
 sleep(5);
 printf("New_1, parent=%d, pid1=%d \n", getppid(), getpid());

 }
}
else
{ printf("Old, parent=%d, pid1=%d, pid2=%d \n",getppid(),pid1,pid2);
sleep(5);
wait(&st);
if (pid1 < 0)
{
printf("Fork error");
return -1;
}
}
wait(&st);
return 0;
}