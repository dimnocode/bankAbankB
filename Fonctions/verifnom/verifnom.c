#include <stdlib.h>
#include <stdio.h>

//Sous-fonction n�cessaires

int strlength(char s[]){
	int i=0;
	
	while(s[i] != '\0') {
		++i;
	}
	
	return i;
}





//Fonction verifnom

int verifnom(char *nom){
	
	int i, lnom;
	//Calcul de la longueur de la chaine
	lnom = strlength(nom);
		
	//Passage vers majuscule de la chaine (option)
	//lowtoupcase(nom);
	
	//Si 1er caract�re est un espace alors invalide
	if((int)nom[0] == 32) {
		return 0;
	}
	
	//V�rification des caract�res
	for(i=0;i<lnom;++i){
		
		
		if(((int)nom[i] < 65 || (int)nom[i] > 90) && ((int)nom[i] != 32)){
			return 0;
		}
	
	
	}
	return 1;
	
}



//Fonction main de test
void main(){
	
	char nom[31];
	
	printf("\nEntrez un nom : ");
	gets(nom);
	
	printf("\n  Valide (0=non, 1=oui) : %d\n", verifnom(nom));
	puts(nom);
	
	system("pause");
}
