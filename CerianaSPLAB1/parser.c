#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "LinkedList.h"
#include "entidades.h"
#include "informes.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EntidadFromText(char* path, LinkedList* pArrayList)
{
    ePais* auxEntidad;
    char buffer[5][255];
    int cant;
    int retorno = -1;
    FILE* pFile = fopen(path,"r");

    if(pFile== NULL)//si no se pudo abrir por alguna razon retorno -1
    {
        printf("Problemas al abrir el archivo\n\n");
        retorno = -1;
    }
    else
    {
        fscanf(pFile,"%[^\n]\n",buffer[0]); // me salteo la primer linea

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]); // cargo los datos separados por coma en un buffer

            if(cant !=5)
            {
                break;
            }

            auxEntidad = entidad_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]); //carga el empleado segun los parametros

            if(auxEntidad!=NULL)
            {
                ll_add(pArrayList,auxEntidad);
                retorno = 0;
            }

        }
    }


    fclose(pFile);
    return retorno;
}
