// Uso de _CRT_SECURE_NO_WARNINGS. Ver https://t.ly/aZuv  
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "FVK4484-P1a.h"
#include <time.h>
#define NRO_BYTES sizeof(i)

void Ej1_Inicial();
void Ej1_LosFloatsNoSonReales();
void Ej1_InicialCorregido();
void Ej1_InicialMasRapido();

int main(int argc, char* argv[], char* envp[])
{
	// Necesario para imprimir caracteres específicos del español
	setlocale(LC_ALL, "Spanish"); // Necesita #include <locale.h>

	//->aquí va el código inicial de la práctica
	Ej1_Inicial();
	Ej1_LosFloatsNoSonReales();
	Ej1_InicialCorregido();
	Ej1_InicialMasRapido();

	printf("\nPor favor, pulse la tecla ENTRAR para terminar ...\n");
	(void)getchar();  // printf y getchar=> necesitan #include <stdio.h>

	return 0;
}

// Copiar esto al mismo archivo donde está main
void Ej1_Inicial() {
	clock_t inicio = clock();  // inicia medición de tiempo

	//printf("Tamaño de i: %d bytes\n", NRO_BYTES); 
	unsigned char i;
	for (char i = 1; i > 0; i++) {
		printf("%d:0x%02x -> ", i, i);
		ImprimeBinario(i, NRO_BYTES * 8);
		printf("\n");
	}

	clock_t fin = clock();  // finaliza medición de tiempo
	double milisegundos = (fin - inicio) / CLOCKS_PER_SEC * 1000;

	printf(__FUNCTION__ ": Tiempo: %.3f ms\n", milisegundos);
	printf("Tamaño de i: %zu bytes\n", NRO_BYTES);
}

void Ej1_LosFloatsNoSonReales() {
	int i = 0;
	for (double j = 0.0; j != 3.0; j += 1.0 / 3.0)
	{
		printf("%f", j);
		printf("\n");
	}
}

#define LIMITE 0
typedef char tipo_test_t;
typedef unsigned char unsigned_tipo_test_t;

void Ej1_InicialCorregido() {
	clock_t inicio = clock();  // inicia medición de tiempo

	tipo_test_t i = 0;
	// Imprime todos los valores de i
	do {
		printf("%d:0x%02x -> ", i, (unsigned_tipo_test_t)i);
		ImprimeBinario(i, NRO_BYTES * 8);
		printf("\n");
		i += 1;
	} while (i != LIMITE);

	clock_t fin = clock();
	double milisegundos =
		1000.0 * (double)(fin - inicio) / CLOCKS_PER_SEC;

	printf(__FUNCTION__ ": Tiempo de ejecución: %.3f ms\n", milisegundos);
	printf("Tamaño de i: %zu bytes\n", NRO_BYTES);
}

void Ej1_InicialMasRapido() {
	clock_t inicio = clock();  // inicia medición de tiempo

	int len = 0;
	char buffer[200];
	tipo_test_t i = 0;
	// Imprime todos los valores de i
	do {
		len = snprintf(buffer, sizeof(buffer), "%d:0x%02x -> ", i, (unsigned_tipo_test_t)i);
		len += ImprimeBinario(buffer + char(len), sizeof(buffer) - len, i, NRO_BYTES * 8);
		printf("%s\n", buffer);
		i += 1;
	} while (i != LIMITE);

	clock_t fin = clock();
	double milisegundos =
		1000.0 * (double)(fin - inicio) / CLOCKS_PER_SEC;

	printf(__FUNCTION__ ": Tiempo de ejecución: %.3f ms\n", milisegundos);
	printf("Tamaño de i: %d bytes\n", NRO_BYTES);
}

