#include <bits/stdc++.h>
#define MAX_N 30
using namespace std;

int n;
int couplet[MAX_N*2][7];


int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n*2; ++i)
        for(int j = 0; j < 7; ++j)
            cin >> couplet[i][j];
    
    for(int i = 0; i < n*2; i+=2) {
        bool output = false;
        
        /* Judge A */
        if(couplet[i][1] == couplet[i][3] || couplet[i][1] != couplet[i][5] || couplet[i+1][1] == couplet[i+1][3] || couplet[i+1][1] != couplet[i+1][5]) {
            output = true;
            cout << "A";
        }

        /* Judge B */
        if(couplet[i][6] != 1 || couplet[i+1][6] != 0) {
            output = true;
            cout << "B";
        }
        
        /* Judge C */
        if(couplet[i][1] == couplet[i+1][1] || couplet[i][3] == couplet[i+1][3] || couplet[i][5] == couplet[i+1][5]) {
            output = true;
            cout << "C";
        }
        
        if(!output)
            cout << "None";
        cout << "\n";
    }
}