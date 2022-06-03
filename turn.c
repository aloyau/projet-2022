#include<stdio.h>
#include<stdlib.h>

//header inclus:
//#include "hstruct.h"
#include "hturn.h"

void recurseCase(int abscisse, int ordonnee, Case* plate, int size);

//le terrain va de 0 à size -1 il faut faire attention entre la saisie et ce qu'on met dans le fonction il faut lui soustraire1

//procédure qui permet de verifier si les coordonné sont valides pour la récursivité
void lineconfirm(Case* plate , int abscisse, int ordonnee, int size){ 
	if(abscisse < size && abscisse >= 0 && ordonnee < size && ordonnee >= 0){
		recurseCase( abscisse, ordonnee, plate, size);
	}
	return;
}



// a finir fonction qui met les cases vide en visible attention à ordonnee et abscisse doivent avoir -1 pour correspondrent sur le tableaux.
void recurseCase(int abscisse, int ordonnee, Case* plate, int size){
	plate = plate + abscisse + ordonnee * size;
	
	if((*plate).discover == 1){
		plate = plate - abscisse - ordonnee * size;
		return;
	}
	(*plate).discover = 1;
	if((*plate).status != 0){
		plate = plate - abscisse - ordonnee * size;
		return;
	}
	plate = plate - abscisse - ordonnee * size; //on effectue la récursivité sur chaque case à proximité
	lineconfirm(plate , abscisse-1, ordonnee-1, size);
	lineconfirm(plate , abscisse, ordonnee-1, size);
	lineconfirm(plate , abscisse+1, ordonnee-1, size);
	lineconfirm(plate , abscisse-1, ordonnee, size);
	lineconfirm(plate , abscisse+1, ordonnee, size);
	lineconfirm(plate , abscisse-1, ordonnee+1, size);
	lineconfirm(plate , abscisse, ordonnee+1, size);
	lineconfirm(plate , abscisse+1, ordonnee+1, size);
}

// la fonction effectue une action de sur la case qui est de la découvrir et elle s'appelle de manière récursive pour toute une zone. Il faut au début remettre le pointeur sur la première case du terrain
int  selectionCase(int abscisse, int ordonnee, Case* plate, int size){
	Case* initial = NULL;
	plate = plate + abscisse + ordonnee * size;
	
	if((*plate).status == -1){  //le joueur à perdu
		plate = initial ;
		return(0);
	}
	
	if((*plate).status > -1){
		recurseCase( abscisse, ordonnee, plate, size);
		plate = initial ; 
		return(1);
	}	


}

void sign_Case(int abscisse, int ordonnee, Case* plate, int size){
	
}
