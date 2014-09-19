#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#if condition
    /* Code source à compiler si la condition est vraie */
#elif condition2
    /* Sinon si la condition 2 est vraie compiler ce code source */
#endif

#ifdef LINUX
    /* Code source pour Linux */
#endif


#define MAJEUR(age, nom) if (age >= 18) \
                    printf("Vous etes majeur %s\n", nom);

#define NOIR 1

typedef int IMAGE1[2][2];
typedef int (*ptr_fonction)(int,int);


/*atof,atoi convert string to integer / double */

fscanf(FILE *stream, const char *format, ...);
/*Renvoie le nombre de motif trouver avec succée. stop espace / saut de ligne si %s*/
/*FORMAT*/
/*                                  */


int fseek(FILE *flot, long decalage, int origine);
/*se déplace dans le fichier  SEEK_SET/CUR/END*/
char *strcpy(char *dst, const char *src);
/*Attention pas d'alloc sur dst donc dsl Grande*/
char *strncpy(char *dst, const char *src, size_t n);
/*Comme strcpy sauf que l'on copie que n char*/
char *strcat(char *dst, const char *s) ;
/*Gaffe a la taille de dst*/
void *memcpy(void *dest, const void *src, size_t n);
/*Copie n octet de la zone de memoire de src vers dsl sans alloc*/

/*stdin, stdout, stderr*/

struct pile_amortie{
  int occupation;
  int capacite;
  int elements;
};

struct matrice {
  int nb_lignes;
  int nb_colonnes ;
  double ** coefficients;
};

enum type_carte{
  TREFLE = NOIR,
  COEUR  = 2,
  PIQUE  = 3,
  CARREAU = 4,
};

union contenu{
  int entier;
  double gros;
  short petit;
  char caractere;
  char string[12];
};

struct sample{
  union contenu c;
  enum type_carte t;
  int choix;
};

typedef struct sample sample;

void param_variable(int nombreArg,...){
  union contenu c;
  //c.string = calloc(12,sizeof(char));
  va_list vl;
  int j = 0;
  va_start(vl,nombreArg);
  for (j=0;j<nombreArg;j++){
    c.string[j]=va_arg(vl,char);
  }
  c.string[j]=0;
  va_end(vl);
  printf("%s\n",c.string);
}

int addition(int a,int b ){
  return a+b;
}

int main(){

  ptr_fonction f = &addition;
  int i = f(2,3);
  printf("%d\n",i);

  sample s;
  s.c.caractere = 'a';
  s.t = TREFLE;
  s.choix = 2;
  printf("c=%c,t=%d,choix=%d\n",s.c.caractere,s.t,s.choix);
  MAJEUR(22,"Etienne");
  param_variable(5,'a','b','c','d','e');

  return 1;
}
