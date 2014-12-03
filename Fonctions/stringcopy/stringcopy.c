#include <stdio.h>
#include <stdlib.h>

// Sous fonction strlength(char[])
// Retourne la longueur d'une chaine de caractères en INT




int strlength(char s[]){
	
	int i=0;
	
	while(s[i] != '\0') {
		++i;
	}
	
	return i;
}


//Fonction stringcopy()
//---------------------


void stringcopy(char* source, char* destination){
	
	int i;
	
	for(i=0; i <= strlength(source); ++i){
		
		destination[i] = source[i];
				
	}
	
	
	
	
}


void main(){
	
	char str1[31], str2[31];
	
	printf("Entrez une phrase dans la var string1 : ");
	gets(str1);
	
	stringcopy(str1, str2);
	
	printf("Contenu de str2 : ");
	puts(str2);
}
