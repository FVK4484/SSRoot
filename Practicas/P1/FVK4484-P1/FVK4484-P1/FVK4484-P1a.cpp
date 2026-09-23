#include <stdio.h>
#include "FVK4484-P1a.h"

// Implementación de la función que imprime el valor en binario
int ImprimeBinario(int valor, int bits)
{
    for (int i = bits - 1; i >= 0; i--)
    {
        printf("%d", (valor >> i) & 1);
        // Imprime un espacio para separar cada nibble
        if (i % 4 == 0)
            printf(" ");
        // Imprime un espacio adicional para separara cada byte
        if (i % 8 == 0)
            printf(" ");
    }
    return bits;
}