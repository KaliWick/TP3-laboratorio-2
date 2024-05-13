#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
void cargarCadena(char *pal, int tam)
{
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}
bool fechaAnterior(Fecha obj)
{
    Fecha hoy;
    bool aux=false;
    if(obj.getAnio()<hoy.getAnio())
    {
        aux=true;
    }
    else if(obj.getAnio()==hoy.getAnio() && obj.getMes()<hoy.getMes())
    {
        aux=true;
    }
    else if(obj.getAnio()==hoy.getAnio() && obj.getMes()==hoy.getMes() && obj.getDia()<hoy.getDia())
    {
        aux=true;
    }
    if(aux==false)
    {
        if(obj.getAnio()>=1900 && obj.getMes()>0 && obj.getMes()<=12 && obj.getDia()>0 && obj.getDia()<=31)
        {
            cout<<"LA FECHA INGRESADA ES POSTERIOR"<<endl;
            system("pause");
            system("cls");
            return aux;
        }
    }
    return aux;
}
//EMPRESA
void limpiarEmpresa()
{
    ArchivoEmpresas arcEmp("empresas.dat");
    arcEmp.limpiarArchivo();
}
void bajaLogica()
{
    int num;
    ArchivoEmpresas arcEmp;
    cout<<"INGRESE EL NUMERO DE EMPRESA A MODIFICAR: ";
    cin>>num;
    int pos=arcEmp.buscarRegistro(num);
    if(pos<0)
    {
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Empresa obj;
    obj=arcEmp.leerRegistro(pos);
    obj.setEstado(false);
    arcEmp.modificarRegistro(obj, pos);
    cout<<"LA EMPRESA HA SIDO ELIMINADA CORRECTAMENTE"<<endl;
    system("pause");
}
void modificarRegistro()
{
    ArchivoEmpresas arcEmp("empresas.dat");
    int num;
    cout<<"INGRESE EL NUMERO DE EMPRESA A MODIFICAR: ";
    cin>>num;
    int pos=arcEmp.buscarRegistro(num);
    if(pos<0)
    {
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Empresa obj;
    obj=arcEmp.leerRegistro(pos);
    Fecha fechaNueva;
    cout<<"INGRESE LA FECHA DE CREACION ACTUALIZADA: "<<endl;
    fechaNueva.cargar();
    obj.setFecha(fechaNueva);
    arcEmp.modificarRegistro(obj, pos);
}
void altaEmpresa()
{
    ArchivoEmpresas arcEmp("empresas.dat");
    Empresa obj;
    obj.Cargar();
    int pos=arcEmp.buscarRegistro(obj.getNumero());
    if(pos != -1)
    {
        cout<<"YA EXISTE UNA EMPRESA CON ESE NUMERO EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true)
    {
        arcEmp.grabarRegistro(obj);
    }
    else
    {
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
    }
}
void listarEmpresas()
{
    ArchivoEmpresas arcEmp;
    arcEmp.listarArchivo();
}
void buscarRegistro()
{
    int num;
    cout<<"INGRESE EL NUMERO DE LA EMPRESA A BUSCAR: ";
    cin>>num;
    ArchivoEmpresas arcEmp;
    Empresa obj;
    int pos = arcEmp.buscarRegistro(num);
    if(pos<0)
    {
        cout<<"NO EXISTE UNA EMPRESA CON ESE NUMERO EN EL ARCHIVO"<<endl;
        return;
    }
    obj = arcEmp.leerRegistro(pos);
    system("cls");
    obj.Mostrar();
}
//MUNICIPIO
void limpiarMunicipio()
{
    ArchivoMunicipio arcMun("municipios.dat");
    arcMun.limpiarArchivo();
}
void cargarMunicipio()
{
    ArchivoMunicipio arC;
    Municipio obj;
    obj.Cargar();
    int pos=arC.buscarRegistro(obj.getNumero());
    if(pos != -1)
    {
        cout<<"YA EXISTE UN MUNCIPIO CON ESE NUMERO EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true)
    {
        arC.grabarRegistro(obj);
    }
    else
    {
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
    }
}
void listarMunicipio()
{
    ArchivoMunicipio arC;
    arC.listarArchivo();
}
void bajaMunicipio()
{
    int num;
    ArchivoMunicipio arC;
    cout<<"INGRESE EL NUMERO DE MUNICIPIO A MODIFICAR: ";
    cin>>num;
    int pos=arC.buscarRegistro(num);
    if(pos<0)
    {
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Municipio obj;
    obj=arC.leerRegistro(pos);
    obj.setEstado(false);
    arC.modificarRegistro(obj, pos);
}
void habMunicipio()
{
    int num;
    ArchivoMunicipio arC;
    cout<<"INGRESE EL NUMERO DE MUNICIPIO A MODIFICAR: ";
    cin>>num;
    int pos=arC.buscarRegistro(num);
    if(pos<0)
    {
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Municipio obj;
    obj=arC.leerRegistro(pos);
    int cantHab;
    cout<<"INGRESE LA CANTIDAD DE HABITANTES ACTUAL: ";
    cin>>cantHab;
    obj.setCantHab(cantHab);
    arC.modificarRegistro(obj, pos);
}
void buscarMunicipio()
{
    int num;
    cout<<"INGRESE EL NUMERO DEL MUNICIPIO A BUSCAR: ";
    cin>>num;
    ArchivoMunicipio arC;
    Municipio obj;
    int pos = arC.buscarRegistro(num);
    if(pos<0)
    {
        cout<<"NO EXISTE UN MUNICIPIO CON ESE NUMERO EN EL ARCHIVO"<<endl;
        return;
    }
    obj = arC.leerRegistro(pos);
    system("cls");
    obj.Mostrar();
}
bool validarMunicipio(int num)
{
    ArchivoMunicipio arC;
    Municipio obj;
    int pos = arC.buscarRegistro(num);
    if(pos<0)
    {
        cout<<"NO EXISTE UN MUNICIPIO CON ESE NUMERO EN EL ARCHIVO"<<endl;
        return false;
    }
    return true;
}
//REPORTES
void reporte1()
{
    int cat;
    cout<<"INGRESA UNA CATEGORIA: ";
    cin>>cat;

    ArchivoEmpresas arc;
    Empresa obj;
    int cant=arc.contarRegistro();
    for(int i=0; i<cant; i++)
    {
        obj=arc.leerRegistro(i);
        if((obj.getCategoria()==cat)&&(obj.getEstado()==true))
        {
            obj.Mostrar();
            cout<<endl;
        }
    }
}
void reporte2()
{
    ArchivoEmpresas arc;
    Empresa obj;
    int cant=arc.contarRegistro();
    for(int i=0; i<cant; i++)
    {
        obj=arc.leerRegistro(i);
        if((obj.getCantEmpleados()>50)&&(obj.getEstado()==true))
        {
            obj.Mostrar();
            cout<<endl;
        }
    }
}
void contarEmpresasporMunicipio(int *vec)
{
    ArchivoEmpresas arc;
    Empresa obj;
    int cant=arc.contarRegistro();
    for(int i=0; i<cant; i++)
    {
        obj=arc.leerRegistro(i);
        vec[(obj.getMunicipio())-1]++;
    }
}
void reporte3()
{
    int cantMuni[135] {}, CM=0;
    contarEmpresasporMunicipio(cantMuni);
    for(int i=0; i<135; i++)
    {
        if(cantMuni[i]==0)
        {
            CM++;
        }
    }
    cout<<"CANTIDAD DE MUNICIPIOS SIN EMPRESA: "<<CM<<endl;
}
void reporte4()
{

    int cantMuni[135] {}, CM=0;
    contarEmpresasporMunicipio(cantMuni);
    for(int i=0; i<135; i++)
    {
        if(cantMuni[i]>=5)
        {
            cout<<"EL MUNICIPIO: "<<i+1<<" TIENE MAS DE 5 EMPRESAS"<<endl;
        }
    }
}
void reporte5()
{
    ArchivoEmpresas arc;
    Empresa obj;
    int cant=arc.contarRegistro();
    int vCat[20] {}, maxcat=0;
    for(int i=0; i<20; i++)
    {
        vCat[(obj.getCategoria())-1]++;
    }
    for(int i=1; i<20; i++)
    {
        if(vCat[maxcat]<vCat[i])
        {
            maxcat=i;
        }
    }
    cout<<"LA CATEGORIA CON MAS EMPRESAS ES LA: "<<maxcat+1<<endl;
}
//CONFIGURACION
void backupEmpresas()
{
    ArchivoEmpresas arcEmp;
    ArchivoEmpresas bkpEmp("empresas.bkp");
    Empresa obj;
    bkpEmp.limpiarArchivo();
    int cant=arcEmp.contarRegistro();
    for(int i=0; i<cant; i++)
    {
        obj=arcEmp.leerRegistro(i);
        bkpEmp.grabarRegistro(obj);
    }
}
void restaurarEmpresas()
{
    ArchivoEmpresas arcEmp;
    ArchivoEmpresas bkpEmp("empresas.bkp");
    Empresa obj;
    arcEmp.limpiarArchivo();
    int cant=bkpEmp.contarRegistro();
    for(int i=0; i<cant; i++)
    {
        obj=bkpEmp.leerRegistro(i);
        arcEmp.grabarRegistro(obj);
    }
}
void backupMunicipios()
{
    ArchivoMunicipio arcMun;
    ArchivoMunicipio bkpMun("municipios.bkp");
    Municipio obj;
    bkpMun.limpiarArchivo();
    int cant=arcMun.contarRegistro();
    for(int i=0; i<cant; i++)
    {
        obj=arcMun.leerRegistro(i);
        bkpMun.grabarRegistro(obj);
    }
}
void restaurarMunicipios()
{
    ArchivoMunicipio arcMun;
    ArchivoMunicipio bkpMun("municipios.bkp");
    Municipio obj;
    arcMun.limpiarArchivo();
    int cant=bkpMun.contarRegistro();
    for(int i=0; i<cant; i++)
    {
        obj=bkpMun.leerRegistro(i);
        arcMun.grabarRegistro(obj);
    }
}
void establecerDatosInicio()
{
    ArchivoEmpresas arcEmp;
    ArchivoEmpresas iniEmp("empresas.ini");
    Empresa obj_empresa;
    arcEmp.limpiarArchivo();
    int cant=iniEmp.contarRegistro();
    for(int i=0; i<cant; i++)
    {
        obj_empresa=iniEmp.leerRegistro(i);
        arcEmp.grabarRegistro(obj_empresa);
    }
    ArchivoMunicipio arcMun;
    ArchivoMunicipio iniMun("municipio.ini");
    Municipio obj_municipio;
    arcMun.limpiarArchivo();
    cant=iniMun.contarRegistro();
    for(int i=0; i<cant; i++)
    {
        obj_municipio=iniMun.leerRegistro(i);
        arcMun.grabarRegistro(obj_municipio);
    }
}
void archivosInicio()//esta funcion permite cargar a mano los datos de inicio
{
    Empresa obj_empresa;
    FILE *p=fopen("empresas.ini","ab");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<10; i++)
    {
        obj_empresa.Cargar();
        fwrite(&obj_empresa,sizeof(Empresa),1,p);
    }
    fclose(p);
    Municipio obj_municipio;
    FILE *k=fopen("municipio.ini","ab");
    if(k==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<10; i++)
    {
        obj_municipio.Cargar();
        cout<<endl;
        fwrite(&obj_municipio,sizeof(Municipio),1,k);
    }
    fclose(k);

}
#endif // FUNCIONES_H_INCLUDED
