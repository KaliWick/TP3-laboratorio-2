#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
void cargarCadena(char *pal, int tam);
//fecha;
bool fechaAnterior(Fecha obj);
//empresa
void limpiarEmpresa();
void modificarRegistro();
void buscarRegistro();
void bajaLogica();
void altaLogica();
void altaEmpresa();
//municipio
void limpiarMunicipio();
void cargarMunicipio();
void listarMunicipio();
void bajaMunicipio();
void altaMunicipio();
void buscarMunicipio();
bool validarMunicipio(int num);
//Reportes
void reporte1();
void reporte2();
void contarEmpresasporMunicipio(int *vec);
void reporte3();
void reporte4();
void reporte5();
//Configuracion
void backupEmpresas();
void restaurarEmpresas();
void backupMunicipios();
void restaurarMunicipios();
void establecerDatosInicio();
void archivosInicio();//<-esta funcion crea los .ini y te pide cargarlos manualmente
#endif // PROTOTIPOS_H_INCLUDED
