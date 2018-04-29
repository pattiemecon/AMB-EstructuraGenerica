#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#include "../Programacion-I/pattie/Funciones/funciones.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1



int eGen_init( eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idGenerica= 0;
        }
    }
    return retorno;
}

int eGen_buscarLugarLibre(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eGen_siguienteId(eGenerica listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idGenerica>retorno)
                    {
                         retorno=listado[i].idGenerica;
                    }

            }
        }
    }

    return retorno+1;
}


int eGen_buscarPorId(eGenerica listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



void eGen_mostrarUno(eGenerica parametro)
{
     printf("\n %d - %s",parametro.idGenerica,parametro.nombre);

}

void eGen_mostrarUnoConEstado(eGenerica parametro)
{
    switch(parametro.estado)
    {
    case LIBRE:
        printf("\n %d - %s - %s",parametro.idGenerica,parametro.nombre,"[LIBRE]");
        break;
    case OCUPADO:
        printf("\n %d - %s",parametro.idGenerica,parametro.nombre);
        break;
    default:
        printf("\n %d - %s - %s",parametro.idGenerica,parametro.nombre,"[N/A]");
        break;
    }
}

int eGen_mostrarListado(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                eGen_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}


int eGen_mostrarListadoConBorrados(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            eGen_mostrarUnoConEstado(listado[i]);
        }
    }
    return retorno;
}




int eGen_alta(eGenerica  listado[],int limite)
{
    int retorno = -1;
    char nombre[TAM_NOMBRE];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eGen_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eGen_siguienteId(listado,limite);

            retorno = -4;
            do
            {
                pedirString("Ingrese nombre: ", nombre, TAM_NOMBRE);
                if(strcmp(nombre, "") == 0)
                {
                    printf("El dato es obligatorio, por favor reingrese\n");
                }
            } while(strcmp(nombre, "") == 0);

            retorno = 0;
            strcpy(listado[indice].nombre, nombre);
            listado[indice].idGenerica = id;
            listado[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

int eGen_baja(eGenerica  listado[],int limite)
{
    int retorno = -1;
    int indice;
    int muestraListado;
    int id;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        do
        {
            muestraListado = eGen_mostrarListado(listado, limite);

            if(muestraListado < 0)
            {
                printf("\Error al listar...\n");
                break;
            }

            id = pedirEnteroSinValidar("\nIngrese ID a borrar: ");
            indice = eGen_buscarPorId(listado, limite, id);
            if(indice < 0)
            {
                printf("No se encontro el ID ingresado. Por favor reingrese\n");
            }
        } while(indice < 0);

        retorno = 0;
        listado[indice].estado = LIBRE;
    }
    return retorno;
}

int eGen_modificacion(eGenerica  listado[],int limite)
{
    int retorno = -1;
    int indice;
    int muestraListado;
    int id;
    char nombre[TAM_NOMBRE];

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        do
        {
            muestraListado = eGen_mostrarListado(listado, limite);

            if(muestraListado < 0)
            {
                printf("\Error al listar...\n");
                break;
            }

            id = pedirEnteroSinValidar("\nIngrese ID a modificar: ");
            indice = eGen_buscarPorId(listado, limite, id);
            if(indice < 0)
            {
                printf("No se encontro el ID ingresado. Por favor reingrese\n");
            }
        } while(indice < 0);

        retorno = -3;
        do
        {
            pedirString("Ingrese nuevo nombre: ", nombre, TAM_NOMBRE);
            if(strcmp(nombre, "") == 0)
            {
                printf("El dato es obligatorio, por favor reingrese\n");
            }
        } while(strcmp(nombre, "") == 0);

        retorno = 0;
        strcpy(listado[indice].nombre, nombre);
    }
    return retorno;
}
