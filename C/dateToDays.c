#include <stdio.h>
#define BASE 10	
typedef struct date_s {
			int m, y;
} date_t;

int dayPerMonth(int, int);
int bisestile(int);
int stoi(char *);

int main(int argc, char *argv[])
{
	date_t date;
	int acc, i; 
	if (argc == 4) {
		acc = stoi(argv[1]);
		date.m = stoi(argv[2]);
		date.y = stoi(argv[3]);
		
		for (i = 1; i < date.m; i++)
				acc += dayPerMonth(i, date.y);
		
		printf("%d\n", acc);
		
	} else
		printf("Arguments entered: %d; %d more requested.\n", argc-1, 4-argc);
		
	return 0;
}

int dayPerMonth(int m, int y) {
	switch (m) {
		case 2: return 28 + bisestile(y);
		case 4:
		case 6:
		case 9:
		case 11: return 30;
		default: return 31;
	}
}

int bisestile(int y) {
	if (y % 4 == 0 && y % 100 || y % 400 == 0)
		return 1;
	return 0;
}

int stoi(char *str) {
	int acc, i;
	for (i = 0, acc = 0; *(str+i) != '\0'; i++)
		acc = acc*BASE + *(str+i) - '0';
	return acc;
}
		
		
		
		