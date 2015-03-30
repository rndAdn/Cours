#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int verif(int desc, int alire, int pivot){
    char* buff = malloc(sizeof(char)*alire);
    int i;
    int lu;
    while ((lu = read(desc, buff, 1024)) != 0){
        for(i = 0; i<lu; i++){
            if(!(buff[i] >= '0' && buff[i] <= '9' )){
                return -1;
            }
        }
    }
    return 0;

}



int main(int argc, char *argv[]){
    if (argc != 4) exit -1;
    int alire = atoi(argv[2])
    int pivot = atoi(argv[3])

    int fic = open(argv[1],O_RDONLY);
    printf("%d\n",verif(fic, alire, pivot));
}
