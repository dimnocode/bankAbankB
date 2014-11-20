/*struct clientA encodenouvclientA(void) struct clientA
 {
 int numero ;
 char nom [31];
 char prenom [31];
 char datenaiss [11] ;
 char num_compte [20] ;
 char num_reg_nat [14] ;
 };
 Ñh creerez une fonction nommee . encodenouvclientA. 
 dont le prototype est le suivant :struct clientA encodenouvclientA (void) ; 
 
 Cette fonction permet a l°¶utilisateur d°¶encoder les informations concernant un nouveau client de la banque A.
 
 La fonction verifie la validite des informations et invite l°¶utilisateur a se corriger si certaines informations sont erronees.
 
 Cette fonction fera notamment appel aux fonctions verifnom, verifprenom, verifdatenaiss , verifnumcompte ,
 verifnumregnat et compatibildatenaissregnat evoquees precedemment. 
 
 Les . saisies vides . (lorsque l°¶utilisateur appuie sur la touche ENTER sans avoir prealablement saisi de caractere) sont interdites pour chaque information concernant un client de la banque A
 (autrement dit pas de . saisie vide . pour le numero, le nom, le prenom, la date de naissance,
 le numero de compte bancaire et le numero de registre national).
 
 Les informations valides concernant le nouveau client de la banque A seront
 contenues dans la structure clientA retournee par la fonction ;*/


#include<stdlib.h>
#include<stdio.h>


{
    
    int numero ;
    char nom [31];
    char prenom [31];
    char datenaiss [11] ;
    char num_compte [20] ;
    char num_reg_nat [14] ;
}; cA

struct clientA encodenouvclientA(void);

{
    int i=0;     /*compteur pour les boucles*/
    int nombcaracnom=0;    /*variable pour mettre le nombre de caractères contenu dans la chaine nom*/
    int nombcaracprenom=0; /*idem prenom*/
    int nombcaracdatenaiss=0; /*idem date de naissance*/
    int nombcaracnum_compte=0; /*idem numero de compte*/
    int nombcracnum_reg_nat=0 /*idem numero de reg nationnal*/
    
    
    /*attention numÈro de client pas encore codÈ ici*/
    /*attention numÈro de client pas encore codÈ ici*/
    /*attention numÈro de client pas encore codÈ ici*/
    /*attention numÈro de client pas encore codÈ ici*/
    /*attention numÈro de client pas encore codÈ ici*/
    
    
    while(return!=1)/*return de la vÈrification*/
    {
        printf("veuillez entrer le nom du nouveau client\n");
        gets(cA.nom);                        /*saisie nom*/
        
        while(nom[i]!='\0')
        {
            nombcaracnom++;              /*cette boucle compte le nombre de caractères dans la chaine de la saisie 'nom'*/
            i++;
        }
    
        if(nombcaracnom>31)               /* verification que la chaine de la saisie 'nom' ne depasse pas les 31 caracteres (30 caracteres+ \0)*/
        {
            printf("le nombre de caract%cres du nom d%cpasse le nombre maximum autoris%c (soit30 caract%cres maximum)",138,130,130,138);
            return=0;
        }
        else
        {
            if(nom[0]=='\0')              /*verification que la saisie n'est pas vide (ENTER sans avoir saisi de caractere)*/
            {                             /*si pas verifié dans verif nom, on peut aussi verifier que la saisie n'est pas composée uniquement d'espace avec*/
                return=0;                 /*cette fonction :  for(i=0;i!>nombrecaracnom;i++)                          */
            }                             /*                       { if(nom[i]==' ')                                 */
            else                          /*                         { return=0;                                     */
            {                             /*                         }                                               */
                                          /*                       }                                                 */
                
                /*mettre la suite de la vÈrif nom ici*/
            }
        }
        
    }
    
