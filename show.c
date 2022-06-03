

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//header inclus:
#include "hshow.h"

//#include "hstruct.h"

#define SIZE 1

char* translate_int(int num){ //transforme un unt en une chaîne char, il faut faire un free
	
	char* word=NULL;
	char letter;
	char number = 1;
	//int power;
	
	letter=0;
		
	if(number<0){
		word= malloc(2* sizeof(char));
		*word= '-' ;
		word++;
		letter=48 + num;
		*word=letter;
		word= word-1;
		return(word);
	}
	
	else{
	word = malloc(sizeof(char));
	letter=48 + num;
	*word=letter;
	return(word);
	}
}

char* affectation_char1(char* point, int size, char* content){
	point = malloc(size * sizeof(char));
	*point = *content;
	return(point);	
}

//return ce que doit montrer sur la case entre caché marqué 
// ou le nombre de mine à proximité.
char* whatIshow(Case square){ 
	char* content;
	
	if(square.discover == -1){
		affectation_char1(content, SIZE, " ");
	}
	else if(square.discover == 0){
		affectation_char1(content, SIZE, "P");
	}
	else if(square.discover == 1){
		content = translate_int(square.status);
	}
	else{
		affectation_char1(content, SIZE, "R");
	}
	return(content);
}

void showgame( Case* plate, int size){
	
	char letter = 'A';
	int y;
	int i;
	char number = 1;
	printf("   ");
	for(i=0 ; i< size ; i++){
		printf("%c ", letter);
		letter++;
	}
	printf("\n");
	
	for(i=0; i< size ; i++){
		if(i<9){
		printf("%c ", number);
		number++;
		}
		else if (i < 19){
			
		
			
		}
		for (y = 0; y<size ; y++){
			printf("|%s", whatIshow(*plate));
			free(whatIshow(*plate));
			printf("| \n");
		}
	}
}



