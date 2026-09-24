// Ejercicio final práctica 0
// Funciona cambiando ESPERA_MS a 2000 ms?
#include <stdio.h>
#include <Windows.h>
#include <locale>

int entero32;
int32_t OtroEntero32;

#define ESPERA_MS (500)
#define _1MHzEnHerzios (1000000.0)

int var = 5;
int* p1 = &var;
int p3, *p2;

void modificaPar(int* ppar)
{
	//*ppar = 6;
	(*ppar)++;
}

void ImprimeGhz() {

	modificaPar(&var);

	char car;
	long int antes, ahora = 0;
	double VelocidadCPUGhz;

	printf("Tamaño de int %d\n", sizeof(antes));
	printf("Tamaño de char %d\n", sizeof(car));
	printf("Tamaño de double %f\n", sizeof(VelocidadCPUGhz));
	printf("Tamaño de int %d\n", sizeof(&antes));
	printf("Tamaño de char %d\n", sizeof(&car));
	printf("Tamaño de double %f\n", sizeof(&VelocidadCPUGhz));

	antes = __rdtsc(); // Leo el valor del contador RDTSC y lo guardo
	Sleep(ESPERA_MS); // Espero un tiempo determinado (en milisegundos)
	ahora = __rdtsc();// Leo el valor del contador ahora

	VelocidadCPUGhz = (double)(ahora - antes) / (ESPERA_MS * _1MHzEnHerzios);
	printf("\nLa frecuencia en Hz es: %f", VelocidadCPUGhz);
}




int main(int argc, char* argv[], char* envp[])
{
	// Necesario para imprimir caracteres específicos del español
	setlocale(LC_ALL, "Spanish"); // Necesita #include <locale.h>

	ImprimeGhz();

	printf("\nPor favor, pulse la tecla ENTRAR para terminar ...\n");
	(void)getchar();  // printf y getchar=> necesitan #include <stdio.h>
	return 0;
}