#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define faux 0
#define vrai 1

#define M 100
#define P 100

//////Structures
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
} cB;

char temp[1000];


//////Declaration des fonctions

int verifnom(char *nom);
int verifprenom(char *prenom);
int nbchartoint(char *chaine);
int daysinmonth(int mo, int ye);
int verifdatenaiss(char *chaine);
int verifnumcompte (char* chaine);
int compatibildatenaissregnat (char* dateofbirth, char* numregnat);
int verifNumRegNat(char* chaine);
struct clientA encodenouvclientA(void);
struct clientB encodenouvclientB(void);
void stringcopy(char* source, char* destination);
void structclientAcopy(struct clientA source, struct clientA *destination);
void structclientBcopy(struct clientB source, struct clientB *destination);
int stringcomp(char *chaineA, char* chaineB);
void tri_numero(struct clientA source[] ,int n);
void trinom(struct clientA source[],int size);
void copyfileA(char*nom,int nb,struct clientA *destination);
void copyfileB(char*nom,int nb,struct clientB *destination);
void readfile (char *nom,struct clientA *sourceA,struct clientB *sourceB, int *nbc);
void recherchedicho(struct clientA trinA[],int nbCa,struct clientB B[], int nbCb, struct clientB Communs[], int *nbClientCom);
void copyfileCom(char*nom,int nb,struct clientB *destination);




//////Fonctions

int strlength(char* s)
{
	int i=0;

	while(s[i] != '\0') 	//Tant que le caractere de fin de chaine n'est pas rencontre
	{
		++i;		//On incremente de 1
	}

	return i;		//Retourne la longueur de la chaine
}



int verifnom(char *nom){

	int i, lnom;

	lnom = strlength(nom); 		//Calcul de la longueur de la chaine


	if((int)nom[0] == 32) { 	//Si 1er caractere est un espace alors retourne 0
		printf("\nNe peut pas commencer par un espace!!\n");
		system("pause");
		return 0;
	}


	for(i=0;i<lnom;++i){  		//Verification des caracteres


		if(((int)nom[i] < 65 || (int)nom[i] > 90) && ((int)nom[i] != 32)){	//Si caractere invalide (Autre que majuscule ou espace), retourne 0
			printf("\nNe peut contenir que des majuscules et espaces!!\n");
			system("pause");
			return 0;
		}


	}
	return 1;	//Dans tous les autres cas retourne 1

}

int verifprenom(char *prenom){

	int i, lprenom;

	lprenom = strlength(prenom);	//Calcul de la longueur de la chaine


	if((int)prenom[0] == 32 || (int)prenom[0] == 45) { 	//Si 1er caractere est un espace alors retoune 0
		printf("\nNe peut pas commencer par un espace ou un tiret!!\n");
		system("pause");
		return 0;
	}


	for(i=0;i<lprenom;++i){ 	//Verification des caracteres


		if(((int)prenom[i] < 65 || (int)prenom[i] > 90) && (int)prenom[i] != 32 && (int)prenom[i] != 45 ){	//Si caractere invalide (Autre que majuscule, espace, tiret), retourne 0
			printf("\nNe peut contenir que des majuscules,espaces et tiret!!\n");
			system("pause");
			return 0;
		}


	}
	return 1;	//Dans tous les autres cas retourne 1

}

int nbchartoint(char *chaine){

	int i, res=0, lchaine = strlength(chaine);


	for(i=0;i<lchaine;++i){ //Pour la longueur de la chaine passee en argument

		if((int)chaine[i] >= 48 && (int)chaine[i] <= 57){	//Si les char represente des chiffres

			res += ((int)chaine[i] - 48) * (int)pow(10.0, (float)lchaine-i-1); //Valeur numerique du char * 10 exposant sa position dans la chaine

		} 	else {	//Si pas un nombre
			return res = -1; //Res = -1
		}
	}

	return res; 	//Retourne res

}



