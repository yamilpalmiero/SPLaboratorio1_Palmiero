#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	char bufferArchivo[51];
	int opcionInformes;
	int flag = 0;
	LinkedList *pListaArticulos = ll_newLinkedList(); //Constructor que crea e inicializa la lista de artculos en memo dinamica
	eRubro arrayRubros[] = { { 1, "Cuidado de ropa" }, { 2,
			"Limpieza y desinfeccion" }, { 3, "Cuidado personal e higiene" }, {
			4, "Cuidado del automotor" } };

	do {
		utn_getEntero(&opcionMenu,
				"\n\n***MENU PRINCIPAL***\nElija una opcion:\n\n1) Cargar datos desde archivo \n2) Ordenar lista de articulos\n3) Imprimir articulos\n4) Realizar descuentos\n5) Generar archivo de salida\n6) Informe de los articulos \n7) Salir\n",
				"\nError", 1, 7, 2);

		system("cls");

		switch (opcionMenu) {
		case 1:
			printf("Ingrese nombre del archivo textualmente: ");
			gets(bufferArchivo);
			if (strcmp(bufferArchivo, "Datos_SP_LABO1.csv") == 0) {
				if (controller_loadFromText(bufferArchivo, pListaArticulos) == 0) {
					flag = 1;
				}
			} else {
				printf("\nError, debe ingresar el nombre tal cual.\n");
			}
			break;
		case 2:
			if (flag == 0) {
				printf("\nError, primero debe cargar la lista de articulos.");
			} else {
				if (ll_sort(pListaArticulos, articulo_criterio, 1) == 0) {
					printf("\nOrdenamiento exitoso.\n");
				}
			}
			break;
		case 3:
			if (flag == 0) {
				printf("\nError, primero debe cargar la lista de articulos.");
			}
			articulo_mostrarArticulos(pListaArticulos);
			break;
		case 4:
			if (flag == 0) {
				printf("\nError, primero debe cargar la lista de articulos.");
			} else {
				ll_map(pListaArticulos, articulo_realizarDescuento);
				printf("\nSe realizaron los descuentos.\n");
			}
			break;
		case 5:
			if (flag == 0) {
				printf("\nError, primero debe cargar la lista de articulos.");
			} else {
				controller_saveAsText("mapeado.csv", pListaArticulos);
			}
			break;
		case 6:
			do {
				utn_getEntero(&opcionInformes,
						"\n***MENU INFORMES***\nElija una opcion:\n\n1) Mostrar la cantidad de articulos cuyo precio sea mayor a $100 \n2) Mostrar la cantidad de articulos del rubro 1-CUIDADO DE ROPA\n3) Salir\n",
						"\nError", 1, 3, 2);

				system("cls");

				switch (opcionInformes) {
				case 1:
					if (flag == 0) {
						printf(
								"\nError, primero debe cargar la lista de articulos.");
					}
					articulo_mostrarArticulos(pListaArticulos);
					break;
				case 2:
					if (flag == 0) {
						printf(
								"\nError, primero debe cargar la lista de articulos.");
					}
					articulo_mostrarArticulos(pListaArticulos);
					break;
				case 3:
					printf("\nSalio de Informes!\n\n");
					system("pause");
					break;
				}

			} while (opcionInformes != 3);
			break;
		case 7:
			printf("\nSalio!!\n\n");
			system("pause");
			break;
		}

	} while (opcionMenu != 7);

	return EXIT_SUCCESS;
}
