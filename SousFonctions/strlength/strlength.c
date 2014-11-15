#include <stdio.h>
#include <stdlib.h>

// Sous fonction strlength(char[])
// Retourne la longueur d'une chaine de caractères en INT


//Fonction
//--------
int strlength(char s[]){
	
	int i=0;
	
	while(s[i] != '\0') {
		++i;
	}
	
	return i;
}

//Main test

void main(){

  char tab[100];
  printf("\nEntrez un phrase : ");
  gets(tab);
  
  printf("\nNombre de caract%cre : %d\n\n", 138, strlength(tab));
  system("pause");

}
