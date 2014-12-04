#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/////////////////////////////////////////Structures/////////////////////////////////////////
struct clientA 
{    
int numero ;
char nom [31];
char prenom [31];
char datenaiss [11] ;
char num_compte [20] ;
char num_reg_nat [14] ;
} cA;

struct clientB
{
char nom [31];
char prenom [31];
char datenaiss [11] ;
}cB;



int strlength(char* s);
int verifnom(char *nom);
int verifprenom(char *prenom);
int nbchartoint(char *chaine);
int daysinmonth(int mo, int ye);
int verifdatenaiss(char *chaine);
int verifnumcompte (char* chaine);
int compatibildatenaissregnat (char* dateofbirth, char* numregnat);
int verifNumRegNat(char* chaine);
void encodenouvclientA(void);
void encodenouvclientB(void);
void stringcopy(char* source, char* destination);
void structclientAcopy(struct clientA source, struct clientA *destination);
int stringcomp(char *chaineA, char* chaineB);











/////////////////////////////////////////Fonctions/////////////////////////////////////////

 int strlength(char* s)
{ 
 	int i=0; 
 	 
 	while(s[i] != '\0') 
{ 
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
 	 
 	//Si 1er caractère est un espace alors invalide 
 	if((int)nom[0] == 32) { 
 		return 0; 
 	} 
 	 
 	//Vérification des caractères 
 	for(i=0;i<lnom;++i){ 
 		 
 		 
 		if(((int)nom[i] < 65 || (int)nom[i] > 90) && ((int)nom[i] != 32)){ 
 			return 0; 
 		} 
 	 
 	 
 	} 
 	return 1; 
 	 
 } 
 
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
 
 int nbchartoint(char *chaine){ 
 	 
 	int i, res=0, lchaine = strlength(chaine); 
 	 
 	 
 	for(i=0;i<lchaine;++i){ 
 		 
 		if((int)chaine[i] >= 48 && (int)chaine[i] <= 57){ 
 			 
 			res += ((int)chaine[i] - 48) * (int)pow(10.0, (float)lchaine-i-1); 
 			 
 		} 	else {  
 				return res = -1; 
 			} 
 	} 
 	 
 	return res; 
 	 
 } 
 
 
//daysinmonth
int daysinmonth(int mo, int ye){
	
	int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 	//Tableau du nombre de jours pour chaque mois (annees non bisextiles)
	
	if((ye % 4 == 0 && ye % 100 != 0) || ye % 400 == 0) { 					//Si l'annee est bisextile (divisible par 4 et non par 100 ou divisible par 400)
		monthdays[1] = 29;													//Alors le nombre de jour du mois de fevrier est de 29
	}
	
	return monthdays[mo-1];													//Retourne le nombre de jour du mois
	
}
 
 
 
 
 //Fonction verifdatenaiss(char *chaine) 
 
 
 
 
 int verifdatenaiss(char *chaine) { 
   int i, j, m, a, result; 
    
    
   if(strlength(chaine) == 10 && chaine[2] == '/' && chaine[5] == '/') {				//Si longeur de chaine = 10 ET  
   																						//si les "/" sont bien places 
   		char jour[3] = {chaine[0], chaine[1], '\0' }; 
 		char mois[3] = {chaine[3], chaine[4], '\0' };									//Division de la date en differentes  
 		char annee[5] = {chaine[6], chaine[7], chaine[8], chaine[9], '\0' };			//variables char[] jours, mois, annees 
   
         j = nbchartoint(jour); 
         m = nbchartoint(mois);															//Conversion en int 
         a = nbchartoint(annee); 
          
          
 		if(j <= daysinmonth(m, a) && j >= 1){											//Si le jour du mois est valide (annee bisextile) 
 												 
     		if(a >= 1905 && a <=1996) {													//Si la date est posterieure au 31 décembre 1904 et  
     																					//anterieure au 1er janvier 1997 
     		 
 				return 1;																//Alors retourne 1 = valide 
 			}  
 		 
   		} 	  
 
     } 
    
 	return 0;																			//Dans tous les autres cas, retourne 0
 	
 } 
 
 int verifnumcompte (char* chaine)                 /*Fonction de vérification de numéro de compte*/ 
 
 
 { 
    int i; 
     for(i=0;i<20;i++) 
     { 
                      if((chaine[0]!='B'||chaine[1]!='E')) 
                      { 
                      printf("Ce num%cro de compte est incorrect\n",130); 
                      return 0;                                  
                      } 
                      if ((i==2||i==3||i==5||i==6||i==7||i==8||i==10||i==11||i==12||i==13||i==15||i==16||i==17||i==18)&&(chaine[i]<48||chaine[i]>57)) 
                      { 
                      printf("Ce num%cro de compte est incorrect\n",130); 
                      return 0;                   
              
                      } 
                      if((i==4||i==9||i==14)&&(chaine[i]!=' ')) 
                     { 
                      printf("Ce num%cro de compte est incorrect\n",130); 
                      return 0;                   
                      } 
     return 1; 
     } 
 } 

int compatibildatenaissregnat (char* dateofbirth, char* numregnat)  
 { 
      
   if (dateofbirth [9] != numregnat [1]) //vérif le dernier chiffre de la date de naissance et deuxieme chiffre du registre nat 
   { 
   printf("votre date de naissance ne correspond pas au registre national\n"); 
   return 0; 
   } 
   else 
   { 
       if (dateofbirth [8] != numregnat [0])//vérif l'avant dernier chiffre de la date de naissance et le premier chiffre du registre nat 
       { 
       printf("votre date de naissance ne correspond pas au registre national\n"); 
       return 0; 
       } 
       else 
       { 
            
             if (dateofbirth [4] != numregnat [3])//vérif le dernier chiffre du mois de la date de naissance et le quatrieme chiffre du registre nat 
           { 
           printf("votre date de naissance ne correspond pas au registre national\n"); 
           return 0; 
           } 
           else 
           { 
               if (dateofbirth [3] != numregnat [2]) //vérif le premier chiffre du mois de la date de naissance et le troisième chiffres du registre nat 
               { 
               printf("votre date de naissance ne correspond pas au registre national\n"); 
               return 0; 
               } 
               else 
               { 
                     if (dateofbirth [1] != numregnat [5])//vérif le dernier chiffre du jour de la date de naissance et le dernier chiffre du registre nat 
                     { 
                     printf("votre date de naissance ne correspond pas au registre national\n"); 
                     return 0; 
                     } 
                     else 
                     { 
                         if (dateofbirth [0] != numregnat [4]) //vérif le deuxième chiffre du jour de la date de naissance et l'avant dernier chiffres du registre nat 
                         { 
                         printf("votre date de naissance ne correspond pas au registre national\n"); 
                         return 0; 
                         } 
                         else 
                         { 
                         return 1;  
                         } 
                     } 
                
               } 
            
           } 
            
       }           
   } 
 
 
 } 

 
 
int verifNumRegNat(char* chaine)
{
                int i=0;
                int etat = 1;
                
                
                if (chaine[13]!='\0')
                {
                return 0;
                }
                while (i < 13 )
                {
                    
        if(i != 6 && i != 10)
        {
            if(chaine[i]<'0'||chaine[i]>'9')
            {
                etat = 0;
            }
        }
        else
        {
            if (chaine[i]!='-')
            {
                etat = 0;
            }
        }
        i=i+1;
                }
        return etat;
}
 
 



void encodenouvclientA(void)
{

      
                      
                       printf("veuillez entrer le num%cro de client du nouveau client\n",130);
                       scanf("%d",&cA.numero);
      
       
       fflush(stdin);
       
       do
       {
                       printf("veuillez entrer le nom du nouveau client\n");
                       gets(cA.nom);
                      

       }
       while(verifnom(cA.nom)!=1 || cA.nom[0]=='\0');
       
       
       
       do
       {
                       printf("veuillez entrer le pr%cnom du nouveau client\n",130);
                       gets(cA.prenom);
                                     
       }
       while(verifprenom(cA.prenom)!=1 || cA.prenom[0]=='\0');
       
        do
       {
                       printf("veuillez entrer le num%cro de compte du nouveau client\n",130);
                       printf("le num%cro de comprte s'encode comme suit : BEXX XXXX XXXX XXXX\n",130);
                       gets(cA.num_compte);
                                
       }
       while(verifnumcompte (cA.num_compte)!=1 || cA.num_compte[0]=='\0');
       
       do
       {
                            do
                            {
                                  printf("veuillez entrer la date de naissance du nouveau client.\n");
                                  printf("la date de naissance s'encode comme suit : jj/mm/aaaa\n");
                                  gets(cA.datenaiss);
                       
                            }
                            while(verifdatenaiss(cA.datenaiss)!=1 || cA.datenaiss[0]=='\0');
       
      
                            do
                            {
                                  printf("veuillez entrer le num%cro de registre nationnal du nouveau client\n",130);
                                  printf("le num%cro de registre nationnal s'encode comme suit : aammjj-XXX-XX\n",130);
                                  gets(cA.num_reg_nat);
                       
                            }
                            while(cA.num_reg_nat[0] == '\0'||verifNumRegNat(cA.num_reg_nat)!=1 );
       }
       while(compatibildatenaissregnat(cA.datenaiss, cA.num_reg_nat)!=1);
}


void encodenouvclientB(void)
{

      
                      
                      
       
       do
       {
                       printf("veuillez entrer le nom du nouveau client\n");
                       gets(cB.nom);
                      

       }
       while(verifnom(cB.nom)!=1 || cB.nom[0]=='\0');
       
       
       
       do
       {
                       printf("veuillez entrer le pr%cnom du nouveau client\n",130);
                       gets(cB.prenom);
                                     
       }
       while(verifprenom(cB.prenom)!=1 || cB.prenom[0]=='\0');
       
        
       
      
      do
      {
      printf("veuillez entrer la date de naissance du nouveau client.\n");
      printf("la date de naissance s'encode comme suit : jj/mm/aaaa\n");
      gets(cB.datenaiss);
                       
      }
      while(verifdatenaiss(cB.datenaiss)!=1 || cB.datenaiss[0]=='\0');
       
      
                            
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




int stringcomp(char *chaineA, char* chaineB)   //Fonction qui compare les differentes chaine de caract
{
 int i=0;
 while (chaineA[i]!='\0'&&chaineB[i]!='\0')
 {
  if (chaineA[i] > chaineB[i])
  {
   return -1 ;             
  } 
  else if(chaineA[i]<chaineB[i])
  {
   return 1 ;   
  } 
  i++;   
 }  
 if(strlength(chaineA) == strlength(chaineB))
 {
  return 0 ;           
 }
 else if(strlength(chaineA) < strlength(chaineB))
 {
  return 1;
 }
 else 
 {
   return -1;
 }
}


void main(){
	
}
