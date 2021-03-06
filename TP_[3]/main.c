#include <stdio.h>
#include <stdlib.h>


#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

#include "auxiliares.h"
#include "Tipo.h"
#include "Estado.h"
#include "menus.h"
#define TAM_TIPO 3
#define TAM_ESTADO 4

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
	int vacio;
	do{
		switch(menu())
		{
			case 1:
				if(controller_BorrarYCargar(listaPasajeros)=='s'){
					if(!controller_loadFromText("data.csv",listaPasajeros, tipos, estados, TAM_TIPO, TAM_ESTADO)){
						printf("Se cargaron los datos con exito.\n");
					}else{
						printf("Hubo en error en las validaciones.\n");
					}
				}
				break;
			case 2:
				if(controller_BorrarYCargar(listaPasajeros)=='s'){
					if(!controller_loadFromBinary("data.bin",listaPasajeros)){
						printf("Se cargaron los datos con exito.\n");
					}else{
						printf("Hubo en error en las validaciones. O Archivo bin no existe\n");
					}
				}
				break;
			case 3:
				if(controller_addPassenger(listaPasajeros, tipos, estados, TAM_TIPO, TAM_ESTADO)==-1){
					printf("Hubo en error en las validaciones.\n");
				}
				break;
			case 4:
				vacio=ll_isEmpty(listaPasajeros);
				if(vacio){
					printf("Primero carge algun registro. (Opcion: 1-2-3)");
				}else if(!vacio){
					if(controller_editPassenger(listaPasajeros, tipos, estados, TAM_TIPO, TAM_ESTADO)==-1){
						printf("Hubo un problema con la validacion.\n");
					}
				}
				break;
			case 5:
				vacio=ll_isEmpty(listaPasajeros);
				if(vacio){
					printf("Primero carge algun registro. (Opcion: 1-2-3)");
				}else if(!vacio){
					if(controller_removePassenger(listaPasajeros, tipos, estados, TAM_TIPO, TAM_ESTADO)==-1){
						printf("Hubo un problema con la validacion.\n");
					}
				}
				break;
			case 6:
				vacio=ll_isEmpty(listaPasajeros);
				if(vacio){
					printf("Primero carge algun registro. (Opcion: 1-2-3)");
				}else if(!vacio){
					if(controller_ListPassenger(listaPasajeros, tipos, estados,TAM_TIPO, TAM_ESTADO)==-1){
						printf("Hubo un problema con la validacion.\n");
					}
				}
				break;
			case 7:
				vacio=ll_isEmpty(listaPasajeros);
				if(vacio){
					printf("Primero carge algun registro. (Opcion: 1-2-3)");
				}else if(!vacio){
					if(controller_sortPassenger(listaPasajeros, tipos, estados,TAM_TIPO, TAM_ESTADO)==-1){
						printf("Hubo un problema con la validacion.\n");
					}
				}

				break;
			case 8:
				if(controller_saveAsText("data.csv",listaPasajeros, tipos, estados,TAM_TIPO, TAM_ESTADO)==-1){
					printf("Hubo un problema con la validacion.\n");
				}else{
					printf("Se guardo con exito.\n");
				}
				break;
			case 9:
				if(controller_saveAsBinary("data.bin",listaPasajeros)==-1){
					printf("Hubo un problema con la validacion.\n");
				}else{
					printf("Se guardo con exito.\n");
				}
				break;
			case 10:
				if(!cerrar(&salir)){
					printf("Hubo un problema con la validacion.\n");
				}else{
					controller_liberarMemoria(listaPasajeros);
				}
				break;
		}
		system("pause");
		system("cls");
	}while(salir!='s');

    return 0;
}
