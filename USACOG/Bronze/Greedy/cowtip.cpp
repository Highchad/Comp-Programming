#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

void flip(vector<vector<int>> &grid, int width, int height) {
    for (int a=0; a<=height; a++) {
        for (int b=0; b<=width; b++) {
            if (grid[a][b]==0) {
                grid[a][b]=1;
            } else {
                grid[a][b]=0;
            }
        }
    }
}

int main() {
    setIO("cowtip");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int MAXN=3e5+13;
    
    int n;
    int totalflips=0;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            grid[i][j] = row[j] - '0';
        }
    }


    for (int i=n-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            if (grid[i][j]==1) {
                totalflips++;
                flip(grid, j, i);
            }
        }
    }
    cout << totalflips << endl;
}