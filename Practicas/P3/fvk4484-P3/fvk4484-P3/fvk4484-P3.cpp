#include <locale.h>
#include <stdio.h>
#include <Windows.h>
#include "sslib/SSLib.h"

int main(int argc, char* argv[], char* envp[])
{
	// Necesario para imprimir caracteres específicos del español
	setlocale(LC_ALL, "Spanish"); // Necesita #include <locale.h>

	ss::Dbg dbg;

	// Copiar esto dentro de la función main, tras setlocale...
	if (argc < 2) {
		printf("Error: Debe indicar el nombre del directorio a procesar\n");
		return 1;
	}
	printf("Mostrando los archivos del directorio:\n%s\n\n", argv[1]);

	// comprueba si el directorio existe. Necesita incluir <Windows.h>
	DWORD atributos = GetFileAttributesA(argv[1]);
	if (atributos == INVALID_FILE_ATTRIBUTES) {
		printf("Error: No se ha dado un nombre de directorio correcto:\n(%s)\n", argv[1]);
		return 2;
	}
	if ((atributos & FILE_ATTRIBUTE_DIRECTORY) == 0) {
		printf("Error: No es un directorio:\n(%s)\n", argv[1]);
		return 3;
	}

	printf("\nPor favor, pulse la tecla ENTRAR para terminar ...\n");
	(void)getchar();  // printf y getchar=> necesitan #include <stdio.h>
	return 0;
}