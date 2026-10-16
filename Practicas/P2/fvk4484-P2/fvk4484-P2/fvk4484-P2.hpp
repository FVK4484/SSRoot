// Declaraciones asociadas a una clase.
// Namespace: agrupación de clases, funciones y variables globales
namespace ss {

	class Crono {	// Declaración de la clase Crono
		void Iniciar();
		void Parar();
		double Lee();
	private:
		int clocks_ini;
		int clocks_fin;
		int clocks;
		float segs;
	public:
		Crono();  // Constructor (opcional)
		~Crono(); // Destructor (opcional)

	}; // fin clase

} // fin namespace ss