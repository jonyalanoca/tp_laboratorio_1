#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

#include "Tipo.h"
#include "Estado.h"
#include "otros.h"
#include "menus.h"
#define TAM_TIPO 3
#define TAM_ESTADO 4

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo dato.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);
    LinkedList* listaPasajeros = ll_newLinkedList();
    verificarNULL(listaPasajeros);
	eTipo tipos[TAM_TIPO];
	hardCodearTipos(tipos, TAM_TIPO);
	eEstado estados[TAM_ESTADO];
	hardCodearEstados(estados, TAM_ESTADO);
	char salir;
	do{
		switch(menu())
		{
			case 1:
				controller_loadFromText("data.csv",listaPasajeros, tipos, estados, TAM_TIPO, TAM_ESTADO);
				break;
			case 2:
				controller_loadFromBinary("data.bin",listaPasajeros);
				break;
			case 3:
				controller_addPassenger(listaPasajeros, tipos, estados, TAM_TIPO, TAM_ESTADO);
				break;
			case 4:
				controller_editPassenger(listaPasajeros, tipos, estados, TAM_TIPO, TAM_ESTADO);
				break;
			case 5:
				controller_removePassenger(listaPasajeros, tipos, estados, TAM_TIPO, TAM_ESTADO);
				break;
			case 6:
				controller_ListPassenger(listaPasajeros, tipos, estados,TAM_TIPO, TAM_ESTADO);
				break;
			case 7:
				controller_sortPassenger(listaPasajeros, tipos, estados,TAM_TIPO, TAM_ESTADO);
				break;
			case 8:
				controller_saveAsText("data.csv",listaPasajeros, tipos, estados,TAM_TIPO, TAM_ESTADO);
				break;
			case 9:
				controller_saveAsBinary("data.bin",listaPasajeros);
				break;
			case 10:
				if(!cerrar(&salir)){
					printf("Hubo un problema con la validacion.\n");
				}
				break;
		}
		system("pause");
		system("cls");
	}while(salir!='s');

    return 0;
}


