#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#define DELAY 80
#define LRWALL '<'
#define RRWALL '>'
#define URWALL '^'
#define DRWALL 'v'
#define WALL '*'

typedef struct ball{
    int x;
    int y;
    int delay;
    char ico;
    char oldico;
    char direction_x;
    char direction_y;
}ball;
typedef struct wall{
    int x;
    int y;
    char flag;
}wall;
int quit=0,ch;
static void drawMap(wall *w,int n){
    int i=0;
    border(RRWALL,LRWALL,DRWALL,URWALL,'+','+','+','+');
    for(;i<n;++i){
        mvaddch(w->y,w->x,w->flag);
        ++w;
    }
}
static inline void initball(ball *b,int d,char c){
    memset(b,0,sizeof(ball));
    b->delay=d;
    b->ico=c;
    b->oldico=' ';
}
static inline void eraseball(ball *b){
    mvaddch(b->y,b->x,b->oldico);
}
static inline void drawball(ball *b){
    b->oldico=(mvinch(b->y,b->x))&A_CHARTEXT;
    switch(b->oldico){
        case WALL:quit=1;break;
        case LRWALL:b->direction_x=-1;b->direction_y=0;break;
        case RRWALL:b->direction_x=1;b->direction_y=0;break;
        case URWALL:b->direction_x=0;b->direction_y=-1;break;
        case DRWALL:b->direction_x=0;b->direction_y=1;break;
        default:break;
    }
    mvaddch(b->y,b->x,b->ico);
}
static inline void updateball(ball *b){
    eraseball(b);
    b->y+=b->direction_y;
    b->x+=b->direction_x;
}
static void collision(ball *b){
    int cur=mvinch(b->y,b->x);
    /* mvprintw(10,10,"%d",cur); */
    switch(cur&A_CHARTEXT){
        case WALL:quit=1;break;
        case LRWALL:b->direction_x=-1;b->direction_y=0;break;
        case RRWALL:b->direction_x=1;b->direction_y=0;break;
        case URWALL:b->direction_x=0;b->direction_y=-1;break;
        case DRWALL:b->direction_x=0;b->direction_y=1;break;
        default:break;
    }
}
static void changedirection(ball *b){
    ch=getch();
    switch(ch){
        case 'x':quit=1;break;
        case KEY_UP: b->direction_y=-1;b->direction_x=0;break;
        case KEY_DOWN: b->direction_y=1;b->direction_x=0;break;
        case KEY_LEFT: b->direction_x=-1;b->direction_y=0;break;
        case KEY_RIGHT: b->direction_x=1;b->direction_y=0;break;
        default:break;
    }

}
int main(){
    ball b;
    wall w[50];
    int i=0;
    for(;i<15;++i){
        w[i].y=15;
        w[i].x=10+i;
        w[i].flag=URWALL;
    }
    for(;i<30;++i){
        w[i].y=w[14].y+i-15;
        w[i].x=w[14].x;
        w[i].flag=WALL;
    }
    for(;i<50;++i){
        w[i].y=w[29].y;
        w[i].x=w[29].x+i-30;
        w[i].flag=DRWALL;
    }

    initscr();
    raw();
    keypad(stdscr,TRUE);
    noecho();
    curs_set(FALSE);

    initball(&b,DELAY,'O');
    b.direction_x=1;
    drawMap(w,50);

    timeout(DELAY);

    while(1){
        /* getmaxyx(stdscr,max_y,max_x); */
        /* clear(); */

        /* drawMap(NULL,0); */
        /* collision(&b); */
        drawball(&b);

        refresh();

        changedirection(&b);
        updateball(&b);
        /* ch=halfdelay(190); */
        if(quit)
            break;
    }

    endwin();
    exit(EXIT_SUCCESS);
}
