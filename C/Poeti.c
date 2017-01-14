/*
Il programma ha come obiettivo supportare un utente che vuole comporre una poesia; a tale proposito il programma da la possibilità di memorizzare un insieme di versi (al più 100), insieme a delle funzionalità di analisi per i versi (al più 200 caratteri).
L'utente può quindi, tramite il menù principale, scegliere tra diverse opzioni quale operazione fare, fino a concludere selezionando l'opzione Termine.

Il menù è il seguente:

leggi verso: acquisisce un verso per una successiva elaborazione
salva verso: salva il verso precedentemente acquisito come ultimo verso aggiunto
leggi versi: acquisisce due versi per elaborazioni successive
salva versi: salva i versi precedentemente acquisiti come ultimi versi aggiunti
controlla lunghezza: rispetto agli 2 ultimi versi acquisiti, viene confrontata la lunghezza di due strighe: la lunghezza della prima è ''compatibile'' con quella della seconda se e solo se quest'ultima è compresa tra [-20%,+20%] della lunghezza della prima.
visualizza versi compatibili: rispetto all'ultimo verso acquisito visualizza tutti i versi con esso compatibili, restituendo il numero di versi trovati. Il programma principale visualizza tale valore dopo l'elenco dei versi compatibili.
visualizza versi in rima: rispetto all'ultimo verso acquisito, cerca e visualizza tutti i versi in rima con il verso dato, restituendo il numero di versi trovati. Il programma principale visualizza tale valore dopo l'elenco dei versi compatibili. Una condizione che si ritiene accettabile per la rima, è che le ultime tre lettere dei due versi siano uguali (attenzione ai versi corti).
effettua cesura: rispetto all'ultimo verso acquisito, viene visualizzata la parte del verso che precede o il punto o il punto e virgola. Se il verso non contiene alcuno di tali simboli, non si visualizza nulla.
verifica assonanza: rispetto agli 2 ultimi versi acquisiti, è presente se coincidono le ultime due vocali dei due versi.
verifica allitterazione: rispetto all'ultimo verso acquisito, è presente se contiene almeno 3 parole consecutive che iniziano con la stessa lettera.
verifica metrica: rispetto agli 2 ultimi versi acquisiti, la metrica è rispettata se i due versi producono assonanza e contengono allitterazioni.
termina
Il programma consente di acquisire un verso (oppure due) e di effettuarne l'elaborazione prima di eventualmente salvarlo (l'utente potrebbe decidere che il verso non &egravE; abbastanza bello). Per questo motivo le funzionalità di acquisizione e salvataggio sono separate). È possibile effettuare più elaborazioni consecutive prima di salvare il verso (i versi).

Si suggerisce di sviluppare e utilizzare (anche più di una volta) i seguenti sottoprogrammi (ne serviranno anche di altri):

int compatibili (char *, char *);
int assonanza (char *, char *);
int allitterazione (char *);
int metrica (char *, char *);
int rima (char [][X], char *);
Il programma deve essere robusto, ovvero non deve andare in errore nel caso in cui l'utente selezioni la voce "salva versi" ma in precedenza era stato letto un solo verso.#include <stdio.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_VERSI 100
#define MAX_CHAR 200

int isVowel(char);
int no_empty(char *);
void leggi_verso(char *);
void salva_verso(char[][MAX_CHAR+1], char*, int);
void leggi_versi();
void salva_versi(char[][MAX_CHAR+1], char*, char*, int);
int controlla_lunghezza(char*, char*); 
int visualizza_versi_compatibili(char[][MAX_CHAR+1], char*, int);
int in_rima(char *, char *);
int visualizza_versi_in_rima(char*, char[][MAX_CHAR+1], int); 
void effettua_cesura(char*); 
int verifica_assonanza(char*, char*); 
int verifica_allitterazione(char*); 
int verifica_metrica(char *, char *); 
void printMenu();

int main(int argc, char *argv[])
{
	char versi[MAX_VERSI][MAX_CHAR+1], temp1[MAX_CHAR+1], temp2[MAX_CHAR+1];
	int choice, i, n_versi_c, n_v_rima, switch_temp;
	temp1[0] = '\0';
	temp2[0] = '\0';
	versi[0][0] = '\0';
	i = 0;
	switch_temp = 0;
	
	do {
		printMenu();
		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
			case 1: scanf("\n"); /* Per assorbire l'invio altrimenti acquisito da gets*/
					if (switch_temp) {
						strcpy(temp2, temp1);
						leggi_verso(temp1);
					}
					else {
						leggi_verso(temp1);
						switch_temp = 1;
					}
					break;
			case 2: salva_verso(versi, temp1, i); 
					i++;
					break;
			case 3: scanf("\n");
					leggi_versi(temp1, temp2); 
					switch_temp = 1;
					break;
			case 4: salva_versi(versi, temp1, temp2, i); 
					i += 2;
					break;
			case 5: if (controlla_lunghezza(temp1, temp2) == 1)  
						printf("Versi compatibili\n");
					break;
			case 6: n_versi_c = visualizza_versi_compatibili(versi, temp1, i); 
					if (n_versi_c != -1)
						printf("%d\n", n_versi_c);
					break;
			case 7: n_v_rima = visualizza_versi_in_rima(temp1, versi, i); 
					if (n_v_rima != -1)
						printf("%d\n", n_v_rima);
					break;
			case 8: effettua_cesura(temp1); 
					break;
			case 9: if(verifica_assonanza(temp1, temp2) == 1)
						printf("Assonanza presente\n");
					break;
			case 10: if (verifica_allitterazione(temp1) == 1)
						printf("Allitterazione presente\n");
					break;
			case 11: verifica_metrica(temp1, temp2);
					break;
			case 12: break;
			default: printf("Scelta non valida\n");
		}
	} while (choice != 12);
	printf("Arrivederci!\n\n");
	return 0;
}


