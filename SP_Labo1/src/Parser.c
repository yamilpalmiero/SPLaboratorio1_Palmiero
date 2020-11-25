#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"

int parser_ArticuloFromText(FILE *pFile, LinkedList *pListaArticulos) {
	int retorno = -1;
	int flag = 0;
	char bufferId[50];
	char bufferArticulo[50];
	char bufferMedida[50];
	char bufferPrecio[50];
	char bufferIdRubro[50];
	eArticulo *pArticulo; //Puntero al elemento donde se van a cargar los campos con su tipo de dato correspondiente

	if (pFile != NULL) {
		while (!feof(pFile)) { //Mientras el archivo no llegue al final hace esto: borra las comas y guarda los campos en un buffer
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId,
					bufferArticulo, bufferMedida, bufferPrecio, bufferIdRubro);
			if (flag == 0) { //La primera vez ingresa en este flag entonces la primera lectura seria fantasta. Esto es porque el archivo TIENE titulos
				flag++;
				continue;
			}
			pArticulo = articulo_newParametros(bufferId, bufferArticulo,
					bufferMedida, bufferPrecio, bufferIdRubro); //Carga los campos en el buffer pero con la funcion los pasa a su tipo correspondiente
			if (pArticulo != NULL) {
				ll_add(pListaArticulos, pArticulo); //Agrego el elemento a la LinkedList
				retorno = 0;
			}
		}
	}

	return retorno;
}
