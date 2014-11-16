//Fonction lowtoupcase(char *chaine) (option supplémentaire non demandée)
//Transforme les minuscules en majuscules


#include <stdlib.h>
#include <stdio.h>

//(Sous)fonction nécessaires

int strlength(char s[]){
	int i=0;
	
	while(s[i] != '\0') {
		++i;
	}
	
	return i;
}


//Fonction lowtoupcase
void lowtoupcase(char *chaine){
	int i, lchaine;
	
	lchaine = strlength(chaine);
	for(i=0;i<lchaine;++i){
		if((int)chaine[i] <= 122 && (int)chaine[i] >= 97){
			chaine[i] -= 32;
		}
	}
	
}

//Fonction Main de test

void main(){

	char chn[50];
	
	printf("Entrez une chaine de caract%cre en minuscule : ", 138);
	gets(chn);
	
	lowtoupcase(chn);
	
	printf("\n");
	puts(chn);

}


