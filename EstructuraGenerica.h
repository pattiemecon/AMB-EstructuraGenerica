#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED

#define TAM_NOMBRE 50

typedef struct
{
    char nombre[TAM_NOMBRE];
    //------------
    int idGenerica;
    int estado;
}eGenerica;

int eGen_init(eGenerica[],int limite);
int eGen_buscarPorId(eGenerica[] ,int limite, int id);
int eGen_buscarPorIdBorrados(eGenerica[] ,int limite, int id);
int eGen_siguienteId(eGenerica[] ,int limite);
int eGen_buscarLugarLibre(eGenerica listado[],int limite);

void eGen_mostrarUno(eGenerica parametro);
void eGen_mostrarUnoConEstado(eGenerica parametro);
int eGen_mostrarListado(eGenerica[] ,int limite);
int eGen_mostrarListadoConBorrados(eGenerica[] ,int limite);
int eGen_mostrarListadoConOcupados(eGenerica[] ,int limite);

int eGen_alta(eGenerica[] ,int limite);
int eGen_baja(eGenerica[] ,int limite);
int eGen_modificacion(eGenerica[] ,int limite);
int eGen_rehabilitar(eGenerica[] ,int limite);

int eGen_ordenar(eGenerica[] ,int limite, int orden);

#endif // ESTRUCTURAGENERICA_H_INCLUDED
