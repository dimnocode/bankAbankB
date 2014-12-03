#include <stdlib.h>
#include <stdio.h>

#define M 100





struct clientA 
{
int numero;
char nom[31];
char prenom[31];
char datenaiss[11] ;
char num_compte[20];
char num_reg_nat[14];
}cA;


int strlength(char s[]){
	
	int i=0;
	
	while(s[i] != '\0') {
		++i;
	}
	
	return i;
}
	
void stringcopy(char* source, char* destination){
	
	int i;
	
	for(i=0; i <= strlength(source); ++i){
		
		destination[i] = source[i];
				
	}
	
	
}


void structclientAcopy(struct clientA source, struct clientA *destination){
	
	destination->numero = source.numero;
	
	stringcopy(source.nom, destination->nom);
	stringcopy(source.prenom, destination->prenom);
	stringcopy(source.datenaiss, destination->datenaiss);
	stringcopy(source.num_compte, destination->num_compte);
	stringcopy(source.num_reg_nat, destination->num_reg_nat);
	
	
}


void main(){
	
	//struct clientA cA;
	struct clientA cbis;
	char test[10];
	

	
	cA.numero = 123;
	gets(cA.nom);
	gets(cA.prenom);
	gets(cA.datenaiss);
	gets(cA.num_compte);
	gets(cA.num_reg_nat);

	
	
	structclientAcopy(cA, &cbis);
	
	printf("\n%s",cbis.nom);
	printf("\n%s",cbis.prenom);
	printf("\n%s",cbis.datenaiss);
	printf("\n%s",cbis.num_compte);
	printf("\n%s",cbis.num_reg_nat);


}
