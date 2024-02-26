#include <iostream>
#include <vector>
#include <string>
#define MAXCARACTERES 100
using namespace std;

string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
string ascii[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};


void traductor_morse(string cadena){
    string resultado = "";
    for (size_t i = 0; i < cadena.length(); i++)
    {
        if (cadena[i] == ' ')
        {
            resultado += " ";
        }
        else
        {
            for (size_t j = 0; j < 26; j++)
            {
                if (toupper(cadena[i]) == ascii[j][0])
                {
                    resultado += morse[j];
                    resultado += " ";
                }
            }
        }
    }
    cout << resultado << endl;
}

void traductor_ascii(string cadena){
    string resultado = "";
    string letra = "";
    for (size_t i = 0; i < cadena.length(); i++)
    {
        if (cadena[i] == ' ')
        {
            for (size_t j = 0; j < 26; j++)
            {
                if (letra == morse[j])
                {
                    resultado += ascii[j];
                }
            }
            letra = "";
        }
        else
        {
            letra += cadena[i];
        }
    }
    for (size_t j = 0; j < 26; j++)
    {
        if (letra == morse[j])
        {
            resultado += ascii[j];
        }
    }
    cout << resultado << endl;
}

int main() {
    
    char cadena[MAXCARACTERES];
    cout << "Ingrese la cadena a traducir: ";
    cin.getline(cadena, MAXCARACTERES);
    string cadenaString = cadena;
    char opcion;

    cout << "Ingrese S para traducir de ASCII a Morse, o N para traducir de Morse a ASCII: ";
    cin >> opcion;
    opcion = toupper(opcion);
    while (opcion != 'S' && opcion != 'N')
    {
        cout << "Opción inválida" << endl;
        cout << "Ingrese S para traducir de ASCII a Morse, o N para traducir de Morse a ASCII: ";
        cin >> opcion;
        opcion = toupper(opcion);
    }
    if (opcion == 'S')
    {
        traductor_morse(cadenaString);
    }
    else
    {
        traductor_ascii(cadenaString);
    }
    return 0;
}