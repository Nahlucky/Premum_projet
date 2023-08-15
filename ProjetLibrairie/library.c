#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

/*
Fonction pour remplir une structure de livre (Book)
Elle prend en paramètre ( 5 ):
	- Un pointeur vers une structure de livre [ InfoBook * ]
	- Titre du livre [ char * ]
	- Type du livre [ char * ]
	- Edition du livre [ char * ]
	- Auteur du livre [ char * ]
	
Elle renvoie: La structure de livre [ InfoBook * ] rempli
*/
Book add_book(Book new_book, char *titre, char *type, char *edition, char *auteur){
	strcpy(new_book->titre, titre);
	strcpy(new_book->type, type);
	strcpy(new_book->edition, edition);
	strcpy(new_book->auteur, auteur);

	return new_book;
}

//-------------------------------------------------------------------//
/*
Fonction pour vérifier si la liste des étudiants est vide ou non
Elle prend en paramètre: un pointeur vers une structure [ ListeEtudiant * ]

Elle retourne:
	- true  : si la liste est vide
	- false : si la liste existe (non vide)
*/
int is_ListeEtudiant_empty(LE etudiant){
	if(etudiant == NULL)
		return true;
	return false;
}

/*
Fonction pour créer une nouvelle liste
Elle retourne la valeur NULL car c'est une liste vide
*/
LE nouveau_ListeEtudiant(){
	return NULL;
}

/*
Fonction pour afficher la liste des étudiants qui sont sur la liste
Affichage:
	1) Profil de l'étudiant
	2) Information sur le livre (document)

Elle prend : un pointeur vers une structure d'étudiant [ ListeEtudiant * ]
*/
void afficher_ListeEtudiant(LE etudiant){
	if(is_ListeEtudiant_empty(etudiant) == true){
		printf("La liste des etudiants est vide!\n");
	}
	else{
		while(etudiant != NULL){
			printf("--------------------------------------------------------------------\n");
			printf("Profil de l'etudiant:\n");
			printf("Nom: %s\nPrenoms: %s\nClasse: %s\nNumero: %d\n\n", etudiant->nom, etudiant->prenoms, etudiant->classe, etudiant->numero);
			printf("Information sur le(s) livre(s):\n");
			printf("Titre: %s\nType: %s\nEdition: %s\nAuteur: %s\n", etudiant->book->titre, etudiant->book->type, etudiant->book->edition, etudiant->book->auteur);
			printf("--------------------------------------------------------------------\n");
			etudiant = etudiant->next;
		}
	}
	
}

/*
Fonction pour compter la longueur d'une liste

Elle prend un pointeur vers une structure de livre [ InfoBook * ], la liste

Elle renvoie la longueur de la liste [ int ]
*/
int longueur_de_la_liste(LE etudiant){
	int longueur = 0;

	while(etudiant != NULL){
		etudiant = etudiant->next;
		longueur++;
	}
	
	return longueur;
}

/*
Fonction pour ajouter un(e) étudiant(e) à la fin de la liste
Elle prend en paramètre:
	- la liste des étudiants ( pointeur vers la structrure ListeEtudiant)
	- Nom de l'étudiant à ajouter [ char * ] 
	- Prenoms de l'étudiant [ char * ]
	- Classe de l'étudiant [ char * ]
	- Numéro de l'étudiant [ int ]
	- Le livre empreunter [ InfoBook * ]
*/
LE ajouter_etudiant_fin(LE etudiant, char *anarana, char *fanampiny, char *kilasy, int laharana, Book book){
	ListeEtudiant *nouveau_etudiant;
	nouveau_etudiant = malloc(sizeof(*etudiant));
	
	if(nouveau_etudiant == NULL){
		fprintf(stderr, "Erreur: allocation dynamique.\n");
	}
	
	strcpy(nouveau_etudiant->nom, anarana);
	strcpy(nouveau_etudiant->prenoms, fanampiny);
	strcpy(nouveau_etudiant->classe, kilasy);
	nouveau_etudiant->numero = laharana;
	nouveau_etudiant->book   = book;
	nouveau_etudiant->next   = etudiant;
	
	return nouveau_etudiant;

}

/*
Fonction pour ajouter un(e) étudiant(e) au début de la liste
Elle prend en paramètre:
	- la liste des étudiants ( pointeur vers la structrure ListeEtudiant)
	- Nom de l'étudiant à ajouter [ char * ] 
	- Prenoms de l'étudiant [ char * ]
	- Classe de l'étudiant [ char * ]
	- Numéro de l'étudiant [ int ]
	- Le livre empreunter [ InfoBook * ]
	
*/
LE ajouter_etudiant_debut(LE etudiant, char *anarana, char *fanampiny, char *kilasy, int laharana, Book book){
	ListeEtudiant *nouveau_etudiant;
	nouveau_etudiant = malloc(sizeof(*etudiant));
	
	if(nouveau_etudiant == NULL){
		fprintf(stderr, "Erreur: allocation dynamique.\n");
	}
	
	strcpy(nouveau_etudiant->nom, anarana);
	strcpy(nouveau_etudiant->prenoms, fanampiny);
	strcpy(nouveau_etudiant->classe, kilasy);
	nouveau_etudiant->numero = laharana;
	nouveau_etudiant->book   = book;
	nouveau_etudiant->next   = nouveau_ListeEtudiant();
	
	if(is_ListeEtudiant_empty(etudiant) == true){
		return nouveau_etudiant;
	}
	
	else{
		ListeEtudiant *tmp = malloc(sizeof(*tmp));
		tmp = etudiant;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = nouveau_etudiant;
		
		return etudiant;
	}
}

