#include <iostream>
#include <unistd.h>
#include <ncurses.h>

using namespace std;



const int width = 20;
const int height = 20;


enum snakeDir {LEFT,RIGHT, UP, DOWN, STOP = 0};

void setUp(bool *gameOver, int* x, int* y, int *fruitX,int*fruitY, int*score, snakeDir *dir){
    *gameOver = false;
    *dir = STOP;
    *x = width/2;
    *y = height/2;
    *fruitX = rand()% width;
    *fruitY = rand()% height;
    *score =0;

    
}
void draw(int x, int y, int fruitX, int fruitY){
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
            else if (j==fruitY && k == fruitY){
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
    
    

}
void getInput(snakeDir * dir, bool *gameOver){
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    if(getch() == 'w'){
        *dir = UP;
        return;
    }
    else if(getch() == 'a'){
        *dir = LEFT;
        return;
    }
    else if(getch() == 's'){
        *dir = DOWN;
        return;
    }
    else if(getch() == 'd'){
        *dir = RIGHT;
        return;
    }
    else if(getch() == 'x'){
        *gameOver = true;
        return;
    }
    
}

void controller(snakeDir dir, int *x, int *y){
    switch (dir)
    {
    case LEFT:
        *x--;
        break;
    case RIGHT:
        *x++;
        break;
    case UP:
        *y--;
        break;
    case DOWN:
        *y++;
        break;
    default:
        break;
    }
}
int main(){


    bool gameOver;
    int x,y,fruitX,fruitY,score;
    snakeDir dir;
    setUp(&gameOver, &x,&y,&fruitX,&fruitY,&score, &dir);

    while (!gameOver){
        draw(x,y,fruitX,fruitY);   
        getInput(&dir, &gameOver);
        controller(dir, &x, &y);
        sleep(5);
    }
    return 0;
}