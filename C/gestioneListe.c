#include <stdio.h>
#include <malloc.h>

typedef struct lista_s {
		int val;
		struct lista_s* next;
}	lista_t;

lista_t* inserisciInTesta(lista_t* head, int n)
{
	lista_t *nuovo;					/*Puntatore cui assegnare l'indirizzo del nuovo elemento della lista*/
	
	if (nuovo = malloc(sizeof(lista_t))) {		/* Se la memoria per il nuovo elemento viene allocata,*/
		nuovo->val = n;							/* assegno n al campo "val" dell'elemento */ 
		nuovo->next = head;						/* e lo collego al blocco cui prima puntava head.*/
		head = nuovo;							/* A questo punto, poiché head punta sempre al primo elemento, passo a head l'indirizzo del nuovo elemento "nuovo".*/
	} 
	else 
		printf("Memoria esaurita\n");				/* Se l'allocazione fallisce, stampo errore*/
	return head;								/* In ogni caso, ritorno head (al più, la lista rimane invariata).*/
}	

/****************************************************/

lista_t* inserisciInCoda(lista_t *head, int n)
{
	lista_t *nuovo, *p;				/* Puntatori cui assegno: 1) l'indirizzo del nuovo elemento; 
															  2) un indirizzo temporaneo utilizzato per scorrere la lista.*/
	if (nuovo = malloc(sizeof(lista_t))) {		/* Se la memoria per il nuovo elemento viene allocata,*/
		nuovo->val = n;							/* assegno n al campo "val" dell'elemento */ 		/* e lo collego al blocco cui prima puntava head.*/
		nuovo->next = NULL;						/* e, essendo nuovo l'ultimo elemento, faccio sì che punti a NULL*/
		if (head != NULL) {						/* Se la lista ha già elementi (head non punta a NULL) */
			for (p = head; p->next; p = p->next)/* mi scorro la lista fino a trovare l'ultimo elemento, */
				;								/* spostando il puntatore da un elemento al successivo a ogni ciclo, */
			p->next = nuovo;					/* e, trovato l'ultimo e uscito dal for, assegno al suo next l'indirizzo del nuovo blocco,*/
		}										/* cosicché non punti più a NULL, ma a "nuovo", che è di fatto diventato l'ultimo elemento.*/
		else									/* Se la lista non ha elementi,*/
			head = nuovo;						/* aggiungo il primo, facendo puntare head a nuovo (head punta sempre al primo elemento che, in questo caso, è anche l'ultimo).*/
	}
	else 										/* Se l'allocazione fallisce,*/
		printf("Memoria esaurita\n");				/* stampo errore e, in ogni caso,*/
	return head;								/* restituisco head.*/
	
/********************************************************/
		
void liberaListaR(lista_t *head)
{
	if (head == NULL)							/* Se la lista non ha elementi (head punta a NULL)*/
		return;									/* mi fermo; altrimenti, */
		liberaListaR(head->next);				/* richiamo la funzione e ripeto la verifica per l'elemento successivo, considerandolo come una nuova head.*/
		free(head);								/* Quando la funzione smette di essere chiamata, siamo arrivati alla fine della lista: allora, i suoi elementi vengono liberati dall'ultimo al primo.*/
	}
}

/********************************************************/

void stampaLista(lista_t *head)
{
	lista_t *p;									/* Dichiaro un puntatore da far variare in un for, */
	
	for (p = head; p != NULL; p = p->next)		/* lo inizializzo con head e scorro gli elementi della lista fino a che il p non punta a niente (elementi esauriti). */
		printf("%d ", p->val);					/* Ad ogni ciclo, stampo l'intero contenuto nell'elemento della lista, */
	printf("\n");								/* e, dopo aver stampato tutti gli interi, termino con un "a capo". */
	return;
}

/*********************************************************/

void stampaListaR(lista_t *head)
{
	if (head == NULL) {							/* Se la lista non ha elementi o si tratta dell'ultimo elemento (head punta a NULL), */
		printf("\n");							/* stampo un "a capo" e */
		return;									/* mi fermo; altrimenti, */
	}
	printf("%d ", head->val);					/* stampo l'intero contenuto nell'elemento  e */
	stampaListaR(head->next);					/* richiamo la funzione: ripeto le operazioni per l'elemento successivo, considerando il next dell'attuale elemento come una nuova head.*/
}