#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Tipo.h"
#include "Estado.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger,eTipo tipos[], eEstado estados[], int tamT, int tamE)
{
	int todoOk=-1;
	int cant;
	Passenger* aux=NULL;
	char matriz[7][100];
	if(pFile!=NULL && pArrayListPassenger!=NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],%[^\n],%[^\n],%[^\n]",matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6]);
		while(!feof(pFile)){
			cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6]);
			if(cant<7){
				break;
			}
			aux=Passenger_newParametros(matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6], tipos, estados,tamT, tamE);
			ll_add(pArrayListPassenger,aux);
		}
		todoOk=0;
	}
    return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	int cant;
	Passenger* aux=NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL){
		while(!feof(pFile)){
			aux=Passenger_new();
			cant=fread(aux, sizeof(Passenger), 1,pFile);
			if(cant<1){
				break;
			}
			ll_add(pArrayListPassenger,aux);
			todoOk=0;
		}

	}
	return todoOk;
}
