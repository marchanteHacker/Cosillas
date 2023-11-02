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
    int socketServidor, socketCliente, tamanyoDireccionCliente;

    // Estructura de dirección del servidor y del cliente.
    struct sockaddr_in direccionSocketServidor, direccionSocketCliente;

    // Resultado a enviar al cliente.
    char resultado[SIZE];

    // Tamaño del vector recibido, índice de recorrido.
    int tam, i;

    // Resultado numérico de la operación solicitada por el cliente.
    // int r;

    // **0.5 puntos** EJ 2.1. Construcción del socket servidor y tratamiento del error.

    socketServidor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketServidor == -1)
    {
        perror("SOCKET");
        exit(EXIT_FAILURE);
    }

    // **0.5 puntos** EJ 2.2. Construcción de la estructura de dirección del servidor.

    direccionSocketServidor.sin_family = AF_INET;
    direccionSocketServidor.sin_port = htons(PUERTOSERVIDOR);
    direccionSocketServidor.sin_addr.s_addr = INADDR_ANY;

    // **0.5 puntos** EJ 2.3. Realización del bind y tratamiento del error.

    if (bind(socketServidor, (struct sockaddr *)&direccionSocketServidor, sizeof(direccionSocketServidor)) == -1)
    {
        perror("BIND");
        close(socketServidor);
        exit(EXIT_FAILURE);
    }

    // **0.5 puntos** EJ 2.4. Realización del listen y tratamiento del error.

    if (listen(socketServidor, NUMEROCLIENTESENCOLA) == -1)
    {
        perror("LISTEN");
        close(socketServidor);
        exit(EXIT_FAILURE);
    }

    // Bucle de espera activa.
    while (1)
    {
        printf("[SERVIDOR] Esperando datos\n");

        // **0.5 puntos** EJ 2.5. Realización del accept y tratamiento del error.

        socketCliente = accept(socketServidor, (struct sockaddr *)&direccionSocketCliente, &tamanyoDireccionCliente);
        if (socketCliente == -1)
        {
            perror("SOCKET CLIENTE");
            exit(EXIT_FAILURE);
        }

        // **0.5 puntos** EJ 2.6. Recepción del tamaño de los vectores A y B enviado por el cliente y tratamiento del error.
        // **NOTA: en caso de error, cierre sólo la conexión con el socket cliente.

        if (read(socketCliente, &tam, sizeof(tam)) == -1)
        {
            perror("READ");
            close(socketCliente);
            exit(EXIT_FAILURE);
        }

        int vectorA[tam], vectorB[tam];

        // **0.5 puntos** EJ 2.7. Recepción del vector A enviado por el cliente y tratamiento del error.
        // **NOTA: en caso de error, cierre sólo la conexión con el socket cliente.

        if (read(socketCliente, vectorA, sizeof(vectorA)) == -1)
        {
            perror("READ");
            close(socketCliente);
            exit(EXIT_FAILURE);
        }

        // **0.5 puntos** EJ 2.8. Recepción del vector B enviado por el cliente y tratamiento del error.
        // **NOTA: en caso de error, cierre sólo la conexión con el socket cliente.

        if (read(socketCliente, vectorB, sizeof(vectorB)) == -1)
        {
            perror("READ");
            close(socketCliente);
            exit(EXIT_FAILURE);
        }

        // **0.5 puntos** EJ 2.9. Cálculo de la Suma de elementos de 2 arreglos en paralelo

        int r[tam];

	#pragma omp parallel for schedule(static, 1)
	    for (int i = 0; i < tam; i++)
		r[i] = vectorA[i] + vectorB[i];
        

        sprintf(resultado, "Resultado: ");
        for (int i = 0; i < tam; i++)
        {
            sprintf(resultado + strlen(resultado), "%d", r[i]);
            if (i < tam - 1)
            {
                sprintf(resultado + strlen(resultado), ", ");
            }
        }

        // **0.5 puntos** EJ 2.10. Envío del resultado al cliente y tartamiento del error.
        // **NOTA: en caso de error, cierre sólo la conexión con el socket cliente.

        if(write(socketCliente, resultado, sizeof(resultado)) == -1){
            perror("WRITE");
            close(socketCliente);
            exit(EXIT_FAILURE);
        }

        // Cierre del socket cliente.
        close(socketCliente);
    }

    // Cierre del socket servidor.
    close(socketServidor);

    return EXIT_SUCCESS;
}
