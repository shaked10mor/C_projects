Explanation:
The user needs to guess the chosen word. 
If the user has 10 wrong turns - he loses the game.

C code:

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *words[] = {
	"apple",
	"banana",
	"home"
};

int main(){

srand(time(NULL));
int num_guess = 10;
int n = (rand()%3);
int len = strlen (words[n]);
int l = len;
int L = l;
char word[len+1];   
word[len] = '\0';
for (int r = 0; len>0; r++){
    char s = (words[n])[r];
    word [r] = s;
    len -= 1;
}
char word_guess[l+1];
word_guess[l] = '\0';
for(int i = 0; l>0; i++){
     word_guess[i] = '?';
        l = l - 1;
}
char a[26];
a [26] = '\0';
int u = 0;
int total_gues = 26;
while ((num_guess>0) && (u==0)){
    char ch;
    int le = L;
    int b = 0;
    printf("%s (%d guesses remaining)\n", word_guess, num_guess);
    while (b==0){
        b = 1;
        printf("Please enter a letter: ");		
        scanf("%c", &ch);
        char q = getchar();
        if (ch=="?"){
         printf("Your guess '%c' is not a letter.\n", ch);
         b = 0;
         continue;
        }
        if (ch>64 && ch<91)
            ch = ch + 32;
        for (int j = 0; j<26; j++){
            char k = a[j]; 
            if (ch==k){
                printf("You already guessed '%c'.\n", ch);
                b = 0;
                break;
            }
        }
        if (65>ch || ch>122 || (ch<97 && ch>90)){
            printf("Your guess '%c' is not a letter.\n", ch);
            b = 0;
            }
     }

    a [26 - total_gues] = ch;
    total_gues -= 1;
    int x = 0;

    for (int y = 0; y<L; y++){
        if (word[y]==ch){
            word_guess[y] = ch;
            x = 1;
        }
    }
    if (x==1)
        printf("Good guess!\n");
    else{
        printf("No appearances of '%c'...\n", ch);
         num_guess -= 1;
    }
    u = 1;
    for (int z = 0; le>0; z++){
        char aa = word[z];
        char bb = word_guess[z];
        le -= 1;
        if (aa != bb)
            u = 0;
    }
}

if (u==1)
    printf("You win! the word is: %s\n", word);
else
    printf("No more guesses remaining....you lost!\n");

}
