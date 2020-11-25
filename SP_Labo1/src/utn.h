#ifndef UTN_H_
#define UTN_H_

#endif /* UTN_H_ */

/*
 * brief Toma un numero entero por teclado y lo devuelve por puntero
 * param Direccion de memoria donde se guardara el entero
 * param Mensaje que pide el dato numerico
 * param Mensaje de error cuando lo que se ingresa por teclado no es lo solicitado
 * param Valor minimo posible
 * param Valor maximo posible
 * param Cantidad de intentos para ingresar el dato correctamente
 */
int utn_getEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

/*
 * brief Toma un numero con decimales por teclado y lo devuelve por puntero
 * param Direccion de memoria donde se guardara el flotante
 * param Mensaje que pide el dato numerico
 * param Mensaje de error cuando lo que se ingresa por teclado no es lo solicitado
 * param Valor minimo posible
 * param Valor maximo posible
 * param Cantidad de intentos para ingresar el dato correctamente
 */
int utn_getFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

/*
 * brief Toma una cadena por teclado y la devuelve
 * param Direccion de memoria donde se guardara la cadena
 * param Mensaje del dato que pide
 * param Mensaje de error cuando lo que se ingresa por teclado no es lo solicitado
 * param Valor minimo posible
 * param Valor maximo posible
 * param Cantidad de intentos para ingresar el dato correctamente
 */
int utn_getCadena(char *pCadena, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

/*
 * brief Lee una cadena por teclado hasta que encuentra un '\n' o hasta que llega a longitud - 1
 * param cadena Puntero al espacio de memoria donde se va a copiar la cadena obtenida
 * param longitud Define el tamaño de la cadena
 * return Retorna 0 si se pudo obtener la cadena y -1 si no
 */
int utn_myGets(char *cadena, int longitud);

/*
 * brief Obtiene un numero entero
 * param pResultado Puntero al espacio de memoria donde se dejara el resultado
 * return Retorna 0 si se obtuvo el numero entero y -1 si no
 */
int utn_getInt(int *pResultado);

/*
 * brief Recibe una cadena y evalua si todos sus elementos son numeros
 * param cadena Puntero al espacio de memoria donde se va a guardar la cadena
 * param limite Define el tamaño de la cadena
 * return Retorna 1 si es verdad que todos sus elementos son numeros y 0 si no
 */
int utn_esNumericaEnteros(char *cadena, int limite);

/*
 * brief Obtiene un numero flotante
 * param pResultado Puntero al espacio de memoria donde se dejara el resultado
 * return Retorna 0 si se obtuvo el numero flotante y -1 si no
 */
int utn_getFloat(float *pResultado);

/*
 * brief Recibe una cadena y evalua si todos sus elementos son numeros
 * param cadena Puntero al espacio de memoria donde se va a guardar la cadena
 * param limite Define el tamaño de la cadena
 * return Retorna 1 si es verdad que todos sus elementos son numeros y 0 si no
 */
int utn_esNumericaFlotantes(char *cadena, int limite);

/*
 * brief Imprime un menu de opciones por pantalla
 * return Retorna la opcion seleccionada por el usuario
 */
int menu();

/*
 * brief Imprime un menu de opciones por pantalla
 * return Retorna la opcion seleccionada por el usuario
 */
int submenuInformes();
