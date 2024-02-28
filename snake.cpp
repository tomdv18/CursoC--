#include <iostream>
#include <unistd.h>
#include <ncurses.h>


using namespace std;

#define LENGTHTAIL 50

const int width = 20;
const int height = 15;

enum snakeDir {STOP = 0, LEFT,RIGHT, UP, DOWN};

struct SnakeGame{
    bool gameOver;
    int x,y,fruitX,fruitY,score;
    int tailX[LENGTHTAIL];
    int tailY[LENGTHTAIL];
    int nTail;
    snakeDir dir;

};




void pantallaFinal(int score){
    cout << endl << "+-+-+-+-+ +-+-+-+-+" << endl;
    cout << "|G|a|m|e| |o|v|e|r|" << endl;
    cout << "+-+-+-+-+ +-+-+-+-+" << endl;

}

void setUp(SnakeGame * snake) {
    snake->gameOver = false;
    snake->dir = STOP;
    snake->x = width / 2;
    snake->y = height / 2;
    snake->fruitX = rand() % width - 1;
    snake->fruitY = rand() % height- 1;
    snake->score = 0;
    snake->nTail = 0;

}
void draw(int x, int y, int fruitX, int fruitY, int score, int nTail, int tailX[LENGTHTAIL], int tailY[LENGTHTAIL]){
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
                cout << "■";
            }
            else if (k== 0  || k == width -1){
                cout << "#";
            }          
            else{
                bool print = false;
                for (size_t t = 0; t < nTail; t++){
                    if ((tailX)[t] == k && (tailY)[t] == j){
                        cout << "o";
                        print = true;
                    }
                }
                if (!print) cout << " ";
            }
        }
        cout << endl;
    }

    for (size_t i = 0; i < width; i++){
       cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
    
    

}


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

void controller(SnakeGame * snake){
    
    int prevX = snake->x;
    int prevY = snake->y;
    int prev2X, prev2Y;
    int temp = snake->tailX[0];
    int temp2 = snake->tailY[0];
    snake->tailX[0] = prevX;
    snake->tailY[0] = prevY;

    for(int i = 1; i < snake->nTail ; i++)
    {
        prev2X = snake->tailX[i];
        prev2Y = snake->tailY[i];
        snake->tailX[i] = temp;
        snake->tailY[i] = temp2;
        temp = prev2X;
        temp2 = prev2Y;
    }
    switch (snake->dir)
    {
    case LEFT:
        snake->x = snake->x - 1;
        break;
    case RIGHT:
        snake->x= snake->x + 1;
        break;
    case UP:
        snake->y = snake->y - 1;
        break;
    case DOWN:
        snake->y= snake->y + 1;
        break;
    default:
        break;
    }
    for (size_t k = 0; k < snake->nTail; k++){
        if (snake->x == snake->tailX[k] && snake->tailY[k] == snake->y){
            snake->gameOver = true;
        }
        
    }
    if (snake->x<= 0 || snake->x >= width ||  snake->y <=0 || snake->y >= height){
        snake->gameOver = true;
    }

    if (snake->x == snake->fruitX && snake->y == snake->fruitY){
        snake->score = snake->score +5;
        snake->nTail = snake->nTail +1;
        snake->fruitX = rand()% width  -1;
        snake->fruitY = rand()% height -1;
        cout << "Point Scored!" << endl;
    }
}
int main(){

    SnakeGame snake;
    
    setUp(&snake);

    while (!(snake.gameOver)){
        draw(snake.x,snake.y,snake.fruitX, snake.fruitY, snake.score, snake.nTail, snake.tailX, snake.tailY);   
        getInput(&(snake.dir), &(snake.gameOver));
        controller(&snake);
        sleep(1);
    }
    pantallaFinal(snake.score);
    return 0;
}