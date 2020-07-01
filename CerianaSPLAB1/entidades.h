#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

typedef struct{

int id;
char pais[25];
int recuperados;
int infectados;
int muertos;

}ePais;

#endif // ENTIDADES_H_INCLUDED

ePais* pais_new();
ePais* entidad_newParametros(char* idStr,char* paisStr,char* recuperadosStr,char* infectadosStr,char* muertosStr);

int entidad_setPais(ePais* this,char* pais);
int entidad_getPais(ePais* this,char* pais);
int entidad_setId(ePais* this,int id);
int entidad_getId(ePais* this,int* id);
int entidad_setRecuperados(ePais* this,int recuperados);
int entidad_getRecuperados(ePais* this,int* recuperados);
int entidad_setInfectados(ePais* this,int infectados);
int entidad_getInfectados(ePais* this,int* infectados);
int entidad_setMuertos(ePais* this,int muertos);
int entidad_getMuertos(ePais* this,int* muertos);
