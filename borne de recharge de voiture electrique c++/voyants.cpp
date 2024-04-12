#include "voyants.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <mem_sh.h>
#include <donnees.h>
#include <lcarte.h>

entrees *io;
 int shmid;
 //int time;



void voyants::init(){

	io = acces_memoire(&shmid);

}
void voyants::clignoteDefault(led couleur){	
	int i;	
	for(i=0;i<4;i++){
	io-> led_defaut=couleur;
	sleep(1);
	io->led_defaut=OFF;
	sleep(1);
}
}

void voyants::clignoteCharge(led couleur){	
	int i;
	for(i=0;i<4;i++){
	io-> led_charge=couleur;
	sleep(1);
	io->led_charge=OFF;
	sleep(1);
	}
}


void voyants::eteindreDispo(led couleur){
	io->led_dispo=OFF;
}

void voyants::allumerCharge(led couleur){
	io-> led_charge=couleur;
}

void voyants::allumerTrappe(led couleur){
	io-> led_trappe=couleur;
}

void voyants::allumerDispo(led couleur){
	io-> led_dispo=couleur;
}
void voyants::eteindreTrappe(led couleur){
	io-> led_trappe=couleur;
}
void voyants::allumerPrise(led couleur){
	io-> led_prise=couleur;
}

