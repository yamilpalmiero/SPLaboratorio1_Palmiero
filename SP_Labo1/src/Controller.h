#include "Articulo.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#endif /* CONTROLLER_H_ */

int controller_loadFromText(char *path, LinkedList *pListaArticulos);
int controller_sortArticulos(LinkedList *pListaArticulos);
int controller_saveAsText(char *path, LinkedList *pListaArticulos);
