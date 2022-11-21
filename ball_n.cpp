#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

#define MAX_X  80
#define MAX_Y  20
#define BALL_SHAPE '@'

class Ball {
    protected:
        int x , y;
        int delta_x, delta_y;
        int max_x, max_y;
        char shape;

    protected:
        void init(int p_mx, int p_my, char b_shape = BALL_SHAPE);
        void printAt(char c);

    public:
        Ball();
        Ball(int p_mx, int p_my, char p_shape);


        void show();
        void erase();
        void bounce();
};


Ball::Ball()
{
    init(MAX_X,MAX_Y);
}

Ball::Ball(int p_mx, int p_my, char p_shape)
{
    init(p_mx,p_my,p_shape);    
}

void Ball::init(int p_mx, int p_my, char b_shape)
{
    max_x = p_mx;
    max_y = p_my;

    x = (rand() % (max_x - 2)) + 1;
    y = (rand() % (max_y - 2)) + 1;
    delta_x = (rand() % 2) ? 1 : -1;
    delta_y = (rand() % 2) ? 1 : -1;

    shape = b_shape;
}


void Ball::printAt(char c)
{
    gotoxy(x,y);
    printf("%c", c);
    fflush(stdout);
}

void Ball::show()
{
    printAt(shape);    
}

void Ball::erase()
{
    printAt(' ');        
}

void Ball::bounce()
{
    x += delta_x;
    if (x <= 0 || x >= MAX_X)
        delta_x *= -1;

    y = y + delta_y;
    if (y <= 0 || y >= MAX_Y)
        delta_y *= -1;    
}

#define BALL_COUNT  10

//-----------------------------
int main(int argc, char const *argv[])
{
    srand(time(NULL));   
    clear();


    Ball ball[BALL_COUNT];

    for(;;) {
        for (int b=0; b < BALL_COUNT; b++)
            ball[b].show();

        usleep(50000);

        for (int b=0; b < BALL_COUNT; b++)
            ball[b].erase();
        for (int b=0; b < BALL_COUNT; b++)
            ball[b].bounce();
    }

    return 0;
}

