#include <arpa/inet.h>
#include <stdio.h>
#include <netdb.h>
 
int main()
{
 char **doblePuntero;
 char EntradaDatos[80];
 char espacioIP[32];
 printf("Introduce dominio tipo: www.yomismo.com, o una IP\n");
 scanf(" %s",EntradaDatos);
 struct hostent *punteroHosten;
 punteroHosten=gethostbyname(EntradaDatos);
 printf("**********HOST************\n");
 printf("DIRECCIÓN: %s\n",punteroHosten->h_name );
 
 printf("**********ALIAS*****************\n");
 for(doblePuntero = punteroHosten->h_aliases; *doblePuntero != NULL; doblePuntero++) {
        printf("Alias del HOST: %s\n",*doblePuntero);
}
 printf("******TIPO DE DIRECCIÓN************\n");
 
 printf("TIPO: %i\n",punteroHosten->h_addrtype);
 
 printf("******BYTES DE LONGITUD DIRECCIÓN************\n");
 
 printf("LONGITUD: %i\n",punteroHosten->h_length);
 
printf("******LISTA DE DIRECCIONES************\n");
 
  doblePuntero = punteroHosten->h_addr_list;
            /* Imprime todos los alias llamando a la función ,inet_ntop()
             de #include <arpa/inet.h>  */
            for(; *doblePuntero!=NULL; doblePuntero++) {
                inet_ntop(punteroHosten->h_addrtype, *doblePuntero, espacioIP, sizeof(espacioIP));
                printf(" DIRECCIONES: %s\n", espacioIP);
            } //inet_ntop() convierte IP versión IPv4 y IPv6 de binario a texto
 
printf("ESPACIO OCUPADO POR CADA IP: BYTES %li\n", sizeof(espacioIP));
 
return 0;
 
}