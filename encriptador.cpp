#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define DESPLAZAMIENTO 6 // 12 es el desplazamiento, se puede cambiar

string ascii[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z","A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", "."};
int tamanio = sizeof(ascii) / sizeof(ascii[0]);

void cifrar(){
    cout << "Cifrar\n";
    char txt[50];
    cin.ignore();
    cout << "Ingrese el texto a cifrar: ";
    cin.getline(txt, 50);
    for (size_t i = 0; i < strlen(txt); i++){
        for (size_t j = 0; j < tamanio; j++){
            if (txt[i] == ascii[j][0]){
                int auxiliar = (j+DESPLAZAMIENTO)% tamanio; 
                txt[i] = ascii[auxiliar][0];
                break;
            }
        }
    }
    cout << "Texto:  `"<< txt;
    cout << "` \n";
}

void descifrar(){
    cout << "Descifrar\n";
    char txt[50];
    cin.ignore();
    cout << "Ingrese el texto a descifrar: ";
    cin.getline(txt, 75);
    for (size_t i = 0; i < strlen(txt); i++){
        for (size_t j = 0; j < tamanio; j++){
            if (txt[i] == ascii[j][0]){
                int auxiliar = (j-DESPLAZAMIENTO+ tamanio)% tamanio; 

                txt[i] = ascii[auxiliar][0];
                break;
            }
        }
    }
    cout << "Texto:  `"<< txt;
    cout << "` \n";
}

int menu(){
    int opcion;
    cout << "1. Cifrar\n";
    cout << "2. Descifrar\n";
    cout << "3. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cifrar();
        return 0;
    case 2:
        descifrar();
        return 0;
    case 3:
        exit(0);
        return -1;
    default:
        cout << "Opcion no valida!\n";
        return 0;
    }
}
int main(){
    cout <<"Total de caracteres considerados: " << tamanio << endl;
    while (menu() != -1);
    return 0;
}