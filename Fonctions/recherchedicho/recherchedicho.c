#include <stdio.h>  /* permet d'utiliser printf, scanf*/
#include <stdlib.h>  /* permet d'utiliser la fonction rand */
#define VRAI 1
#define FAUX 0
#define N 10 /* N est le nombre maximum de noms de personne du tableau de noms de personne */
#define LONGMAX 20 /* nombre de caractères maximum pour le nom d'une personne */

i

int recherchedichonom(struct clienA trinomA[i].nom,int taille,struct clientB sourceB[i].nom)//fonction qui recherche un nom dans un tableau trié pour les nom 
{
    int i,bg=0,bd= taille-1, trouve=FAUX;
    while(trouve==FAUX && bg <= bd)//tant qu'on n'a pas trouvé la valeur et qu'on n'a pas fouillé tout le tableau
    {
        i=(bg+bd)/2;
        if(strcomp(trinomA[i].nom,sourceB[i].nom)==-1)
            bd = i-1;
        else
            if(strcomp(tab[i],nom)==1)
                bg=i+1;
            else
                trouve = VRAI;
    }
    return trouve;
}

/*int recherchedichoprenom(struct clienA trinomA[i].prenom,int taille,struct clientB sourceB[i].prenom)//fonction qui recherche un nom dans un tableau trié
{
    int i,bg=0,bd= taille-1, trouve=FAUX;
    while(trouve==FAUX && bg <= bd)//tant qu'on n'a pas trouvé la valeur et qu'on n'a pas fouillé tout le tableau
    {
        i=(bg+bd)/2;
        if(strcomp(trinomA[i].prenom,sourceB[i].prenom)==-1)
            bd = i-1;
        else
            if(strcomp(trinomA[i].nom,sourceB[i].nom)==1)
                bg=i+1;
            else
                trouve = VRAI;
    }
    return trouve;
}

int recherchedichodatenaiss(struct clienA trinomA[i].datenaiss,int taille,struct clientB sourceB[i].datenaiss)//fonction qui recherche un nom dans un tableau trié
{
    int i,bg=0,bd= taille-1, trouve=FAUX;
    while(trouve==FAUX && bg <= bd)//tant qu'on n'a pas trouvé la valeur et qu'on n'a pas fouillé tout le tableau
  {
        i=(bg+bd)/2;
        if(strcomp(trinomA[i].datenaiss,sourceB[i].datenaiss)==-1)
            bd = i-1;
        else
            if(strcomp(trinomA[i].datenaiss,sourceB[i].datenaiss)==1)
                bg=i+1;
            else
                trouve = VRAI;
    }
    return trouve;
}*/



main ()
{
	struct clientA trinomA[M];
	int nbClientB;
	struct clientA sourceA[P];//P = nombre totale de client dans la banque B
	struct clientB clients_communs[P]


    if((recherchedichonom(trinomA[M].nom,nbClientB,sourceB[P].nom])==1) && (recherchedichoprenom(trinomA[M].prenom,nbClientB,sourceB[P].prenom])==1) && (recherchedichodatenaiss(trinomA[M].datenaiss,nbClientB,sourceB[P].datenaiss)==1))
       {
	   		stringcopy(trinomA[i].nom, clients_communs[i].nom);
	   		stringcopy(trinomA[i].prenom, clients_communs[i].prenom);
	   		stringcopy(trinomA[i].datenaiss, clients_communs[i].datenaiss);
	   
	   
	   }
    else
       printf("%s ne se trouve pas dans la banque B\n",nomcherche);
    system("pause");
}
