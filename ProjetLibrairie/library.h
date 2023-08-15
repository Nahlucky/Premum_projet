#ifndef LIBRARY_H
#define LIBRARY_H

typedef enum{
	true, 
	false
}Bool;

typedef struct InfoBook{
/*
	Données sur le livre empreinté
*/
	char titre[50];
	char type[50];
	char edition[50];
	char auteur[50];

}InfoBook, *Book;

typedef struct ListeEtudiant{
/*
	Profil de l'empreinteur
*/
	char nom[50];
	char prenoms[50];
	char classe[20];
	int  numero;
	
	struct InfoBook *book;
	struct ListeEtudiant *next;

}ListeEtudiant, *LE;


Book add_book(Book new_book, char *titre, char *type, char *edition, char *auteur);
//----------------------------------------------------//
int is_ListeEtudiant_empty(LE etudiant);
LE nouveau_ListeEtudiant();
void afficher_ListeEtudiant(LE etudiant);
int longueur_de_la_liste(LE etudiant);
LE ajouter_etudiant_fin(LE etudiant, char *anarana, char *fanampiny, char *kilasy, int laharana, Book book);
LE ajouter_etudiant_debut(LE etudiant, char *anarana, char *fanampiny, char *kilasy, int laharana, Book book);
LE retirer_etudiant_debut(LE etudiant);
LE retirer_etudiant_fin(LE etudiant);
LE retirer_etudiant_select(LE etudiant, int numero, char *livre);

#endif
