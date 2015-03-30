
/*
<------  entete fichier  ------>
 ______________________________________________________________________________________________
|        |      |		  |     |                       |                  |                  |
| taille | mode | lgrdnom | nom | contenut du fichier 1 | entete fichier 2 | entete fichier 2 |
|________|______|_________|_____|_______________________|__________________|__________________|
les 3 champs seront donc ecrit par write(archive,&et,sizeof(struct entete))
*/
#include <string.h>
#include <errno.h>
#include <err.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFSIZE 1024

typedef struct entete{
	size_t taille;
	mode_t mode;
	size_t lgrnom;
} entete;

void archivage(int argc, char const *argv[]){
	entete et;
	struct stat st;
	char buf[BUFSIZE];
	int lu,archive,input,i;

	if((archive = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0600)) < 0)
		err(1,"impossible d ouvrie l archive %s ",argv[2]);
	for(i=3;i<argc;i++){
		if((stat(argv[i],&st) != 0)|((input = open(argv[i],O_RDONLY))<0)){
			warn("impossible d archiver %s ",argv[i]);
			continue;
		}
		et.taille = st.st_size;
		et.mode = st.st_mode;
		et.lgrnom = strlen(argv[i]);
		write(archive,&et,sizeof(struct entete));
		write(archive,argv[i],et.lgrnom);
		//printf("impossible d archiver %d %s \n",input,argv[i]);
		while(1){
			lu = read(input,buf,BUFSIZE);
			if (write(archive,buf,lu) != lu) err(1,"Probleme d'ecriture");
			if (lu < BUFSIZE) break;
		}
		close(input);
	}
	close(archive);

}

void desarchivage (char const *argv[]){
	entete et;
	char buf[BUFSIZE];
	char nomoutput[PATH_MAX];
	int lu,archive,output,j;
	if((archive = open(argv[2],O_RDONLY))==-1)
		err(1,"impossible d ouvrie l archive %s ",argv[2]);
	while(1){
		lu = read(archive,&et,sizeof(struct entete));
		if(lu ==0) break;
		if(lu != sizeof(struct entete))err(1,"erreur format ");
		if(read(archive,nomoutput,et.lgrnom)!=et.lgrnom)
			err(1,"erreur format ");
		nomoutput[et.lgrnom]=0;
		if((output = open(nomoutput,O_WRONLY|O_CREAT|O_TRUNC,et.mode))==-1)
			warn("impossible de de creer le fichier %s \n",nomoutput);
		else{
			for(j=0;j<et.taille/BUFSIZE;j++){
				lu = read(archive,buf,BUFSIZE);
				if (write(output,buf,BUFSIZE)!=lu)err(1,"Probleme d'ecriture");
				//il faudrait tester les valeurs de retours
			}
			read(archive,buf,et.taille%BUFSIZE);
			write(output,buf,et.taille%BUFSIZE);
			close(output);
		}
	}
	close(archive);

}
int main(int argc, char const *argv[]){
	if(argc<3){
		exit(0);
	}
	else if (strcmp(argv[1],"-cf")==0){
		archivage(argc,argv);
	}
	else if(argc==3 && strcmp(argv[1],"-xf")==0){
		desarchivage(argv);
	}
	else
		printf("usage : \n");
	return 0;
}

/*
	1) declarer un lien symbolique S.ISLNK(st.stmode)
	2) appel system readlink si filename est un lien symbolique vars le fichier truc, alors truc est ecrit dans buf
	si toto pointe tatata alors apres lstat("tatata"..) st.st_size est 6 (longueure de tatata)
	3) creer un lien symbolique (char *src , char * dest)

	if(S.ISLNK(st.stmode)){
		readlink(argv[i],linkname,PATH-MAX);
		//ecrit l entete
		write(archive,filname,st.st_size)
	}
	else
	 code ecrit avant pour les fichiers

Exercice 1 question 4:

traiter les liens symbolique
S_ISLINK(mode) vaut !0

*)à l'archivage l'enntete est le même le contene par contre est obtenu par readlink et non plus
open/read?

*)au desarchivage on lit l'entete de la mm facon dans tous les cas.
Si S_ISLINK dectecte un lien on utilise symlink()
au lieu de write/open
int symlink(char * original, char * lien);
attention, si lien est un fichier existant , symlink echoue et et errno=EEXIST
dans notre cas on peut faire un unlink(lien) avant pour ecraser la cible.

Repertoire ?
*)a l'archivage : * ouvrir le Repertoire et le parcourir opendir/readdir
									si fichier traiter comme avant.
									si repertoire appel recursif
							Stocker nom complet relatif.
*)au desarchivage :
									pas recursif.
									il faut faire un mkdir -p si dossier non existant.

*/