int daysinmonth(int mo, int ye){

	int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 	//Tableau du nombre de jours pour chaque mois (annees non bisextiles)

	if((ye % 4 == 0 && ye % 100 != 0) || ye % 400 == 0) { 					//Si l'annee est bisextile (divisible par 4 et non par 100 ou divisible par 400)
		monthdays[1] = 29;													//Alors le nombre de jour du mois de fevrier est de 29
	}

	return monthdays[mo-1];													//Retourne le nombre de jour du mois

}



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

			if(a >= 1905 && a <=1996) {													//Si la date est posterieure au 31 decembre 1904 et
				//anterieure au 1er janvier 1997

				return 1;																//Alors retourne 1 = valide
			}

		}

	}
	printf("\nLe format de la date de naissance n'est pas correct'!\n");
	system("pause");
	return 0;																			//Dans tous les autres cas, retourne 0

}


int verifnumcompte (char* chaine)                 //Fonction de verification de numero de compte


{
	int i;



	for(i=0;i<20;i++)
	{
		if(chaine[19]!='\0')       //Verifie si le dernier caracthere du numero de compte est bien celui de fin de chaine de sorte a ce qu'il y ai une erreur si le format est un autre que BE00 0000 0000 0000.
		{
			printf("\nCe num%cro de compte est incorrect\n",130);
			system("pause");
			return 0;
		}
		if((chaine[0]!='B'||chaine[1]!='E'))      //Verifie si les 2 premieres ccase du tableau sont bien B et E. Si different de BE => Erreur
		{
			printf("\nCe num%cro de compte est incorrect\n",130);
			system("pause");
			return 0;
		}
		if ((i==2||i==3||i==5||i==6||i==7||i==8||i==10||i==11||i==12||i==13||i==15||i==16||i==17||i==18)&&(chaine[i]<48||chaine[i]>57)) //Verifie que tout les index ci a gauche sont bien des chiffres (code ascii de 0 Ã  9). Si lettre ou autre symbole => Erreur
		{
			printf("\nCe num%cro de compte est incorrect\n",130);
			system("pause");
			return 0;

		}
		if((i==4||i==9||i==14)&&(chaine[i]!=' '))  // Verifie si les cases du tableau separent toute celle ci dessus sont bien des espaces. Si different d'un espace => Erreur
		{
			printf("\nCe num%cro de compte est incorrect\n",130);
			system("pause");
			return 0;
		}

	}
	return 1;   // Retourne 1, une valeur qui stipule que toute les autre condition ci dessus sont respectee. ==> Numero de compte Correcte (BE12 3456 7890 1234)
}



