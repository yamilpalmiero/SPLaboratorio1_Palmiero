#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"

int controller_loadFromText(char *path, LinkedList *pListaArticulos) {
	int retorno = -1;
	FILE *pFile = NULL;

	if (path != NULL && pListaArticulos != NULL) {
		pFile = fopen(path, "r");
		if (pFile != NULL) {
			if (parser_ArticuloFromText(pFile, pListaArticulos) == 0) {
				printf("\nCarga exitosa.");
				retorno = 0;
			}
		}
		fclose(pFile);
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------
int controller_sortArticulos(LinkedList *pListaArticulos) {
	int retorno = -1;

	if (pListaArticulos != NULL) {
		ll_sort(pListaArticulos, articulo_criterio, 1);
		retorno = 0;
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------
int controller_saveAsText(char *path, LinkedList *pListaArticulos) {
	int retorno = -1;
	FILE *pFile = NULL;
	eArticulo *pArticulo;

	if (path != NULL && pListaArticulos != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			for (int i = 0; i < ll_len(pListaArticulos); i++) {
				pArticulo = ll_get(pListaArticulos, i);
				if (pArticulo != NULL)
					fwrite(pArticulo, sizeof(eArticulo), 1, pFile);
			}
			fclose(pFile);
			printf("Guardado con exito.\n");
			retorno = 0;
		}
	}

	return retorno;
}
