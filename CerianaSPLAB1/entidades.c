#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "LinkedList.h"
#include "entidades.h"

/** \brief asigna un puntero a un espacio en la memoria reservado
** \return retorna puntero a entidad
*/
ePais* pais_new()
{

    ePais*  auxEntidad = (ePais*) malloc(sizeof(ePais));

    if(auxEntidad!=NULL)
    {
        auxEntidad->id = 0;
        strcpy(auxEntidad->pais," ");
        auxEntidad->recuperados= 0;
        auxEntidad->infectados= 0;
        auxEntidad->muertos= 0;
    }

    return auxEntidad;
}

/** \brief crea una entidad a partir de parametros
 *
 * \param idStr char*
 * \param paisStr char*
 * \param recuperadosStr char*
 * \param infectadosStr char*
 * \param muertosStr char*
 * \return retorna puntero a entidad
 *
 */

ePais* entidad_newParametros(char* idStr,char* paisStr,char* recuperadosStr,char* infectadosStr,char* muertosStr)
{

    ePais* auxEntidad = pais_new();



    if(auxEntidad!= NULL) //si no es un puntero a null
    {

        if(! (entidad_setId(auxEntidad,atoi(idStr))//si esta todo mal hago un free()
                && entidad_setPais(auxEntidad,paisStr)
                && entidad_setRecuperados(auxEntidad,atoi(recuperadosStr))
                && entidad_setInfectados(auxEntidad,atoi(infectadosStr))
                && entidad_setMuertos(auxEntidad,atoi(muertosStr)))
          )
        {
            free(auxEntidad);
            auxEntidad = NULL;
        }

    }


    return auxEntidad;
}

/** \brief modifica de un entidad el pais
 *
 * \param this ePais*
 * \param pais int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_setPais(ePais* this,char* pais)
{
    int todoOk = 0;

    if(this!= NULL && pais!=NULL && strlen(pais) >=3 && strlen(pais)<20 )
    {
        strcpy(this->pais, pais);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief consigue de un entidad el pais
 *
 * \param this ePais*
 * \param pais int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_getPais(ePais* this,char* pais)
{
    int todoOk = 0;

    if(this!= NULL && pais !=NULL)
    {
        strcpy(pais,this->pais);
        todoOk = 1;
    }


    return todoOk;
}
/** \brief modifica de un entidad el id
 *
 * \param this ePais*
 * \param id int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_setId(ePais* this,int id)
{
    int todoOk = 0;

    if(this != NULL && id>=0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief consigue de un entidad el id
 *
 * \param this ePais*
 * \param id int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_getId(ePais* this,int* id)
{
    int todoOk = 0;

    if(this!= NULL && id!=NULL )
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief modifica de un entidad los recuperados
 *
 * \param this ePais*
 * \param id int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_setRecuperados(ePais* this,int recuperados)
{
    int todoOk = 0;

    if(this != NULL && recuperados>=0)
    {
        this->recuperados = recuperados;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief consigue de un entidad los recuperados
 *
 * \param this ePais*
 * \param recuperados int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_getRecuperados(ePais* this,int* recuperados)
{
    int todoOk = 0;

    if(this!= NULL && recuperados!=NULL )
    {
        *recuperados = this->recuperados;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief modifica de un entidad el infectados
 *
 * \param this ePais*
 * \param infectados int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_setInfectados(ePais* this,int infectados)
{
    int todoOk = 0;

    if(this != NULL && infectados>=0)
    {
        this->infectados = infectados;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief consigue de un entidad el infectados
 *
 * \param this ePais*
 * \param infectados int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_getInfectados(ePais* this,int* infectados)
{
    int todoOk = 0;

    if(this!= NULL && infectados!=NULL )
    {
        *infectados = this->infectados;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief modifica de un entidad el muertos
 *
 * \param this ePais*
 * \param muertos int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_setMuertos(ePais* this,int muertos)
{
    int todoOk = 0;

    if(this != NULL && muertos>=0)
    {
        this->muertos = muertos;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief consigue de un entidad el muertos
 *
 * \param this ePais*
 * \param muertos int*
 * \return retorna 0 si todo bien o 1 si error
 *
 */
int entidad_getMuertos(ePais* this,int* muertos)
{
    int todoOk = 0;

    if(this!= NULL && muertos!=NULL )
    {
        *muertos = this->muertos;
        todoOk = 1;
    }
    return todoOk;
}


