// Uso de _CRT_SECURE_NO_WARNINGS. Ver https://t.ly/aZuv  
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void Eje2_Inicial();

int main(int argc, char* argv[], char* envp[])
{
	// Necesario para imprimir caracteres específicos del español
	setlocale(LC_ALL, "Spanish"); // Necesita #include <locale.h>


	//->aquí va el código inicial de la práctica
	// Evitar advertencias de parámetros no usados
	Eje2_Inicial();


	printf("\nPor favor, pulse la tecla ENTRAR para terminar ...\n");
	(void)getchar();  // printf y getchar=> necesitan #include <stdio.h>
	return 0;
}

// Copiar esta función al mismo archivo que main, y llamarla desde main
// Un experimento con estructuras y uniones
void Eje2_Inicial() {
	struct {
		int entero;
		char car;
	} vEstructura = { 256, 1 }; // Define + inicializa la estructura
	union {
		int entero;
		char car;
	}  vUnion = { 256 }; // Define + inicializa la unión

	vUnion.car = 1;
	printf(__FUNCTION__ ":\n");
	/* sizeof devuelve size_t; usar %zu o castear a int para evitar advertencias de formato */
	printf("\tEstructura: %d Tam: %zu\n", vEstructura.entero, sizeof(vEstructura));
	printf("\tUnion: %d Tam: %zu\n", vUnion.entero, sizeof(vUnion));
}
// <- Hasta aquí ejercicio 2.1