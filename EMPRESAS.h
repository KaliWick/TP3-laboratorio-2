#ifndef EMPRESAS_H_INCLUDED
#define EMPRESAS_H_INCLUDED
class Empresa
{
private:
    int numero;
    char nombre[30];
    int cantidadEmpleados;
    int categoria;
    int numeroMunicipio;
    float facturacionAnual;
    Fecha fechaCreacion;
    bool estado;
public:
    //SETS
    void setNumero(int n){numero=n;}
    void setNombre(const char *nom){strcpy(nombre,nom);}
    void setCantEmpleados(int cantEmp){cantidadEmpleados=cantEmp;}
    void setCategoria (int cat)
    {
        if(cat>0&&cat<=80){categoria=cat;}
    }
    void setMunicipio(int m)
    {
        if((m>0)&&(m<=150)){numeroMunicipio=m;}
    }
    void setFacturacionAnual(int f)
    {
        if(f>0){facturacionAnual=f;}
    }
    void setFecha(Fecha obj)
    {
        fechaCreacion=obj;
    }
    void setEstado(int e)
    {
        estado=e;
    }
    //GETS
    int getNumero()
    {
        return numero;
    }
    const char getNombre()
    {
        return *nombre;
    }
    int getCantEmpleados()
    {
        return cantidadEmpleados;
    }
    int getCategoria()
    {
        return categoria;
    }
    int getMunicipio(){return numeroMunicipio;}
    float getFacturacionAnual()
    {
        return facturacionAnual;
    }
    bool getEstado()
    {
        return estado;
    }
    //CONSTRUCTOR
    Empresa()
    {
        estado=false;
    }
    //FUNCIONES
    void Cargar();
    void Mostrar();
};
void Empresa::Cargar()
{
    cout<<"NUMERO: ";
    cin>>numero;
    if(numero<1)
    {
        return;
    }
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"CANTIDAD EMPLEADOS: ";
    cin>>cantidadEmpleados;
    cout<<"CATEGORIA (1 a 80): ";
    cin>>categoria;
    if(categoria<=0||categoria>80)
    {
        cout<<"CATEGORIA INVALIDA"<<endl;
        return;
    }
    cout<<"MUNICIPIO (1 a 135): ";
    cin>>numeroMunicipio;
     if(numeroMunicipio<=0||numeroMunicipio>135)
    {
        cout<<"MUNICIPIO INVALIDO"<<endl;
        return;
    }

    if(validarMunicipio(numeroMunicipio)==false)
    {
        return;
    }
    while(fechaCreacion.cargar()==false || fechaAnterior(fechaCreacion)==false){}
    cout<<"INGRESE LA FACTURACION ANUAL: $";
    cin>>facturacionAnual;
    estado=true;
}
void Empresa::Mostrar()
{
    if(estado)
    {
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CANTIDAD EMPLEADOS: "<<cantidadEmpleados<<endl;
        cout<<"CATEGORIA: "<<categoria<<endl;
        cout<<"MUNICIPIO: "<<numeroMunicipio<<endl;
        fechaCreacion.mostrar();
        cout<<"FACTURACION ANUAL:"<<facturacionAnual<<endl;
        estado=true;
        cout<<" "<<endl;
    }
}

#endif // EMPRESAS_H_INCLUDED
