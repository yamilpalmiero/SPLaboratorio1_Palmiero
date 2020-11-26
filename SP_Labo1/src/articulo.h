#ifndef ARTICULO_H_
#define ARTICULO_H_

typedef struct {
	int id; //PK
	char descripcion[51];
} eRubro;

typedef struct {
	int id; //PK
	char articulo[51];
	int medida;
	float precio;
	int idRubro; //FK
} eArticulo;

#endif /* ARTICULO_H_ */

eArticulo* articulo_new(void);
int articulo_delete(eArticulo *this);
//---------------------------------------------------------------------------------------------------------------------

//SETTERS--------------------------------------------------------------------------------------------------------------
int articulo_setId(eArticulo *this, int id);
int articulo_setIdAsInt(eArticulo *this, char *id);
int articulo_setArticulo(eArticulo *this, char *articulo);
int articulo_setMedida(eArticulo *this, int medida);
int articulo_setMedidaAsInt(eArticulo *this, char *medida);
int articulo_setPrecio(eArticulo *this, float precio);
int articulo_setPrecioAsFloat(eArticulo *this, char *precio);
int articulo_setIdRubro(eArticulo *this, int idRubro);
int articulo_setIdRubroAsInt(eArticulo *this, char *idRubro);
//---------------------------------------------------------------------------------------------------------------------

//GETTERS--------------------------------------------------------------------------------------------------------------
int articulo_getId(eArticulo *this, int *resultado);
int articulo_getArticulo(eArticulo *this, char *resultado);
int articulo_getMedida(eArticulo *this, int *resultado);
int articulo_getPrecio(eArticulo *this, float *resultado);
int articulo_getIdRubro(eArticulo *this, int *resultado);

//---------------------------------------------------------------------------------------------------------------------
eArticulo* articulo_newParametros(char *id, char *articulo, char *medida,
		char *precio, char *idRubro);
//---------------------------------------------------------------------------------------------------------------------
int articulo_criterio(void *this1, void *this2);
//---------------------------------------------------------------------------------------------------------------------
int articulo_mostrarArticulos(LinkedList *pListaArticulos);
//---------------------------------------------------------------------------------------------------------------------
int articulo_mostrarArticulo(eArticulo *this);
//---------------------------------------------------------------------------------------------------------------------
void articulo_realizarDescuento(eArticulo *pArticulo);
