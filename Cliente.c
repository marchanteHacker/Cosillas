
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE 256
#define IPSERVIDOR "127.0.0.1"
#define PUERTOSERVIDOR 1100

int main(int argc, char *argv[])
{
    // Valor inicial del vector A, valor inicial del vector B.
    float iniA, iniB;

    // Tamaño de los vectores, índice de recorrido.
    int tam, i;

    // Resultado devuelto por el servidor.
    char resultado[SIZE];

    // Descriptor del socket del servidor
    int socketServidor;

    // Estructura de dirección del servidor.
    struct sockaddr_in direccionSocketServidor;

    // **0.5 puntos** EJ 1.1. Tratamiento de errores en los parámetros de entrada.

    // **0.5 puntos** EJ 1.2. Inicialización de las variables iniA, iniB, y tam.

    // **0.5 puntos** EJ 1.4. Construcción del socket servidor y tratamiento del error.

    // **0.5 puntos** EJ 1.5. Construcción de la estructura de dirección del servidor y tratamiento del error.

    // **0.5 puntos** EJ 1.6. Realizar conexión con el servidor y tratamiento del error.

    // **0.5 puntos** EJ 1.7. Envío del tamaño de los vectores y tratamiento del error.

    // **0.5 puntos** EJ 1.8. Envío del vector A al servidor y tratamiento del error.

    // **0.5 puntos** EJ 1.9. Envío del vector B al servidor y tratamiento del error.

    // **0.5 puntos** EJ 1.10. Recepción de los resultados del servidor y tratamiento del error.

    // Cierre del socket servidor.
    close(socketServidor);
    return EXIT_SUCCESS;
}
