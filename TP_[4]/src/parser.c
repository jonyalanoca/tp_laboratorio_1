#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "cpus.h"
int parser_cargarTexto(FILE* pFile, LinkedList* listaCPU){
	int todoOk=-1;
	char matriz[9][100];
	int cant;
	eCPU* auxCPU;
	if(pFile!=NULL && listaCPU!=NULL){

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6],matriz[7],matriz[8]);
		while(!feof(pFile)){
			cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6],matriz[7],matriz[8]);
			if(cant<9){
				break;
			}
			auxCPU=cpu_nuevoParametros(matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6],matriz[7],matriz[8]);
			ll_add(listaCPU, auxCPU);
		}
		todoOk=0;
	}
	return todoOk;
}
