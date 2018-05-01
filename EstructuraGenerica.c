#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#include "../Programacion-I/pattie/Funciones/funciones.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1
#define BAJA 2


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
    int posicionLibre = -1; //Guarda la primer posicion con estado LIBRE que encuentra
    int posicionBaja = -1; //Guarda la primer posicion con estado BAJA que encuentra

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                posicionLibre = i;
                break;
            }
        }

        if(posicionLibre < 0) //No hay posiciones con estado LIBRE, busco la primer posición con estado BAJA
        {
            for(i=0;i<limite;i++)
            {
                if(listado[i].estado == BAJA)
                {
                    posicionBaja = i;
                    break;
                }
            }

            if(posicionBaja >= 0)
            {
                retorno = posicionBaja; //Retorno la primera posición con estado BAJA
            }
        }
        else
        {
            retorno = posicionLibre; //Retorno la primera posición con estado LIBRE
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
            if(listado[i].estado == OCUPADO || listado[i].estado == BAJA) //Tengo en cuenta las bajas lógicas para no duplicar id al rehabilitar
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

int eGen_buscarPorIdBorrados(eGenerica listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == BAJA && listado[i].idGenerica == id)
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
    case LIBRE: //No muestro las posiciones con estado LIBRE porque contienen basura
        break;
    case BAJA:
        printf("\n %d - %s - %s",parametro.idGenerica,parametro.nombre,"[BAJA]");
        break;
    case OCUPADO:
        printf("\n %d - %s",parametro.idGenerica,parametro.nombre);
        break;
    default:
        printf("\n %d - %s - %s",parametro.idGenerica,parametro.nombre,"[N/A]");
        break;
    }
}

int eGen_mostrarListadoConOcupados(eGenerica listado[],int limite)
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
            if(listado[i].estado==BAJA)
            {
                eGen_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
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
            eGen_mostrarUnoConEstado(listado[i]);
        }
    }
    return retorno;
}

int eGen_alta(eGenerica  listado[],int limite)
{
    int retorno = -1;
    eGenerica temporario;
    int indice;
    char confirma[3];

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eGen_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            temporario.idGenerica = eGen_siguienteId(listado,limite);

            retorno = -4;
            do
            {
                pedirString("Ingrese nombre: ", temporario.nombre, TAM_NOMBRE);
                if(strcmp(temporario.nombre, "") == 0)
                {
                    printf("El dato es obligatorio, por favor reingrese\n");
                }
            } while(strcmp(temporario.nombre, "") == 0);

            retorno = -5;
            do
            {
                printf("\nSe va a dar de alta:");
                eGen_mostrarUno(temporario);
                pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
                if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
                {
                    printf("Debe ingresar S o N. Por favor reingrese\n");
                }
            } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

            if(stricmp(confirma, "S") == 0)
            {
                retorno = 0;
                strcpy(listado[indice].nombre, temporario.nombre);
                listado[indice].idGenerica = temporario.idGenerica;
                listado[indice].estado = OCUPADO;
            }
            else
            {
                printf("Accion cancelada por el usuario\n");
            }
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
    char confirma[3];

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        do
        {
            muestraListado = eGen_mostrarListadoConOcupados(listado, limite);

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

        retorno = -3;
        do
        {
            printf("\nSe va a dar de baja:");
            eGen_mostrarUno(listado[indice]);
            pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
            if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
            {
                printf("Debe ingresar S o N. Por favor reingrese\n");
            }
        } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

        if(stricmp(confirma, "S") == 0)
        {
            retorno = 0;
            listado[indice].estado = BAJA;
        }
        else
        {
            printf("Accion cancelada por el usuario\n");
        }
    }

    return retorno;
}

int eGen_modificacion(eGenerica  listado[],int limite)
{
    int retorno = -1;
    int indice;
    int muestraListado;
    eGenerica temporario;
    char confirma[3];

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        do
        {
            muestraListado = eGen_mostrarListadoConOcupados(listado, limite);

            if(muestraListado < 0)
            {
                printf("\Error al listar...\n");
                break;
            }

            temporario.idGenerica = pedirEnteroSinValidar("\nIngrese ID a modificar: ");
            indice = eGen_buscarPorId(listado, limite, temporario.idGenerica);
            if(indice < 0)
            {
                printf("No se encontro el ID ingresado. Por favor reingrese\n");
            }
        } while(indice < 0);

        retorno = -3;
        do
        {
            pedirString("Ingrese nuevo nombre: ", temporario.nombre, TAM_NOMBRE);
            if(strcmp(temporario.nombre, "") == 0)
            {
                printf("El dato es obligatorio, por favor reingrese\n");
            }
        } while(strcmp(temporario.nombre, "") == 0);

        retorno = -4;
        do
        {
            printf("\nSe va a modificar:");
            eGen_mostrarUno(listado[indice]);
            printf("\nPor:");
            eGen_mostrarUno(temporario);
            pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
            if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
            {
                printf("Debe ingresar S o N. Por favor reingrese\n");
            }
        } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

        if(stricmp(confirma, "S") == 0)
        {
            retorno = 0;
            strcpy(listado[indice].nombre, temporario.nombre);
        }
        else
        {
            printf("Accion cancelada por el usuario\n");
        }
    }
    return retorno;
}

int eGen_rehabilitar(eGenerica  listado[],int limite)
{
    int retorno = -1;
    int indice;
    int muestraListado;
    int id;
    char confirma[3];

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        do
        {
            muestraListado = eGen_mostrarListadoConBorrados(listado, limite);

            if(muestraListado < 0)
            {
                printf("\Error al listar...\n");
                break;
            }

            id = pedirEnteroSinValidar("\nIngrese ID a rehabilitar: ");
            indice = eGen_buscarPorIdBorrados(listado, limite, id);
            if(indice < 0)
            {
                printf("No se encontro el ID ingresado. Por favor reingrese\n");
            }
        } while(indice < 0);

        retorno = -3;
        do
        {
            printf("\nSe va a rehabilitar:");
            eGen_mostrarUno(listado[indice]);
            pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
            if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
            {
                printf("Debe ingresar S o N. Por favor reingrese\n");
            }
        } while(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0);

        if(stricmp(confirma, "S") == 0)
        {
            retorno = 0;
            listado[indice].estado = OCUPADO;
        }
        else
        {
            printf("Accion cancelada por el usuario\n");
        }
    }
    return retorno;
}
