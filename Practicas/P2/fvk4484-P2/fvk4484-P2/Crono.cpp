#include <cstdio>
#include <ctime>
#include "fvk4484-P2.hpp"
#include <Windows.h>

// Definiciones asociadas a una clase.
namespace ss {  // Namespace: agrupación de clases, funciones y variables globales

	// Definición del constructor
	Crono::Crono()
	{
		clocks_ini = 0;
		clocks_fin = 0;
		clocks = 0;
		segs = 0.0;
	}
	// Definición del destructor
	Crono::~Crono()
	{
	}

	void Crono::Iniciar() {
		clocks_ini = clock();
	}

	void Crono::Parar() {
		clocks_fin = clock();
		clocks = clocks_fin - clocks_ini;
		segs = (double)clocks / CLOCKS_PER_SEC;
	}

	double Crono::Lee() {
		return segs;
	}

} // fin namespace ss