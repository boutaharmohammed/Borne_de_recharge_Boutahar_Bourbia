#ifndef VOYANTS_H
#define VOYANTS_H

#include <stdio.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <unistd.h>
#include "timer.h"
/*extern entrees *io;
extern int shmid;
extern int depart_timer;
*/
class voyants
{
 public:
void clignoteDefault(led couleur);
void eteindreDispo(led couleur);
void allumerCharge(led couleur);
void allumerTrappe(led couleur);
void allumerDispo(led couleur);
void clignoteCharge(led couleur);
void init();
void eteindreTrappe(led couleur);
void allumerPrise(led couleur);
void Recharge();
};

#endif
