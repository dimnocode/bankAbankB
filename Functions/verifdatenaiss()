
// Fonction
// --------
// int verifdatenaiss(char* chaine)
// Cette fonction retourne la valeur 0 si la chaîne de caractères ne correspond pas à une date de naissance valide
// et retourne la valeur 1 dans le cas contraire ;

17/12/2011
0123456789

#include <stdio.h>
#include <stdlib.h>

int verifdatenaiss(char *chaine) {
  int i, j, m, a, result;
  char jour[2], mois[2], annee[4];
  
  if (strlength(*chaine) != 10) {
  
    return 0;
    
  } else if(chaine[2] != '/' || chaine[5] != '/') {
  
      return 0;
  
    } else {
        for(i=0;i<=1;++i){
          jour[i] = chaine[i];
        }
        
        for(i=3;i<=4;++i){
          mois[i] = chaine[i];
        }
        
        for(i=3;i<=4;++i){
          mois[i] = chaine[i];
        }
        
        for(i=6;i<=9;++i){
          anne[i] = chaine[i];
        }
        
        j = chartoint(jour);
        m = chartoint(mois);
        a = chartoint(annee);
        
    
      }
  
  if(j > 31 || j < 1 || m > 12 || m < 1 || a < 1900 || a > 2015 ||){
    return 0;
  } else {
  
    return 1;
  }

}
