#ifndef TIMER_H
#define TIMER_H

#include <donnees_borne.h>
#include <memoire_borne.h>
#include <mem_sh.h>
#include <donnees.h>

extern entrees*io;
extern int shmid;
extern int depart_timer;


void timer_initialiser();
int timer_valeur();


 #endif
