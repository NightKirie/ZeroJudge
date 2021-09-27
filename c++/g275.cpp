#include <iostream>
#define MAX_N 30
using namespace std;

int main(int argc, char** argv) {
    int n;
    cin >> n;
    int array[MAX_N*2][7];
    
    for(int i = 0; i < n*2; ++i)
        for(int j = 0; j < 7; ++j)
            cin >> array[i][j];
    
    for(int i = 0; i < n*2; i+=2) {
        bool output = false;
        
        /* Judge A */
        if(array[i][1] == array[i][3] || array[i][1] != array[i][5] || array[i+1][1] == array[i+1][3] || array[i+1][1] != array[i+1][5]) {
            output = true;
            cout << "A";
        }

        /* Judge B */
        if(array[i][6] != 1 || array[i+1][6] != 0) {
            output = true;
            cout << "B";
        }
        
        /* Judge C */
        if(array[i][1] == array[i+1][1] || array[i][3] == array[i+1][3] || array[i][5] == array[i+1][5]) {
            output = true;
            cout << "C";
        }
        
        if(!output)
            cout << "None";
        cout << "\n";
    }
}