#include <map>
#include <iostream>
#include <fstream>
#include "game.h"
#include "game_data.h"
using namespace std;

class TicTacToe
{
private:
    map<pair<string, int>, pair<int, int>> key;
    int *board, number_of_matches;
    string player_first, player_second;
    bool players;

public:
    TicTacToe() {
        ifstream data_file;
        data_file.open("data.dat", ios::in);
        while(true) {
            if(data_file.is_open()) {
                string temp;
                int key_id, value1, value2;
                while(data_file >> temp) {
                    data_file >> key_id >> value1 >> value2;
                    key.insert({{temp, key_id}, {value1, value2}}) ;
                }
                data_file.close();
                break;
            }
            else {
                data_file.close();
                makeData();
                data_file.open("data.dat");
            }
        }
        if(!this->players) {
            this->player_first = "Player1";
            this->player_second = "Player2";
        } 
    }
    TicTacToe (string player_first, string player_second) {
        this->players = true;
        TicTacToe();
        this->player_first = player_first;
        this->player_second = player_second;
        this->number_of_matches = 0;
    }
    TicTacToe (string player_first, string player_second, int number_of_matches) {
        TicTacToe(player_first, player_second);
        this->number_of_matches = number_of_matches;
    }
};

int main()
{
    TicTacToe game;
    int answer;
    CLEAR;
    while(true) {
        cout << "Choose an option: " << endl;
        cout << "1.Single Match" << endl;
        cout << "2.Tournament" << endl;
        cin >> answer;
        if(answer != 1 && answer != 0) {
            cout << "Invalid Input" << endl;
            WAIT;
        }
        else 
            break;
    }
    
}