#ifndef ARTICULO_H_
#define ARTICULO_H_

typedef struct {
	int id;
	char articulo[51];
	int medida;
	float precio;
	int idRubro;
} eArticulo;

#endif /* ARTICULO_H_ */
