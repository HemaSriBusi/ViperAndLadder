#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void playerinfo();
void gamelayout();
int dice();
void game();
int control(int *,int *,int, int);
void snake();
void display();
void snakedecrement(int *, int *);
void ladderincrement(int *, int *); 
void ladder();
char p1[30];
int i1 = 9;
int j1 = 0;
int i2 = 9;
int j2 = 0;
int ladder_ini[2];
int ladder_fin[2];
int snake_ini[2];
int snake_fin[2];

int main() {
    printf("start\n");
    playerinfo();
    game();
    return 0;
}

void playerinfo() {
    printf("enter player1 name");
    gets(p1);
    printf("player symbol is 0\n");
}

void gamelayout() {
    int layout[10][10] = {
                            {100,99,98,97,96,95,94,93,92,91},
                            {81,82,83,84,85,86,87,88,89,90},
                            {80,79,78,77,76,75,74,73,72,71},
                            {61,62,63,64,65,66,67,68,69,70},
                            {60,59,58,57,56,55,54,53,52,51},
                            {41,42,43,44,45,46,47,48,49,50},
                            {40,39,38,37,36,35,34,33,32,31},
                            {21,22,23,24,25,26,27,28,29,30},
                            {20,19,18,17,16,15,14,13,12,11},
                            {1,2,3,4,5,6,7,8,9,10}
                        };       
}

void display(int *layout[10], int a, int b, int symbol) {
       
    
}

int dice() {
    int rno;
    srand(time(NULL));
    rno = rand() % 6 + 1;
    printf("Hi %d\n", rno);

    return rno;
}


void game() {
    char move;   
    int symbol = 0;
    int score1 = 0;
    int score2 = 0;
    int die;
    int count;
    int *p1_row_pos;
    int *p1_col_pos;
    int *p2_row_pos;
    int *p2_col_pos;
    p1_row_pos = &i1;
    p1_col_pos = &j1;
    p2_row_pos = &i2;
    p2_col_pos = &j2;

    while (score1 < 100 && score2 < 100) {
        if (symbol == 0) {
            count = 0;  
            printf("players turn,press enter key to throw the dice");
            scanf("%c",&move);
            do { 
                count++;
                die = dice();
                printf("Player Value: %d\n",die);
                score1 += control(p1_row_pos, p1_col_pos, 0, die);

                snakedecrement(p1_row_pos, p1_col_pos);
                ladderincrement(p1_row_pos, p1_col_pos);
                display(*p1_row_pos,*p1_col_pos, symbol);

            } while (die == 6 && count < 3);
            symbol = 999;
        }

        else {
            count = 0;
            printf("computers turn \n");
            char ch;
            scanf("%c", &ch); 
            do {
                count++;  
                die = dice();
                printf("Computer Value: %d\n",die);
                score2 += control(p2_row_pos, p2_col_pos, 0, die);

                snakedecrement(p2_row_pos, p2_col_pos);
                ladderincrement(p2_row_pos, p2_col_pos);
                display(*p2_row_pos, *p2_col_pos, symbol);

            } while (die == 6 && count < 3);
            symbol = 0;
        }


    }
    
    if (symbol == 0)
        printf("computer is the winner");
    else
        printf("%s is the winner",p1);
}


int control( int *i, int *j, int k,int die) {
    int score = 1;
        if(*i == 9 && *j == 0)
          k = 1;  
        while (k < die) { 
                if ((*i) % 2 != 0) {
      
                    while ((*j) <= 9) {
                        if (k < die)
                            k++;
                        else
                            break;
                        (*j)++;
                        score++;
                    }
                    if ((*j) > 9) {
                        (*j)--;
                        (*i)--;
                    }
                }

                else {

                    while ((*j) >= 0) {
                        if (k < die)
                            k++;
                        else
                            break;
                        (*j)--;
                        score++;
                    }

                     if((*j) < 0) {
                         (*j)++;
                        (*i)--;
                     }
                }

        }

    return score;
}
   
    
void snake() {
    int temp;
    srand(time(NULL));
    while (1) {
        int r = rand() % 10;
        if ( r % 2 == 0) { 
            snake_ini[0] = r;
            break;
        }
    }

    while(1) {    
        int r = rand() % 10;
        if ( r % 2 == 0) {
            snake_ini[1] = r;
            break;
        }
    }

    while(1) {
        int r = rand() % 10;
        if ( r % 2 == 0) {
            snake_fin[1] = r;
            break;
        }
    }

    while(1) {
        int r = rand() % 10;

        if (snake_ini[0] == r && r % 2 != 0)
            continue;
        else {
            snake_fin[0] = r;
            break;
        }
    }

    if (snake_fin[0] > snake_ini[0]) {
        temp = snake_fin[0];
        snake_fin[0] = snake_ini[0];
        snake_ini[0] = temp;
    }
}

void ladder() {
    int temp;
    srand(time(NULL));

    while(1) {   
        int r = rand() % 10;
        if ( r % 2 != 0) {
            ladder_ini[0] = r;
            break;
        }
    }

    while(1) {
        int r = rand() % 10;
        if ( r % 2 != 0 ) {
            ladder_ini[1] = r;
            break;
        }
    }

    while(1) {
        int r = rand() % 10;
        if ( r % 2 != 0) {
            ladder_fin[1] = r;
            break;
        }
    }

    while(1) {
        int r = rand() % 10;
        if ( ladder_ini[0] == r && r % 2 == 0 ) 
            continue;
        else {
            ladder_fin[0] = r;
            break;
        }
    }

    if ( ladder_fin[0] < ladder_ini[0]) {
        temp = ladder_ini[0];
        ladder_ini[0] = ladder_fin[0];
        ladder_fin[0] = temp;
    }

}

void snakedecrement(int *p_row, int *p_col) {
    if(snake_ini[0] == *p_row && snake_ini[1] == *p_col) {
        printf("you got bit by a snake\n");
        *p_row = snake_fin[0];
        *p_col = snake_fin[1];
    }
}


void ladderincrement(int *p_row, int *p_col) {
    if(ladder_ini[0] == *p_row && ladder_ini[1] == *p_col) {
        printf("you got a ladder\n");
        *p_row = ladder_fin[0];
        *p_col = ladder_fin[1];
    }
}


























































