#include <iostream>
#include <map>
using namespace std;

map <string, pair<int, int>> key;

int checkWin(string &str);
pair<int, int> createMap(string data, int id);

int checkWin(string &str) {
    bool flag = false;
    for(int i = 0; i < (int)str.size(); ++i) {
        if(str[i] == 'x') {
            flag = true;
            break;
        }
    }
    if(!flag)
        return -2;
    // for(int i = 0; i < 7; i+=3) {
    //     if(str[i] == str[i+1] && str[i+1] == str[i+2])
    //         return (int)(str[i] - 48);
    // }
    // for(int i = 0; i < 3; ++i) {
    //     if(str[i] == str[i+3] && str[i+3] == str[i+6])
    //         return (int)(str[i] - 48);
    // }
    // if(str[0] == str[4] && str[4] == str[8])
    //     return (int)(str[4] - 48);
    // if(str[2] == str[4] && str[4] == str[6])
    //     return (int)(str[4] - 48);

    for (int i = 0; i < 3; ++i) {
        for(int j = i+1; j  <= 3; ++j) {
            if(str[i] == str[j] && str[i] != 'x') 
                return (int)(str[i] - 48);
        }
    }

    return -1;
}

pair<int, int> createMap(string data, int id) {
    pair<int, int> score = {0, 0};
    int current_score_status = 0;
    for(int i = 0; i < (int)data.size(); ++i) {
        if(data[i] != 'x')
            continue;
        data[i] = (char)(id + 48);
        // if(key.find(data) != key.end()) {
        //     data[i] = 'x';
        //     continue;
        // }
        current_score_status = checkWin(data);
        if(current_score_status == -2) {
            if(key.find(data) == key.end())
                key.insert({data, score});
            data[i] = 'x';
            return score;
        }
        if(current_score_status == 1) {
            if(key.find(data) == key.end())
                key.insert({data, {0, 1}});
            data[i] = 'x';
            score.second++;
            // return score;
            continue;
        }
        if(current_score_status == 0) {
            if(key.find(data) == key.end())
                key.insert({data, {1, 0}});
            data[i] = 'x';
            score.first++;  
            // return score;
            continue;
        }  
        pair<int, int> temp = {0, 0};
        temp = createMap(data, (i+1)%2);
        score.first += temp.first;
        score.second += temp.second;
        data[i] = 'x';
    }
    key.insert({data, score});
    return score;
}

int main() {
    string data = "xxxx";
    createMap(data, 0);
    for(auto &it: key) {
        cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    }
}