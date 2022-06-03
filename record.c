#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int comparetime(long nnew, long old){
	if(nnew < old){
		return(1);
	}
	else{
		return(0);
	}
}

//réecrie la valeur long toujours composer de huit chiffre
void rewrite(FILE* reader, long record){
	int verify = 0 ;
	long tempory = 0 ;
	int numzero = 8 ;
	tempory = record ;
	int i = 0 ;
	char num[8];
	while(tempory >= 10){
		tempory = tempory / 10 ;
		numzero -- ;
	}
	for( i = 0 ; i < numzero ; i++){
		fputs("0", reader);
	}
	
	itoa(record, num, 10);
	
	fputs(num , reader);
	if(verify == 0){
		exit(10);
	}
}
//récupère un long sur dans le fichier la où le pointeur pointe.
long recuplong(FILE* reader){
	char * num = NULL;
	int record;
	fgets(num, 10, reader);
	
	record = strtol(num, NULL, 10);
	
	return(record);
}
	
	
	// à finir qui puisse naviguer entre les records
	
	
	
	
// utiliser strtol et fgets pour extraire la ligne de chiffre et la convertir en nombre

// entre le temps et vérifie si c'est un record si oui le réecrie à une place approprié.
//void 
