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

int main(int argc, char *args[]) {
  int pipeDes[2];
  char * argv[3];
  pid_t p;
  if (pipe(pipeDes) == -1){
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
    int des = open(args[2],O_WRONLY | O_CREAT | O_TRUNC,0600);
    close(pipeDes[1]);
    argv[0] = "psql";
    //argv[1] = "-q";
    argv[1] = "base";
    argv[2] = NULL;
    dup2(des, 1);
    close(des);
    dup2(pipeDes[0], 0);
    close(pipeDes[0]);
    if(execvp("psql",argv) ==-1){
      exit(255);
    }
  }
  //wait(NULL);
  int statut;
  close(pipeDes[0]);
  //write(pipeDes[1],args[1],strlen(args[1]));
  write(pipeDes[1],"\\i ",strlen("\\i "));
  write(pipeDes[1],args[1],strlen(args[1]));
  write(pipeDes[1],"\\q",strlen("\\q"));
  close(pipeDes[1]);
  wait(&statut);
}
