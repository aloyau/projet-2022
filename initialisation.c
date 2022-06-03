#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//headers inclus:
//#include "hstruct.h"
#include "hinitialisation.h"



//on remet souvent voir tout le temps le pointeur au point de départ grâace au variable tempory ou initial

// fonction qui place aléatoirement des mine sur le terrain entier avec 
void minedropper(Case* table, int size, int minenumber){
	int num = 0 ;
	int i = 0 ;
	Case* verify = NULL;
	Case* tempory = NULL;
	
	verify = table;
	
	srand(time(NULL));	
	
	while(num <= minenumber){ // on va vérifier plusieurs fois dans la boucle si on ne dépasse pas le nombre de mine et aussi si on ne remet pas de mine sur une autre
		
		for(i = 0 ; i < (size * size) ; i++){
			tempory = table + i;
			
			if((*tempory).status != -1){
				
				while(num <= minenumber){
					
					if((rand() % size) == 1){
						(*tempory).status = -1 ;
						num++ ;
					}
				}
			}
		}
	table = verify ;
	}
	table = verify ;
	
}

//confirme si les coordonne à proximité de la case sont valide et ajoute si il trouve une mine
int confirmmarkCase(Case* table, int size, int abscisse, int ordonnee, int ab, int ord){
	
	if (abscisse < size && abscisse >= 0 && ordonnee < size && ordonnee >= 0){
		
		if((*(table + ab + (ord * size))).status == -1){
			return(1);
		}
	}
	return(0);	
}

//procédure qui attribut le numbre de mine à proximité d'une case	
void markCase(Case* table, int size){
		int verify = 0;
		int y = 0 ;
		int i = 0 ;
		int abscisse = 0 ;
		int ordonnee = 0 ;
		Case* initial = NULL;
		initial = table ;
		do{
			verify = 0 ;
			for(i=0 ; i < size; i++){
				abscisse = 0;
				
				for(y = 0 ; y < size ; i++){
			
					if((*table).status != -1){ // on va vérifier cahque case à coé de celle-ci en vérifiant une par une si il y à une mine 
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, -1, -1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 0, -1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 1, -1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, -1, 0);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 1, 0);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, -1, 1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 0, 1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 1, 1);
					}
					table++ ; // on va sur la prochaine case
					abscisse++ ; // abscisse et ordonnee son des valeurs qui vont servir à verifier si on est toujours sur le terrain
				}
				ordonnee++ ;	
				
				
			}
			
		table = initial;
			for(i = 0 ; i < (size * size) ; i++){
				if((*table).status ==-2){
					verify++ ;
				}
			}
		}while(verify != 0);
	table = initial;
}
	
	
//procédure qui attribut le nombre de mine du terranin complet
void indicationdropper(Case* table, int size){
	Case* initial = NULL;
	int i =0 ;
	initial = table;
	
	for(i = 0; i < (size * size) ; i++){
		markCase(table, size);
	}
	table = initial;
}
	
// cette fonxtion retourne un pointeur Case sur un espace remplie de mine et d'indication prêt à être utiliser	
Case* initable(int size, int minenumber){
	Case* table = NULL;
	table = malloc ( size * size * sizeof(Case));
	minedropper(table, size, minenumber);
	indicationdropper(table, size);
	return(table);
}
