
#include <stdlib.h>
#include <stdio.h>

int main(){

FILE* fichier = fopen("data.txt","r"); ;

int c;
int nLignes = 0;
while((c=fgetc(fichier)) != EOF) //on parcourt l'ensemble des caracteres et on compte le nombre de retour à la ligne 

{
	if(c=='\n')
		nLignes++;
}
printf("%d \n", nLignes);
return(0);
}