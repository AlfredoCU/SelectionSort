#include <iostream>
#include <ctime>

using namespace std;

/*
 * Funcion para imprimir el arreglo.
 */
void print(int arrayN[], int n) {
    cout << "[";
    for(int i = 0; i < n; i++) {
        if(i < n - 1) {
            cout << arrayN[i] << ", ";
        } else {
            cout << arrayN[i];
        }
    }
    cout << "]" << endl;
}

/*
 * Funcion para intercambiar los elementos.
 */
void swapArray(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

/*
 * Funcion selecccion -> ordenamiento.
 */
void seleccion(int arrayN[], int n) {
    int menor, i = 0, j;

    while(i < n) {
        menor = i;
        j = i + 1;

        while(j <= n) {
            if(arrayN[j] < arrayN[menor]) {
                menor = j;
            }
            j++;
        }
        if(menor != i) {
            swapArray(&arrayN[i], &arrayN[menor]);
        }
        i++;
    }
}

/*
 * Funcion principal.
 */
int main() {
    srand(time(0));
    int arrayNum[10];
    int length = (sizeof(arrayNum) / sizeof(*arrayNum));

    for(int i = 0; i < length; i++) {
        arrayNum[i] = 1 + rand() % 100;
    }

    cout << "Ordenamiento Seleccion" << endl << endl;
    cout << "- Longitud del arreglo: " << length << endl;

    cout << "- Arreglo original: ";
    print(arrayNum, length);

    seleccion(arrayNum, length - 1);

    cout << "- Arreglo ordenado: ";
    print(arrayNum, length);
    return 0;
}
