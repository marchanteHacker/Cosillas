
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
    int iniA, iniB;

    // Tamaño de los vectores, índice de recorrido.
    int tam, i;

    // Resultado devuelto por el servidor.
    char resultado[SIZE];

    // Descriptor del socket del servidor
    int socketServidor;

    // Estructura de dirección del servidor.
    struct sockaddr_in direccionSocketServidor;

    // **0.5 puntos** EJ 1.1. Tratamiento de errores en los parámetros de entrada.

    if(argc < 1){
        printf("Comando incorrecto -> ./Cliente tam");
        exit(EXIT_FAILURE);
    }

    // **0.5 puntos** EJ 1.2. Inicialización de las variables iniA, iniB, y tam.

    tam = atoi(argv[1]);
    int vectorA[tam], vectorB[tam];

    for(int i = 0; i < tam; i++){
        printf("Introduce el valor para la posicion %d del vector A: ", i);
        scanf("%d", &iniA);
        vectorA[i] = iniA;
        printf("Introduce el valor para la posicion %d del vector B: ", i);
        scanf("%d", &iniB);
        vectorB[i] = iniB;
    }

    printf("Vector A ->");
    for(int i = 0; i < tam; i++){
        printf("%d ",vectorA[i]);
    }

    printf("\n");

    printf("Vector B ->");
    for(int i = 0; i < tam; i++){
        printf("%d ",vectorB[i]);
    }

    // **0.5 puntos** EJ 1.4. Construcción del socket servidor y tratamiento del error.

    socketServidor = socket(AF_INET, SOCK_STREAM, 0);
    if(socketServidor == -1){
        perror("SOCKET");
        exit(EXIT_FAILURE);
    }

    // **0.5 puntos** EJ 1.5. Construcción de la estructura de dirección del servidor y tratamiento del error.

    direccionSocketServidor.sin_family = AF_INET;
    direccionSocketServidor.sin_port = htons(PUERTOSERVIDOR);
    if(inet_pton(AF_INET, IPSERVIDOR, &direccionSocketServidor.sin_addr.s_addr) == -1){
        perror("INET_PTON");
        close(socketServidor);
        exit(EXIT_FAILURE);
    }

    // **0.5 puntos** EJ 1.6. Realizar conexión con el servidor y tratamiento del error.

    if(connect(socketServidor, (struct sockaddr *)&direccionSocketServidor, sizeof(direccionSocketServidor)) == -1){
        perror("CONNECT");
        close(socketServidor);
        exit(EXIT_FAILURE);
    }

    // **0.5 puntos** EJ 1.7. Envío del tamaño de los vectores y tratamiento del error.

    if(write(socketServidor, &tam, sizeof(tam)) == -1){
        perror("WRITE");
        close(socketServidor);
        exit(EXIT_FAILURE);
    }

    // **0.5 puntos** EJ 1.8. Envío del vector A al servidor y tratamiento del error.

    if(write(socketServidor, vectorA, sizeof(vectorA)) == -1){
        perror("WRITE");
        close(socketServidor);
        exit(EXIT_FAILURE);
    }

    // **0.5 puntos** EJ 1.9. Envío del vector B al servidor y tratamiento del error.

    if(write(socketServidor, vectorB, sizeof(vectorB)) == -1){
        perror("WRITE");
        close(socketServidor);
        exit(EXIT_FAILURE);
    }

    // **0.5 puntos** EJ 1.10. Recepción de los resultados del servidor y tratamiento del error.

    if(read(socketServidor, resultado, sizeof(resultado)) == -1){
        perror("READ");
        close(socketServidor);
        exit(EXIT_FAILURE);
    }

    printf("\n%s\n", resultado);

    // Cierre del socket servidor.
    close(socketServidor);
    return EXIT_SUCCESS;
}
