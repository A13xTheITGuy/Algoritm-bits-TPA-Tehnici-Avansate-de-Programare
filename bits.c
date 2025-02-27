#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h> //getch();

unsigned char v[1000 / 8 + 1]; // 126 octeti // vector initializat cu 0 deoarece este declarat global

unsigned char validare_numar(double nr) // validare numar introdus de la tastatura
{
	if (floor(nr) != nr || nr < 0 || nr>1000 && nr != -1) {
		printf(" | ERROR | Numar invalid! ( trebuie numar intreg intre [0,1000] )! \n");
		return 0;
	}
	else
		if (floor(nr) != nr && nr >= 0 && nr <= 1000 && nr != -1) {
			printf(" | ERROR | Numar invalid! ( trebuie numar intreg intre [0,1000] )! \n");
			return 0;
		}

		else
			if (nr == -1)
				return 1;
			else
				return 1;
}

int main()
{
	// uint16_t = short int
	double nr;
	uint16_t nr_int;
	printf("\n | Assignment 1 - introducere Problema 1 ( bits ) | \n");
	printf(" | Stan Alexandu Daniel ; Subgrupa 03.1 IS Anul 1 | \n");
	printf("\n | Cerinta | 1. Se da o multime de numere naturale cu valori de la 0 la 1000. Se citesc de la intrare diferite valori in intervalul [0,1000], sa se utilizeze un vector de octeti de dimensiune cat mai mica pentru memorarea elementelor multimii. (Vezi Curs 1)\n");
	printf("\n | INFO | Numerele sunt afisate in ordine crescatoare!\n");
	printf("          Vectorul este declarat global ( si initializat cu 0 automat ) prin forma: unsigned char v[1000 / 8 + 1], ocupandu-se din memorie doar 126 de octeti.\n");
	printf("          Numerele pot sa se repete, iar daca un numar este introdus de la tastatura de mai multe ori, atunci algoritmul il va afisa doar o data!\n");
	printf("          Numerele care nu corespund conditiilor ( sa fie intregi si in intervalul [0,1000] ) nu se introduc in vector, fiind afisat un mesaj de informare si reintroducandu-se valoarea!\n\n");
	printf(" | Citire | Introduceti numarul: ");
	scanf("%lf", &nr);

	int nr_in = 0; // variabila pentru numarare numere introduse de la tastatura pana la "-1"

	if (nr == -1) {
		printf(" | ERROR | Nu ati introdus inainte de \"-1\" niciun nr intre [0,1000]! \n");
		exit(EXIT_FAILURE);
	}
	else
		if (!validare_numar(nr)) {
			do {
				printf(" | Citire | Introduceti numarul: ");
				scanf("%lf", &nr);
			} while (!validare_numar(nr));
		}
		else
			nr_in = 1;

	while (nr != -1) {

		// v[nr / 8] = v[nr / 8] | (1 << (7 - nr % 8));
		// cat = 0,1,...125 
		// rest = 0,1,..7

		nr_int = (uint16_t)nr;
		uint16_t cat = nr_int / 8, rest = nr_int % 8; // cat, respectiv rest
		v[cat] = v[cat] | (1 << (7 - rest)); // memorarea numarului
		do {
			nr_in++;
			printf(" | Citire | Introduceti numarul: ");
			scanf("%lf", &nr);
		} while (nr != -1 && !validare_numar(nr));
	}
	nr_in--;

	int nr_i = 0; // variabila pentru numarare numere analizate de la 0 la 126
	unsigned char ok = 0;
	for (int i = 0; i < 126 && nr_i < nr_in; i++) {
		// citirea de la 0 la 126 pana cand am printat exact numarul de elemente introduse de la tastatura
		if (v[i] != 0) {
			if (!ok) {
				printf(" | Verificare | Numerele introduse de la tastatura sunt: "); ok = 1;
			}
			for (int poz = 0; poz <= 8 * sizeof(unsigned char) - 1; poz++) {
				unsigned char bit = 1 & (v[i] >> (7 - poz));
				if (bit) {
					nr_i++; // contorizez numerele pe care le-am gasit
					printf("%d ", i * 8 + poz); // afisare numar 
				}
			}
		}
	}
	if (ok == 1)
		printf("\n");

	printf("\n The End! :)\n\n");
	system("pause"); //getch();
	return 0;
}