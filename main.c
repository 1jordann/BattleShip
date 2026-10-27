#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define SIZE 10
#define SHIP_COUNT 5

/* Five standard Battleship ships: Carrier, Battleship, Cruiser, Submarine, Destroyer. */
const int ship_lengths[SHIP_COUNT] = {5, 4, 3, 3, 2};

void initialize_board(char board[SIZE][SIZE], char fill) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            board[row][col] = fill;
        }
    }
}

void print_board(char board[SIZE][SIZE]) {
    printf("\n    A B C D E F G H I J\n");
    for (int row = 0; row < SIZE; row++) {
        printf("%2d  ", row + 1);
        for (int col = 0; col < SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Put ships on the hidden board, without overlaps or off-board positions. */
void place_ships(char ships[SIZE][SIZE]) {
    for (int ship = 0; ship < SHIP_COUNT; ship++) {
        int length = ship_lengths[ship];
        int placed = 0;
        while (!placed) {
            int vertical = rand() % 2;
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            int valid = 1;

            for (int part = 0; part < length; part++) {
                int r = row + (vertical ? part : 0);
                int c = col + (vertical ? 0 : part);
                if (r >= SIZE || c >= SIZE || ships[r][c] == 'S') {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                for (int part = 0; part < length; part++) {
                    int r = row + (vertical ? part : 0);
                    int c = col + (vertical ? 0 : part);
                    ships[r][c] = 'S';
                }
                placed = 1;
            }
        }
    }
}

int main(void) {
    char ships[SIZE][SIZE];      /* Hidden enemy ship positions */
    char guesses[SIZE][SIZE];    /* Only hits and misses shown to player */
    char input[100];
    int hits = 0;
    int attempts = 0;
    int total_ship_cells = 0;

    srand((unsigned int)time(NULL));
    initialize_board(ships, '.');
    initialize_board(guesses, '.');
    place_ships(ships);

    for (int i = 0; i < SHIP_COUNT; i++) {
        total_ship_cells += ship_lengths[i];
    }

    printf("Welcome to Battleship! Find all 5 hidden ships.\n");
    printf("Enter coordinates like A1, J10, or 1A. Type Q to quit.\n");

    while (hits < total_ship_cells) {
        print_board(guesses);
        printf("Hits: %d/%d | Shots: %d\n", hits, total_ship_cells, attempts);
        printf("Enter coordinate: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nInput ended. Goodbye!\n");
            return 0;
        }
        if (toupper((unsigned char)input[0]) == 'Q' &&
            (input[1] == '\n' || input[1] == '\0')) {
            printf("Thanks for playing!\n");
            return 0;
        }

        /* Allow both A1 and 1A; reject extra characters and invalid positions. */
        char letter = 0;
        int number = 0;
        char extra = 0;
        int parsed = sscanf(input, " %c%d %c", &letter, &number, &extra);
        if (parsed != 2 || !isalpha((unsigned char)letter)) {
            parsed = sscanf(input, " %d%c %c", &number, &letter, &extra);
        }
        letter = (char)toupper((unsigned char)letter);
        if (parsed != 2 || letter < 'A' || letter > 'J' || number < 1 || number > 10) {
            printf("Invalid coordinate. Use A1 through J10.\n");
            continue;
        }

        int row = number - 1;
        int col = letter - 'A';
        if (guesses[row][col] != '.') {
            printf("You already guessed that coordinate. Try another.\n");
            continue;
        }

        attempts++;
        if (ships[row][col] == 'S') {
            guesses[row][col] = 'X';
            hits++;
            printf("Hit!\n");
        } else {
            guesses[row][col] = 'O';
            printf("Miss!\n");
        }
    }

    print_board(guesses);
    printf("You won! All %d ship spaces found in %d shots!\n", hits, attempts);
    return 0;
}
