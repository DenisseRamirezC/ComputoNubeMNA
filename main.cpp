//PROGRAMACION PARALELA: SUMAR DOS ARREGLOS
#include <omp.h>
#include <iostream>
//include "pch.h"
static const int N = 1000; //numero de elementos en cada arreglo
static const int chunk = 100; //tamaño del pedazo del arreglo que se le asigna a cada hilo
static const int mostrar = 10;// mostrar solo los 10 primeros elementos de los arreglos de entrada y el resultado

void imprimeArreglo (float *d); //funcion que imprime el arreglo
//el apuntador f hace referencia al arreglo que se desee

int main(){
    std::cout <<"Sumando Arreglos en Paralelo\n";
    float a[N], b[N], c[N];//a y b son los arreglos de entrada y c el del resultado de la suma
    int i;

    for(int i=0; i<N; i++){
        a[i]=i*5; //operaciones para asignarles valores a cada elemento del array
        b[i]=i*2;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    for(int i=0; i<N; i++)
       c[i]=a[i]+b[i];
    /*finalmente se imprimen los tres arreglos, mostrando unicamente la cantidad de elementos que se especifico
    en la variable mostrar*/
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a:" << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo b:" << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo c:" << std::endl;
    imprimeArreglo(c);
}
void imprimeArreglo (float *d){ 
    for(int x = 0; x < mostrar; x++)
       std::cout << d[x] <<" _ "; //nos dice como se imprimen los valores
    std::cout << std::endl;
}
