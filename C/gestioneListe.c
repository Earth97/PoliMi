typedef struct lista_s {
		int val;
		struct lista_s* next;
}	lista_t;

lista_t* inserisciInTesta(lista_t* head, int n)
{
	lista_t* nuovo;					/*Puntatore cui assegnare l'indirizzo del nuovo elemento della lista*/
	
	if (nuovo = malloc(sizeof(lista_t)) {		/* Se la memoria per il nuovo elemento viene allocata,*/
		nuovo->val = n;							/* assegno n al campo "val" dell'elemento */ 
		nuovo->next = head;						/* e lo collego al blocco cui prima puntava head.*/
		head = nuovo;							/* A questo punto, poiché head punta sempre al primo elemento, passo a head l'indirizzo del nuovo elemento "nuovo".*/
	} 
	else 
		printf("Memoria esaurita\n");				/* Se l'allocazione fallisce, stampo errore*/
	return head;								/* In ogni caso, ritorno head (al più, la lista rimane invariata).*/
}	

lista_t* inserisciInCoda(lista_t* head, int t)
{
	lista_t* nuovo, p;				/* Puntatori cui assegno: 1) l'indirizzo del nuovo elemento; 
															  2) un indirizzo temporaneo utilizzato per scorrere la lista.*/
	if (nuovo = malloc(sizeof(lista_t)) {		/* Se la memoria per il nuovo elemento viene allocata,*/
		nuovo->val = n;							/* assegno n al campo "val" dell'elemento */ 		/* e lo collego al blocco cui prima puntava head.*/
		nuovo->next = NULL;						/* e, essendo nuovo l'ultimo elemento, faccio sì che punti a NULL*/
		if (head != NULL) {						/* Se la lista ha già elementi (head non punta a NULL) */
			for (p = head; p->next; p = p->next)/* mi scorro la lista fino a trovare l'ultimo elemento, */
				;								/* spostando il puntatore da un elemento al successivo a ogni ciclo, */
			p->next = nuovo;					/* e, trovato l'ultimo e uscito dal for, assegno al suo next l'indirizzo del nuovo blocco,*/
		}										/* cosicché non punti più a NULL, ma a "nuovo", che è di fatto diventato l'ultimo elemento.*/
		else									/* Se la lista non ha elementi,*/
			head = next;						/* aggiungo il primo, facendo puntare head a nuovo (head punta sempre al primo elemento che, in questo caso, è anche l'ultimo).*/
	}
	else 										/* Se l'allocazione fallisce,*/
		printf("Memoria esaurita\n");				/* stampo errore e, in ogni caso,*/
	return head;								/* restituisco head.*/
			
	