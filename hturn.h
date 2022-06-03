#include<stdio.h>
#include<stdlib.h>

//headers inclus:
#ifndef HMAIN
	#define HMAIN
	#include "headermain.h"
#endif

/*#ifndef HSTRUCT
	#define HSTRUCT
	#include "hstruct.h"
#endif

*/

void recurseCase(int abscisse, int ordonnee, Case* plate, int size);

void lineconfirm(Case* plate , int abscisse, int ordonnee, int size);

int  selectionCase(int abscisse, int ordonnee, Case* plate, int size);

