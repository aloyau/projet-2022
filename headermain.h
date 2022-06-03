



//header inclus:

#define HMAIN

//à chaque ds condition si on doit inclure le point h si il est déjà inclus alors il ne sera pas rappeler


//definition des tailles standard de terrain
#define SMALL 9
#define BIG 16
#define DIFICULT 25


typedef struct{
	int status;
//indique si la case est miné ou pas, -1 miné, 0 aucune mine autour, 1 une mine autour... max 8.
	int discover;
//permet de connaître le statut de la case -1 caché, 0 un marqueur, 1 visible
}Case;

#ifndef HSHOW
	#define HSHOW
	#include "hshow.h" 
#endif


#ifndef HTURN
	#define HTURN
	#include "hturn.h"
#endif


#ifndef HRECORD
	#define HRECORD
	#include "hrecord.h"
#endif

#ifndef HINI
	#define HINI
	#include "hinitialisation.h"
#endif
