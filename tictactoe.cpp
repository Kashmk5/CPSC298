#include <iostream>
#include <vector>
class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    bool isPlayerTurn;
public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), isPlayerTurn(true) {}
    void displayBoard() {
        std::cout << "-------------" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << "| ";
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j] << " | ";
            }
            std::cout << std::endl << "-------------" << std::endl;
        }
    }
    bool isGameOver() {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
        }
        // Check columns
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;
        // Check for a draw
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }
    void makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move! Try again." << std::endl;
            return;
        }
        board[row][col] = isPlayerTurn ? 'X' : 'O';
        isPlayerTurn = !isPlayerTurn;
    }
    void play() {
        std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
        std::cout << "Enter row and column numbers (0-2) to make a move." << std::endl;
        while (!isGameOver()) {
            displayBoard();
            if (isPlayerTurn) {
                int row, col;
                std::cout << "Your turn (X). Enter row and column: ";
                std::cin >> row >> col;
                makeMove(row, col);
            } else {
                // Computer's turn (O)
                std::cout << "Computer's turn (O)." << std::endl;
                // Implement your computer player's strategy here
                // For simplicity, let's make a random move
                int row, col;
                do {
                    row = rand() % 3;
                    col = rand() % 3;
                } while (board[row][col] != ' ');
                makeMove(row, col);
            }
        }
        displayBoard();
        if (isPlayerTurn) {
            std::cout << "Congratulations! You won the game." << std::endl;
        } else {
            std::cout << "Sorry! Computer won the game." << std::endl;
        }
    }
};
int main() {
    TicTacToe game;
    game.play();
    return 0;
}

