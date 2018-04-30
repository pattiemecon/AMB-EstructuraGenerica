#include <stdio.h>
#include <stdlib.h>
#include "EstructuraGenerica.h"
//#include "susFunciones.h"
#define CANTIDAD 10
int main()
{
    eGenerica listadoGenerico[CANTIDAD];
    eGen_init(listadoGenerico,CANTIDAD);

    printf( "\n \t muestro el array... esta vacio");
    eGen_mostrarListadoConOcupados(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t muestro el array con los borrados");
    eGen_mostrarListado(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t cargo dos elementos y muestro el array\n");
    eGen_alta(listadoGenerico,CANTIDAD);
    eGen_alta(listadoGenerico,CANTIDAD);
    eGen_mostrarListadoConOcupados(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t modifico un elemento y muestro el array\n");
    eGen_modificacion(listadoGenerico,CANTIDAD);
    eGen_mostrarListadoConOcupados(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t borro el otro elemento y muestro el array\n");
    eGen_baja(listadoGenerico,CANTIDAD);
    eGen_mostrarListadoConOcupados(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios\n");
    eGen_mostrarListado(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t rehabilito el elemento y muestro el array\n");
    eGen_rehabilitar(listadoGenerico,CANTIDAD);
    eGen_mostrarListadoConOcupados(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios\n");
    eGen_mostrarListado(listadoGenerico,CANTIDAD);
    getchar();


    return 0;
}
