#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    // Initialize an n x n matrix with all cells marked as '-'
    vector<vector<char>> a(n, vector<char>(n, '-'));
    
    // Process each task
    while(k--) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Adjust indices for 0-based indexing

        // Mark all cells in row r
        for(int j = 0; j < n; j++) {
            a[r][j] = 'X';
        }

        // Mark all cells in column c
        for(int i = 0; i < n; i++) {
            a[i][c] = 'X';
        }

        // Count empty cells (cells marked as '-')
        int empty_cells = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == '-') {
                    empty_cells++;
                }
            }
        }

        // Output the count of empty cells after the task
        cout << empty_cells << endl;
    }

    return 0;
}
