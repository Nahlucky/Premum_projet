#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define MAX_LINES 500
#define MAX_CHAR 10000

Info add_info(Info new_info, char *adresse, char *telephone, char *genre, char *parcours){
	strcpy(new_info->adresse ,adresse);
	strcpy(new_info->telephone, telephone);
	strcpy(new_info->genre, genre);
	strcpy(new_info->parcours, parcours);

	return new_info;
}

//-------------------------------------------------------------------//
/*
Fonction pour vérifier si la liste des étudiants est vide ou non
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
1) Profil de l'étudiant
2) Information sur le livre (document)
*/
void afficher_ListeEtudiant(LE etudiant){
	if(is_ListeEtudiant_empty(etudiant) == true){
		printf("La liste des etudiants est vide!\n");
	}
	else{
		while(etudiant != NULL){
			printf("--------------------------------------------------------------------\n");
			printf("Profil de l'etudiant:\n");
			printf("Nom: %s\nPrenoms: %s\nDate de naissance: %s\n\n", etudiant->nom, etudiant->prenom, etudiant->date_de_naissance);
			printf("Autre information:\n");
			printf("Adresse: %s\nTel: %s\nGenre: %s\nParcours: %s\n", etudiant->info->adresse, etudiant->info->telephone, etudiant->info->genre, etudiant->info->parcours);
			printf("--------------------------------------------------------------------\n");
			etudiant = etudiant->next;
		}
	}
	
}

/*
Fonction pour ajouter un(e) étudiant(e) à la fin de la liste
*/
LE ajouter_etudiant_fin(LE etudiant, char *anarana, char *fanampiny, char *daty_nahaterahana, Info info){
	ListeEtudiant *nouveau_etudiant;
	nouveau_etudiant = malloc(sizeof(*etudiant));
	
	if(nouveau_etudiant == NULL){
		fprintf(stderr, "Erreur: allocation dynamique.\n");
	}
	
	strcpy(nouveau_etudiant->nom, anarana);
	strcpy(nouveau_etudiant->prenom, fanampiny);
	strcpy(nouveau_etudiant->date_de_naissance, daty_nahaterahana);
	nouveau_etudiant->info = info;
	nouveau_etudiant->next = etudiant;
	
	return nouveau_etudiant;

}

/*
Fonction pour retourner le nombre de ligne dans un fichier
*/
int nombre_de_ligne(FILE *fichier, char *chemin){
	char *tmp = malloc(sizeof(char)*100);
	int ligne = 0;
	fichier = fopen(chemin, "r");
	
	while(fgets(tmp, 100, fichier) != NULL){
			ligne++;
	}
	
	fclose(fichier);
	return ligne;
}

/*
Fonction pour trier le contenu d'un fichier
Les paramètres:
	- "chemins_vers_fichier": indique le chemin vers le fichier à trier
	- "mode": indique le mode de triage | "n": triage selon la valeur numérique de la chaîne
					    | "r": triage renversée
*/
void trier(char *fichier_a_ouvrir, char *fichier_de_destination, char *mode){
	char **liste = (char**)malloc(sizeof(char*)*MAX_LINES);
	for(int i = 0; i < MAX_LINES; i++){
		*(liste+i) = (char*)malloc(sizeof(char)*MAX_CHAR);       
	}
	FILE *fichier_a_trier = fopen(fichier_a_ouvrir, "r+");
	FILE *fichier_triee   = fopen(fichier_de_destination, "w+");
	
	int numero = 0;
	int i = 0, j = 0;
	char *tmp = (char*)calloc(MAX_CHAR, sizeof(char));
	while(fgets(*(liste+numero), MAX_CHAR, fichier_a_trier) != NULL){
		strtok(*(liste+numero), "\n");
		numero++;
	}
	/* Triage normale */
	if(strcmp(mode, "n") == 0){
		while(j <= 100){
			for(i = 0; i < numero - 1; i++){
				if(strcmp(*(liste+i), *(liste+i+1)) > 0 ){
					tmp 	     = *(liste+i);
					*(liste+i)   = *(liste+i+1);
					*(liste+i+1) = tmp;
				}
			}
			j++;
		}
	}
	/* Triage renversé */
	else if(strcmp(mode, "r") == 0){
		while(j <= 100){
			for(i = 0; i < numero - 1; i++){
				if(strcmp(*(liste+i), *(liste+i+1)) < 0 ){
					tmp 	     = *(liste+i);
					*(liste+i)   = *(liste+i+1);
					*(liste+i+1) = tmp;
				}
			}
			j++;
		}
	}
	else{
		printf("mode \"%s\" non reconnu, choisir:\n\"n\": triage normal\n\"r\": triage renversée\n", mode);
		exit(1);
	}
	i = 0;
	/* Insertion des contenus triés dans le fichier */
	while(i < numero){
		fputs(*(liste+i), fichier_triee);
		fputs("\n", fichier_triee);
		i++;
	}
	free(liste);
	fclose(fichier_triee);
	fclose(fichier_a_trier);
}

