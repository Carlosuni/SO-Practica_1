#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <unistd.h>             /* Cabecera llamada al sistema gtcwd  */
#include <sys/types.h>          /* Cabeceras llamadas al sistema opendir, readdir y closedir  */
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#ifndef PATH_MAX
  #define PATH_MAX 255
#endif

int main(int argc, char *argv[])
{	

	//para el path y la estructura de directorios
	DIR * dir;
  	struct dirent *dirs;
  	char path[PATH_MAX];
  
 	path[PATH_MAX] = '\0';

 	//comprobamos que tenga como maximo 1 argumento
	if (argc > 2)      
	{
		printf("Error. Número de argumentos inválidos\n");

	}
	else if(argc==1){
		//si no se pasan argumentos lista el directorio en el que nos encontremos
		//con el "." nos situa en el directorio en el que nos encontramos ya, para poder abrirlo con opendir
		dir = opendir(".");

		while (dirs = readdir(dir), dirs != NULL)
		{
			if (strncmp(dirs->d_name, ".", PATH_MAX) == 0) continue;
			if (strncmp(dirs->d_name, "..", PATH_MAX) == 0) continue;

			//vamos mostrando por pantalla con puts (ya que se nos dijo que no usasemos printf`para mostrar por panatalla los directorios)
			puts(dirs->d_name);
		}
		//cerramos directorio
		closedir(dir);

	}
	else{
		//si se pasa argumento(directorio)... se lista el del directorio c
		printf("%s", argv[0]);
		printf("%s", argv[1]);
		printf("ok2\n");

		//ponemos en el path el argumento 1 ( que es el directorio que queremos listar)
		strncpy(path, argv[1], PATH_MAX-1);
		dir = opendir(path);
 		//si es NULL es que no pudimos abrir el directorio
	  	if (dir == NULL)
	  	{
	   		fprintf(stderr,"No se puede abrir «%s»: %s\n",path,strerror(errno));
	   		return -1;
	   	}

	   	//recorremos el directorio de la misma manera que antes mostrando su contenido
		while (dirs = readdir(dir), dirs != NULL)
		{
			if (strncmp(dirs->d_name, ".", PATH_MAX) == 0) continue;
			if (strncmp(dirs->d_name, "..", PATH_MAX) == 0) continue;
			
			//vamos mostrando por pantalla con puts (ya que se nos dijo que no usasemos printf`para mostrar por panatalla los directorios)
			puts(dirs->d_name);
		}
		//cerramos directorio
		closedir(dir);

	}

	return 0;
}
