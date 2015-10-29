/*******************************************************************
/ Programm    : Bruchrechnung                                         
/ Verfasser   : Schmidt                                           
/ Datum       : Urprogramm: 24.10.2012                                          
/ Eingabe     : 2 rationale Zahlen                          
/ Verarbeitung: diverse Berechnungen                   
/ Änderungen  : 24.10.2012
/ *******************************************************************/

/* Einbinden von nötigen Header-Dateien                             */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include "mainfile.h"

struct bruch_s {
	int nenner, zaehler;
};

struct bruch_s add(struct bruch_s bruch, struct bruch_s bruch2) {
	struct bruch_s returnBruch;
	//Auf gleichen Nenner bringen
	if (bruch.nenner != bruch2.nenner) {
		int bruch_nenner_old = bruch.nenner;
		bruch.zaehler *= bruch2.nenner;
		bruch.nenner *= bruch2.nenner;
		bruch2.zaehler *= bruch_nenner_old;
		bruch2.nenner *= bruch_nenner_old;
		//printf("%d %d %d %d", bruch.zaehler, bruch.nenner, bruch2.zaehler, bruch2.nenner);
	}
	returnBruch.zaehler = bruch.zaehler + bruch2.zaehler;
	returnBruch.nenner = bruch.nenner;
	while ((returnBruch.nenner % returnBruch.zaehler == 0) && returnBruch.nenner != 0 && returnBruch.zaehler != 0) {
		int old_zaehler = returnBruch.zaehler;
		returnBruch.zaehler /= old_zaehler;
		returnBruch.nenner /= old_zaehler;
	}
	return returnBruch;
}

struct bruch_s sub(struct bruch_s bruch, struct bruch_s bruch2) {
	struct bruch_s returnBruch;
	//Auf gleichen Nenner bringen
	if (bruch.nenner != bruch2.nenner) {
		int bruch_nenner_old = bruch.nenner;
		bruch.zaehler *= bruch2.nenner;
		bruch.nenner *= bruch2.nenner;
		bruch2.zaehler *= bruch_nenner_old;
		bruch2.nenner *= bruch_nenner_old;
		//printf("%d %d %d %d", bruch.zaehler, bruch.nenner, bruch2.zaehler, bruch2.nenner);
	}
	returnBruch.zaehler = bruch.zaehler - bruch2.zaehler;
	returnBruch.nenner = bruch.nenner;
	while ((returnBruch.nenner % returnBruch.zaehler == 0) && returnBruch.nenner != 0 && returnBruch.zaehler != 0) {
		int old_zaehler = returnBruch.zaehler;
		returnBruch.zaehler /= old_zaehler;
		returnBruch.nenner /= old_zaehler;
	}
	return returnBruch;
}

struct bruch_s divide(struct bruch_s bruch, struct bruch_s bruch2) {
	struct bruch_s returnBruch;
	returnBruch.zaehler = bruch.zaehler * bruch2.zaehler;
	returnBruch.nenner = bruch.nenner * bruch2.nenner;
	while ((returnBruch.nenner % returnBruch.zaehler == 0) && returnBruch.nenner != 0 && returnBruch.zaehler != 0) {
		int old_zaehler = returnBruch.zaehler;
		returnBruch.zaehler /= old_zaehler;
		returnBruch.nenner /= old_zaehler;
	}
	return returnBruch;
}

struct bruch_s mult(struct bruch_s bruch, struct bruch_s bruch2) {
	struct bruch_s returnBruch;
	returnBruch.zaehler = bruch.zaehler * bruch2.nenner;
	returnBruch.nenner = bruch.nenner * bruch2.zaehler;
	while ((returnBruch.nenner % returnBruch.zaehler == 0) && returnBruch.nenner != 0 && returnBruch.zaehler != 0) {
		int old_zaehler = returnBruch.zaehler;
		returnBruch.zaehler /= old_zaehler;
		returnBruch.nenner /= old_zaehler;
	}
	return returnBruch;
}

int main()
{
	struct bruch_s bruch = { 0,0 }, bruch2 = { 0,0 }, showValue;
	printf("Bitte Zaehler und Nenner Bruch 1 eingeben: ");
	scanf("%d %d", &bruch.zaehler, &bruch.nenner);
	printf("Bitte Zaehler und Nenner Bruch 2 eingeben: ");
	scanf("%d %d", &bruch2.zaehler, &bruch2.nenner);
	showValue = add(bruch, bruch2);
	printf("%d/%d + %d/%d = %d/%d\n", bruch.zaehler, bruch.nenner, bruch2.zaehler, bruch2.nenner, showValue.zaehler, showValue.nenner);
	showValue = sub(bruch, bruch2);
	printf("%d/%d - %d/%d = %d/%d\n", bruch.zaehler, bruch.nenner, bruch2.zaehler, bruch2.nenner, showValue.zaehler, showValue.nenner);
	showValue = mult(bruch, bruch2);
	printf("%d/%d * %d/%d = %d/%d\n", bruch.zaehler, bruch.nenner, bruch2.zaehler, bruch2.nenner, showValue.zaehler, showValue.nenner);
	showValue = divide(bruch, bruch2);
	printf("%d/%d / %d/%d = %d/%d\n", bruch.zaehler, bruch.nenner, bruch2.zaehler, bruch2.nenner, showValue.zaehler, showValue.nenner);
	system("pause");
	return(0);
}

