#ifndef ARCHIVOS_EMPRESAS_H_INCLUDED
#define ARCHIVOS_EMPRESAS_H_INCLUDED
class ArchivoEmpresas
{
private:
    char nombre[30];
public:
    //SETS

    //GETS

    //CONSTRUCTOR
    ArchivoEmpresas(const char *n="empresas.dat")
    {
        strcpy(nombre,n);
    }

    //METODOS
    void limpiarArchivo();
    void grabarRegistro(Empresa obj);
    void modificarRegistro(Empresa obj, int pos);
    Empresa leerRegistro(int pos);
    int contarRegistro();
    void listarArchivo();
    int buscarRegistro(int num);
};

void ArchivoEmpresas::limpiarArchivo()
{
    FILE *p=fopen(nombre, "wb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fclose(p);
}
void ArchivoEmpresas::grabarRegistro(Empresa obj)
{
    FILE *p=fopen(nombre, "ab");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}
void ArchivoEmpresas::modificarRegistro(Empresa obj, int pos)
{
    FILE *p;
    p=fopen(nombre, "rb+");
        if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(p,sizeof obj * pos,0);
    fwrite(&obj, sizeof obj,1,p);
    fclose(p);
}
Empresa ArchivoEmpresas::leerRegistro(int pos)
{
    FILE *p;
    Empresa obj;
    obj.setNumero(-1);
    p=fopen(nombre,"rb");
        if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        obj.setNumero(-2);
        return obj;
    }
    fseek(p,sizeof obj * pos,0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int ArchivoEmpresas::contarRegistro()
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
    return cantBytes/sizeof (Empresa);
}
void ArchivoEmpresas::listarArchivo()
{
 int cant=contarRegistro();
 Empresa obj;
 for(int i=0; i<cant;i++)
 {
    obj=leerRegistro(i);
    obj.Mostrar();
    if (obj.getEstado())
    {
       cout<<endl;
    }
 }
}
int ArchivoEmpresas::buscarRegistro(int num)
{
 int cant=contarRegistro();
 Empresa obj;
 for(int i=0; i<cant;i++)
 {
    obj=leerRegistro(i);
    if(num==obj.getNumero())
    {
        return i;
    }
 }
    return -1;
}

#endif // ARCHIVOS_EMPRESAS_H_INCLUDED
