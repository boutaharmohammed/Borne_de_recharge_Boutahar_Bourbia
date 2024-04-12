#include  <stdio.h>
#include "timer.h"
#include <iostream>


int depart_timer;

void timer_initialiser()
{
	io=acces_memoire(&shmid);
	/* associe la zone de memoire partagee au pointeur */
	if (io==NULL) std::cout<<"Erreur pas de mem sh\n" <<std::endl;
	depart_timer=io->timer_sec;
}

int timer_valeur(){
	int temps =io->timer_sec-depart_timer;
	return temps;
}
