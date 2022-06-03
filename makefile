all : exec

main.o : main.c headermain.h 
	gcc -c $< -o $@
	
show.o : show.c hshow.h headermain.h 
	gcc -c $< -o $@
	
turn.o : turn.c hturn.h headermain.h
	gcc -c $< -o $@
	
initialisation.o : initialisation.c hinitialisation.h headermain.h
	gcc -c $< -o $@
	
record.o : record.c hrecord.h headermain.h
	gcc -c $< -o $@
	
exec: main.o show.o turn.o initialisation.o record.o
	gcc main.o show.o turn.o initialisation.o record.o exec
