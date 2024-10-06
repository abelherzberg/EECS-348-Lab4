#include <stdio.h>

int score;

void possible_scoring_combos(score){
    for(int td_and_2pt = 0; td_and_2pt * 8 <= score; td_and_2pt++){
        for(int td_and_pat = 0; td_and_pat*7 + td_and_2pt*8 <= score; td_and_pat++){
            for(int td = 0; td*6 + td_and_pat*7 + td_and_2pt*8 <= score; td++){
                for(int fg = 0; fg*3 + td*6 + td_and_pat*7 + td_and_pat*8 <= score; fg++){
                    for(int safety = 0; safety*2 + fg*3 + td*6 + td_and_pat*7 + td_and_2pt*8 <=score; safety++){
                        if(safety*2 + fg*3 + td*6 + td_and_pat*7 + td_and_2pt*8 == score){
                            printf("%d TD + 2pt conversion, %d TD + PAT, %d TD, %d 3pt FG, %d Safety \n", td_and_2pt, td_and_pat, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    while(1){
        printf("Enter a score: ");
        scanf("%d", &score);

        if(score < 2){
            printf("Score invalid because it is less than 2");
            break;
        }
        else{
            printf("Possible scoring combinations if a team's score is %d: \n", score);
            possible_scoring_combos(score);
        }
    }
}