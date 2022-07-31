#include <stdio.h>
#include <stdlib.h> 
#include<unistd.h>

int main(int argc, char const *argv[])
{
   
	char Codigo_ascii[17];
    size_t i, j;
    Codigo_ascii[16] = '\0';
	char cadena[10]="HOLODOMOR";
    char *apuntador_ptr;
    char *mipuntero=cadena;
    
    int  salida;	/* Salida del comando */
    char comando[60];	/* Comando a ejecutar */


	for (int i = 0; i < 10; ++i)
	{
		printf("En la dirección: [%p]  Letra: [%c] \n",&cadena[i],cadena[i]);
	apuntador_ptr ++;

	}

	for (i = 0; i < 123; ++i) {
		printf("%02X ", ((unsigned char*)mipuntero)[i]);
		if (((unsigned char*)mipuntero)[i] >= ' ' && ((unsigned char*)mipuntero)[i] <= '~')
		 {
			Codigo_ascii[i % 16] = ((unsigned char*)mipuntero)[i];
		} else {
			Codigo_ascii[i % 16] = '.';
		}
		if ((i+1) % 8 == 0 || i+1==123) {
			printf(" ");
			if ((i+1) % 16 == 0) {
				printf(" |  %s \n", Codigo_ascii);
			} 
			}
			}


long int pid;
pid=getpid();
printf("\n");
printf( " PID asignado por el kernel:%ld\n",pid);

    printf ("Llamada (pmap  -d) a system.\n");
    sprintf (comando, "pmap  -d %ld", pid);
    salida = system (comando);
        
	return 0;
}