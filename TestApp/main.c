/*
 * main.c
 *
 *  Created on: Oct 22, 2020
 *  Author: Bojan Uljarevic RA-15/2017
 *
 *  ZADATAK:
 *
 *  Napraviti modul koji predstavlja jednostruko spregnutu listu.
 *  Modul izvesti kao dinamičku biblioteku koja se povezuje prilikom pokretanja programa.
 *  Zatim napraviti funkciju koja dve uređene (sortirane) liste
 *  spaja u jednu isto uređenu (sortiranu) listu.
 *
 *  IMPLEMENTACIJA:
 *
 *  Modul koji predstavlja jednostruko spregnutu listu je implementiran u datotekama
 *  SinglyLinkedList.h i SinglyLinkedList.c. Unutar modula su definisane strukture liste
 *  i cvorova liste, te funkcije za stvaranje, unistavanje, pretragu, umetanje, brisanje elemenata,
 *  sortiranje i spajanje kao i niz pomocnih funkcija za lakse rukovanje strukturom podataka.
 *  Projekat je izveden kao dinamicka biblioteka (libSinglyLinkedList.so).
 *
 *	TESTIRANJE:
 *
 *	Testiranje se izvodi u okviru projekta TestApp koji se sastoji iz:
 *
 *	1) Unity framework-a koji je potreban za izvrsavanje unit testova
 *	   Datoteke: unity.h, unity_internals.h, unity.c
 *	2) Kod u kom su definisani unit testovi koji se izvrsavaju nad datom dinamickom bibliotekom.
 *	   Konkretni testovi su jasno precizirani unutar prilozenih datoteka.
 *	   Ovdje se takodje testna aplikacija povezuje sa dinamickom bibliotekom prilikom izvrsavanja
 *	   upotrebom biblioteke "dlfcn.h".
 *	   Datoteke: SinglyLinkedListTest.h, SinglyLinkedListTest.c
 *	3) Glavne datoteke iz koje se pokrecu unit testovi
 *	   Datoteka: main.c
 *
 *	MISRA-C STANDARD:
 *
 *  Tokom izrade zadatka tezilo se ka postovanju MISRA standarda unutar biblioteke
 *  i testne aplikacije. Zbog sprege sa sistemskim bibliotekama ili otezanja implementacije
 *  predstojeca pravila nisu ispostovana. Prekrsaji su navedeni redoslijedom kojim se
 *  pojavljuju nakon kompilacije TI kompajlerom za c6000 familiju procesora.
 *  Potpun listing prekrsaja prilozen je u datoteci misra_log.
 *  Listing prekrsaja koji se nalaze u gorepomenutim datotekama
 *   prilozen je u datoteci relevant_misra_log.
 *
 *  1) 20.9/R The input/output library <stdio.h> shall not be used in production code
 *
 *  	Obrazlozenje: stdio.h zaglavnje je koristeno za funkciju ListDump koja ispisuje njen
 *  	sadrzaj i koja je korisna za uvid u rad ostalih funkcionalnosti biblioteke.
 *
 *  2) 5.7/A  No identifier name should be reused
 *
 *  	Obrazlozenje: Genericka imena poput list, current i iterator su koristena
 *  	u mnogobrojnim funkcijama  jer cine kod jasnijim i smatra se da bi dodjela
 *  	raznolikih imena ekvivalentnim objektima samo doprinijela konfuziji i nepreglednosti.
 *
 *  3) 20.11/R  The library functions abort, exit, getenv and system
 *  			from library <stdlib.h> shall not be used
 *     13.1/R   Assignment operators shall not be used in expressions that yield a Boolean value
 *     12.2/R   The value of an expression shall be the same
 *     		    under any order of evaluation that the standard permits
 *
 *  	Obrazlozenje: Navedeni prekrsaji se javljaju unutar funkcije LoadListLibrary(void)
 *  	unutar datoteke SinglyLinkedListTest.c .
 *  	Pojavljuju se u bloku koda koji vrsi povezivanje pokazivaca funkcije sa
 *  	odgovarajucom funkcijom iz dinamicke biblioteke.
 *  	Ovakvo rukovanje je demonstrirano na predavanjima i stoga se smatra validnim.
 *
 *  4) 10.1/R  The value of an expression of integer type shall not be implicitly converted
 *             to a different underlying type if the expression is not constant
 *             and is a function argument
 *
 *      Obrazlozenje: Prekrsaj se javlja prilikom poziva unit testova unutar datoteke
 *      SinglyLinkedListTest.c . Pretpostavka je da unity framework prilikom ovih testova
 *      vrsi implicitne konverzije tipa prilikom ispitivanja jednakosti.
 *
 */

#include "SinglyLinkedListTest.h"
#include "unity.h"

int main() {

	UNITY_BEGIN();

	LoadListLibrary();

	RUN_TEST(ListIsEmptyAfterCreation);
	RUN_TEST(ListPushAndPopFrontTest);
	RUN_TEST(ListAppendAndPopBackTest);
	RUN_TEST(ListAppendTest);
	RUN_TEST(ListSortTest);
	RUN_TEST(ListArbitraryInsertionTest);
	RUN_TEST(ListSearchTest);
	RUN_TEST(ListArbitraryDeletionTest);
	RUN_TEST(ListIsEmptyAfterDestruction);
	RUN_TEST(MergeSortedTest);

	CloseListLibrary();

	return UNITY_END();
}
