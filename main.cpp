#include <iostream>
#include <string.h>

#define MAX 5

using namespace std;

int exist_grado(int ver[MAX], int ncoef) {

    for (int i=0; (ver[i]==0) && (i< MAX) && (ncoef != 0); i++ ) {
        ncoef --;
    }
    return ncoef;
}

int input_polinomio(string nro_polinomio) {
    int n;
    cout<<"Cual sera el grado del "<<nro_polinomio<<" polinomio?"<<endl;
    cin>>n;
    int aux = n;
    int a[n];
    for (int i=0; n>=0; n--,i++) {
        cout<<"Ingrese el Coeficiente de x^"<<n<<endl;
        cin>>a[i];
    }
    int coef = exist_grado(a, aux);
    return coef;
}

void print_limit(int result) {
    cout<<"por lo tanto existe Limite"<<"\n\n"<<"\t\t"<<"el cual el LIM es "<<result;
}

int main() {
    int coefA, coefB, lim;
    float result = 0;
    do{
        coefA = input_polinomio("Primer");
    }while(coefA == 0);
    int a[coefA]; //def de arreglo del polinomio
    
    do{
        coefB = input_polinomio("Segundo");
    }while(coefB == 0);
    int b[coefB]; //def de arreglo del polinomio

    cout<<"El grado del polinomio numerador es "<<coefA<<" y el del denominador es "<<coefB<<endl;

    if( coefA > coefB ) {
        lim = coefA - coefB;
        while (lim != 0) {
            result = result + a[lim];
            lim --;
        }
        if ( result != 0 ) {
            print_limit(result);
        } else {
            cout<<"por lo tanbto No existe Limite, ya que tiende al Infinito";
        }
    } else {
        if( coefA < coefB ) {
            print_limit(0);
        } else {
            result = ( a[0]/b[0] );
            print_limit(result);
        }
    }
    return 0;
}

