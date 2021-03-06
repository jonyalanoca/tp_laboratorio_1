/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

#include "menus.h"
#include "controller.h"
#include "auxiliares.h"
#include "cpus.h"


int main(void)
{
	setbuf(stdout,NULL);
	LinkedList* listaCPU=ll_newLinkedList();
	LinkedList* clonlista=NULL;
	LinkedList* clonlista10=NULL;
	LinkedList* clonFiltrado=NULL;
	int id=500;
	char salir;
	do{
		switch(menu())
		{
			case 1:
				controller_cargarArchivoTexto("rankCPU.csv", listaCPU);
				break;
			case 2:
				controller_agregarAlFinal(listaCPU, &id);
				break;
			case 3:
				if(ll_isEmpty(listaCPU)==0){
					controller_tamanioLista(listaCPU);
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}
				break;
			case 4:
				if(ll_isEmpty(listaCPU)==0){
					controller_insertarReemplazarCPU(listaCPU, &id);
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}

				break;
			case 5:
				if(ll_isEmpty(listaCPU)==0){
					controller_insertarSinReemplazarCPU(listaCPU,&id);
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}

				break;
			case 6:
				if(ll_isEmpty(listaCPU)==0){
					controller_obtenerIndex(listaCPU);
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}
				break;
			case 7:
				if(ll_isEmpty(listaCPU)==0){
					if(!ll_sort(listaCPU,compararPorId,ascendenteDescendente())){
						printf("Uff! Costo, pero lo logramos. Se Ordeno la lista con exito.\n");
					}else{
						printf("Ocurrio un problema al ordenar.\n");
					}
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}

				break;
			case 8:
				if(ll_isEmpty(listaCPU)==0){
					if(!ll_sort(listaCPU,compararPorProcesador,ascendenteDescendente())){
						printf("Uff! Costo, pero lo logramos. Se Ordeno la lista con exito.\n");
					}else{
						printf("Ocurrio un problema al ordenar.\n");
					}
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}

				break;
			case 9:
				if(ll_isEmpty(listaCPU)==0){
					controller_listarCPUs(listaCPU);
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}

				break;
			case 10:
				if(ll_isEmpty(listaCPU)==0){
					controller_guardarComoTexto("rankCPU.csv",listaCPU);
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}

				break;
			case 11:
				if(ll_isEmpty(listaCPU)==0){
					clonlista=ll_clone(listaCPU);
					if(clonlista!=NULL){
						printf("Se clono la lista con exito.\n");
					}
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}

				break;
			case 12:
				if(ll_isEmpty(clonlista)==0){
					controller_listarCPUs(clonlista);
				}else{
					printf("Antes debe cargar datos (11).\n");
				}

				break;
			case 13:
				if(ll_isEmpty(clonlista)==0){
					controller_comprarListas(clonlista,listaCPU);
				}else{
					printf("Antes debe cargar datos (11).\n");
				}

				break;
			case 14:
				if(ll_isEmpty(clonlista)==0){
					controller_compararUnElemento(listaCPU,clonlista);
				}else{
					printf("Antes debe cargar datos (11).\n");
				}
				break;
			case 15:
				if(ll_isEmpty(clonlista)==0){
					controller_eliminarUnElemento(clonlista);
				}else{
					printf("Antes debe cargar datos (11).\n");
				}

				break;
			case 16:
				if(ll_isEmpty(listaCPU)==0){
					clonlista10=ll_subList(listaCPU, 0,10);
					if(clonlista10!=NULL){
						printf("Se clono la lista con exito.\n");
					}
				}else{
					printf("Antes debe cargar datos (1)(2).\n");
				}

				break;
			case 17:
				if(ll_isEmpty(clonlista10)==0){
					controller_listarCPUs(clonlista10);
				}else{
					printf("Antes debe cargar datos (16).\n");
				}
				break;
			case 18:
				if(ll_isEmpty(clonlista10)==0){
					controller_limpiarListaClon10(clonlista10);
				}else{
					printf("Antes debe cargar datos (16).\n");
				}
				break;
			case 19:
				if(ll_isEmpty(clonlista10)==0){
					controller_eliminarElementoYAgregarloAlPrincipal(listaCPU,clonlista10,id);
				}else{
					printf("Antes debe cargar datos (16).\n");
				}
				break;
			case 20:
				if(ll_isEmpty(listaCPU)==0){
				clonFiltrado=ll_filter(listaCPU,filtrarPorAMD);
				}else{
					printf("Antes debe cargar datos (16).\n");
				}
				break;
			case 21:
				if(ll_isEmpty(clonFiltrado)==0){
					controller_listarCPUs(clonFiltrado);
				}else{
					printf("Antes debe cargar datos (16).\n");
				}
				break;
			case 22:
				if(!cerrar(&salir)){
					printf("Hubo un problema con la validacion.\n");
				}else{
					controller_limpiarElementos(listaCPU);
					ll_deleteLinkedList(listaCPU);
					controller_limpiarElementos(clonlista);
					ll_deleteLinkedList(clonlista);
					controller_limpiarElementos(clonlista10);
					ll_deleteLinkedList(clonlista10);
					controller_limpiarElementos(clonFiltrado);
					ll_deleteLinkedList(clonFiltrado);

				}
				break;
		}
		system("pause");
		system("cls");
	}while(salir!='s');

    return 0;
}
