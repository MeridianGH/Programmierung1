#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

typedef struct {
    char **field;
    size_t size;
} Board;

typedef struct {
    char *name;
    char symbol;
} Player;

typedef enum {
    running,
    win,
    loss
} state;


void draw(Board *board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) { printf("+---"); }
        printf("+\n");
        for (int j = 0; j < board->size + 1; j++) {
            printf("| %c ", j != board->size ? board->field[i][j] : i + '0');
            printf(j != board->size ? "" : "\n");
        }
    }
    for (int j = 0; j < board->size; j++) { printf("+---"); }
    printf("+\n");
    for (int i = 0; i < board->size; i++) { printf("  %c ", i + 'A'); }
    printf("\n");
}

void turn(Board *board, Player player) { // NOLINT(misc-no-recursion)
    // Get address.
    char address[3];
    printf("%s'%s (%c) turn:\n", player.name, player.name[strlen(player.name) - 1] == 's' ? "" : "s", player.symbol);
    scanf("%s", &address[0]);

    // Validate address.
    int i = address[1] - '0';
    int j = address[0] - 'A';
    if (i < 0 || i > board->size - 1 || j < 0 || j > board->size - 1 || board->field[i][j] != 0) {
        printf("Invalid address.\n");
        turn(board, player);
        return;
    }

    // Set field.
    board->field[i][j] = player.symbol;
}

state checkGameState(Board *board, Player player) {
    // Row or Column win.
    for (int i = 0; i < board->size; i++) {
        // Rows.
        char r = board->field[i][0];
        for (int j = 0; j < board->size; j++) {
            if (r == 0 || board->field[i][j] != r) { break; }
            if (j == board->size - 1) {
                if (r == player.symbol) { return win; }
            }
        }
        // Columns.
        char c = board->field[0][i];
        for (int j = 0; j < board->size; j++) {
            if (c == 0 || board->field[j][i] != c) { break; }
            if (j == board->size - 1) {
                if (c == player.symbol) { return win; }
            }
        }
    }

    // Downwards diagonal win.
    char downC = board->field[0][0];
    for (int i = 0; i < board->size; i++) {
        if (downC == 0 || board->field[i][i] != downC) { break; }
        if (i == board->size - 1 && downC == player.symbol) { return win; }
    }
    // Upwards diagonal win
    char upC = board->field[board->size - 1][0];
    for (int i = 0; i < board->size; i++) {
        if (upC == 0 || board->field[board->size - 1 - i][i] != upC) { break; }
        if (i == board->size - 1 && upC == player.symbol) { return win; }
    }

    // Still empty fields, keep running.
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->field[i][j] == 0) {
                return running;
            }
        }
    }

    // No win and no empty fields.
    return loss;
}

void ttt(Board *board, Player players[], size_t playerCount) {
    state gameState;
    while (true) {
        int i;
        // Iterate over players and allow each to make a turn.
        for (i = 0; i < playerCount; i++) {
            turn(board, players[i]);
            draw(board);
            gameState = checkGameState(board, players[i]);
            if (gameState != running) { break; }
        }

        if (gameState == loss) {
            printf("Board is full. No one wins!\n");
            break;
        }
        if (gameState == win) {
            printf("%s (%c) wins!\n", players[i].name, players[i].symbol);
            break;
        }
    }
}

int main(void) {
    // Get board size and initialize board.
    int boardSize;
    printf("Board size?\n");
    scanf(" %d", &boardSize); // NOLINT(cert-err34-c)
    char **field = (char **)calloc(boardSize, sizeof(char *));
    for (int i = 0; i < boardSize; i++) { field[i] = (char *)calloc(boardSize, sizeof(char)); }

    Board board = { field, boardSize };

    // Get player count and set players.
    int playerCount;
    printf("Player count? (Recommended %d)\n", 2 > (boardSize / 2) ? 2 : (boardSize / 2));
    scanf(" %d", &playerCount); // NOLINT(cert-err34-c)

    Player players[playerCount];
    for (int i = 0; i < playerCount; i++) {
        char *name = calloc(100, sizeof(char));
        char symbol;
        printf("Player %d name?\n", i + 1);
        scanf(" %s", &name[0]);
        printf("Player %d symbol?\n", i + 1);
        scanf(" %c", &symbol);
        Player player = { name, symbol };
        players[i] = player;
        printf("Player %d: %s (%c)\n", i + 1, player.name, player.symbol);
    }

    draw(&board);

    ttt(&board, players, playerCount);
}
