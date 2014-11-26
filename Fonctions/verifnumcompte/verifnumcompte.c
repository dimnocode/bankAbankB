#include <stdlib.h>
#include <stdio.h>

int fgetsPerso(char *destination,int size);    
int verifnumcompte (char* chaine);             
int fgetsPerso(char *destination,int size)      /*Fonction qui fai en sorte que si on depasse le nombre de caractere de la saisie, ca nous mes une erreur*/
{
  int nombreCaracteres = 0;
  int i;
  destination[size-1]='\0';
  char lettre;
  do
  {
    lettre = getchar();
    if(lettre!='\n')
    {
      destination[nombreCaracteres] = lettre;
      nombreCaracteres++;
    }
    if(nombreCaracteres>size-1)
    {
      return 0;
    }  
  }
  while(lettre != '\n');
  return 1;
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

main()         /*Main pour vérifier que les fonctions fonctionnes*/
{
      char chaine[20] = "";
      printf("Veuillez entrer votre num de compte : ");
      if(fgetsPerso(chaine,sizeof(chaine))==1)            /*Pour faire appel a la fonction de verif de chaine, il faudra introduire le if a chaque foi*/
      {
        verifnumcompte(chaine);                            /*Ne pas oublier de changer le NOM de la fonction et le nom du tableau de verification a chaque foi (nom, prenom, adresse, etc etc*/
      }                          
      else
      {
        printf("erreur\n");
      }                   
      system("pause");
}
