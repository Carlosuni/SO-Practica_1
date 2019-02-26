
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


#define TAM_BUFFER = 1024


// Comprueba que el fichero existe
// Si el fichero existe devuelvo 1
int fichero_existe (const char* fichero)
{
	struct stat propiedades;
	return (stat(fichero, propiedades) == 0);
}

// Se le pasa por referencia 2 punteros a 2 arrays de caracteres
int copiar_archivo(char *archivo_original, char *archivo_copia)
{
	char buffer [1024];
	int fd_orig, fd_copia;
	int bytes_leidos;

	// Apertura del archivo original en modo lectura
	if (fd_orig = open(archivo_original, O_RONLY) < 0)
	{
		fprintf(stderr, "Error al abrir el fichero %s\n", archivo_original)

		exit(-1);
	}

	// Creación del archivo de copia en modo lectura
	if (fd_copia = creat(archivo_copia, 0664) < 0)
	{
		fprintf(stderr, "Error al crear el fichero %s\n", archivo_copia)

		exit(-1);
	}

	// Leemos el archivo original y lo vamos copiando al archivo destino

	// Leer hasta llegar al fin del fichero
	while (bytes_leidos = read(fd_orig, buffer, TAM_BUFFER) > 0)
	{
		if (write(archivo_original, buffer, bytes_leidos) < bytes_leidos)
		{
			// Si no puede escribir salimos
			close(fd_orig);
			close(fd_copia);
			exit(-3);
		}

	}

	// Comprueba que se ha podido leer el archivo
	if (bytes_leidos < 0)
	{
		close(fd_orig);
		close(fd_copia);
		perror("Error a leer el archivo\n");
		exit(-4);
	}


}

int main(int argc, char* argv[]) {

	char *ruta_f_original = "./archivo_entrada.txt";
	char *ruta_f_copia = "./archivo_salida.txt";

	if (argc < 3)
	{
		fprintf(stderr, "Error. Número de argumentos inválidos\n");
		exit(-1);
	}

	if (!fichero_existe(argv[1]))
	{
		perror("No existe el archivo");
		exit(-1);
	}

	int resultado;
	resultado = copiar_archivo(argv[1], argv[2])

	if (!copiar_archivo)

	//copiar_Archivo()


	return 0;
}
	

