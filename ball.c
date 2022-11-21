#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))


#define MAX_X  80
#define MAX_Y  20
#define BALL_SHAPE '@'


typedef struct {
    int x , y;
    int delta_x, delta_y;
    int max_x, max_y;
} ball_t;

void init_ball(ball_t *ball) {
    ball->x = (rand() % (MAX_X - 2)) + 1;
    ball->y = (rand() % (MAX_Y - 2)) + 1;
    ball->delta_x = (rand() % 2) ? 1 : -1;
    ball->delta_y = (rand() % 2) ? 1 : -1;
}

void move_ball(ball_t *ball) {
    ball->x += ball->delta_x;
    if (ball->x <= 0 || ball->x >= MAX_X)
        ball->delta_x *= -1;

    ball->y = ball->y + ball->delta_y;
    if (ball->y <= 0 || ball->y >= MAX_Y)
        ball->delta_y *= -1;
}


int main(int argc, char const *argv[])
{
    srand(time(NULL));   
    clear();

    ball_t ball;
    init_ball(&ball);

    for(;;) {
        gotoxy(ball.x, ball.y);
        printf("%c",BALL_SHAPE);
        fflush(stdout); 

        usleep(50000);

        
        gotoxy(ball.x, ball.y);
        printf("%c",' ');
        fflush(stdout); 

        move_ball(&ball);
    }

    return 0;
}

