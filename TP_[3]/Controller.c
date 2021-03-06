#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "validaciones.h"
#include "menus.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
	int todoOk=-1;
	if (path!=NULL &&  pArrayListPassenger!=NULL){
		FILE* pFile= fopen(path,"r");
		if(pFile!=NULL){
			parser_PassengerFromText(pFile,pArrayListPassenger, tipos, estados, tamT, tamE);
			todoOk=0;
		}
		fclose(pFile);
	}
	return todoOk;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	if (path!=NULL &&  pArrayListPassenger!=NULL){
		FILE* pFile= fopen(path,"rb");
		if(pFile!=NULL){
			parser_PassengerFromBinary(pFile,pArrayListPassenger);
			todoOk=0;
		}
		fclose(pFile);
	}
	return todoOk;
}
int controller_addPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
    int todoOk=-1;
    char opcion;
    if(pArrayListPassenger!=NULL){
    	Passenger* aux=NULL;
    	char matriz[7][20];
    	int id=controller_searchMaxId(pArrayListPassenger);
    	float precio;
    	int tipoPasajero;
    	int vueloEstado;
    	system("cls");
    	//cargar y validar datos
    	cargarValidarCadena("Ingrese el nombre del pasajero",20,matriz[1]);
    	cargarValidarCadena("Ingrese el Apellido del pasajero",20,matriz[2]);
    	cargarValidarDecimalPositivo("Ingrese el precio del vuelo",&precio);
    	cargarValidarAlfaNumerico("Ingrese el codigo de vuelo",20,matriz[4]);
    	mostrarTipos(tipos,tamT);
    	buscarIdExistenteTipo(tipos, tamT, &tipoPasajero);
    	mostrarEstados(estados, tamE);
    	buscarIdExistenteEstado(estados, tamE, &vueloEstado);
    	//transformacion a strings
    	id++;
    	sprintf(matriz[0],"%d",id);
    	sprintf(matriz[3],"%f",precio);
    	obtenerDescripcionPorIdTipo(tipos,tamT,tipoPasajero, matriz[5]);
    	obtenerDescripcionPorIdEstado(estados, tamE,vueloEstado, matriz[6]);
    	//
    	aux=Passenger_newParametros(matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6], tipos, estados,tamT, tamE);
    	system("cls");
    	controller_showHeadList();
    	mostrarPasajero(aux, tipos, estados,tamT, tamE);
    	printf("----------------------------------------------------------------------------------------\n");
    	cargarValidarCharEntreDos("Confirme para guardar el registro (s/n)",&opcion,'s','n');
    	if(opcion=='s'){
    		ll_add(pArrayListPassenger,aux);
    		printf("Se guardaron los datos con exito.\n");
    	}else{
    		free(aux);
    		printf("No se realizaron cabios.\n");
    	}
    	todoOk=0;
    }
    return todoOk;
}

