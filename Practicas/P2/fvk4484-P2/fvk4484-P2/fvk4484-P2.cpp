// Uso de _CRT_SECURE_NO_WARNINGS. Ver https://t.ly/aZuv  
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void Eje2_Inicial();
void Ej2_EstructuraEnDisco();
// void ImprimeLineaHex();

int main(int argc, char* argv[], char* envp[])
{
	// Necesario para imprimir caracteres específicos del español
	setlocale(LC_ALL, "Spanish"); // Necesita #include <locale.h>


	//->aquí va el código inicial de la práctica
	// Evitar advertencias de parámetros no usados
	Eje2_Inicial();
	Ej2_EstructuraEnDisco();
	// ImprimeLineaHex();

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
		char matriz[4];
	} vEstructura = { 0x89abcdef , 1 }; // Define + inicializa la estructura
	union {
		int entero;
		char car;
		unsigned char matriz[4];
	}  vUnion = { 0x89abcdef }; // Define + inicializa la unión

	vUnion.car = 1;
	printf(__FUNCTION__ ":\n");
	/* sizeof devuelve size_t; usar %zu o castear a int para evitar advertencias de formato */
	printf("\tEstructura: %d Tam: %zu\n", vEstructura.entero, sizeof(vEstructura));
	printf("\tUnion: %d Tam: %zu\n", vUnion.entero, sizeof(vUnion));

	vUnion.entero = 0x89abcdef; // byte 0: 0xef, byte 1: 0xcd, byte 2: 0xab, byte 3: 0x89
	printf("vUnion.entero vale 0x%x\n", vUnion.entero);
	printf("El valor del byte 2 de vUnion.entero es: 0x%x\n", vUnion.matriz[2]);  // sustituir ??? por la xpresión que calcula el byte 2 de vUnion.entero 
	vEstructura.entero = 0x89abcdef; // byte 0: 0xef, byte 1: 0xcd, byte 2: 0xab, byte 3: 0x89
	printf("vEstructura.entero vale 0x%x\n", vUnion.entero);
	printf("El valor del byte 2 de vEstructura.entero es: 0x%x\n", vEstructura.matriz[3]);
}
// <- Hasta aquí ejercicio 2.1

#define VAL_ENTERO 0x12345678
typedef struct {
	int entero;
	char car;
} tEstructura_t;
// Escribe un bloque de memoria en un archivo binario.
// Devuelve el número de bytes escritos, o -1 si no se puede abrir el archivo.
int GuardaBloqueMemoria(const char nombre[], const void* pInicioBloque, size_t tamBloque)
{
	FILE* f;
	if (fopen_s(&f, nombre, "wb") != 0)
		return -1;
	int n = (int)fwrite(pInicioBloque, 1, tamBloque, f);
	fclose(f);
	return n;
}

typedef union {
	unsigned int uint8_t;	// Interpreta el union como un entero de 8 bits sin signo
	unsigned int uint32_t; // Interpreta el union como un entero de 32 bits sin signo
} ejUnion_t;

#define TAM_BYTES_EN_LINEA 16
// Imprime el valor de un contador y una línea hexadecimal.
// Devuelve el número de caracteres escritos.
size_t ImprimeLineaHex(const unsigned char datos[], size_t nDatos, int* pContador, int nroBytesPorDato = 1)
{
	ejUnion_t* pUnion;  // Pista: ¿para qué podemos usar esto?
	char buffer[TAM_BYTES_EN_LINEA * 3 + 100];
	size_t len = snprintf(buffer, sizeof(buffer), "%08X  ", *pContador);
	for (size_t i = 0; i < TAM_BYTES_EN_LINEA && i < nDatos; i += nroBytesPorDato) {
		if (nroBytesPorDato == 1) {
			unsigned char dato8 = datos[i];
			len += snprintf(buffer + len, sizeof(buffer) - len, "%02X ", dato8);
			(*pContador)++; // incrementa el valor del contador
		}
	}
	len = printf("%s\n", buffer);
	return len;
}

// Eje1_Dumpbin de repuesto. Este es una version de Eje1_Dumpbin, que se hizo en la práctica anterior
// Vuelca por pantalla el contenido completo de un archivo, en hexadecimal, en
// líneas de 16 bytes precedidas por la posición del primer byte de la línea.
// Devuelve el número de bytes volcados, o -1 si no se puede abrir el archivo.
int Eje1_Dumpbin(const char nombre[])
{
	const size_t TAM_LINEA_DUMP = 16;
	unsigned char bloque[TAM_LINEA_DUMP], buffer[TAM_LINEA_DUMP * 3 + 100];
	FILE* f;
	if (fopen_s(&f, nombre, "rb") != 0) {
		printf("Error al abrir el archivo %s.\n", nombre);
		return -1;
	}
	printf("Contenido del archivo %s\n", nombre);
	int contador = 0;
	size_t n = fread(bloque, 1, TAM_LINEA_DUMP, f);
	while (n > 0) {                 // n < TAM_LINEA_DUMP: última línea
		ImprimeLineaHex(bloque, (size_t)n, &contador);
		n = fread(bloque, 1, TAM_LINEA_DUMP, f);   // n == 0: fin de archivo
	}
	fclose(f);
	return contador;
}

void Ej2_EstructuraEnDisco()  //previo
{
	static tEstructura_t varLocal = { VAL_ENTERO, 5 };
	printf(__FUNCTION__ ":\n");
	printf("\tsizeof(tEstructura_t) = %d\n",
		(int)sizeof(tEstructura_t));
	// Guarda un campo en un archivo binario y lo muestra con un visor hexadecimal.
	GuardaBloqueMemoria("campo_car.bin", &varLocal.car, varLocal.car);
	Eje1_Dumpbin("prueba.bin");
	/* el visor hexadecimal de la P1. También puede usar el editor binario de Visual Studio,
		 ver https://learn.microsoft.com/es-es/cpp/windows/binary-editor?view=msvc-180
	 */
}