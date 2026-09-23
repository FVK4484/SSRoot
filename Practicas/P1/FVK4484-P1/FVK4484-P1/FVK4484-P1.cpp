// Uso de _CRT_SECURE_NO_WARNINGS. Ver https://t.ly/aZuv
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>  // Necesario para medir tiempo de ejecución
#include "FVK4484-P1a.h"

void Ej1_Inicial() {
    clock_t inicio = clock();  // inicia medición de tiempo

    //printf("Tamaño de i: %d bytes\n", NRO_BYTES);
    unsigned char i;
    size_t nro_bytes = sizeof(i);
    for (i = 1; i > 0; i++) {
        printf("%u:0x%02x -> ", (unsigned int)i, (unsigned int)i);
        ImprimeBinario((int)i, (int)(nro_bytes * 8));
        printf("\n");
    }

    clock_t fin = clock();  // finaliza medición de tiempo
    double milisegundos = (double)(fin - inicio) / (double)CLOCKS_PER_SEC * 1000.0;

    printf("%s: Tiempo: %.3f ms\n", __func__, milisegundos);
    printf("Tamaño de i: %zu bytes\n", nro_bytes);
}

int main(void)
{
    // Necesario para imprimir caracteres específicos del español
    setlocale(LC_ALL, "Spanish"); // Necesita #include <locale.h>

    //->aquí va el código inicial de la práctica

    Ej1_Inicial();  // Llamada a la función Ej1_Inicial()

    printf("\nPor favor, pulse la tecla ENTRAR para terminar ...\n");
    (void)getchar();  // printf y getchar=> necesitan #include <stdio.h>

    return 0;
}

