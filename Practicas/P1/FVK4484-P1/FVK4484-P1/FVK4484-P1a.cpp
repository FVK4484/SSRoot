#include <stdio.h>

// Implementación de la función que imprime el valor en binario
size_t ImprimeBinario(int valor, int bits)
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

size_t ImprimeBinario(char* buffer, size_t tamBuffer, int valor, int bits)
{
	size_t len = 0;
	for (int i = bits - 1; i >= 0; i--)
	{
		len += snprintf(buffer + len, tamBuffer - len,
			"%d", (valor >> i) & 1);
		// Imprime un espacio para separar cada nibble
		if ((i % 4) == 0)
			snprintf(buffer + len, tamBuffer - len, " ");
		if ((i % 8) == 0)
			snprintf(buffer + len, tamBuffer - len, " ");
	}
	return len;
}