    while(return!=1)
    {
        printf("veuillez entrer le pr%cnom du nouveau client\n",130);
        gets(cA.prenom);                   /*saisie prenom*/
        
        i=0;
        
        while(prenom[i]!='\0')
        {
            nombcaracprenom++;/*cette boucle compte le nombre de caractères dans la chaine de la saisie 'prenom'*/
            i++;
        }
        
        if(nombcaracprenom>31) /*verif saisie prenom ne depasse pas 30 caracters+\0*/
        {
            printf("le nombre de caract%cres du pr%cnom d%cpasse le nombre maximum autoris%c (soit 30 caract%cres maximum)",138,130,130,130,138)
            return=0;
        }
        else
        {
            if(prenom[0]=='\0')  /*verification que la saisie n'est pas vide (ENTER sans avoir saisi de caractere)*/
            {
                return=0;
            }
            else
            {
              /*mettre la suite de vÈrif prÈnom ici*/
            }
        }
        
    }
    while(return!=1)
    {
        printf("veuillez entrer la date de naissance du nouveau client.\n");
        printf("la date de naissance s'encode comme suit : jj/mm/aaaa\n");
        gets(cA.datenaiss);               /*saisie date de naissance*/
        
        i=0;
        
        while(datenaiss[i]!='\0')
        {
            nombcaracdatenaiss++;/*cette boucle compte le nombre de caractères dans la chaine de la saisie 'date de naissance'*/
            i++;
        }
        
        if(nombcaracdatenaiss>10)  /*veri que la saisie date de naissance ne depasse pas 10 caracteres*/
        {
            printf("le nombre de caract%cres de la date de naissance d%cpasse le nombre maximum autoris%c (soit 10 caract%cres maximum)",138,130,130,138)
            return=0;
        }
        else
        {
            if(datenaiss[0]=='\0')  /*verification que la saisie n'est pas vide (ENTER sans avoir saisi de caractere)*/
            {
                return=0;
            }
            else
            {
                /*mettre la suite de vÈrif date de naissance ici*/
            }
        }

    }
    while(return!=1)
    {
        printf("veuillez entrer le num%cro de compte du nouveau client\n",130);
        printf("le num%cro de comprte s'encode comme suit : BEXX-XXXX-XXXX\n",130);
        gets(cA.num_compte);              /*saisie numero de compte*/
        
        i=0;
        
        while(prenom[i]!='\0')
        {
            nombrecaracnum_compte++;  /*cette boucle compte le nombre de caractères dans la chaine de la saisie 'numero de compte'*/
            i++;
        }
        
        if(nombcaracnum_compte>20)   /*verif que la saisie numero de compte ne depasse pas 20 caracteres*/
        {
            printf("le nombre de caract%cres du num%cro de compte d%cpasse le nombre maximum autoris%c (soit 20 caract%cres maximum)",138,130,130,130,138)
            return=0;
        }
        else
        {
            if(num_compte[0]=='\0')  /*verification que la saisie n'est pas vide (ENTER sans avoir saisi de caractere)*/            {
                return=0;
            }
            else
            {
                /*mettre la suite de vÈrif numero de compte ici*/
            }
            
        }

        
    }
    while(return!=1)
    {
        printf("veuillez entrer le num%cro de registre national du nouveau client\n",130);
        printf("le num%cro de registre national s'encode comme suit : aammjj-XXX-XX\n",130);
        gets(cA.num_reg_nat);              /*saisie numero de registre national*/
        
        i=0;
        
        while(num_reg_nat[i]!='\0')
        {
            nombrecaracnum_reg_nat++;/*cette boucle compte le nombre de caractères dans la chaine de la saisie 'registre national'*/
            i++;
        }
        
        if(nombcaracnum_reg_nat>14)  /*verif que la saisie registre national ne depasse pas 14 caractère*/
        {
            printf("le nombre de caract%cres du regitre national d%cpasse le nombre maximum autoris%c (soit 14 caract%cres maximum)",138,130,130,138)
            return=0;
        }
        else
        {
            if(num_reg_nat[0]=='\0')   /*verification que la saisie n'est pas vide (ENTER sans avoir saisi de caractere)*/
            {
                return=0;
            }
            else
            {
                /*mettre la suite de vÈrif registre national ici*/
            }
        }

        
    }
}
