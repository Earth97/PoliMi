
/* Scrivere programma che chiede all’utente al più 1000 interi relativi,
terminati quando si inserisce il valore 0 (non fa parte della sequenza).
Il programma visualizza tutti e solo i valori forniti che abbiano un numero
di cifre superiori al numero medio di cifre dei valori inseriti. */



#include <stdio.h>
#define MAX 1000
#define STOP 0
#define BASE 10
int contaCifre(int);

int main(int argc, char *argv[])
{
	int n, valori[MAX], n_cifre[MAX], sum, n_val, i;
	float avg;
	
	scanf("%d", &n);
	for (sum = 0, i = 0; n != STOP && i < MAX; i++) {
		valori[i] = n;
		n_cifre[i] = contaCifre(n);
		sum += n_cifre[i];
		scanf("%d", &n);
	}
	if (i != 0) {
		n_val = i;
		avg = (float)sum/n_val;
		for (i = 0; i < n_val; i++)
			if (n_cifre[i] > avg)
				printf("%d ", valori[i]);
		printf("\n");
	}
	return 0;
}

int contaCifre(int n)
{
	int cont;
	cont = 1;
	while (n > 9) {
		n = n/BASE;
		cont++;
	}
	return cont;
}