int compatibildatenaissregnat (char* dateofbirth, char* numregnat)  //fonction verifiant la compatibilite entre date de naissance et registre national
{																	// pour y arriver cette fonction vas comparer chaque carracte des deux entite pour verifier
	//qu'il soit identique. dans cette fonction deux parametre y sont envoyes, la date de naiss et le registre nat via pointeur

	if (dateofbirth [9] != numregnat [1]) //verif le dernier chiffre de la date de naissance et deuxieme chiffre du registre nat
	{
		printf("\nvotre date de naissance ne correspond pas au registre national\n");
		system("pause");
		return 0;
	}
	else
	{
		if (dateofbirth [8] != numregnat [0])//verif l'avant dernier chiffre de la date de naissance et le premier chiffre du registre nat
		{
			printf("\nvotre date de naissance ne correspond pas au registre national\n");
			system("pause");
			return 0;
		}
		else
		{

			if (dateofbirth [4] != numregnat [3])//verif le dernier chiffre du mois de la date de naissance et le quatrieme chiffre du registre nat
			{
				printf("\nvotre date de naissance ne correspond pas au registre national\n");
				system("pause");
				return 0;
			}
			else
			{
				if (dateofbirth [3] != numregnat [2]) //verif le premier chiffre du mois de la date de naissance et le troisieme chiffres du registre nat
				{
					printf("\nvotre date de naissance ne correspond pas au registre national\n");
					system("pause");
					return 0;
				}
				else
				{
					if (dateofbirth [1] != numregnat [5])//verif le dernier chiffre du jour de la date de naissance et le dernier chiffre du registre nat
					{
						printf("\nvotre date de naissance ne correspond pas au registre national\n");
						system("pause");
						return 0;
					}
					else
					{
						if (dateofbirth [0] != numregnat [4]) //verif le deuxieme chiffre du jour de la date de naissance et l'avant dernier chiffres du registre nat
						{
							printf("\nvotre date de naissance ne correspond pas au registre national\n");
							system("pause");
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
	int i=0;     /*declaration et definition du compteur i Ãƒ  0*/
	int etat = 1; /*declaration et definition d'une variable etat Ãƒ  1*/


	if (chaine[13]!='\0')     /*Verifie que le 13e caractere est bien un caractere de fin de chaine*/
	{
		printf("\nla longueur du registre national n\'est correct");
		system("pause");
		return 0;
	}
	while (i < 13 )     /*Pendant que le compteur est plus petit que 13*/
	{

		if(i != 6 && i != 10)    /*Pour les caracteres qui ne sont pas en position 6 et 10 */
		{
			if(chaine[i]<'0'||chaine[i]>'9')   /*=> verifie que les caracteres sont des nombres*/
			{
				etat = 0;
				printf("\nintroduisez que des chiffres");
				system("pause");
			}
		}
		else      /*Pour les caracteres en position 6 et 10*/
		{
			if (chaine[i]!='-')     /*verifie qu'il s'agit d'un tiret*/
			{
				printf("\nLes tirets ne sont pas bien positionnés");
				system("pause");
				etat = 0;
			}
		}
		i=i+1;    /*incrementation du compteur*/
	}
	return etat;     /*Affiche la variable etat*/
}



struct clientA encodenouvclientA(void) //fonction encodenouvclientA, fonction permettant d'encoder des clients pour la banque A et de stocker les informations dans la structure de type client A nomee cA
{



	printf("veuillez entrer le num%cro de client du nouveau client\n",130);
	scanf("%d",&cA.numero);//permet de stocker le numero du client dans la structure client A, dans le tableau numero


	fflush(stdin);//permet de vider la memoire tampon

	do //boucle "faire ... tant que", cette boucle permet d'encoder le nom du client
	{
		system("cls");
		printf("veuillez entrer le nom du nouveau client\n");
		printf("1caract%cre minimum, 30 caract%cres maximum et uniquement en majuscules\n",138,138);

		gets(temp);								//Stockage dans temp
		if(strlength(temp) <= 30){				//Si longueur <= a 30 alors copie temp dans cA.nom
			stringcopy(temp, cA.nom);
		}
		else{
			printf("\nle nom est trop long");
			system("pause");
		}




	}
	while(verifnom(cA.nom)!=1 || cA.nom[0]=='\0' || strlength(temp) > 30);//tant que les conditions specifiees ne seront pas remplies, le programme demandera de re-saisir le nom



	do//boucle "faire ... tant que", cette boucle permet d'encoder le prenom du client
	{
		system("cls");
		printf("veuillez entrer le pr%cnom du nouveau client\n",130);
		printf("1caract%cre minimum, 30 caract%cres maximum et uniquement en majuscules\n",138,138);

		gets(temp);								//Stockage dans temp
		if(strlength(temp) <= 30){				//Si longueur <= a 30 alors copie temp dans cA.nom
			stringcopy(temp, cA.prenom);
		}
		else{
			printf("\nle pr%cnom est trop long",130);
			system("pause");
		}

	}
	while(verifprenom(cA.prenom)!=1 || cA.prenom[0]=='\0');//tant que les conditions specifiees ne seront pas remplies, le programme demandera de re-saisir le prenom

	do//boucle "faire ... tant que", cette boucle permet d'encoder le numero de compte du client
	{
		system("cls");
		printf("veuillez entrer le num%cro de compte du nouveau client\n",130);
		printf("le num%cro de comprte s'encode comme suit : BEXX XXXX XXXX XXXX\n",130);
		gets(cA.num_compte);//permet de stocker le numero de compte dans la structure clientA, dans le tableau num_compte

	}
	while(verifnumcompte (cA.num_compte)!=1 || cA.num_compte[0]=='\0');//tant que les conditions specifiees ne seront pas remplies, le programme demandera de re-saisir le numero de compte

	do//boucle "faire ... tant que", cette boucle permet de reencoder la date de naissance et le numero de registre nationnal si la verification de concordance (date naissance, registre nationnal) du client n'est pas bonne
	{
		do//boucle "faire ... tant que", cette boucle permet d'encoder la date de naissance du client
		{
			system("cls");
			printf("veuillez entrer la date de naissance du nouveau client.\n");
			printf("la date de naissance s'encode comme suit : jj/mm/aaaa\n");
			gets(cA.datenaiss);//permet de stocker la date de naissance dans la structure clientA, dans le tableau datenaiss

		}
		while(verifdatenaiss(cA.datenaiss)!=1 || cA.datenaiss[0]=='\0');//tant que les conditions specifiees ne seront pas remplies, le programme demandera de re-saisir la date de naissance


		do//boucle "faire ... tant que", cette boucle permet d'encoder le numero de registre national du client
		{
			system("cls");
			printf("veuillez entrer le num%cro de registre nationnal du nouveau client\n",130);
			printf("le num%cro de registre nationnal s'encode comme suit : aammjj-XXX-XX\n",130);
			gets(cA.num_reg_nat);//permet de stocker le numero de registre national dans la structure clientA, dans le tableau num_reg_nat

		}
		while(cA.num_reg_nat[0] == '\0'||verifNumRegNat(cA.num_reg_nat)!=1 );//tant que les conditions specifiees ne seront pas remplies, le programme demandera de re-saisir le numero de registre national
	}
	while(compatibildatenaissregnat(cA.datenaiss, cA.num_reg_nat)!=1);//tant que les conditions specifiees ne seront pas remplies, le programme demandera de re-saisir la date de naissance et le numero de registre national

	return cA;
}


struct clientB encodenouvclientB(void)//fonction encodenouvclientB, fonction permettant d'encoder des clients pour la banque B et de stocker les informations dans la structure de type client B nomee cB
{

	fflush(stdin);//permet de vider la memoire tampon

	do//boucle "faire ... tant que", cette boucle permet d'encoder le nom du client
	{
		system("cls");
		printf("Veuillez entrer le nom du nouveau client\n");

		gets(temp);								//Stockage dans temp
		if(strlength(temp) <= 30){				//Si longueur <= a 30 alors copie temp dans cA.nom
			stringcopy(temp, cB.nom);
		}
		else{
			printf("\nle nom est trop long");
			system("pause");
		}


	}
	while(verifnom(cB.nom)!=1 || cB.nom[0]=='\0');//tant que les conditions specifiees ne seront pas remplies, le programme demandera de re-saisir le nom




	do//boucle "faire ... tant que", cette boucle permet d'encoder le prenom du client
	{
		system("cls");
		printf("Veuillez entrer le pr%cnom du nouveau client\n",130);

		gets(temp);								//Stockage dans temp
		if(strlength(temp) <= 30){				//Si longueur <= a 30 alors copie temp dans cA.nom
			stringcopy(temp, cB.prenom);
		}
		else{
			printf("\nle pr%cnom est trop long",130);
			system("pause");
		}

	}
	while(verifprenom(cB.prenom)!=1 || cB.prenom[0]=='\0');//tant que les conditions specifiees ne seront pas remplies, le programme demandera de re-saisir le prenom




	do//boucle "faire ... tant que", cette boucle permet d'encoder la date naissance du client
	{
		system("cls");
		printf("Veuillez entrer la date de naissance du nouveau client.\n");
		printf("la date de naissance s'encode comme suit : jj/mm/aaaa\n");
		gets(cB.datenaiss);//permet de stocker la date de naissance dans la structure clientB, dans le tableau date de naissance

	}
	while(verifdatenaiss(cB.datenaiss)!=1 || cB.datenaiss[0]=='\0');//tant que les conditions specifiees ne seront pas remplies, le programme demandera de re-saisir la date de naissance

	return cB;

}

void stringcopy(char* source, char* destination){

	int i;

	for(i=0; i <= strlength(source); ++i){  //Tant que le caractere de fin de chaine n'est pas atteint

		destination[i] = source[i];			//Le caractere source est copie dans le caractere de destination

	}


}


void structclientAcopy(struct clientA source, struct clientA *destination){  //Copie les infos clientA de la source vers la destination

	destination->numero = source.numero;						

	stringcopy(source.nom, destination->nom);
	stringcopy(source.prenom, destination->prenom);
	stringcopy(source.datenaiss, destination->datenaiss);
	stringcopy(source.num_compte, destination->num_compte);
	stringcopy(source.num_reg_nat, destination->num_reg_nat);


}

void structclientBcopy(struct clientB source, struct clientB *destination){	 //Copie les infos clientB de la source vers la destination

	stringcopy(source.nom, destination->nom);
	stringcopy(source.prenom, destination->prenom);
	stringcopy(source.datenaiss, destination->datenaiss);

}



int stringcomp(char *chaineA, char* chaineB)   //Fonction qui compare les differentes chaine de caract
{
	int i=0;
	while (chaineA[i]!='\0'&&chaineB[i]!='\0')		//Tant que la chaineA ou la chaine B n'est pas terminee
	{
		if (chaineA[i] > chaineB[i])				//Si le caractere de la chaine A est après dans l'ordre alphabetique

		{
			return -1 ;								//Alors retourne -1 (A est après B)
		}
		else if(chaineA[i]<chaineB[i])				//Si le caractere de la chaine A est avant dans l'ordre alphabetique
		{
			return 1 ;								//Alors retourne 1 (A est avant B)
		}
		i++;										//Passe au caractere suivant
	}
	if(strlength(chaineA) == strlength(chaineB))	//Si la longueur est egale
	{
		return 0 ;									// alors retourne 0 (chaine egale)
	}
	else if(strlength(chaineA) < strlength(chaineB))//Si la chaine A est plus petite que B
	{
		return 1;									//alors retourne 1 (A est avant B)
	}
	else
	{
		return -1;									//Sinon retourne -1 (A est après B)
	}
}

void trinom(struct clientA source[],int size)   //fonction qui tri les chaine de caract envois comme parametre le tableau Ã  trier et la taille de celui-ci
{
	int temp=0;
	int tri=faux; // on initialise que tri = faux pour pouvoir rentrer dans la boucle
	int i=0;
	while (tri==faux) //tant que le tri n'est pas realise on rentre dans la boucle

	{
		tri=vrai;// on inialise tri a vrai car si infine on ne rentre pas dans la condition, c'est que le tri est realiser et on sort de la boucle while
		for(i=0;i<size-1;i++)
		{
			if (stringcomp(source[i].nom, source[i+1].nom)==-1) // dans la condition on comparer deux chaines de caracteres si c'est egale Ã  - le tri n'est pas fait
			{													// et on inverse les cases du tableau de structure pour mettre le plus petit par ordre alphabetique Ã  gauche
				struct clientA temp = source[i];				//creation d'un tableau de structure temporaire pour placer les element Ã  trier!!!
				source[i] = source [i+1];
				source [i+1] = temp;
				tri = faux;
			}
		}
	}
}



void tri_numero(struct clientA source[] ,int n) //envois Ã  la fonction le tableau de struc clientA Ã  trier et le nombre de case Ã  trier
{
	int i=0,temp,tri=faux,pos=n-1; // initialisation des differentes variables

	while(tri==faux) //tant que le tri n'est pas realise on rentre dans la boucle
	{
		tri=vrai; // on inialise tri a vrai car si infine on ne rentre pas dans la condition, c'est que le tri est realiser et on sort de la boucle while
		for(i=0;i<pos;i++)// boucle permetant de circuler dans le tableau
		{
			if(source[i].numero>source[i+1].numero)//condition pour comparer deux case du tableau pour voir si c'est trier ou non
			{
				struct clientA temp=source[i];             //le temp est une structure temporaire clientA, dans les cases ci-dessous nous inverson les case du tableau
				source[i]=source[i+1];						//pour envoyer le plus petit numeros Ã  la gauche du tableau
				source[i+1]= temp;
				tri=faux;								//montre que le tri a eu lieux donc que le tableau n'etait pas encore trie ce qui permet de rentrer dans la boucle
				pos=i;									//on incremente la position pour ne plus devoir checker tout le tableau
			}
		}
	}
}

void copyfileA(char*nom,int nb,struct clientA *destination)//fonction qui permet de copier les informations contenues dans les tableaux de structures sourceA,trinomA,trinumA,  vers les fichiers sourceA,trinomA,trinumA
{
	FILE*fp=NULL;
	struct clientA sourceA[nb];
	fp = fopen(nom,"ab");
	if(fp==NULL)
	{
		printf("erreur ouverture fichier!\n");
		system("pause");
	}
	else
	{

		fwrite(destination,112,nb,fp);

		if(fclose(fp))
		{
			printf("Erreur fermeture fichier.\n");
			system("pause");
		}
	}
}


void copyfileB(char*nom,int nb,struct clientB *destination)//fonction qui permet de copier les informations contenues dans le tableau de  structre sourceB vers le fichier sourceB
{
	FILE*fp=NULL;
	struct clientB sourceB[nb];
	fp = fopen(nom,"ab");
	if(fp==NULL)
	{
		printf("erreur ouverture fichier!\n");
		system("pause");
	}
	else
	{

		fwrite(destination,73,nb,fp);

		if(fclose(fp))
		{
			printf("Erreur fermeture fichier.\n");
			system("pause");
		}
	}
}

void copyfileCom(char*nom,int nb,struct clientB *destination)//fonction qui permet de copier les informations contenues dans le tableau de structre clients_commun vers le fichier clients_commun
{
	FILE*fp=NULL;
	struct clientB sourceB[nb];
	fp = fopen(nom,"wb+");
	if(fp==NULL)
	{
		printf("erreur ouverture fichier!\n");
		system("pause");
	}
	else
	{

		fwrite(destination,73,nb,fp);

		if(fclose(fp))
		{
			printf("Erreur fermeture fichier.\n");
			system("pause");
		}
	}
}


void readfile(char *nom,struct clientA sourceA[],struct clientB sourceB[], int *nbc)//fonction qui permet de lire les informations contenue dans les fichiers sourceA, trinomA, trinumA, sourceB et clients_commun
{

	int nb,i;
	FILE*fp=NULL;
	fp = fopen(nom,"r");
	if (fp==NULL)
	{
		printf("erreur ouverture fichier!\n");
		system("pause");
	}
	else
	{


		if(sourceA != NULL)
		{
			fseek(fp,0,SEEK_END);
			nb = ftell (fp)/112;
			*nbc = nb;

			struct clientA source[nb];
			fseek(fp,0,SEEK_SET);

			fread(sourceA,112,nb,fp);
			for (i=0;i<nb;i++)
			{

				printf("Num%cro du client %d : %d  .\n",130,i+1,sourceA[i].numero);
				printf("Nom de la personne %d : %s .\n",i+1,sourceA[i].nom);
				printf("Pr%cnom de la personne %d : %s .\n",130,i+1,sourceA[i].prenom);
				printf("Date de naissance de la personne %d : %s .\n",i+1,sourceA[i].datenaiss);
				printf("Numero de compte de la personne %d : %s .\n",i+1,sourceA[i].num_compte);
				printf("Numero de registre national de la personne %d : %s .\n",i+1,sourceA[i].num_reg_nat);

			}

		}
		else
		{
			fseek(fp,0,SEEK_END);
			nb=ftell (fp)/73;
			*nbc = nb;
			struct clientB source[nb];
			fseek(fp,0,SEEK_SET);
			fread(sourceB,73,nb,fp);
			for (i=0;i<nb;i++)
			{

				printf("Pr%cnom de la personne %d : %s .\n",130,i+1,sourceB[i].prenom);
				printf("Nom de la personne %d : %s .\n",i+1,sourceB[i].nom);
				printf("Date de naissance de la personne %d : %s .\n",i+1,sourceB[i].datenaiss);
			}
		}

	}


	if(fclose(fp))
	{
		printf("Erreur fermeture fichier.\n");
		system("pause");
	}


}


void recherchedicho(struct clientA trinA[],int nbCa,struct clientB B[], int nbCb, struct clientB Communs[], int *nbCcom)//fonction qui recherche un nom dans un tableau triee pour les nom
{ //envois des parametres tableau clientA trie (trinomA), le nbr de client A, le tableau client B, le nbr client B, creation du tableau clientB/A commun et nbr en commun

	int j;

	for(j=0;j<nbCb;++j){ //permet la circulation dans le tableau

		int i,bg=0,bd=nbCa-1, nomtrouve=faux; //mise en place des variables, bg : borne de gauche du tableau (le premier par ordre alphab, bd borne droite

		while(nomtrouve==faux && bg <= bd)//tant qu'on n'a pas trouvé la valeur et qu'on n'a pas fouillée tout le tableau
		{
			i=(bg+bd)/2; //permet de diviser le tableau en deux et ne controler q'un demi tableau a  la foix
			if(stringcomp(trinA[i].nom,B[j].nom) == -1) // regarde si le nom du tableau B se trouve dans le tableau A trie si renvois -1 il ne se trouve pas du cote droite du tab

				bd = i-1; // on diminue la borne de doite pour diminuer le tableau
			else if(stringcomp(trinA[i].nom,B[j].nom) == 1)//si la comparaison renvois 1, il ne se trouve pas dans la partie gauche, donc on diminuer le tableau via la gauche
				bg = i+1; // on augmente la borne de gauche pour diminuer le tableau

			else

			{
				nomtrouve = vrai; // si la comparaison ne renvois pas -1 ou 1 c'est que le nom est trouve


			}

		}

		if(nomtrouve == vrai && stringcomp(trinA[i].prenom,B[j].prenom) == 0 && stringcomp(trinA[i].datenaiss,B[j].datenaiss) == 0) { //une fois le nom trouve
			//on compare les prenom et les dates de naissance si sa renvois 0 c'est que le client est commun au deux banque
			*nbCcom += 1; //incremente le nombre de client commun trouve
			structclientBcopy(B[j], &Communs[*nbCcom-1]); //on copie les informations du client commun dans le tableau de client commun

		}

	}






}




main(){

	int nbClientA = 0, nbClientB = 0, nbClientCom = 0, i;
	char g;
	int menu;
	int code;
	char sousMenu1;
	char sousMenu2;


	struct clientA sourceA[M];
	struct clientA trinumA[M];
	struct clientA trinomA[M];

	struct clientB sourceB[P];
	struct clientB clients_communs[P];




	do     /*Affichage du menu principal*/
	{
		system("cls");
		printf ("======\n");     
		printf (" Menu \n");
		printf ("======\n\n");
		printf ("1. ENCODER\n");
		printf ("2. RECHERCHE COMMUNS\n");
		printf ("3. LIRE\n");
		printf("\n Entrer un nombre compris entre 1 et 3 \n");
		scanf("%d", &menu);
		//Les lignes ci-dessus composent le menu

		switch(menu)
		{
		case 1 :
			printf("Vous avez choisi ENCODER\n");

			printf("a. Banque A\n");
			printf("b. Banque B\n");
			fflush(stdin);
			scanf("%c", &sousMenu1);
			code = (int)sousMenu1;

			switch(sousMenu1)
			{
			case 97 :
				do{
					printf("Interface d'encodage des clients A\n");
					printf("--------------------------------\n");
					printf("\nCombien de client(s) de la banque A souhaitez-vous encod%c ? ", 130);
					scanf("%d", &nbClientA);
					if(nbClientA>M) {
						printf("\nErreur ! Le nombre doit etre inf%rieur ? %d", M);
					}
				} while(nbClientA>M);

				for(i=0; i<nbClientA; ++i){
					system("cls");
					printf("Interface d'encodage des clients\n");
					printf("--------------------------------\n");
					cA = encodenouvclientA();
					structclientAcopy(cA, &sourceA[i]);
					structclientAcopy(cA, &trinumA[i]);
					structclientAcopy(cA, &trinomA[i]);

				}
				trinom(trinomA,nbClientA);
				tri_numero(trinumA, nbClientA);
				copyfileA("sourceA",nbClientA,sourceA);
				copyfileA("trinomA",nbClientA,trinomA);
				copyfileA("trinumA",nbClientA,trinumA);
				break;
			case 98 :
				do{
					printf("Interface d'encodage des clients B\n");
					printf("--------------------------------\n");
					printf("\nCombien de client(s) de la banque B souhaitez-vous encod%c ? ", 130);
					scanf("%d", &nbClientB);
					if(nbClientB>P) {
						printf("\nErreur ! Le nombre doit etre inf%Drieur ? %d",130, P);
					}
				} while(nbClientB>P);

				for(i=0; i<nbClientB; ++i){
					system("cls");
					printf("Interface d'encodage des clients B\n");
					printf("--------------------------------\n");

					cB = encodenouvclientB();
					structclientBcopy(cB, &sourceB[i]);


				}

				copyfileB("sourceB", nbClientB, sourceB);
				break;
			default : printf("Veuillez choisir exclusivement a ou b en minuscule");
			break;
			}break;
			case 2 :	
				readfile("trinomA",trinomA,NULL, &nbClientA);
				readfile("sourceB",NULL,sourceB, &nbClientB);
				recherchedicho(trinomA, nbClientA,sourceB, nbClientB, clients_communs, &nbClientCom);

				printf("\n\nNombre de clients communs trouves : %d\n", nbClientCom);
				copyfileCom("clients_communs", nbClientCom, clients_communs);
				nbClientCom = 0;
				system("pause");

				break;
			case 3:
				printf("LIRE\n");

				printf("a. Banque A\n");
				printf("b. Banque B\n");
				printf("c. Clients Communs\n");
				fflush(stdin);
				scanf("%c", &sousMenu2);
				code = (int)sousMenu2;

				switch(sousMenu2)
				{
				case 97 :
					printf("\nSource A \n");
					readfile("sourceA",sourceA,NULL, &nbClientA);
					printf("\nTrinom A \n");
					readfile("trinomA",trinomA,NULL, &nbClientA);
					printf("\nTrinum A \n");
					readfile("trinumA",trinumA,NULL, &nbClientA);
					break;
				case 98 :
					printf("\nSource B \n");
					readfile("sourceB",NULL,sourceB, &nbClientB);
					break;
				case 99 :
					printf("\nCommuns B \n");
					readfile("clients_communs",NULL,clients_communs, &nbClientCom);
					break;
				default : printf("Veuillez choisir exclusivement a ou b en minuscule");
				break;
				}
				break;
				default : printf("Veuillez encoder uniquement un numero valide");
				break;


		}



		fflush(stdin);
		printf ("Voulez-vous retourner au menu principal ? \n Entrez 'y' pour oui et 'n' pour non\n");
		scanf("%c",&g);
	}
	while(g=='y'||g=='Y');     /*Tant que l'utilisateur choisi yes pour retourner au menu principal*/

	system("pause");

	// Exemple de test réalisés sur les tableaux de structures pour vérifier leur contenu

	//    for (i=0;i<nbClientB;i++)
	//        {
	//         	printf("\nSourceB :\n");
	//			puts(sourceB[i].prenom);
	//			puts(sourceB[i].nom);
	//			puts(sourceB[i].datenaiss);
	//
	//			printf("\nCommunsB :\n");
	//			puts(clients_communs[i].prenom);
	//			puts(clients_communs[i].nom);
	//			puts(clients_communs[i].datenaiss);
	//        }
	//
	//     for (i=0;i<nbClientCom;i++)
	//        {
	//			printf("\nCommunsB :\n");
	//			puts(clients_communs[i].prenom);
	//			puts(clients_communs[i].nom);
	//			puts(clients_communs[i].datenaiss);
	//        }
	//
	//
	//
	//
	//	for(i=0; i<nbClientA; ++i)	{
	//
	//		printf("\nSource :\n%d\n", sourceA[i].numero);
	//		puts(sourceA[i].prenom);
	//		puts(sourceA[i].nom);
	//		puts(sourceA[i].datenaiss);
	//		puts(sourceA[i].num_compte);
	//		puts(sourceA[i].num_reg_nat);
	//
	//		printf("\nTrinum :\n%d\n", trinumA[i].numero);
	//		puts(trinumA[i].prenom);
	//		puts(trinumA[i].nom);
	//		puts(trinumA[i].datenaiss);
	//		puts(trinumA[i].num_compte);
	//		puts(trinumA[i].num_reg_nat);
	//
	//		printf("\nTrinom :\n%d\n", trinomA[i].numero);
	//		puts(trinomA[i].prenom);
	//		puts(trinomA[i].nom);
	//		puts(trinomA[i].datenaiss);
	//		puts(trinomA[i].num_compte);
	//		puts(trinomA[i].num_reg_nat);
	//
	//
	//
	//
	//	}


}
