#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "LinkedList.h"
#include "entidades.h"
#include "informes.h"


/** \brief muestra en pantalla la lista
 *
 * \param  pArraylist LinkedList*
 * \return  retorna
 *
 */

int listarList(LinkedList* pArrayList)
{

    ePais* auxEntidad = NULL;

    int auxId;
    char auxPais[30];

    int auxRecuperados;
    int auxInfectados;
    int auxMuertos;

    int tam = ll_len(pArrayList);
    int flag = 0;

    printf("ID    Pais            Recuperados        Infectados                Muertos\n");

    if(pArrayList != NULL)
    {
        for(int i = 0; i<tam; i++)
        {

            auxEntidad = (ePais*) ll_get(pArrayList,i);
            if(auxEntidad != NULL)
            {
                flag = 1;
                entidad_getId(auxEntidad,&auxId);
                entidad_getPais(auxEntidad,auxPais);
                entidad_getRecuperados(auxEntidad,&auxRecuperados);
                entidad_getInfectados(auxEntidad,&auxInfectados);
                entidad_getMuertos(auxEntidad,&auxMuertos);
                printf(" %-4d %-20s %-13d %-16d %13d \n",auxId,auxPais,auxRecuperados,auxInfectados,auxMuertos);

            }
        }

        if(!flag)
        {
            printf("Error no hay paises en la memoria\n");
        }
    }
    else
    {
        printf("\nError al cargar la memoria de los paises\n");
    }



    return 1;
}

/** \brief asigna valores aleatorios a los campos
 *
 * \param element void*
 * \return retorna puntero a void del elemento
 *
 */

void* asignarAleatorio(void* element)
{
    int aleatorio;

    ePais* auxPais = NULL;

    if( element != NULL  )
    {
        auxPais = (ePais*)element;
        aleatorio = rand()%(1000000-50000+1)+50000;
        auxPais->recuperados = aleatorio;
        aleatorio = rand()%(2000000-40000+1)+40000;
        auxPais->infectados = aleatorio;
        aleatorio = rand()%(50000-1000+1)+1000;
        auxPais->muertos = aleatorio;
    }
    return auxPais;
}

/** \brief indica si el elemento esta dentro de lo especificado
 *
 * \param elemento void*
 * \return retorna 0 si error, 1 si todoOk
 *
 */

int filtrarPorExitosos(void* elemento)
{
    int retorno = 0;

    ePais* auxPais = NULL;
    if(elemento != NULL)
    {
        auxPais = (ePais*)elemento;
        if(auxPais->muertos <= 5000)
        {
            retorno = 1;
        }
    }
    return retorno;
}


/** \brief indica si el elemento esta dentro de lo especificado
 *
 * \param elemento void*
 * \return retorna 0 si error, 1 si todoOk
 *
 */

int filtrarPorConProblemas(void* elemento)
{
    int retorno = 0;

    ePais* auxPais = NULL;
    if(elemento != NULL)
    {
        auxPais = (ePais*)elemento;

        if(auxPais->infectados >= auxPais->recuperados *3 )
        {
            retorno = 1;
        }
    }



    return retorno;
}
/** \brief muestra en pantalla el/los pais con mayor muertos
 *
 * \param this LinkedList*
 * \return retorna -1 si error, 0 si todoOk
 *
 */

int informarMasMuertes(LinkedList* this)
{
    ePais* auxMayor = NULL;
    ePais* auxActual = NULL;
    int cant;
    int retorno = -1;

    int auxId;
    char auxPais[25];
    int auxRecuperados;
    int auxInfectados;
    int auxMuertos;


    if(this != NULL)
    {
        cant = ll_len(this);
        for(int i = 0; i< cant; i++)
        {
            auxActual = ll_get(this,i);
            if(i == 0){
                auxMayor = ll_get(this,i);
                if(auxMayor==NULL)
                {
                    retorno = -1;
                    break;
                }
            }
            else if (auxActual!=NULL && auxMayor->muertos <= auxActual->muertos)
            {
                auxMayor = auxActual;
                retorno = 0;
            }
        }
        printf("ID    Pais            Recuperados        Infectados          Muertos\n");
        entidad_getId(auxMayor,&auxId);
        entidad_getPais(auxMayor,auxPais);
        entidad_getRecuperados(auxMayor,&auxRecuperados);
        entidad_getInfectados(auxMayor,&auxInfectados);
        entidad_getMuertos(auxMayor,&auxMuertos);
        printf(" %-4d %-20s %-13d %-16d %13d \n",auxId,auxPais,auxRecuperados,auxInfectados,auxMuertos);


    }
    else
    {
        printf("Error, no hay datos que mostrar\n");
    }




    return retorno;
}



/** \brief ordena dos datos por cantidad infectados
 *
 * \param a void*
 * \param b void*
 * \return retorna 1 si fue posible realizarlo 0 si hubo error
 *
 */
int entidad_ordenaPorCantidadInfectados(void* a, void* b)
{
    int retorno = 0;
    ePais* p1;
    ePais* p2;

    if(a!=NULL && b != NULL)
    {
        p1=(ePais*) a;
        p2=(ePais*) b;
        if(p1->infectados > p2 ->infectados)
        {
            retorno = 1;
        }
        else if(p1->infectados < p2 ->infectados)
        {
            retorno = -1;
        }

    }

    return retorno;
}

/** \brief ordena dos datos por id
 *
 * \param a void*
 * \param b void*
 * \return retorna 1 si fue posible realizarlo 0 si hubo error
 *
 */
int entidad_ordenaPorId(void* a, void* b)
{
    int retorno = 0;
    ePais* p1;
    ePais* p2;

    if(a!=NULL && b != NULL)
    {
        p1=(ePais*) a;
        p2=(ePais*) b;
        if(p1->id > p2 ->id)
        {
            retorno = 1;
        }
        else if(p1->id < p2 ->id)
        {
            retorno = -1;
        }

    }

    return retorno;
}






/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int -1 si error, 0 si null en parametros, 1 si todo OK
 *
 */
int saveAsText(char* path, LinkedList* pArrayList)
{
    int retorno = 1;
    int tam;

    int id;
    char pais[20];
    int recuperados;
    int infectados;
    int muertos;


    ePais* auxEntidad;
   if(path!=NULL && pArrayList!=NULL)
    {
        FILE* f = fopen(path,"w");
        tam = ll_len(pArrayList); // consigo el tamanio de la lista
        fprintf(f,"id,pais,recuperados,infectados,muertos\n");//primer linea del csv

        for(int i = 1; i<tam; i++) // desde 1 para no guardar la primer linea
        {
            auxEntidad = ll_get(pArrayList,i);
            entidad_getId(auxEntidad,&id);
            entidad_getPais(auxEntidad,pais);
            entidad_getRecuperados(auxEntidad,&recuperados);
            entidad_getInfectados(auxEntidad,&infectados);
            entidad_getMuertos(auxEntidad,&muertos);
            fprintf(f,"%d,%s,%d,%d,%d\n",id,pais,recuperados,infectados,muertos);
            retorno = 1;
        }
        fclose(f);
    }
    else
    {
        retorno = 0;
    }


    return retorno;
}

