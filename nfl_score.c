#include <stdio.h>

int score; //int variable named score that will store the score value entered by the user. Int is used for this variable instead of float because the score can't be a decimal in the NFL

void possible_scoring_combos(int score){ //function that finds all the possible scoring combinations and takes in score as a parameter
    for(int td_and_2pt = 0; td_and_2pt * 8 <= score; td_and_2pt++){ //for loop that defines the td_and_2pt integer as a starting value of 0. As the test case, multiplies the td_and_2pt value by 8 so long as it doesn't exceed the score variable, and increases the value of td_and_2pt by 1, every time the test is successful
        for(int td_and_pat = 0; td_and_pat*7 + td_and_2pt*8 <= score; td_and_pat++){ //for loop that defines the td_and_pat integer as a starting value of 0. As the test case, multiplies the td_and_pat value by 7 and td_and_2pt value by 8 so long as it doesn't exceed the score variable, and increases the value of td_and_pat by 1, every time the test is successful
            for(int td = 0; td*6 + td_and_pat*7 + td_and_2pt*8 <= score; td++){ //for loop that defines the td integer as a starting value of 0. As the test case, multiplies the td value by 6, td_and_pat value by 7, and td_and_2pt value by 8 so long as it doesn't exceed the score variable, and increases the value of td by 1, every time the test is successful
                for(int fg = 0; fg*3 + td*6 + td_and_pat*7 + td_and_pat*8 <= score; fg++){ //for loop that defines the fg integer as a starting value of 0. As the test case, multiplies the fg value by 3, td value by 6, td_and_pat value by 7 and td_and_2pt value by 8 so long as it doesn't exceed the score variable, and increases the value of fg by 1, every time the test is successful
                    for(int safety = 0; safety*2 + fg*3 + td*6 + td_and_pat*7 + td_and_2pt*8 <=score; safety++){ //for loop that defines the safety integer as a starting value of 0. As the test case, multiplies the safety value by 2, fg value by 3, td value by 6, td_and_pat value by 7 and td_and_2pt value by 8 so long as it doesn't exceed the score variable, and increases the value of safety by 1, every time the test is successful
                        if(safety*2 + fg*3 + td*6 + td_and_pat*7 + td_and_2pt*8 == score){ //if statement that checks to see if the scores calculated are exactly equal to the score provided. This gets rid of combos that are less than the score, because they aren't what the user is looking for
                            printf("%d TD + 2pt conversion, %d TD + PAT, %d TD, %d 3pt FG, %d Safety \n", td_and_2pt, td_and_pat, td, fg, safety); //prints the score combos in the format of the instructions once they pass the if statement and creates a new line for the next combo.
                        }
                    }
                }
            }
        }
    }
}

int main(){ //main function
    while(1){ //while loop that continues infinitely, since 1 equals to true, and while(1) means it will run while stil true. The only way to stop it is with a break, which we will use if the user inputs an invalid score
        printf("Enter a score: "); //print statement that asks the user to enter a score
        scanf("%d", &score); //stores the value ented by the user as the score variable defined at the beginning of the code

        if(score < 2){ //if statement that checks to see if the score variable has a value less than 2, which is not a possible score based on the scoring format of the NFL
            printf("Score invalid because it is less than 2"); //print statement that tells the user they inputted an invalid score
            break; //break call, which ends the while loop, and therefore the entire program
        }
        else{ //else statement that runs so long as the score value is greater than or equal to 2
            printf("Possible scoring combinations if a team's score is %d: \n", score); //print statement that tells the user it is going to return all the possible combinations
            possible_scoring_combos(score); //call to the possible_scoring_combos function above, which will handle the finding and printing of the scoring combos. It takes the score variable as a parameter
        }
    }
}
