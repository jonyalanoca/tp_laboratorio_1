#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpus.h"
#include "auxiliares.h"

eCPU* cpu_nuevo(void){
	eCPU* aux=(eCPU*)malloc(sizeof(eCPU));
	verificarNULL(aux);
	return aux;
}
eCPU* cpu_nuevoParametros(char* rank, char* fabricante, char* procesador, char* cache, char* frecuencia, char* zocalos, char* nucleos, char* hilos, char* lanzamiento){
	eCPU* auxNuevoCPU=cpu_nuevo();
	if(rank!=NULL && fabricante!=NULL && procesador!=NULL && cache!=NULL && frecuencia!=NULL && zocalos!=NULL && nucleos!=NULL && hilos!=NULL && lanzamiento!=NULL){
		cpu_setRank(auxNuevoCPU,atoi(rank));
		cpu_setFabricante(auxNuevoCPU,fabricante);
		cpu_setProcesador(auxNuevoCPU,procesador);
		cpu_setCache(auxNuevoCPU,atoi(cache));
		cpu_setFrecuencia(auxNuevoCPU,atof(frecuencia));
		cpu_setZocalos(auxNuevoCPU,zocalos);
		cpu_setNucleos(auxNuevoCPU,atoi(nucleos));
		cpu_setHilos(auxNuevoCPU,atoi(hilos));
		cpu_setLanzamiento(auxNuevoCPU,atoi(lanzamiento));
	}
	return  auxNuevoCPU;
}

int cpu_setRank(eCPU* pEstructura, int rank){
	int todoOk=-1;
	if(pEstructura!=NULL &&rank >0){
		pEstructura->rank=rank;
		todoOk=0;
	}
	return todoOk;
}
int cpu_setFabricante(eCPU* pEstructura, char* fabricante){
	int todoOk=-1;
	if(pEstructura!=NULL && fabricante!=NULL){
		strcpy(pEstructura->fabricante,fabricante);
		todoOk=0;
	}
	return todoOk;
}
int cpu_setProcesador(eCPU* pEstructura, char* procesador){
	int todoOk=-1;
	if(pEstructura!=NULL && procesador!=NULL){
		strcpy(pEstructura->procesador,procesador);
		todoOk=0;
	}
	return todoOk;
}
int cpu_setCache(eCPU* pEstructura, int cache){
	int todoOk=-1;
	if(pEstructura!=NULL &&cache >0){
		pEstructura->cache=cache;
		todoOk=0;
	}
	return todoOk;
}
int cpu_setFrecuencia(eCPU* pEstructura, float frecuencia){
	int todoOk=-1;
	if(pEstructura!=NULL &&frecuencia >0){
		pEstructura->frecuencia=frecuencia;
		todoOk=0;
	}
	return todoOk;
}
int cpu_setZocalos(eCPU* pEstructura, char* zocalos){
	int todoOk=-1;
	if(pEstructura!=NULL && zocalos!=NULL){
		strcpy(pEstructura->zocalos,zocalos);
		todoOk=0;
	}
	return todoOk;
}

int cpu_setNucleos(eCPU* pEstructura, int nucleos){
	int todoOk=-1;
	if(pEstructura!=NULL &&nucleos >0){
		pEstructura->nucleos=nucleos;
		todoOk=0;
	}
	return todoOk;
}
int cpu_setHilos(eCPU* pEstructura, int hilos){
	int todoOk=-1;
	if(pEstructura!=NULL &&hilos >0){
		pEstructura->hilos=hilos;
		todoOk=0;
	}
	return todoOk;
}
int cpu_setLanzamiento(eCPU* pEstructura, int lanzamiento){
	int todoOk=-1;
	if(pEstructura!=NULL &&lanzamiento >0){
		pEstructura->lanzamiento=lanzamiento;
		todoOk=0;
	}
	return todoOk;
}


void mostrarCPU(eCPU* eEstructura){
	printf("|%4d | %-7s | %-30s | %5d | %5.2f | %-10s | %5d | %5d | %5d |\n", eEstructura->rank, eEstructura->fabricante,eEstructura->procesador,eEstructura->cache,eEstructura->frecuencia,eEstructura->zocalos,eEstructura->nucleos,eEstructura->hilos,eEstructura->lanzamiento);
}

int compararPorId(void* cpu1, void* cpu2){
	int auxReturn=0;
	if(cpu1!=NULL && cpu2!=NULL){
		if(((eCPU*)cpu1)->rank>((eCPU*)cpu2)->rank)
		{
		 auxReturn= 1;
		}
		if(((eCPU*)cpu1)->rank<((eCPU*)cpu2)->rank)
		{
		 auxReturn= -1;
		}
	}
	return auxReturn;
}
int compararPorProcesador(void* cpu1, void* cpu2){
	int auxReturn=0;
	if(cpu1!=NULL && cpu2!=NULL){
		auxReturn=strcmp(((eCPU*)cpu1)->procesador, ((eCPU*)cpu2)->procesador);
	}
	return auxReturn;
}
int filtrarPorAMD(void* pEstructura){
	int resultado=0;
	if(pEstructura!=NULL){
		if(strcmp(((eCPU*)pEstructura)->fabricante,"AMD")==0){
			resultado=1;
		}
	}
	return resultado;
}
