#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED



int listarList(LinkedList* pArrayList);
int filtrarPorExitosos(void* elemento);
int filtrarPorConProblemas(void* elemento);
int informarMasMuertes(LinkedList* this);
int entidad_ordenaPorCantidadInfectados(void* a, void* b);
int entidad_ordenaPorId(void* a, void* b);
int saveAsText(char* path, LinkedList* pArrayList);
