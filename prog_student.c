#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(){

	LE etudiant   = nouveau_ListeEtudiant();	// Création d'une liste vide
	Info info[50]; 					// Information supplémentaire de l'étudiant
	
	FILE *fichier = fopen("Students.csv", "r");	// Fichier contenant la liste de l'élève
	int ligne = 41;
	ligne = nombre_de_ligne(fichier, "Students.csv");
	
	for(int i = 0; i < ligne; i++){
		info[i] = (Info)malloc(sizeof(InfoStudent));
		if(info[i] == NULL){
			fprintf(stderr, "Erreur alloc");
		}
	}
	
	size_t taille = 0;
	
	/*
		Information sur l'étudiant
	*/
	char *nom = malloc(sizeof(char) * 100);
	char *prenom = malloc(sizeof(char) * 100);
	char *date_de_naissance = malloc(sizeof(char) * 100);
	
	/*
		Autre information sur l'étudiant
	*/
	char *adresse = malloc(sizeof(char) * 100);
	char *telephone = malloc(sizeof(char) * 100);
	char *genre = malloc(sizeof(char) * 10);
	char *parcours = malloc(sizeof(char) * 50);
	
	int i = 0; 	// Compteur de ligne du fichier contenant la liste
	
	/*
		Récupération des informations des élèves dans la liste chainée
	*/
	char *all_lines = NULL;
	while(i < ligne){
		getline(&all_lines, &taille, fichier);
		char *token = strtok(all_lines, ",");
		// Nom
		if(token){
			strcpy(nom, token);
			token = strtok(NULL, ",");
		}
		
		// Prénoms
		if(token){
			strcpy(prenom, token);
			token = strtok(NULL, ",");
		}
		
		// Date de naissance
		if(token){
			strcpy(date_de_naissance, token);
			token = strtok(NULL, ",");
		}
		
		// Adresse
		if(token){
			strcpy(adresse, token);
			token = strtok(NULL, ",");
		}
		
		// Telephone
		if(token){
			strcpy(telephone, token);
			token = strtok(NULL, ",");
		}
		
		// Genre
		if(token){
			strcpy(genre, token);
			token = strtok(NULL, ",");
		}
		
		// Parcours
		if(token){
			strcpy(parcours, token);
			token = strtok(NULL, ",");
		}
		info[i] = add_info(info[i], adresse, telephone, genre, parcours);	// Récuperation des autres informations des étudiants
		etudiant = ajouter_etudiant_fin(etudiant, nom, prenom, date_de_naissance, info[i]);	// Ajout des étudiants dans la liste chaînée
		i++;
		
	}
	afficher_ListeEtudiant(etudiant);	// Affichage de la liste contenant les informations des étudiants
	/*
		Triage de la liste des étudiants par ordre alphabétique
	*/
	trier("Students.csv", "New_list.csv", "n");	// Création du fichier trié de la liste
	
	// Libération des ressources
	free(nom);
	free(prenom);
	free(date_de_naissance);
	
	free(adresse);
	free(telephone);
	free(genre);
	free(parcours);
	
	fclose(fichier);
	
	return 0;
}

