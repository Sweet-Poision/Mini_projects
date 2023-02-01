#include <iostream>
using namespace std;

#ifdef _WIN32
#define CLEAR system("cls")

#elif __APPLE__
#define CLEAR system("clear")

#elif __linux__
#define CLEAR system("clear")
#endif

class Game {
    private:
    int *arrayOfBoard;
    string player1, player2;
    public:
    Game(string player1, string player2) {
        arrayOfBoard = new int[9];
        for(int i = 0; i < 9; ++i) 
            arrayOfBoard[i] = -1;
        this->player1 = player1;
        this->player2 = player2;
    }

    char getSignChar(int k) {
        if(arrayOfBoard[k-1] == 0) return 'o';
        else if(arrayOfBoard[-1] == 1) return 'x';
        return k + 48;
    }

    string status() {
        // check diagonals
        //for(int i = 0; i < ) 
        for(int i = 0; i < 3; i+=3)
            if(arrayOfBoard[i] == arrayOfBoard[i+1] && arrayOfBoard[i+1] == arrayOfBoard[i+2])
                return (arrayOfBoard[i] == 'o')?"PLAYER1":"PLAYER2";
        for(int i = 0; i < 3; ++i)
                if(arrayOfBoard[i] == arrayOfBoard[i+3] && arrayOfBoard[i+3] == arrayOfBoard[i+6])
                    return (arrayOfBoard[i] == '0')?"PLAYER1":"PLAYER2";
            

    }

    void drawBoard() {
        char sign = ' ';
        string space = "  ";
        for(int i = 0, k = 1; i < 3; ++i, ++k) {
            for(int j = 0; j < 2; ++j, ++k) {
                sign = getSignChar(k);
                cout << space + sign + space + "|";
            }
            sign = getSignChar(k);
            cout << space + sign + space << endl;
            if(i < 2) {
                for(int j = 0; j < 17; ++j) {
                    cout << "-";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Game newGame("A","B");
    while(newGame.status() == "CONTINUE") {
        newGame.drawBoard();
    }
    
}