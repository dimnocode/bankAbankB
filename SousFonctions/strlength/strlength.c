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

int main(int argc, char *argv[]) {
	return 0;
}


//Main test

void main(){

  char tab[100];
  printf("\nEntrez un phrase : ");
  gets(tab];
  
  printf("\n Nombre de caract%cre : %d, 138, strlength(tab));

}
