#ifndef ARCHIVOS_MUNICIPIO_H_INCLUDED
#define ARCHIVOS_MUNICIPIO_H_INCLUDED
class ArchivoMunicipio
{
private:
    char nombre[50];
public:
    //SETS
    //GETS
    //CONSTRUCTOR
    ArchivoMunicipio(const char *n="municipios.dat")
    {
        strcpy(nombre,n);
    }
    //METODOS
    void limpiarArchivo();
    void grabarRegistro(Municipio obj);
    void modificarRegistro(Municipio obj, int pos);
    Municipio leerRegistro(int pos);
    int contarRegistro();
    void listarArchivo();
    int buscarRegistro(int num);
};
void ArchivoMunicipio::limpiarArchivo()
{
    FILE *p=fopen(nombre, "wb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fclose(p);
}
void ArchivoMunicipio::grabarRegistro(Municipio obj)
{
    FILE *p=fopen(nombre,"ab");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj,sizeof obj,1,p);
    fclose(p);
}
void ArchivoMunicipio::modificarRegistro(Municipio obj, int pos)
{
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(p,sizeof obj*pos,0);
    fwrite(&obj,sizeof obj,1,p);
    fclose(p);
}
Municipio ArchivoMunicipio::leerRegistro(int pos)
{
    FILE *p=fopen(nombre,"rb");
    Municipio obj;
    obj.setNumero(-1);
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        obj.setNumero(-2);
        return obj;
    }
    fseek(p,sizeof obj*pos,0);
    fread(&obj,sizeof obj,1,p);
    fclose(p);
    return obj;
}
int ArchivoMunicipio::contarRegistro()
{
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Municipio);
}
void ArchivoMunicipio::listarArchivo()
{
    int cant=contarRegistro();
    Municipio obj;
    for(int i=0; i<cant; i++)
    {
        obj=leerRegistro(i);
        obj.Mostrar();
        if (obj.getEstado())
        {
            cout<<endl;
        }
    }
}
int ArchivoMunicipio::buscarRegistro(int num)
{
    int cant=contarRegistro();
    Municipio obj;
    for(int i=0; i<cant; i++)
    {
        obj=leerRegistro(i);
        if(num==obj.getNumero())
        {
            return i;
        }
    }
    return -1;
}
#endif // ARCHIVOS_MUNICIPIO_H_INCLUDED

