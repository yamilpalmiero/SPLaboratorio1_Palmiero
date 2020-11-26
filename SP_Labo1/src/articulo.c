#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"

eArticulo* articulo_new(void) {
	return (eArticulo*) malloc(sizeof(eArticulo));
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_delete(eArticulo *this) {
	int retorno = -1;

	if (this != NULL) {
		free(this);
		retorno = 0;
	}

	return retorno;
}
//SETTERS--------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
int articulo_setId(eArticulo *this, int id) {
	int retorno = -1;

	if (this != NULL && id >= 0) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_setIdAsInt(eArticulo *this, char *id) {
	int retorno = -1;

	if (this != NULL && id >= 0) {
		retorno = articulo_setId(this, atoi(id));
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_setArticulo(eArticulo *this, char *articulo) {
	int retorno = -1;

	if (this != NULL && articulo != NULL) {
		strcpy(this->articulo, articulo);
		retorno = 0;
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_setMedida(eArticulo *this, int medida) {
	int retorno = -1;

	if (this != NULL && medida >= 0) {
		this->medida = medida;
		retorno = 0;
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_setMedidaAsInt(eArticulo *this, char *medida) {
	int retorno = -1;

	if (this != NULL && medida >= 0) {
		retorno = articulo_setMedida(this, atoi(medida));
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_setPrecio(eArticulo *this, float precio) {
	int retorno = -1;

	if (this != NULL && precio >= 0) {
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_setPrecioAsFloat(eArticulo *this, char *precio) {
	int retorno = -1;

	if (this != NULL && precio >= 0) {
		retorno = articulo_setPrecio(this, atof(precio));
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_setIdRubro(eArticulo *this, int idRubro) {
	int retorno = -1;

	if (this != NULL && idRubro >= 0) {
		this->idRubro = idRubro;
		retorno = 0;
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_setIdRubroAsInt(eArticulo *this, char *idRubro) {
	int retorno = -1;

	if (this != NULL && idRubro >= 0) {
		retorno = articulo_setIdRubro(this, atoi(idRubro));
	}

	return retorno;
}
//GETTERS--------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
int articulo_getId(eArticulo *this, int *resultado) {
	int retorno = -1;

	if (this != NULL && resultado != NULL) {
		*resultado = this->id;
		retorno = 0;
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_getArticulo(eArticulo *this, char *resultado) {
	int retorno = -1;

	if (this != NULL) {
		strcpy(resultado, this->articulo);
		retorno = 0;
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_getMedida(eArticulo *this, int *resultado) {
	int retorno = -1;

	if (this != NULL && resultado != NULL) {
		*resultado = this->medida;
		retorno = 0;
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_getPrecio(eArticulo *this, float *resultado) {
	int retorno = -1;

	if (this != NULL && resultado != NULL) {
		*resultado = this->precio;
		retorno = 0;
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_getIdRubro(eArticulo *this, int *resultado) {
	int retorno = -1;

	if (this != NULL && resultado != NULL) {
		*resultado = this->idRubro;
		retorno = 0;
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
eArticulo* articulo_newParametros(char *id, char *articulo, char *medida,
		char *precio, char *idRubro) {
	eArticulo *retorno = NULL;
	eArticulo *pAuxArticulo;

	if (id != NULL && articulo != NULL && medida != NULL && precio != NULL
			&& idRubro != NULL) {
		pAuxArticulo = articulo_new();
		if (pAuxArticulo != NULL) {
			if (!articulo_setIdAsInt(pAuxArticulo, id)
					&& !articulo_setArticulo(pAuxArticulo, articulo)
					&& !articulo_setMedidaAsInt(pAuxArticulo, medida)
					&& !articulo_setPrecioAsFloat(pAuxArticulo, precio)
					&& !articulo_setIdRubroAsInt(pAuxArticulo, idRubro)) {
				retorno = pAuxArticulo;
			} else {
				articulo_delete(pAuxArticulo);
			}
		}
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_criterio(void *this1, void *this2) { //Esta funcion es la que sabe que campos hay que comparar para ver como hacemos el ordenamiento y el order es el que me dice si es ascendente o descendente
	int retorno;
	int comparacion;
	char articulo1[50];
	char articulo2[50];

	if (articulo_getArticulo((eArticulo*) this1, articulo1) == 0
			&& articulo_getArticulo((eArticulo*) this2, articulo2) == 0) {
		comparacion = strcmp(articulo1, articulo2);
		if (comparacion < 0) {
			retorno = -1;
		}
		if (comparacion > 0) {
			retorno = 1;
		}
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_mostrarArticulos(LinkedList *pListaArticulos) { //Muestro todos los articulos
	int retorno = -1;
	eArticulo *pArticulo;
	int i;
	int cantidadArticulos = 0;

	if (pListaArticulos != NULL) {
		for (i = 0; i < ll_len(pListaArticulos); i++) {
			pArticulo = ll_get(pListaArticulos, i);
			articulo_mostrarArticulo(pArticulo);
			cantidadArticulos++;
		}
		printf("\nHay %d articulos\n", cantidadArticulos);
		retorno = 0;
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
int articulo_mostrarArticulo(eArticulo *this) { //Muestro la informacion de un solo articulo
	int retorno = -1;
	int bufferId;
	char bufferArticulo[50];
	int bufferMedida;
	float bufferPrecio;
	int bufferIdRubro;
	char descripcionRubro[50];

	if (this != NULL) {
		articulo_getId(this, &bufferId);
		articulo_getArticulo(this, bufferArticulo);
		articulo_getMedida(this, &bufferMedida);
		articulo_getPrecio(this, &bufferPrecio);
		articulo_getIdRubro(this, &bufferIdRubro);
		if (bufferIdRubro == 1) {
			strcpy(descripcionRubro, "Cuidado de ropa.");
		} else if (bufferIdRubro == 2) {
			strcpy(descripcionRubro, "Limpieza y desinfeccion.");
		} else if (bufferIdRubro == 3) {
			strcpy(descripcionRubro, "Cuidado personal e higiene.");
		} else if (bufferIdRubro == 4) {
			strcpy(descripcionRubro, "Cuidado del automotor.");
		}

		printf(
				"\nId: %d - Articulo: %s - Medida: %d - Precio: %.2f - Rubro: %s",
				bufferId, bufferArticulo, bufferMedida, bufferPrecio,
				descripcionRubro);
		retorno = 0;
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------
void articulo_realizarDescuento(eArticulo *pArticulo) {

	if (pArticulo != NULL
			&& articulo_getIdRubro(pArticulo, &pArticulo->idRubro) == 0) { //En este caso si se valida para ver si es posible acceder al elemento (osea que no sea NULL)
		if (articulo_getPrecio(pArticulo, &pArticulo->precio) == 0
				&& pArticulo->idRubro == 1) {
			if (pArticulo->precio >= 120) {
				articulo_setPrecio(pArticulo, pArticulo->precio * 0.8);
			}
		}
	} else if (pArticulo != NULL
			&& articulo_getIdRubro(pArticulo, &pArticulo->idRubro) == 0) {
		if (articulo_getPrecio(pArticulo, &pArticulo->precio) == 0
				&& pArticulo->idRubro == 2) {
			if (pArticulo->precio <= 200) {
				articulo_setPrecio(pArticulo, pArticulo->precio * 0.9);
			}
		}
	}
}
