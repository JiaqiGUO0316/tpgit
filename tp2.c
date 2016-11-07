/* Menu du TP 2 - Base de donnees sur des personnes*/
#include<stdio.h>
#include<string.h>
#define N 50

/* Definition du type date (jour, mois, annee) */
typedef struct { int jour, mois, an; } t_date;

/* Definition du type sexe avec la convention INSEE */
typedef enum { homme = 1, femme } t_sexe;

/* Definition du type personne (prenom, sexe, date de naissance) */
typedef struct { char prenom[20] ; t_sexe sexe ; t_date naissance ; } t_personne ;

	
void afficher_base(t_personne* amis, int nb_amis)
{
	int i;
	for(i=0;i<nb_amis;i++)
	{
		printf("%s ",amis[i].prenom);
		if(amis[i].sexe==1)
			printf("homme ");
		else
			printf("femme ");
		printf("%i ",amis[i].naissance.jour);
		printf("%i ",amis[i].naissance.mois);
		printf("%i ",amis[i].naissance.an);
	}
}

void afficher_nombre_fh(t_personne* amis, int nb_amis)
{	
	int i,h=0,f=0;
	for(i=0;i<nb_amis;i++)
	{
		if(amis[i].sexe==1)
			h++;
		else
			f++;
	}
	printf("le nombre d'hommes est %i, le nombre des femmes est %i ",h,f);
}
void afficher_cadet(t_personne* amis, int nb_amis)
{
	int i, i_max;
	t_date d_max = {0, 0, 0};
	for(i=0;i<nb_amis;i++)
	{
		if(amis[i].naissance.an > d_max.an)
		{
			d_max = amis[i].naissance;
			i_max = i;
		}
		else
		{
			if(amis[i].naissance.an == d_max.an && amis[i].naissance.mois > d_max.mois)
			{
				d_max = amis[i].naissance;
				i_max = i;
			}
			else
			{
				if(amis[i].naissance.an == d_max.an && amis[i].naissance.mois == d_max.mois && amis[i].naissance.jour > d_max.jour)
				{
					d_max = amis[i].naissance;
					i_max = i;
				}
			}
		}
	}	
	amis[i_max];
	printf("%s",amis[i_max].prenom);
	
}

void afficher_anniv(t_personne* amis, int nb_amis)
{	
	printf("Ce traitement n'est pas encore disponible\n");
}	

void ajouter_personne(t_personne* amis, int* nb_amis)
{	
	printf("Ce traitement n'est pas encore disponible\n");
}

/* Programme principal */
int main()
{	

	/* Declaration de la base de donnees, de taille maximale 50 et de taille utile nb_amis */
	t_personne amis[N]={{"Elodie",femme,{30,5,1996}}, {"Julien",homme,{8,11,1996}},{"Camille",femme,{2,6,1995}}, {"Adrien",homme,{20,11,1996}},{"Camille",homme,{12,5,1994}}, {"Lise",femme,{5,10,1995}}} ;
	int nb_amis = 6 ;

	int choix;	/* Choix de l'utilisateur */

	do
	{	/* Affichage du menu */
		printf("\nMenu :\n");
		printf(" 1 - Afficher le contenu de la base\n");
		printf(" 2 - Afficher le nombre d'hommes et de femmes\n");
		printf(" 3 - Afficher le prenom de la personne la plus jeune\n");
		printf(" 4 - Afficher les anniversaires d'un prenom\n");
		printf(" 5 - Ajouter une personne\n");
		printf(" 6 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1 : afficher_base(amis,nb_amis); break;
			case 2:  afficher_nombre_fh(amis,nb_amis); break;
			case 3:  afficher_cadet(amis,nb_amis); break;
			case 4:  afficher_anniv(amis,nb_amis); break;
			case 5:  ajouter_personne(amis,&nb_amis); break;
			case 6:  break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}
	while(choix!=6);
	printf("Au revoir !\n");
	return 0;
}

