/*
 * hardcode.c
 *
 *  Created on: 3 may. 2022
 *      Author: Jony
 */

#include <stdio.h>
#include <stdlib.h>
#include "otros.h"
#include "ArrayPassenger.h"
#include "VueloEstado.h"
int hardcodear(Passenger* list,eVueloEstado* listaEstados, int len,int lenEstados, int* ids, int cantidad){
	int todoOk=-1;
	char nombres[50][20]={"Esteban","Alphonse","Chiquia","Yvon","Joye","Morganica","Ronnie","Alaric","Shanan","Cathrin","Noel","Harwell","Camile","Kimmy","Winnifred","Greta","Howard","Tedman","Alexis","Lanny","Krista","Daphna","Odelinda","Rice","Pamelina","Clementia","Hillery","Giselle","Cecilius","Frank","Odilia","Madonna","Tadeo","Aubrey","Doro","Dorolisa","Clementius","Lindsey","Hermione","Cory","Micki","Beatriz","Germaine","Reagan","Noak","Max","Lezlie","Perri","Katherine","Norman"};
	char apellidos[50][20]={"Eingerfield","Lever","Drydale","Iwanczyk","Le Surf","Priestman","Layus","Ruspine","Wedgwood","Searl","Crosio","Trask","Whitwam","McLoughlin","Ricardou","Blees","Rudham","Mathe","Ivatts","Mereweather","Newling","Byass","Tuer","Copper","Fitchet","Kilroy","Ledekker","McClaren","Kendred","Lockart","Kemell","Pearsall","Mollitt","Marian","Malthouse","Arnould","Melsom","McKeran","Cogger","Gostyke","Keenlayside","Greenin","Beckenham","Iacoviello","Boshere","MacLice","Darling","Obispo","Folker","Edgeson"};
	int precio[50]={12000,10000,90000,70000,20000,45000,80000,74000,100000,15000,12000,10000,90000,70000,20000,45000,80000,74000,100000,15000,12000,10000,90000,70000,20000,45000,80000,74000,100000,15000,12000,10000,90000,70000,20000,45000,80000,74000,100000,15000,12000,10000,90000,70000,20000,45000,80000,74000,100000,15000};
	int clase[50]={1,2,3,3,2,1,1,2,3,1,1,2,3,3,2,1,1,2,3,1,1,2,3,3,2,1,1,2,3,1,1,2,3,3,2,1,1,2,3,1,1,2,3,3,2,1,1,2,3,1};
	int idEstado[50]={2001,2002,2003,2004,2005,2006,2007,2008,2009,2005,2001,2002,2003,2004,2005,2006,2007,2008,2009,2005,2001,2002,2003,2004,2005,2006,2007,2008,2009,2005,2001,2002,2003,2004,2005,2006,2007,2008,2009,2005,2001,2002,2003,2004,2005,2006,2007,2008,2009,2005};
	if(list!=NULL && len>0 && listaEstados!=NULL && lenEstados>0 && cantidad>0){
		for(int i=0; i<cantidad;i++){
			if(!addPassenger(list, len, *ids, nombres[i], apellidos[i],precio[i],clase[i],listaEstados[buscarIndexPorId(listaEstados,lenEstados,idEstado[i],1)].codigoDeVuelo,idEstado[i])){
				(*ids)++;
			}else{
				break;
			}

		}
		todoOk=0;
	}
	return todoOk;
}
