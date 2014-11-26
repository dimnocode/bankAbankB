#include <stdlib.h>
#include <stdio.h>

#define M 





struct clientA 
{
int numero ;
char nom [31];
char prenom [31];
char datenaiss [11] ;
char num_compte [20] ;
char num_reg_nat [14] ;
};


void stringcopy() {  //Fonction de Murphy
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
	
}
