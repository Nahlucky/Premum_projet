#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int main(){
/*
	Ceci c'est juste pour tester le fonctionnement du programme
*/

	LE etudiant   = nouveau_ListeEtudiant();
	Book naruto   = malloc(sizeof(*naruto));
	Book bluelock = malloc(sizeof(*bluelock));
	char *n = (char*)malloc(sizeof(char)*50); strcpy(n, "Naruto");
	char *b = (char*)malloc(sizeof(char)*50); strcpy(b, "BlueLock");
	int longueur = 0;

	// Liste des livres dans la bibliothèque
	naruto = add_book(naruto , n, "Manga", "Past Generation", "Toriama");
	bluelock = add_book(bluelock, b, "Manga", "New Chapter", "Unknow");

	// Les étudiants qui ont empreinter des livres
	etudiant = ajouter_etudiant_fin(etudiant, "Rabesoa", "Onja", "L1 (MATH)", 3, bluelock);
	etudiant = ajouter_etudiant_fin(etudiant, "Randrianantenaina", "Hajatiana Michelas", "L1 (MIT)", 29, naruto);
	etudiant = ajouter_etudiant_fin(etudiant, "Razanadratsara", "Lucky Kaiser Sahel", "L1 (MIT)", 38, naruto);
	etudiant = ajouter_etudiant_fin(etudiant, "Andrianasolo", "Miharisoa Jedidia", "L1 (MIT)", 5, naruto);
	etudiant = ajouter_etudiant_debut(etudiant, "Hajaniriana", "Heritina", "L1 (MIT)", 9, bluelock);
	etudiant = retirer_etudiant_select(etudiant, 9, b);
	//etudiant = retirer_etudiant_select(etudiant, 38, n);
	longueur = longueur_de_la_liste(etudiant);
	
	// Affichage de la liste des étudiants avec les livres empreinter
	afficher_ListeEtudiant(etudiant);
	printf("la longueur de la liste est: %d\n", longueur);
	
	free(etudiant);
	
	return 0;
}
