#include<stdio.h>

#define HRECORD

//headers inclus:
#ifndef HMAIN
	#define HMAIN
	#include "headermain.h"
#endif

int comparetime(long nnew, long old);

void rewrite(FILE* reader, long record);

long recuplong(FILE* reader);
