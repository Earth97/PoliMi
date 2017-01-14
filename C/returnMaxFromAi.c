/* Si consideri la sequenza di valori ai
* , con i = 0, 1, 2,    che soddisfa i seguenti requisiti:
*  a0 = 0
*  a1 = 1
*  a2i = ai
*  a2i+1 = ai + ai+1
* 
* Scrivere programma che chiede all'utente di inserire un numero n intero strettamente positivo (e se cos non e lo richiede 
* allutente finche non rispetta il vincolo) e visualizza il valore pi  u alto tra  a0, a1,    , an.
* Esempio 1 Esempio 2
* Ingresso: 5 	Ingresso: 10
* Uscita: 3 	Uscita: 4       */


#include <stdio.h>
int formula(int);

int main(int argc,char *argv[])
{
	int n, i, max, temp;

	do
		scanf("%d", &n);
	while (n < 0);

	max = formula(0);
	for (i = 1 ; i <= n; i++) {
		temp = formula(i);
		if (temp > max)
			max = temp;
	}
	printf("%d\n", max);
return 0;
}


int formula(int m)
{
	if (m == 0)
		return 0;
	if (m == 1)
		return 1;
	if (m%2 == 0)
		return formula(m/2);
	return formula(m/2)+formula(m/2+1);
}



