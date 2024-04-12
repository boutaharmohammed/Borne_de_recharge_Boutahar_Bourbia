
#include <stdlib.h>
#include <stdio.h>
#include <lcarte.h>
#include <unistd.h>
#include "timer.h"
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <mem_sh.h>
#include <donnees.h>
#include "recharge.h"
#include "voyants.h"
#include <iostream>

int Time ,i;

voyants Voyants;
int recharge::Recharge()
{ int A;
	io=acces_memoire(&shmid); //Accès mémoire
	attente_retrait_carte(); //attente retrait carte
	Voyants.clignoteCharge(VERT);
	timer_initialiser();//intialisation du timer
	Time= timer_valeur();
	while (io -> bouton_charge!=1 || Time>=6){
	Time= timer_valeur();

	}
	if(Time<5)
	{
		Voyants.eteindreDispo(OFF); //Gestion des LEDS
		Voyants.allumerCharge(ROUGE);
		Voyants.allumerTrappe(VERT);
		io->gene_pwm=DC; //io->gene_u=12;
		A= 1;
	}
	if(Time>=5)
	{
		//Voyants.allumerDispo(VERT);
		//A=2;
		//break;
		
	}
	//std::cout<<"Time==== :"<< Time <<std::endl;
	return A;
}

void recharge::charge()
{
	io=acces_memoire(&shmid);
	while((io->gene_u)!=9)
	usleep(1000);// Processeur trop rapide donc on met un sleep 
	Voyants.eteindreTrappe(OFF);
	Voyants.allumerPrise(VERT);
	sleep(1);
	io->gene_pwm=AC_1K;
	sleep(1);
	//io->gene_u=6;
	sleep(1);
	io->contacteur_AC=1;
	io->gene_pwm=AC_CL;

	sleep(1);

	while((io->gene_u)!=9)
	{
		sleep(1);// ralentir car le processeur est trop rapide 
		std::cout<<"en charge:"<<std::endl;
		
		if(io->bouton_stop==1)
		io->gene_u=9;
	}
	io->contacteur_AC=0;
	io->gene_pwm=DC;
	io->gene_u=9;
	Voyants.allumerCharge(VERT);

}

void recharge::recup()
{
	io=acces_memoire(&shmid);
	Voyants.allumerTrappe(VERT);
	while((io->gene_u)!=12)
	usleep(1000);// proc trop rapide 
	std::cout<<"vroum vroum :"<<std::endl;
	Voyants.eteindreTrappe(OFF);
	Voyants.allumerPrise(OFF);
	Voyants.allumerCharge(OFF);
	Voyants.allumerDispo(VERT);


}
