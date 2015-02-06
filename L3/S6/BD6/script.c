#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdarg.h>

void recupBase(int stdinP,int stdoutP){

}

int main(int argc, char *args[]) {
  int pipeDes[2];
  int pipeDes2[2];
  char * argv[3];
  pid_t p;
  if (pipe(pipeDes) == -1){
    //warn("Erreur avec pipe() md5 du fichier %s impossible\n",path);
    // Est qu'il fait ecrire du vide je crois pas.
    return 1;
  }
  if (pipe(pipeDes2) == -1){
    //warn("Erreur avec pipe() md5 du fichier %s impossible\n",path);
    // Est qu'il fait ecrire du vide je crois pas.
    return 1;
  }
  p = fork();
  if(p == -1){
    //warn("Erreur avec Fork() md5 du fichier %s impossible\n",path);
    return 1;
  }
  if(p == 0){
    //int des = open(args[2],O_WRONLY | O_CREAT | O_TRUNC,0600);
    close(pipeDes2[0]);
    close(pipeDes[1]);
    argv[0] = "psql";
    //argv[1] = "-q";
    argv[1] = "base";
    argv[2] = NULL;
    dup2(pipeDes2[1], 1);
    close(pipeDes2[1]);
    dup2(pipeDes[0], 0);
    close(pipeDes[0]);
    if(execvp("psql",argv) ==-1){
      exit(255);
    }
  }
  //wait(NULL);
  int rc;
  close(pipeDes[0]);
  close(pipeDes2[1]);
  char buf[1024];
  //write(pipeDes[1],args[1],strlen(args[1]));
  write(pipeDes[1],"\\i ",strlen("\\i "));
  write(pipeDes[1],args[1],strlen(args[1]));
  write(pipeDes[1],";\n",strlen(";\n"));
  //Passage en lecture non bloquante
  //Check de comment on gere

  //Multiprocess avec signal ??? :)
  // je sais pas quoi faire
  printf("%d\n",fcntl(pipeDes2[0],F_SETFD,O_NONBLOCK));
  sleep(1);
  while(42){
    //printf("HEYEHEY\n");
    rc = read(pipeDes2[0],buf,1024);
    printf("%d\n",rc);
    fflush(stdout);
    if(rc<=0)break;
    printf("%s",buf);
  }
  write(pipeDes[1],"\\dt\n",strlen("\\dt\n"));
  sleep(2);
  while(42){
    //printf("HEYEHEY\n");
    rc = read(pipeDes2[0],buf,1024);
    //printf("%d\n",rc);
    fflush(stdout);
    if(rc<=0)break;
    printf("%s",buf);
  }



  write(pipeDes[1],"\\q",strlen("\\q"));
  close(pipeDes[1]);
  close(pipeDes2[0]);
  wait(NULL);
}