int no_empty(char *temp)
{
	if (*temp != '\0')
		return 1;
	return 0;
}


void leggi_verso(char *temp)
{
	int i, not_ovf;
	char c_temp;
	scanf("%c", temp);
	for (not_ovf = 1, i = 1; *(temp+i-1) != '\n' && not_ovf; )
		if (i == MAX_CHAR+1) {
			printf("Attenzione: limite caratteri raggiunto. Il verso è stato troncato al %d° carattere.\n", MAX_CHAR);
			not_ovf = 0;
			do								/* Acquisisco i caratteri restanti per eliminarli dal buffer ed evitare acquisizioni indesiderate */
				scanf("%c", &c_temp);
			while (c_temp != '\n');
		}
		else {
			scanf("%c", temp+i);
			i++;
		}
	*(temp+i-1) = '\0';
}
		
		
void salva_verso(char versi[][MAX_CHAR+1], char *temp, int i)
{
	if (no_empty(temp) && i < MAX_VERSI)
		strcpy(versi[i], temp);
	else 
		printf("Errore nell'inserimento dei versi\n");
	return;
}


void leggi_versi(char *temp1, char *temp2)
{
	leggi_verso(temp1);  
	leggi_verso(temp2);
	return;
}


void salva_versi(char versi[][MAX_CHAR+1], char *temp1, char *temp2, int i)
{
	if (no_empty(temp1) && no_empty(temp2)) {
		salva_verso(versi, temp1, i);
		salva_verso(versi, temp2, i+1);
	}
	else 
		printf("Errore nell'inserimento dei versi\n");
	return;
}


int controlla_lunghezza(char *temp1, char *temp2)
{
	int len1, len2;
	if (no_empty(temp1) && no_empty(temp2)) {
		len1 = strlen(temp1);
		len2 = strlen(temp2);
		if (len2 >= len1*4/5 && len2 <= len1*6/5) {
			return 1;
		}
		return 0;
	}
	printf("Errore nell'inserimento dei versi\n");
	return -1;
}


int visualizza_versi_compatibili(char versi[][MAX_CHAR+1], char *temp, int n_versi)
{
	int i, count;
	if (n_versi == 0 || !no_empty(temp))
		return -1;
	for (i = 0, count = 0; i < n_versi; i++)
		if (controlla_lunghezza(temp, versi[i])) {
			puts(versi[i]);
			count++;
		}
	return count;
}


