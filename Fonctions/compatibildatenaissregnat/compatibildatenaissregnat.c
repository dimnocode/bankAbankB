/*int compatibildatenaissregnat (char* dateofbirth, char* numregnat) ;

Cette fonction retourne la valeur 1 si la date de naissance est compatible avec le numéro de registre national 
(Les deux premiers chiffres du numéro de registre national correspondent à l’année de naissance ; les deux suivants au mois de la naissance tandis que le 5ème et 6ème chiffre correspondent au jour de la naissance) 
et retourne la valeur 0 dans le cas contraire 
(Ainsi, par exemple, le numéro de registre national 710712-125-24 est compatible avec la date de naissance 12/07/1971 
tandis que le numéro de registre national 710712-125-24 est incompatible avec la date de naissance 07/12/1971) ; */


#include <stdio.h>
#include <stdlib.h>

int compatibildatenaissregnat (char* dateofbirth, char* numregnat) 
{
    
  if (dateofbirth [9] != numregnat [1]) //vérif le dernier chiffre de la date de naissance et deuxieme chiffre du registre nat
  {
  printf("votre date de naissance ne correspond pas au registre national");
  return 0;
  }
  else
  {
      if (dateofbirth [8] != numregnat [0])//vérif l'avant dernier chiffre de la date de naissance et le premier chiffre du registre nat
      {
      printf("votre date de naissance ne correspond pas au registre national");
      return 0;
      }
      else
      {
          
            if (dateofbirth [4] != numregnat [3])//vérif le dernier chiffre du mois de la date de naissance et le quatrieme chiffre du registre nat
          {
          printf("votre date de naissance ne correspond pas au registre national");
          return 0;
          }
          else
          {
              if (dateofbirth [3] != numregnat [2]) //vérif le premier chiffre du mois de la date de naissance et le troisième chiffres du registre nat
              {
              printf("votre date de naissance ne correspond pas au registre national");
              return 0;
              }
              else
              {
                    if (dateofbirth [1] != numregnat [5])//vérif le dernier chiffre du jour de la date de naissance et le dernier chiffre du registre nat
                    {
                    printf("votre date de naissance ne correspond pas au registre national");
                    return 0;
                    }
                    else
                    {
                        if (dateofbirth [0] != numregnat [4]) //vérif le deuxième chiffre du jour de la date de naissance et l'avant dernier chiffres du registre nat
                        {
                        printf("votre date de naissance ne correspond pas au registre national");
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
