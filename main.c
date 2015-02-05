#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arreglo[], int i, int j);
void mezclar(int arreglo[],int inicio, int medio, int fin);
void copiar(int a[], int b[]);

 int n;

int main()
{
    FILE *fp = fopen("arreglo.in", "r");
    time_t t;
    int i;

    srand((unsigned) time(&t));

    fscanf(fp,"%d", &n);

    int arreglo[n];

    for(i = 0; i < n; i++)
    {
        arreglo[i] = rand() % 100;
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ",arreglo[i]);
    }
    printf("\n");
    mergeSort(arreglo,0,n);
    for(i = 0; i < n; i++)
    {
        printf("%d ", arreglo[i]);
    }
    return 0;
}

void mergeSort(int arreglo[], int i, int j)
{
    int mitad;

    if(j - i  > 1)
    {
        mitad = (i+j)/2;
        mergeSort(arreglo, i, mitad);
        mergeSort(arreglo, mitad, j);
        mezclar(arreglo, i, mitad, j);
    }
}

void mezclar(int arreglo[],int inicio, int medio, int fin)
{
    int ordenado[n], izquierda, derecha, i;

    izquierda = inicio;
    derecha = medio;
    copiar(ordenado, arreglo);
    for(i = inicio; i <= fin; i++)
    {
        if(izquierda < medio && (derecha == fin || ordenado[izquierda] <= ordenado[derecha])) // si el derecho llega al fin, se coloca el resto del derecho, si el derecho llega al fin, se coloca el resto del izquierdo
        {
            arreglo[i] = ordenado[izquierda]; //si b en izq menor que b en der
            izquierda++;
        }else
        {
            arreglo[i] = ordenado[derecha]; // si b en der menor que b en izq
            derecha++;
        }
    }

}

void copiar(int a[], int b[])
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

