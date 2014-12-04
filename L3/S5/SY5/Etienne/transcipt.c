#define _POSIX_C_SOURCE 1
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    char buf[1024];
    int pipeIn[2];
    int rc;
    int logTxt;
    pid_t p;
    logTxt = open("log.txt",O_WRONLY | O_CREAT | O_TRUNC,0600);
    pipe(pipeIn);
    p = fork();
    if(p == 0){
      pid_t p2;
      int pipe2[2];
      pipe(pipe2);
      p2 = fork();
      if(p2 == 0){
        dup2(pipeIn[0], 0);
        dup2(pipe2[1], 1);
        close(pipeIn[0]);
        close(pipe2[1]);
        argv[0] = "cat";
        argv[1] = NULL;
        execvp("cat",argv);
      }
      else{
        char * c = "> ";
        while((rc = read(pipe2[0], buf, 1024))!=-1) {
          write(1,buf,rc);
          write(logTxt,c,2);
          write(logTxt,buf,rc);
        }
      }

    }
    else{
      char * c = "< ";
      while((rc = read(0, buf, 1024))!=-1) {
        write(pipeIn[1],buf,rc);
        write(logTxt,c,2);
        write(logTxt,buf,rc);
      }
  }

    //close(pipeDes[0]);

}
