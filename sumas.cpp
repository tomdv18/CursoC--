#include <iostream>
#include <math.h>

using namespace std;



int hacerLoop(int *a){
    for (size_t i = 0; i < 10; i++)
    {
        *a = 2* *a + i;
        cout << *a;
        cout << "\n";

    }
    return 0;
}


int main(){
    int a = 0;
    hacerLoop(&a);
    cout << a;

    return 0;
}