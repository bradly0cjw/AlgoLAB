//
// Created by LINBEI on 3/30/2024.
//
#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> colored(32770, vector<int>(32770));
string str;
int counter;

void draw(int &p, int r, int c, int w) {
    char ch = str[p++];
    if (ch == 'p') {
        draw(p, r, c, w / 2);
        draw(p, r, c + (w / 2), w / 2);
        draw(p, r + (w / 2), c, w / 2);
        draw(p, r + (w / 2), c + (w / 2), w / 2);
    } else if (ch == 'f') {
        for (int i = r; i < r + w; i++)
            for (int j = c; j < c + w; j++) {
                if (!colored[i][j]) {
                    colored[i][j] = true;
                    counter++;
                }
            }
    }
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        counter = 0;
        for (int j = 0; j < 2; j++) {
            cin >> str;
            int p = 0;
            draw(p, 0, 0, 32768);
        }
        cout << "There are " << counter << " black pixels." << endl;
    }
    return 0;
}