int in_rima (char *temp1, char *temp2)
{
	int i, rimati, len1, len2;
	if (no_empty(temp1) && no_empty(temp2)) {
		len1 = strlen(temp1);
		len2 = strlen(temp2);
		if (len1 < 3 || len2 < 3)
			return 0;
		while (!isalpha(*(temp1+len1-1)))
			len1--;
		while (!isalpha(*(temp2+len2-1)))
			len2--;
		for (i = 1, rimati = 1; i <= 3 && rimati; i++) {
			if (temp1[len1-i] != temp2[len2-i])
				rimati = 0;
		}
		return rimati;
	}
	return -1;
}


int visualizza_versi_in_rima(char *temp, char versi[][MAX_CHAR+1], int n_versi) 
{
	int i, count;
	if (n_versi == 0 || !no_empty(temp))
		return -1;
	if (strlen(temp) < 3)    /*Eccezione che previene l'entrata nel ciclo quando si sa a priori che count sarà 0*/
		return 0;
	for (i = 0, count = 0; i < n_versi; i++)
		if (in_rima(temp, versi[i])) {
			puts(versi[i]);
			count++;
		}
	return count;
}


void effettua_cesura(char *temp)
{
	int i, len, stop;
	if (no_empty(temp)) {
		for (i = 0, len = 0, stop = 0; *(temp+i) != '\0' && !stop; i++) {
			if (*(temp+i) == '.' || *(temp+i) == ';')
				stop = 1;
			len++;
		}
		if (stop)
			for (i = 0, len--; i < len; i++)
				printf("%c", *(temp+i));
	}
	else
		printf("';' o '.' non presenti.");
	printf("\n");
	return;
}


int isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	return 0;
}


int verifica_assonanza(char *temp1, char *temp2) {
	int is_asson, i, j, count;
	if (no_empty(temp1) && no_empty(temp2)) {
		count = 0;
		is_asson = 1;
		for (i = strlen(temp1)-1, j = strlen(temp2)-1; is_asson && count < 2; i--)
			if (isVowel(*(temp1+i))) {
				for ( ; !isVowel(*(temp2+j)); j--)
					;
				if (*(temp1+i) == *(temp2+j)) {
					count++;
					j--;
				}
				else
					is_asson = 0;
			}
		if (count == 2)
			return 1;
		return 0;
	}
	printf("Errore nell'inserimento dei versi\n");
	return -1;
}


int verifica_allitterazione(char *temp) {
	char n1, n2, c;
	int cont, i;
	if (no_empty(temp)) {
		n1 = ' '; 
		for (i = 0, cont = 1, c = '\0';  *(temp+i) != '\0' && cont < 3; i++) {
			n2 = *(temp+i);
			if (isalpha(n2) && !isalpha(n1)) {
				if (c == n2 || c == n2 - 32 || c == n2 + 32) /*Gestione maiuscole/minuscole*/
					cont++;
				else 
					cont = 1;
				c = n2;
			}
			n1 = n2;
		}
		if (cont == 3)
			return 1;
		return 0;
	}
	printf("Errore nell'inserimento dei versi\n");
	return -1;
}
			
		
int verifica_metrica(char *temp1, char *temp2) {
	if (no_empty(temp1) && no_empty(temp2)) {
		if (verifica_assonanza(temp1, temp2) && verifica_allitterazione(temp1) && verifica_allitterazione(temp2))
			return 1;
		return 0;
	}
	printf("Errore nell'inserimento dei versi\n");
	return -1;
}


void printMenu() 
{
	printf("\n-------------------------------------\n");
	printf(" 1 - Leggi Verso\n");
	printf(" 2 - Salva Verso\n");
	printf(" 3 - Leggi Versi\n");
	printf(" 4 - Salva Versi\n");
	printf(" 5 - Controlla Lunghezza\n");
	printf(" 6 - Visualizza Versi Compatibili\n");
	printf(" 7 - Visualizza Versi in Rima\n");
	printf(" 8 - Effettua Cesura\n");
	printf(" 9 - Verifica Assonanza\n");
	printf("10 - Verifica Allitterazione\n");
	printf("11 - Verifica Metrica\n");
	printf("12 - Termina\n");
	printf("-------------------------------------\n\n");
	printf("Immetti il numero associato all'operazione da eseguire:\t");
}
	
