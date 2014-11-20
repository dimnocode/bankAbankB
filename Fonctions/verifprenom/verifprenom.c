#include <stdlib.h>
#include <stdio.h>

//Sous-fonction nécessaires

int strlength(char s[]){
	int i=0;
	
	while(s[i] != '\0') {
		++i;
	}
	
	return i;
}


//Fonction verifprenom

int verifprenom(char *prenom){
	
	int i, lprenom;
	//Calcul de la longueur de la chaine
	lprenom = strlength(prenom);
		
	//Passage vers majuscule de la chaine (option)
	//lowtoupcase(prenom);
	
	//Si 1er caractère est un espace alors invalide
	if((int)prenom[0] == 32 || (int)prenom[i] == 45) {
		return 0;
	}
	
	//Vérification des caractères
	for(i=0;i<lprenom;++i){
		
		
		if(((int)prenom[i] < 65 || (int)prenom[i] > 90) && (int)prenom[i] != 32 && (int)prenom[i] != 45 ){
			return 0;
		}
	
	
	}
	return 1;
	
}



//Fonction main de test
void main(){
	
	char nom[31];
	
	printf("\nEntrez un preznom : ");
	gets(nom);
	
	printf("\n  Valide (0=non, 1=oui) : %d\n", verifprenom(nom));
	puts(nom);
	
	system("pause");
}
