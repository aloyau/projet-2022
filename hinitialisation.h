#include<stdio.h>

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

void minedropper(Case* table, int size, int minenumber);

int confirmmarkCase(Case* table, int size, int abscisse, int ordonnee, int ab, int ord);

void markCase(Case* table, int size);

void indicationdropper(Case* table, int size);



Case* initable(int size, int minenumber);

