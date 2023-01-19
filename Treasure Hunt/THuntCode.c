#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//macro for maximum path length
#define Maximum_path_length 70

//declare a datatype playerinfo
struct PlayerInfo {
    int num_of_lives;   //number of lives of player
    char character_symbol;      //represents the player
    int num_of_treasures;        //counter for num of treasures
    char Past_positions;         //history of all past entered positions
};

//data type for game configuration
struct GameInfo {
    int max_moves;             //Max number of moves
    int path_length;   //game oath
    int Bombs_buried[Maximum_path_length];  //array to store bombs position
    int Treasure_buried[Maximum_path_length]; //array to store trasure position
};

int main(void) {
    int i, j;
    //print the header
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    //declare an structure for player info
    struct PlayerInfo player_config;

    //print header for player configuration
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    //prompt the user for a single character to represent a player
    printf("Enter a single character to represent the player: ");
    scanf("\n%c", &player_config.character_symbol);


    //run a loop until valid number of lives is inputed by user
    do {
        //prompt the user for number of lives
        printf("Set the number of lives: ");
        scanf("%d", &player_config.num_of_lives);
        //if number of lives not in range [1-10]
        if (player_config.num_of_lives < 1 || player_config.num_of_lives > 10) {
            //print invalid message
            printf("     Must be between 1 and 10!\n");
        }
    } while (player_config.num_of_lives < 1 || player_config.num_of_lives > 10);

    //print completed the player configuration
    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    //declare a structure for game configuration
    struct GameInfo game_config;

    //run a loop until user eneters valid path length
    do {
        //prompt the user for a path length
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game_config.path_length);
        //if path length is not in range [10-70] print the error message
        if (game_config.path_length < 10 || game_config.path_length > 70) {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        //if path length is not a multiple of 5 print error message
        else if (game_config.path_length % 5 != 0) {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }

    }
    //here condition must be connected by or because we have to iterate if either it is not divisible by 5
    //or the length is out of range for [10 - 70]
    while (game_config.path_length % 5 != 0 || (game_config.path_length < 10 || game_config.path_length > 70));

    //run a loop until user enters valid number of moves
    do {
        //prompt the user for moves
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game_config.max_moves);
        //check if the values is not in range [3-15]
        if (game_config.max_moves < 3 || game_config.max_moves > 15) {
            printf("    Value must be between 3 and 15\n");
        }
    } while (game_config.max_moves < 3 || game_config.max_moves > 15);


    //prompt the user for bomb placements
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    //here path length is not fixed to 35 it is game_config.path_length
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game_config.path_length);


    //prompt the user for bomb placements
    //here we take 5 inputs in each line
    //so total number of lines will be path_length / 5 
    //start is used to prompt the user for index
    // in each loop we have to print position [ start - start+4]
    int start = 1;

    //index to store the data in Bombs_buried array in consecutive location
    int index = 0;
    //iterate total path_length / 5 times
    for (i = 1; i <= game_config.path_length / 5; i++) {
        //intitally start by 1 - 5 so we have declared start to 1
        //then in each iteration we will increase start by 5
        //%2d right align the output by 2 space
        printf("   Positions [%2d-%2d]: ", start, (start + 4));
        //take 5 inputs from the user and store in Bombs_buried
        for (j = 1; j <= 5; j++) {
            scanf("%d", &game_config.Bombs_buried[index]);
            //increase index to store the next value in next location
            index++;
        }
        //set start to 5 so it will increase from 1 -> 6 -> 11 and so on
        start = start + 5;
    }
    printf("BOMB placement set\n\n");


    //prompt the user for treasure placements
    //the logic will be same as bomb placement only we need to change the prompt
    //and store the input in treasure array
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    //here path length is not fixed to 35 it is game_config.path_length
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game_config.path_length);

    //here we take 5 inputs in each line
    //so total number of lines will be path_length / 5 
    start = 1;
    index = 0;
    for (i = 1; i <= game_config.path_length / 5; i++) {
        //%2d right align the output by 2 space
        printf("   Positions [%2d-%2d]: ", start, (start + 4));
        for (j = 1; j <= 5; j++) {
            scanf("%d", &game_config.Treasure_buried[index]);
            index++;
        }
        start = start + 5;
    }
    printf("TREASURE placement set\n\n");


    //print the game configuration
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    //print the details of the player
    printf("Player:\n");
    printf("   Symbol     : %c\n", player_config.character_symbol);
    printf("   Lives      : %d\n", player_config.num_of_lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    //print the details of the games
    printf("Game:\n");
    //%-20 to right align the data
    printf("   Path Length: %d\n", game_config.path_length);
    printf("   Bombs      : ");
    //iterate through the Bombs_buried array and print the each digits
    for (i = 0; i < game_config.path_length; i++) {
        printf("%d", game_config.Bombs_buried[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    //iterate through the treasure array and print the each digits
    for (i = 0; i < game_config.path_length; i++) {
        printf("%d", game_config.Treasure_buried[i]);
    }

    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");


    //declare a char arry for visited
    char visited[70];
    //intially all the points are unvisited so store '-'
    for (i = 0; i < game_config.path_length; i++)
        visited[i] = '-';

    //declare array to store number for paths
    int number[70];
    //declare array to store marks
    char number_marker[70];
    int counter = 1;
    int count_10 = 0;

    //iterate for i-> 0 to path length
    for (i = 0; i < game_config.path_length; i++) {
        //if counter has reached 10
        if (counter % 10 == 0) {
            //reset it to 0 as after 9 it starts with 0
            counter = 0;
            //insert the counter in the number array
            number[i] = counter;
            //add 1 to count_10 and convert it to char by adding '0'
            number_marker[i] = (count_10 + 1) + '0';
            //increase count_10 by 1
            count_10++;
        }
        //else 
        else {
            //add '|' in each position
            number_marker[i] = '|';
            //insert counter in number array
            number[i] = counter;
        }
        counter++;
    }
    int pos = -1;
    int moves = game_config.max_moves;
    int lives = player_config.num_of_lives;
    int treasure = 0;

    //loop until moves is greater than 0 and lives is greater than 0
    while (moves > 0 && lives > 0) {
        //print the position marked
        printf("  ");
        for (i = 0; i < game_config.path_length; i++) {
            //if i is equal to position then print V
            if (pos == i) {
                printf("V");
            }
            //else print " "
            else {
                printf(" ");
            }
        }
        //print the visited char array
        printf("\n  ");
        for (i = 0; i < game_config.path_length; i++)
            printf("%c", visited[i]);
        //print the number_marker array
        printf("\n  ");
        for (i = 0; i < game_config.path_length; i++)
            printf("%c", number_marker[i]);
        //print the number array
        printf("\n  ");
        for (i = 0; i < game_config.path_length; i++)
            printf("%d", number[i]);
        printf("\n+-------------------------------------------------------------+\n");
        printf("  Lives:   %d   | Treasures:   %d   |  Moves Remaining:  %d\n", lives, treasure, moves);
        printf("+-------------------------------------------------------------+\n");

        //prompt the user for move
        do {
            printf("Next Move [1-%d]: ", game_config.path_length);
            scanf("%d", &pos);
            if (pos < 1 || pos>20) {
                printf("  Out of Range!!!\n");
            }
        } while (pos <= 0 || pos > 20);

        printf("\n");

        //decrease position by 1 as each array is 0th index and user is starting
        //move count from 1
        pos = pos - 1;
        //check if that position is already visited
        //if the position is visited it will not remain '-'
        if (visited[pos] != '-') {
            printf("\n================> Dope! You've been here before!\n");
        }
        //if the position contains bomb and treasure
        else if (game_config.Bombs_buried[pos] == 1 && game_config.Treasure_buried[pos] == 1) {
            printf("\n================> [&] !!!  BOOOOM  !!! [&]");
            printf("\n================> [&] $$$  LIfe Insurance Payout!!! [&]\n");
            lives = lives - 1;
            treasure = treasure + 1;
            moves = moves - 1;
            //visited will be updated with '&'
            visited[pos] = '&';
        }
        //if the position contains bomb
        else if (game_config.Bombs_buried[pos] == 1) {
            printf("\n================> [!] !!!  BOOOOM  !!! [!]\n");
            lives = lives - 1;
            moves = moves - 1;
            //visited will be update with '!'
            visited[pos] = '!';
        }
        //if the position contain treasure
        else if (game_config.Treasure_buried[pos] == 1) {
            printf("\n================> [$] $$$  Found Treasure! [$]\n");
            treasure = treasure + 1;
            moves = moves - 1;
            visited[pos] = '$';
        }
        else {
            printf("\n================> [.] ...Nothing found here... [.]\n");
            moves = moves - 1;
            visited[pos] = '.';
        }
    }
    //if lives has become 0
    if (lives == 0) {
        //print no lives remaining 
        printf("No more LIVES remaining!\n\n");
        //pirint all the other details
        printf("  ");
        for (i = 0; i < game_config.path_length; i++) {
            if (pos == i) {
                printf("V");
            }
            else {
                printf(" ");
            }
        }
        printf("\n  ");
        for (i = 0; i < game_config.path_length; i++)
            printf("%c", visited[i]);
        printf("\n  ");
        for (i = 0; i < game_config.path_length; i++)
            printf("%c", number_marker[i]);
        printf("\n  ");
        for (i = 0; i < game_config.path_length; i++)
            printf("%d", number[i]);
        printf("\n+-------------------------------------------------------------+\n");
        printf("  Lives:   %d   | Treasures:   %d   |  Moves Remaining:  %d\n", lives, treasure, moves);
        printf("+-------------------------------------------------------------+\n");

    }
    //else no moves remaining
    else {
        printf("No more MOVES remaining!\n\n");
        printf("  ");
        for (i = 0; i < game_config.path_length; i++) {
            if (pos == i) {
                printf("V");
            }
            else {
                printf(" ");
            }
        }
        printf("\n  ");
        for (i = 0; i < game_config.path_length; i++)
            printf("%c", visited[i]);
        printf("\n  ");
        for (i = 0; i < game_config.path_length; i++)
            printf("%c", number_marker[i]);
        printf("\n  ");
        for (i = 0; i < game_config.path_length; i++)
            printf("%d", number[i]);
        printf("\n+-------------------------------------------------------------+\n");
        printf("  Lives:   %d   | Treasures:   %d   |  Moves Remaining:  %d\n", lives, treasure, moves);
        printf("+-------------------------------------------------------------+\n");
    }
    printf("\n");
    printf("############################\n");
    printf("#     Game Over!           #\n");
    printf("############################\n");

    printf("\nYou should play again and try to beat your score!");
    return 0;
}