// Uso de _CRT_SECURE_NO_WARNINGS. Ver https://t.ly/aZuv  
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include "FVK4484-P1.h"

void Ej1_Inicial();
void Ej1_LosFloatsNoSonReales();
void Ej1_InicialCorregido();
void Ej1_InicialMasRapido();
void Eje1_DumpbinAntesDeEmpezar(const char nombre[]);
int LeeBloqueArchivo(const char nombre[], unsigned char bloque[]);

int main(int argc, char* argv[], char* envp[])
{
	// Necesario para imprimir caracteres específicos del español
	setlocale(LC_ALL, "Spanish"); // Necesita #include <locale.h>

	//->aquí va el código inicial de la práctica
	//Ej1_Inicial();
	//Ej1_LosFloatsNoSonReales();
	//Ej1_InicialCorregido();
	//Ej1_InicialMasRapido();
	Eje1_DumpbinAntesDeEmpezar("prueba.bin");

	printf("\nPor favor, pulse la tecla ENTRAR para terminar ...\n");
	(void)getchar();  // printf y getchar => necesitan #include <stdio.h>

	return 0;
}

/*
// Copiar esto al mismo archivo donde está main
#define NRO_BYTES sizeof(i)
void Ej1_Inicial() {
	clock_t inicio = clock();  // inicia medición de tiempo

	//printf("Tamaño de i: %d bytes\n", NRO_BYTES);
	char i;
	for (i = 1; i > 0; i++) {
		printf("%d:0x%02x -> ", i, i);
		ImprimeBinario(i, NRO_BYTES * 8);
		printf("\n");
	}

	clock_t fin = clock();  // finaliza medición de tiempo
	double milisegundos = (fin - inicio) / CLOCKS_PER_SEC * 1000;

	printf(__FUNCTION__ ": Tiempo: %.3f ms\n", milisegundos);
	printf("Tamaño de i: %d bytes\n", NRO_BYTES);
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
	double milisegundos = 1000.0 * (double)(fin - inicio) / CLOCKS_PER_SEC;
	printf(__FUNCTION__ ": Tiempo de ejecución: %.3f ms\n", milisegundos);
	printf("Tamaño de i: %d bytes\n", NRO_BYTES);
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
	double milisegundos = 1000.0 * (double)(fin - inicio) / CLOCKS_PER_SEC;
	printf(__FUNCTION__ ": Tiempo de ejecución: %.3f ms\n", milisegundos);
	printf("Tamaño de i: %d bytes\n", NRO_BYTES);
}
*/

// ------------------------------------------------------------------
// Sesión 2: matrices C y archivos
// ------------------------------------------------------------------

// Lee los primeros bytes de 'nombre' y los deja en 'bloque'.
// Devuelve el número de bytes leídos, o -1 si no se puede abrir el archivo.
int LeeBloqueArchivo(const char nombre[], unsigned char bloque[])
{
	FILE* f;
	if (fopen_s(&f, nombre, "rb") != 0)
		return -1;
	int n = (int)fread(bloque, 1, 32, f);
	fclose(f);
	return n;
}

// Para probarlo, llamar a esta función desde main 
//    con el nombre "prueba.bin"
// Ejercicio inicial sobre archivos, P1-Sesión 2.
void Eje1_DumpbinAntesDeEmpezar(const char nombre[]) {
	unsigned char bloque[32], var1 = 1;
	int n = LeeBloqueArchivo(nombre, bloque);
	for (int i = 0; i < n; i++)
		printf("%02X ", bloque[i]);
	printf("\n");
}

