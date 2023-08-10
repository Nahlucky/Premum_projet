#ifndef LIBRARY_H
#define LIBRARY_H

typedef enum{
	true, 
	false
}Bool;

typedef struct InfoStudent{
/*
	Données sur le livre empreinté
*/
	char adresse[50];
	char telephone[50];
	char genre[50];
	char parcours[50];

}InfoStudent, *Info;

typedef struct ListeEtudiant{
/*
	Profil de l'empreinteur
*/
	char nom[50];
	char prenom[50];
	char date_de_naissance[20];
	
	struct InfoStudent *info;
	struct ListeEtudiant *next;

}ListeEtudiant, *LE;


Info add_info(Info new_info, char *adresse, char *telephone, char *genre, char *parcours);
//----------------------------------------------------//
int is_ListeEtudiant_empty(LE etudiant);
LE nouveau_ListeEtudiant();
void afficher_ListeEtudiant(LE etudiant);
LE ajouter_etudiant_fin(LE etudiant, char *anarana, char *fanampiny, char *daty_nahaterahana, Info info);
int nombre_de_ligne(FILE *fichier, char *chemin);
void trier(char *fichier_a_ouvrir, char *fichier_de_destination, char *mode);

#endif
