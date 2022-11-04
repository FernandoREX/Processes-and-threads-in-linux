/*
*	Fernando Rosas Gomez 🧙‍♂️
*	"Procesos en Linux" Sistemas Operativos
*	03/11/2022
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
* Escribir una funcion que cree n procesos hijos y a su vez cada hijo debe crear x procesos hijos
*/
void CreacionNietos(int n){
	pid_t pid;
  	int contador, contadorHijos, contador_h, contadorNieto;

	contador = contadorNieto = 1;
  
  	while (contador<=n) {
    	switch (pid = fork()) { //Creacion de procesos usando "fork()"
      	case -1: //Error al crear procesos
        	printf("\nError al crear el proceso\n");
        	exit(0);
      	break;
      	case 0: //Se creo exitosamente el proceso hijo
        	//printf("Soy el proceso hijo (pid=%i) y mi padre es (pid=%i)\n",getpid(), getppid());
        	for (contadorHijos = 0; contadorHijos < 2; contadorHijos++){
          		switch (pid=fork()) { //Creacion de procesos usando "fork()"
            		case -1: //Error al crear procesos
              			printf("Error al crear al proceso nieto\n");
            		case 0: //Se creo exitosamente el proceso nieto
              			printf("\tHijo(pid=%i)--->nieto%i(pid=%i)\n", getppid(),contadorNieto,getpid());
              			exit(0);
            		default://Proceso hijo
              		contadorNieto++;
          		}
        	}
        	exit(0);
        	contador_h++;
      	break;
      	default: //Proceso padre
      		printf("Padre(pid=%i)--->hijo%i(pid=%i)\n", getpid(), n ,pid);
      		n--;
      	break;
    	}
  	}
}

/*
* Modificar la funcion para que cada nieto realice la impresión a pantalla de una tabla de multiplicar.
* Cada nieto solo calcula e imprime la mitad de la tabla
* El hijo 1 de cada hijo (nieto1) deberá de imprimir la tabla correspondiente y su bloque del 1 al 5
* El hijo 2 de cada hijo (nieto2) deberá de imprimir la tabla correspondiente y su bloque del 6 al 10
* Cada nieto debe identificar al número de hijo que le corresponde a su padre, el número de nieto y su PID
*/

void Tarea2(int n){
	pid_t pid;
  	int contador, contadorHijos, contador_h, contadorNieto;

	contador = contadorNieto = 1;
  
  	while (contador<=n) {
    	switch (pid = fork()) { //Creacion de procesos usando "fork()"
      	case -1: //Error al crear procesos
        	printf("\nError al crear el proceso\n");
        	exit(0);
      	break;
      	case 0: //Se creo exitosamente el proceso hijo
        	for (contadorHijos = 0; contadorHijos < 2; contadorHijos++){
          		switch (pid=fork()) { //Creacion de procesos usando "fork()"
            		case -1: //Error al crear procesos
              			printf("Error al crear al proceso nieto\n");
            		case 0: //Se creo exitosamente el proceso nieto
              			printf("\tHijo(pid=%i)--->nieto%i(pid=%i)\n", getppid(),contadorNieto,getpid());
						for(int I = 1; I < 6; I++){ //Realiza la primera mitad de las operaciones n*1 --> n*5
							if(contadorNieto == 1){
								printf("\nHilo %i, Nieto %i (pid = %i); %ix%i = %i \n", n, contadorNieto, pid, n, I, n*I);
							}
						}
						for(int I = 6; I < 11; I++){ //Realiza la segunda mitad de las operaciones n*6 --> n*10
							if(contadorNieto == 2){
								printf("Hilo %i, Nieto %i (pid = %i); %ix%i = %i \n", n, contadorNieto, getpid(), n, I, n*I);
							}
						}
              			exit(0);
            		default: //Proceso hijo
              		contadorNieto++;
          		}
        	}
        	exit(0);
        	contador_h++;
      	break;
      	default: //Proceso Padre
      		printf("Padre(pid=%i)--->hijo%i(pid=%i)\n", getpid(), n ,pid);
      		n--;
      	break;
    	}
  	}
}

int main()
{
	int n;
	printf("Numero de procesos: ");
  	scanf("%i", &n);
  	printf("Soy el proceso principal: %i\n", getpid());
  	printf("-------------------------------------------\n");
	//Invocacion de las funciones
	//TareaB(n);
	Tarea2(n);
}
