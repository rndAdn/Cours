#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char ** argv){
  struct flock fl;
  fl.l_type = F_RDLCK;
  fl.l_whence = SEEK_CUR;
  fl.l_start = 0;
  fl.l_len = 1024;

  int fic = open("/Users/ByTeK/Documents/Cours/L3/S5/SY5/Etienne/TP7/test.txt",O_RDONLY);
  char * buf[1024];
  int rc;

    while(42){
        fcntl(fic,F_GETLK,&fl);
        if(fl.l_type == F_UNLCK){
          fl.l_type = F_RDLCK;
          if(fcntl(fic,F_SETLK,&fl)!=-1 && (rc = read(fic,buf,1024))!= 0){
              write(2,buf,rc);
              fl.l_type = F_UNLCK;
              fcntl(fic,F_GETLK,&fl);
              fl.l_type = F_RDLCK;
            }
            else break;
        }
      else break;
    }
  return 0;
}
