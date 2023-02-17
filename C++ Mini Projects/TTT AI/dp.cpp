#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<pair<string, int>, vector<pair<int, pair<int, int>>>> key;

int isWinning(string str) {
    if(str[0] == str[3] && str[0] != 'x')
        return (str[0] - 48);
    if(str[1] == str[2] && str[1] != 'x')
        return (str[1] - 48);
    return -1;
}

pair<int, int> createMap(string data, int id) {
    pair<int, int> score = {0, 0};
    pair<int, int> temp_score;
    int win_status = isWinning(data);
    if(win_status == 0)
        return {1, 0};
    else if(win_status == 1) 
        return {0, 1};

    for(int i = 0; i < (int)data.size(); ++i) {
        temp_score = {0, 0};
        if(data[i] != 'x') 
            continue;
        data[i] = (char)id + 48;
        temp_score = createMap(data, (id+1)%2);
        data[i] = 'x';
        key[{data, id}].push_back({i, temp_score});
        score.first += temp_score.first;
        score.second += temp_score.second;
    }
    return score;
}

void printMap() {
    for(auto &it: key) {
        cout << "{ " << it.first.first << ", " << it.first.second << " }" << endl;
        cout << "[ ";
        for(auto &itv: it.second) {
            cout << "{ " << itv.first << " " << itv.second.first << " " << itv.second.second << " }, ";
        } 
        cout << " ]\n" << endl; 
    }
}

int main() {
    string data = "xxxx";
    createMap(data, 0);

    printMap();
}