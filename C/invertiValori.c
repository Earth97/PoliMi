/* Acquisisci interi fino a quando l'utente inserisce 0; stampa gli interi in ordine invertito. */

#include <stdio.h>
#include "./gestioneListe.h"
#define STOP 0

int main(int argc, char *argv[])
{
	lista_t *head = NULL;					
	int n;
	scanf("%d", &n);									/* Acquisisco un valore e lo salvo in n; */
	while (n != STOP) {								/* se il valore non è STOP(qui 0), */
		head = inserisciInTesta(head, n);			/* lo inserisco in testa alla lista. N.B. quando chiamo una funzione che gestisce una lista, essa ritornerà sempre "head", da assegnare alla variabile "head" presente nel main.*/
		scanf("%d", &n);								/* Successivamente, acquisisco un nuovo valore.*/
	}
	
	stampaLista(head);								/* Infine, stampo la lista, che presenterà i valori inseriti dall'utente in ordine inverso (si pensi all'ordine di inserimento nella lista*/
	
	return 0;
}
