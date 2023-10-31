#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <omp.h>

#define SIZE 256
#define PUERTOSERVIDOR 1100
#define NUMEROCLIENTESENCOLA 10

int main(void)
{
	
   	// Descriptor del socket del servidor, descriptor del socket del cliente y tamaño de la estructura de la dirección del cliente.
	int socketServidor,socketCliente,tamanyoDireccionCliente;

	// Estructura de dirección del servidor y del cliente.
    struct sockaddr_in direccionSocketServidor,direccionSocketCliente; 
    
    // Resultado a enviar al cliente.
    char resultado[SIZE];

	// Tamaño del vector recibido, índice de recorrido.
	int tam, i;

	// Resultado numérico de la operación solicitada por el cliente.
	float r;

	// **0.5 puntos** EJ 2.1. Construcción del socket servidor y tratamiento del error.

  

	// **0.5 puntos** EJ 2.2. Construcción de la estructura de dirección del servidor.
  	

    // **0.5 puntos** EJ 2.3. Realización del bind y tratamiento del error.
 	
    // **0.5 puntos** EJ 2.4. Realización del listen y tratamiento del error.
 	

    // Bucle de espera activa.
    while(1)
    {
        printf("[SERVIDOR] Esperando datos\n");
        
        // **0.5 puntos** EJ 2.5. Realización del accept y tratamiento del error.
  	

        // **0.5 puntos** EJ 2.6. Recepción del tamaño de los vectores A y B enviado por el cliente y tratamiento del error.	   
        // **NOTA: en caso de error, cierre sólo la conexión con el socket cliente.
	

	   

        // **0.5 puntos** EJ 2.7. Recepción del vector A enviado por el cliente y tratamiento del error.	   
        // **NOTA: en caso de error, cierre sólo la conexión con el socket cliente.
 		

        // **0.5 puntos** EJ 2.8. Recepción del vector B enviado por el cliente y tratamiento del error.	   
        // **NOTA: en caso de error, cierre sólo la conexión con el socket cliente.
 	

	    

		// **0.5 puntos** EJ 2.9. Cálculo del producto escalar de dos vectores en paralelo con planificación dinamica, tamaño de chunk 3 y 2 threads.
	
		

        // **0.5 puntos** EJ 2.10. Envío del resultado al cliente y tartamiento del error.	   
        // **NOTA: en caso de error, cierre sólo la conexión con el socket cliente.
  	
  
    
		// Cierre del socket cliente.
        close(socketCliente);
    }

	// Cierre del socket servidor.
    close(socketServidor);
   
    return EXIT_SUCCESS;
}
