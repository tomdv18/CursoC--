#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;



int main(){
    setlocale(LC_CTYPE, "spanish");

    float capital, tasa, tiempo = -1;

    while (capital <= 0)
    {
        cout << "Ingrese el capital: ";
        cin >> capital;
    }
    while (tasa <= 0)
    {
        cout << "Ingrese la tasa de interés: ";
        cin >> tasa;
    }
    while (tiempo <= 0)
    {
        cout << "Ingrese el tiempo (En anios): ";
        cin >> tiempo;
    }

    float resultado = capital * pow((1 + tasa/100), tiempo);
    float sin_interes = capital + tiempo *( capital *tasa/100);

    cout << "El monto final es: " << resultado << endl;
    cout << "De no haber usado interes compuesto, el monto final sería: " << sin_interes  << endl;

    return 0;
}