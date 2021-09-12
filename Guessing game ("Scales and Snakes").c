Note:
The current game map will be displayed in the Visual Studio Code terminal, after each round. 

C code:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define PLAYER1 'X'
#define PLAYER2 'O'
#define BLANK   '.'

void print_board(int p1, int p2);
int get_guess(char curr_player);
int get_steps(int guess);
int check_win(int pos);

int main()
{
  int p1 = 0;
  int p2 = 0;
  srand(time(0)); // seed random generator
  printf("Welcome to the game!\n");
while ((p1<SIZE*SIZE) && (p2<SIZE*SIZE)){
 p2 += get_steps(get_guess(PLAYER2));
 if (p2==p1) {
    p1 = 0;
    printf("%c gets kicked back to the beginning!\n", PLAYER1);
 }
 if (check_win(p2)==1)
    break;
  print_board(p1, p2);
 p1 += get_steps(get_guess(PLAYER1));
 if (p2==p1) {
    p2 = 0;
    printf("%c gets kicked back to the beginning!\n", PLAYER2);
 }
 if (check_win(p1)==1)
    break;
  print_board(p1, p2);
}
if (p1>p2)
    printf("%c wins!\n",PLAYER1);
else
    printf("%c wins!\n",PLAYER2);    
return 0;
}

void print_board(int p1, int p2)
{
int n = 0;
  while (n<(SIZE*SIZE)) {
    if (n==p1)
        printf("%c", PLAYER1);
    else if (n==p2)
        printf("%c", PLAYER2);
    else
        printf("%c", BLANK);
    if ((n%SIZE)==(SIZE-1))
      printf("\n");
    n += 1;
  }  
}

int get_guess(char curr_player)
{
    int guess = 0;
    printf("It is %c's turn now.\n", curr_player);
    printf("Enter guess (1 to %d): ", SIZE);
    while ((guess<1) || (guess>SIZE)) {
     scanf("%d", &guess); 
    }
    return guess;
}

int get_steps(int guess)
{
  int x = (rand()%SIZE) + 1; 
  int steps = SIZE - abs (guess - x);
    printf("Die shows %d, moving %d steps forward...\n",x, steps);
    return steps;
}

int check_win(int pos)
{
if (pos>(SIZE*SIZE -1)) 
  return 1;
else 
  return 0;
}
