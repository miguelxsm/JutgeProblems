#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Función de comparación personalizada para el ranking
bool compareRanking(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first > b.first) return true;
    if (a.first < b.first) return false;
    return a.second < b.second;
}

int main() {
    map<string, int> playersElo;
    set<string> connectedPlayers;
    string command, player1, player2;
    vector<pair<int, string>> ranking;

    while (cin >> command) {
        if (command == "LOGIN") {
            cin >> player1;
            if (connectedPlayers.find(player1) == connectedPlayers.end()) {
                connectedPlayers.insert(player1);
                if (playersElo.find(player1) == playersElo.end()) {
                    playersElo[player1] = 1200;
                }
            }
        }
        else if (command == "LOGOUT") {
            cin >> player1;
            connectedPlayers.erase(player1);
        }
        else if (command == "PLAY") {
            cin >> player1 >> player2;
            if (connectedPlayers.find(player1) != connectedPlayers.end() &&
                connectedPlayers.find(player2) != connectedPlayers.end()) {
                playersElo[player1] = max(1200, playersElo[player1] + 10);
                playersElo[player2] = max(1200, playersElo[player2] - 10);
            }
            else {
                cout << "player(s) not connected" << endl;
            }
        }
        else if (command == "GET_ELO") {
            cin >> player1;
            cout << player1 << " " << playersElo[player1] << endl;
        }
    }

    // Crear ranking
    cout << endl << "RANKING" << endl;
    for (const auto& p : playersElo) {
        ranking.push_back({p.second, p.first});
    }
    sort(ranking.begin(), ranking.end(), compareRanking);

    for (const auto& p : ranking) {
        cout << p.second << " " << p.first << endl;
    }

    return 0;
}
