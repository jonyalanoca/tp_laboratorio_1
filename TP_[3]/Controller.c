#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "validaciones.h"
#include "menus.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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
/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
    int todoOk=-1;
    char volver='n';
    int auxId;
    int auxIndex;
    Passenger* aux=NULL;
    if(pArrayListPassenger!=NULL){
    	controller_ListPassenger(pArrayListPassenger, tipos, estados, tamT, tamE);
    	cargarValidarEnteroPositivo("Ingrese el id del Pasajero  a midificar",&auxId);
    	auxIndex=controller_findIndexById(pArrayListPassenger, auxId);
    	if(auxIndex!=-1){
    		aux=(Passenger*)ll_get(pArrayListPassenger,auxIndex);
			do{
				switch(menuModificar())
				{
					case 1:
						if(Passenger_modificarNombre(aux)==0){
							printf("Seguadoron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 2:
						if(Passenger_modificarApellido(aux)==0){
							printf("Seguadoron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 3:
						if(Passenger_modificarCodigoVuelo(aux)==0){
							printf("Seguadoron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 4:
						if(Passenger_modificarPrecio(aux)==0){
							printf("Seguadoron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 5:
						if(Passenger_modificarTipoPasajero(aux, tipos, tamT)==0){
							printf("Seguadoron los cambios con exito.\n");
						}else{
							printf("Hubo un erro en la validacion NULL.\n");
						}
						break;
					case 6:
						if(Passenger_modificarEstadoVuelo(aux, estados, tamE)==0){
							printf("Seguadoron los cambios con exito.\n");
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

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
	int returnAux=0;
	Passenger* aux=NULL;
	if (pArrayListPassenger!=NULL){
		system("cls");
		controller_showHeadList();
		for(int i =0; i<ll_len(pArrayListPassenger); i++){
			aux=(Passenger*)ll_get(pArrayListPassenger, i);
			mostrarPasajero(aux, tipos, estados, tamT, tamE);
		}
	}
	return returnAux;
}
void controller_showHeadList(void){
	printf("----------------------------------------------------------------------------------------\n");
	printf("   ID	    NAME        LASTNAME      PRICE     FLYCODE  TYPE-PASSENGER   STATUS-FLIGHT|\n");
	printf("----------------------------------------------------------------------------------------\n");
}
/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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