int controller_editPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
    int todoOk=-1;
    char volver='n';
    int auxId;
    int auxIndex;
    Passenger* aux=NULL;
    if(pArrayListPassenger!=NULL && tipos!=NULL && estados!=NULL && tamT>0 && tamE>0){
    	todoOk=0;
    	controller_ListPassenger(pArrayListPassenger, tipos, estados, tamT, tamE);
    	cargarValidarEnteroPositivo("Ingrese el id del Pasajero  a modificar",&auxId);
    	auxIndex=controller_findIndexById(pArrayListPassenger, auxId);
    	if(auxIndex!=-1){
    		aux=(Passenger*)ll_get(pArrayListPassenger,auxIndex);
			do{
				switch(menuModificar())
				{
					case 1:
						if(Passenger_modificarNombre(aux)==0){
							printf("Se guardaron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 2:
						if(Passenger_modificarApellido(aux)==0){
							printf("Se guardaron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 3:
						if(Passenger_modificarCodigoVuelo(aux)==0){
							printf("Se guardaron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 4:
						if(Passenger_modificarPrecio(aux)==0){
							printf("Se guardaron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 5:
						if(Passenger_modificarTipoPasajero(aux, tipos, tamT)==0){
							printf("Se guardaron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 6:
						if(Passenger_modificarEstadoVuelo(aux, estados, tamE)==0){
							printf("Se guardaron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 7:
						volver='s';
						break;
				}
				if(volver=='n'){
					system("pause");
					system("cls");
				}

			}while(volver!='s');
    	}else{
    		printf("No se encontro el ID.\n");
    	}
    }
    return todoOk;
}

int controller_removePassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
    int todoOk=-1;
    int auxId;
    int auxIndex;
    char opcion;
    Passenger* aux=NULL;
    if(pArrayListPassenger!=NULL && tipos!=NULL && estados!=NULL && tamT>0 && tamE>0){
    	controller_ListPassenger(pArrayListPassenger, tipos, estados, tamT, tamE);
		cargarValidarEnteroPositivo("Ingrese el id del Pasajero  a remover",&auxId);
		auxIndex=controller_findIndexById(pArrayListPassenger, auxId);
		if(auxIndex!=-1){
			aux=(Passenger*)ll_get(pArrayListPassenger, auxIndex);
			system("cls");
			controller_showHeadList();
			mostrarPasajero(aux, tipos, estados,tamT, tamE);
			printf("----------------------------------------------------------------------------------------\n");
			cargarValidarCharEntreDos("Confirme para borrar el registro (s/n)",&opcion,'s','n');
			if(opcion=='s'){
				ll_remove(pArrayListPassenger,auxIndex);
				free(aux);
				printf("Se removio el registro con exito.\n");
			}else{
				printf("No se realizaron cabios.\n");
			}
		}else{
			printf("No se encontro el ID.\n");
    	}
		todoOk=0;
    }
    return todoOk;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
	int todoOk=-1;
	Passenger* aux=NULL;
	if (pArrayListPassenger!=NULL){
		system("cls");
		controller_showHeadList();
		for(int i =0; i<ll_len(pArrayListPassenger); i++){
			aux=(Passenger*)ll_get(pArrayListPassenger, i);
			mostrarPasajero(aux, tipos, estados, tamT, tamE);
		}
		printf("----------------------------------------------------------------------------------------\n");
		todoOk=0;
	}
	return todoOk;
}
void controller_showHeadList(void){
	printf("----------------------------------------------------------------------------------------\n");
	printf("   ID	    NAME        LASTNAME      PRICE     FLYCODE  TYPE-PASSENGER   STATUS-FLIGHT|\n");
	printf("----------------------------------------------------------------------------------------\n");
}

int controller_sortPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
	int todoOk=-1;
	if (pArrayListPassenger!=NULL){
		switch(menuOrdenar()){
			case 1:
				if(!ll_sort(pArrayListPassenger,compararPorId,ascendenteDescendente())){
					printf("Uff! Costo, pero lo logramos. Se Ordeno la lista con exito.\n");
				}else{
					printf("Ocurrio un problema al ordenar.\n");
				}
				break;
			case 2:
				if(!ll_sort(pArrayListPassenger,compararPorNombre,ascendenteDescendente())){
					printf("Uff! Costo, pero lo logramos. Se Ordeno la lista con exito.\n");
				}else{
					printf("Ocurrio un problema al ordenar.\n");
				}
				break;
			case 3:
				if(!ll_sort(pArrayListPassenger,compararPorApellido,ascendenteDescendente())){
					printf("Uff! Costo, pero lo logramos. Se Ordeno la lista con exito.\n");
				}else{
					printf("Ocurrio un problema al ordenar.\n");
				}
				break;
			case 4:
				if(!ll_sort(pArrayListPassenger,compararPorPrecio,ascendenteDescendente())){
					printf("Uff! Costo, pero lo logramos. Se Ordeno la lista con exito.\n");
				}else{
					printf("Ocurrio un problema al ordenar.\n");
				}
				break;
			case 5:
				if(!ll_sort(pArrayListPassenger,compararPorCodigo,ascendenteDescendente())){
					printf("Uff! Costo, pero lo logramos. Se Ordeno la lista con exito.\n");
				}else{
					printf("Ocurrio un problema al ordenar.\n");
				}
				break;
			case 6:
				if(!ll_sort(pArrayListPassenger,compararPorTipo,ascendenteDescendente())){
					printf("Uff! Costo, pero lo logramos. Se Ordeno la lista con exito.\n");
				}else{
					printf("Ocurrio un problema al ordenar.\n");
				}
				break;
			case 7:
				if(!ll_sort(pArrayListPassenger,compararPorEstado,ascendenteDescendente())){
					printf("Uff! Costo, pero lo logramos. Se Ordeno la lista con exito.\n");
				}else{
					printf("Ocurrio un problema al ordenar.\n");
				}
				break;
		}
		todoOk=0;
	}
	return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
    int todoOk=-1;
    int len;
    char tipoPasajeroStr[20];
    char estadoVueloStr[20];
    Passenger* aux;
    if(pArrayListPassenger!=NULL&& path!=NULL){
    	FILE* pFile=fopen(path, "w");
    	if(pFile!=NULL){
    		len=ll_len(pArrayListPassenger);
    		fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
    		for(int i=0; i<len;i++){
    			aux=(Passenger*)ll_get(pArrayListPassenger, i);
    			obtenerDescripcionPorIdTipo(tipos, tamT, aux->tipoPasajero, tipoPasajeroStr);
    			obtenerDescripcionPorIdEstado(estados, tamE, aux->estadoVuelo, estadoVueloStr);
    			fprintf(pFile,"%d,%s,%s,%0.f,%s,%s,%s\n",aux->id, aux->nombre, aux->apellido, aux->precio, aux->codigoVuelo, tipoPasajeroStr, estadoVueloStr);
    		}
    		todoOk=0;
    	}
    	fclose(pFile);
    }
    return todoOk;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
    int len;
    Passenger* aux=NULL;
    if(pArrayListPassenger!=NULL&& path!=NULL){
    	FILE* pFile= fopen(path,"wb");
		len=ll_len(pArrayListPassenger);
		if(pFile!=NULL){
			for(int i =0; i<len; i++){
				aux=(Passenger*)ll_get(pArrayListPassenger, i);
				fwrite(aux, sizeof(Passenger), 1,pFile);
			}
			todoOk=0;
		}
		fclose(pFile);
    }
    return todoOk;
}
int controller_searchMaxId(LinkedList* pArrayListPassenger){
	int todoOk=-1;
	int banderaMax=0;
	int len;
	int idMax;
	Passenger* aux=NULL;
	if(pArrayListPassenger!=NULL){
		len=ll_len(pArrayListPassenger);
		if(len>0){
			for(int i=0;i<len;i++){
				aux=(Passenger*)ll_get(pArrayListPassenger,i);
				if(banderaMax==0){
					idMax=aux->id;
					banderaMax=1;
				}else if(idMax<aux->id){
					idMax=aux->id;
				}
			}
			todoOk=idMax;
		}else{
			todoOk=0;
		}
	}
	return todoOk;

}
int controller_findIndexById(LinkedList* pArrayListPassenger, int id){
	int todoOk=-1;
	int len;
	Passenger* aux;
	if(pArrayListPassenger){
		len=ll_len(pArrayListPassenger);
		for(int i=0; i<len;i++){
			aux=(Passenger*)ll_get(pArrayListPassenger, i);
			if(aux->id==id){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}
int controller_liberarMemoria(LinkedList* pArrayListPassenger){
	int todoOk=-1;
	if(pArrayListPassenger!=NULL){
		controller_limpiarElementos(pArrayListPassenger);
		ll_deleteLinkedList(pArrayListPassenger);
		todoOk=0;
	}
	return todoOk;
}
char controller_BorrarYCargar(LinkedList* pArrayListPassenger){
	char aux='s';
	if(pArrayListPassenger!=NULL){
		if(!ll_isEmpty(pArrayListPassenger)){
				printf("ADVERTENCIA.\nESTA POR CARGAR NUEVO ARCHIVO.\nSe borraran los datos existentes en el programa.\n");
				cargarValidarCharEntreDos("Confirme la nueva carga(s/n)",&aux,'s','n');
				if(aux=='s'){
					controller_limpiarElementos(pArrayListPassenger);
					ll_clear(pArrayListPassenger);
				}
			}
	}
	return aux;
}
int controller_limpiarElementos(LinkedList* pArrayListPassenger){
	int todoOk=-1;
	int len;
	if(pArrayListPassenger!=NULL){
		len=ll_len(pArrayListPassenger);
		for (int i=0;i<len;i++){
			free((Passenger*)ll_get(pArrayListPassenger,i));
		}
		todoOk=0;
	}
	return todoOk;
}
