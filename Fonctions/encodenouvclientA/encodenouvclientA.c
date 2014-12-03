/*struct clientA encodenouvclientA(void) struct clientA
{
int numero ;
char nom [31];
char prenom [31];
char datenaiss [11] ;
char num_compte [20] ;
char num_reg_nat [14] ;
};
„h creerez une fonction nommee . encodenouvclientA. dont le prototype est le suivant :
 struct clientA encodenouvclientA (void) ; Cette fonction permet a l¡
 ¦utilisateur d¡¦encoder les informations concernant un nouveau client de la banque A.
 La fonction verifie la validite des informations et invite l¡
 ¦utilisateur a se corriger si certaines informations sont erronees. 
 Cette fonction fera notamment appel aux fonctions verifnom, verifprenom, verifdatenaiss , verifnumcompte , 
 verifnumregnat et compatibildatenaissregnat evoquees precedemment. Les . saisies vides . (lorsque l¡
 ¦utilisateur appuie sur la touche ENTER sans avoir prealablement saisi de caractere) sont interdites pour 
 chaque information concernant un client de la banque A 
 (autrement dit pas de . saisie vide . pour le numero, le nom, le prenom, la date de naissance, 
 le numero de compte bancaire et le numero de registre national). 
 Les informations valides concernant le nouveau client de la banque A seront 
 contenues dans la structure clientA retournee par la fonction ;*/
 
 
#include<stdlib.h>
#include<stdio.h>

 int strlength(char s[])
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
 int daysinmonth(int d, int y){ 
 	 
 	int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
 	 
 	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {  
 		monthdays[1] = 29; 
 	} 
 	 
 	return monthdays[d-1]; 
 	 
 } 
 
 
 
 
 //Fonction verifdatenaiss(char *chaine) 
 
 
 
 
 int verifdatenaiss(char *chaine) { 
   int i, j, m, a, result; 
    
    
   if(strlength(chaine) == 10 && chaine[2] == '/' && chaine[5] == '/') {					//Si longeur de chaine = 10 ET  
   																						//si les "/" sont bien placés 
   		char jour[3] = {chaine[0], chaine[1], '\0' }; 
 		char mois[3] = {chaine[3], chaine[4], '\0' };									//Division de la date en différentes  
 		char annee[5] = {chaine[6], chaine[7], chaine[8], chaine[9], '\0' };			//variables char[] jours, mois, années 
   
         j = nbchartoint(jour); 
         m = nbchartoint(mois);															//Conversion en int 
         a = nbchartoint(annee); 
          
          
 		if(j <= daysinmonth(m, a) && j >= 1){											//Si le jour du mois est valide (année bisextile) 
 												 
     		if(a >= 1905 && a <=1996) {													//Si la date est postérieure au 31 décembre 1904 et  
     																					//antérieure au 1er janvier 1997 
     		 
 				return 1;																//Alors retourne 1 = valide 
 			}  
 		 
   		} 	  
 
     } 
    
 	return 0;																			//Si longeur de chaine != 10 OU  
 																						//si les "/" ne sont pas bien placés 
 																						//Retourne 0 = invalide   
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
 

struct clientA 
{    
int numero ;
char nom [31];
char prenom [31];
char datenaiss [11] ;
char num_compte [20] ;
char num_reg_nat [14] ;
} cA;

encodenouvclientA(void)
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

main()
{
  encodenouvclientA();
  printf("%d\n",numero);
  puts(cA.nom);
  puts(cA.prenom);
  puts(cA.num_compte);
  puts(cA.datenaiss);
  puts(cA.num_reg_nat);
  printf("les donnees sont elles correctes?\n");
  
  system("pause");    
}

