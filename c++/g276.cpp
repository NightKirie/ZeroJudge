#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_M 100
#define MAX_K 500
using namespace std;

int n, m, k;
int board[MAX_N][MAX_M] = {0};
int king_pos[MAX_K][2];
int bombing_pos[MAX_K][2];
int bombing_count = 0;
int king_dead[MAX_K] = {0};
int move_pos[MAX_K][2];

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; ++i) {
        cin >> king_pos[i][0] >> king_pos[i][1];       
        cin >> move_pos[i][0] >> move_pos[i][1];
    }

    while(1) {
        /* move_pos king first, if king go outside, remove_pos king */
        for(int i = 0; i < k; ++i) {
            if(!king_dead[i]) {
                board[king_pos[i][0]][king_pos[i][1]] = 1;
                king_pos[i][0] += move_pos[i][0];
                king_pos[i][1] += move_pos[i][1];
                if(king_pos[i][0] >= n || king_pos[i][0] < 0 || king_pos[i][1] >= m || king_pos[i][1] < 0)
                    king_dead[i] = 1;
            }
        }

        /* Detect if king is dead */
        bombing_count = 0;
        for(int i = 0; i < k; ++i) {
            if(!king_dead[i]) {
                if(board[king_pos[i][0]][king_pos[i][1]]) {
                    bombing_pos[bombing_count][0] = king_pos[i][0];
                    bombing_pos[bombing_count][1] = king_pos[i][1];
                    bombing_count += 1;
                    king_dead[i] = 1;
                }
            }
        }
        while(bombing_count--) {
            board[bombing_pos[bombing_count][0]][bombing_pos[bombing_count][1]] = 0;
        }


        bool all_dead = true;
        for(int i = 0; i < k; ++i)
            if(!king_dead[i]) {
                all_dead = false;
                break;
            }
        if(all_dead) {
            int bomb_num = 0;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    bomb_num += board[i][j];
            cout << bomb_num << "\n";
            break;
        }

    }
}