#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "validaciones.h"
#include "LinkedList.h"
#include "informes.h"
#include "parser.h"



int menu();

int main()
{
    srand (time(NULL));
    LinkedList* listaInicial = ll_newLinkedList();
    LinkedList* listaConValores = NULL;
    LinkedList* listaFiltrada = NULL;

    int opcion;
    int continuar = 1;


    do
    {
        opcion = menu();

        switch(opcion)
        {
            case 1:
                parser_EntidadFromText("pandemia.csv",listaInicial);
                break;
            case 2:
                if(listaConValores==NULL)
                {
                    listarList(listaInicial);
                }
                else
                {
                    listarList(listaConValores);
                }
                break;
            case 3:
                listaConValores = ll_map(listaInicial,asignarAleatorio);
                if(listaConValores != NULL)
                {
                    printf("Valores asignados con exito\n");
                }
                break;
            case 4:
                listaFiltrada = ll_filter(listaConValores,filtrarPorExitosos);
                if(listaFiltrada == NULL)
                {
                    printf("No se pudo realizar la operacion\n");
                }
                else
                {
                    saveAsText("filtroPorExito.csv",listaFiltrada);
                }
                break;
            case 5:
                listaFiltrada = ll_filter(listaConValores,filtrarPorConProblemas);
                if(listaFiltrada == NULL)
                {
                    printf("No se pudo realizar la operacion\n");
                }
                else
                {
                    saveAsText("filtroPorEnElHorno.csv",listaFiltrada);
                }
                break;
            case 6:
                ll_sort(listaConValores,entidad_ordenaPorCantidadInfectados,0);
                listarList(listaConValores);
                ll_sort(listaConValores,entidad_ordenaPorId,1);
                break;
            case 7:
                informarMasMuertes(listaConValores);
                break;
            default:
                continuar = 0;
                printf("Ha salido del programa\n");
            break;
        }
        system("pause");


    }while(continuar);




    return 0;
}


int menu()
{
    int retorno = -1;
    system("cls");
    printf("1.Cargar archivo\n");
    printf("2.Imprimir lista\n");
    printf("3.Asignar estadisticas\n");
    printf("4.Filtrar por paises exitosos\n");
    printf("5.Filtrar por paises para nada exitosos\n");
    printf("6.Ordenar por nivel de infeccion\n");
    printf("7.Mostrar mas castigado\n");
    printf("8.Salir\n");

    utn_getNumero( &retorno,"Ingrese un valor del 1 al 8: ","Error, el valor ingresado es incorrecto\n",1,8,5);

    return retorno;
}
