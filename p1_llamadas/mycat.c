#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <sys/types.h>          /* Cabeceras llamada al sistema open  */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>             /* Cabecera llamadas al sistema read, write y close  */
#include <stdlib.h>

#define TAM_BUFFER 1024


// Comprueba que el fichero existe
// Si el fichero existe devuelvo 1
int fichero_existe (const char* fichero)
{
	struct stat propiedades;
 	return (stat(fichero, &propiedades) == 0);
}

// Se le pasa por referencia 1 puntero a 1 array de caracteres
int leer_archivo(char *archivo_original)
{
	char buffer [TAM_BUFFER];
	int fd_orig;
	int bytes_leidos;

	// Apertura del archivo original en modo lectura
	if ((fd_orig = open(archivo_original, O_RDONLY)) < 0)
	{
		fprintf(stderr, "Error al abrir el fichero %s\n", archivo_original);

		exit(-1);
	}


	// Leemos el archivo original y lo vamos imprimiendo por pantalla

	// Leer hasta llegar al fin del fichero
	while ((bytes_leidos = read(fd_orig, buffer, TAM_BUFFER)) > 0)
	{

        //printf("%s", buffer);
		if (write(STDOUT_FILENO, buffer, bytes_leidos) < bytes_leidos)
		{
			// Si no puede escribir salimos
			close(fd_orig);
			exit(-1);
		}

	}

	// Comprueba que se ha podido leer el archivo
	if (bytes_leidos < 0)
	{
		close(fd_orig);
		perror("Error a leer el archivo\n");
		exit(-1);
	}

    return 1;

}


int main(int argc, char *argv[])
{  
    if (argc != 2)      
	{
		fprintf(stderr, "Error. Número de argumentos inválidos\n");
		exit(-1);
	}

    //char *ruta_f_original = "./p1_tests/f1.txt";

    if (!fichero_existe(argv[1]))
	{
		perror("No existe el archivo");
		exit(-1);
	}

    
    //printf("Ejecutando programa mycat sobre el archivo %s\n", argv[1]);

    int resultado;
	resultado = leer_archivo(argv[1]);

    if (resultado < 0)
	{
	    perror("Error. No es posible leer el archivo");
	    exit(-1);
	}


    return 1;
}