/*
Fonction pour supprimer un(e) étudiant(e) au début de la liste
Elle prend en paramètre la liste etudiant [ ListeEtudiant * ]
Et renvoie une nouvelle liste [ ListeEtudiant * ] avec l'élément de début (l'étudiant qui se trouve au début de ma liste) retirer
*/
LE retirer_etudiant_debut(LE etudiant){
	ListeEtudiant *tmp = malloc(sizeof(*tmp));

	tmp = etudiant;
	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = NULL;
	
	return etudiant;
}

/*
Fonction pour supprimer un(e) étudiant(e) à la fin de la liste
Elle prend en paramètre la liste etudiant [ ListeEtudiant * ]
Et renvoie une nouvelle liste [ ListeEtudiant * ] avec l'élément de (l'étudiant qui se trouve à la fin de ma liste) fin retirer
*/
LE retirer_etudiant_fin(LE etudiant){
	ListeEtudiant *tmp = malloc(sizeof(*tmp));

	tmp = etudiant;
	tmp = tmp->next;

	return tmp;
}

/*
Fonction pour supprimer un(e) étudiant(e) séléctionné(e) dans la liste
Elle prend en paramètre:
	- la liste de l'étudiant [ ListeEtudiant ]
	- numéro de l'étudiant [ int ]
	- Le titre du livre empreunter [ char * ]
*/
LE retirer_etudiant_select(LE etudiant, int numero_select, char livre[50]){
	ListeEtudiant *tmp = malloc(sizeof(*tmp));
	int i = 1;
	int longueur_tmp = 0;
	int liste_a_enlever = 0;
	char *temporaire = malloc(sizeof(char)*50);
	
	tmp = etudiant;
	while(i <= longueur_de_la_liste(etudiant)){
		strcpy(temporaire, tmp->book->titre);
		
		if(i == 1 && (tmp->numero == numero_select) && (strcmp(temporaire, livre) == 0)){
			etudiant = retirer_etudiant_fin(etudiant);
			return etudiant;
		}
		
		else if(i != 1 && (tmp->numero == numero_select) && (strcmp(temporaire, livre) == 0)){
			if(tmp->next != NULL){
				tmp = tmp->next;
				break;
			}
			else if(tmp->next == NULL){
				break;
			}
		}
		
		tmp = tmp->next;
		i++;
	}
	
	longueur_tmp = longueur_de_la_liste(tmp);
	if(longueur_tmp == 0){
		fprintf(stderr, "L'eleve numero [ %d ] n'a pas empreunter le livre [ %s ]\n", numero_select, livre);
		return etudiant;
	}
	
	// Allocation dynamique des variables pour stocker chaques éléments de tmp
	Book *book = (Book*)malloc(sizeof(Book) * longueur_tmp);
	char **nom      = (char**)malloc(sizeof(char*) * longueur_tmp);
	char **prenoms  = (char**)malloc(sizeof(char*) * longueur_tmp);
	char **classe   = (char**)malloc(sizeof(char*) * longueur_tmp);
	int *numero     = (int*)malloc(sizeof(int) * longueur_tmp);
	for(int j = 0; j < longueur_tmp; j++){
		*(nom+j)     = (char*)malloc(sizeof(char) * 50);
		*(prenoms+j) = (char*)malloc(sizeof(char) * 50);
		*(classe+j)  = (char*)malloc(sizeof(char) * 50);
	}
	
	// Affectation des données vers les variables correspondantes 
	for(int j = 0; j < longueur_tmp ; j++){
		*(book+j) = tmp->book;
		strcpy(*(nom+j), tmp->nom);
		strcpy(*(prenoms+j), tmp->prenoms);
		strcpy(*(classe+j), tmp->classe);
		*(numero+j) = tmp->numero;
		tmp = tmp->next;
	}
	
	liste_a_enlever = longueur_de_la_liste(etudiant) - i + 1;
	
	
	for(int j = 0; j < liste_a_enlever; j++){
		etudiant = retirer_etudiant_debut(etudiant);
	}
	
	for(int j = 0; j < liste_a_enlever - 1; j++){
		etudiant = ajouter_etudiant_debut(etudiant, *(nom+j), *(prenoms+j), *(classe+j), *(numero+j), *(book+j));
	}
	
	return etudiant;
}
