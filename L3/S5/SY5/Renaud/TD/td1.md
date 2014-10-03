[SY5] TD 2 2/10/14

# EX1
##
```
#include <syslstat.h>

int main(int argc, char*[] argv){
    struct stat s;
    // Vérifier qu'il y a bien un argument

    if(stat(argv[1], &s) == -1){
        printf("Fichier inconnu\n");
    }
    return 0;

}
```
##

```
#include <syslstat.h>

int main(int argc, char*[] argv){
    struct stat s;
    // Vérifier qu'il y a bien un argument

    if(stat(argv[1], &s) == -1){
        printf("Fichier inconnu\n");
        return -1;
    }
    if(s.st_size == 0){
        printf("Fichier vide\n");
    }
    return 0;
}
```

##


```
#include <syslstat.h>

int main(int argc, char*[] argv){
    struct stat s1;
    struct stat s2;
    // Vérifier qu'il y a bien deux argument

    if(stat(argv[1], &s1) == -1){
        printf("Fichier inconnu\n");
        return -1;
    }
    if(stat(argv[1], &s2) == -1){
        printf("Fichier inconnu\n");
        return -1;
    }
    if(s1.st_ino == s2.st_ino){
        printf("Les fichier ont le même inode\n");
    }
    return 0;
}
```
##

##
