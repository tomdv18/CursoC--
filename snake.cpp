#include <iostream>
#include <unistd.h>
#include <ncurses.h>

using namespace std;



const int width = 20;
const int height = 20;


enum snakeDir {STOP = 0, LEFT,RIGHT, UP, DOWN};

void setUp(bool *gameOver, int* x, int* y, int *fruitX,int*fruitY, int*score, snakeDir *dir){
    *gameOver = false;
    *dir = STOP;
    *x = width/2;
    *y = height/2;
    *fruitX = rand()% width;
    *fruitY = rand()% height;
    *score =0;

    
}
void draw(int x, int y, int fruitX, int fruitY, int score){
    system("clear");
    for (size_t i = 0; i < width; i++){
        cout << "#";
    }
    cout << endl;

    for (size_t j = 0; j < height; j++){
        for (size_t k = 0; k < width; k++){
            if (j== y && k == x){
                cout << "0";
            }
            else if (j==fruitY && k == fruitX){
                cout << "o";
            }
            else if (k== 0  || k == width -1){
                cout << "#";
            }         
            else
            cout << " ";
        }
        cout << endl;
    }

    for (size_t i = 0; i < width; i++){
       cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
    
    

}
#include <ncurses.h>

void getInput(snakeDir * dir, bool *gameOver){
    initscr(); // Inicializa ncurses
    cbreak(); // Desactiva el buffer de línea, pasando todo al usuario
    noecho(); // No muestra los caracteres ingresados

    timeout(0); // La función getch() no espera la entrada del usuario
    int ch = getch(); // Lee el caracter

    if(ch == 'w'){
        *dir = UP;
    }
    else if(ch == 'a'){
        *dir = LEFT;
    }
    else if(ch == 's'){
        *dir = DOWN;
    }
    else if(ch == 'd'){
        *dir = RIGHT;
    }
    else if(ch == 'x'){
        *gameOver = true;
    }

    endwin(); // Finaliza ncurses
}

void controller(snakeDir dir, int *x, int *y, bool *gameOver, int *fruitX, int* fruitY, int*score){
    if (*x == *fruitX && *y == *fruitY){
        cout << "Point Scored!" << endl;
        *score = *score +1;
        *fruitX = rand()% width;
        *fruitY = rand()% height;
    }
    switch (dir)
    {
    case LEFT:
        *x = *x - 1;
        break;
    case RIGHT:
        *x= *x + 1;
        break;
    case UP:
        *y = *y - 1;
        break;
    case DOWN:
        *y= *y + 1;
        break;
    default:
        break;
    }
    if (*x< 0 || *x > width ||  *y < 0 || *y > height){
        *gameOver = true;
    }

    
}
int main(){


    bool gameOver;
    int x,y,fruitX,fruitY,score;
    snakeDir dir;
    setUp(&gameOver, &x,&y,&fruitX,&fruitY,&score, &dir);

    while (!gameOver){
        draw(x,y,fruitX,fruitY, score);   
        getInput(&dir, &gameOver);
        controller(dir, &x, &y, &gameOver, &fruitX, &fruitY, &score);
        sleep(1);
    }
    return 0;
}