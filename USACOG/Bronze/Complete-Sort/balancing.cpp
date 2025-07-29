#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("balancing.in");
	ofstream fout("balancing.out");

    int n;
    int b;
    fin >> n >> b;

    vector<pair<int, int>> coords(n);
    for (int i=0; i<n; i++) {
        fin >> coords[i].first >> coords[i].second;
    }

    int m=n;
    for (int j=0; j<n; j++) {
        for (int q=0; q<n; q++) {
            int quad_one=0;
            int quad_two=0;
            int quad_three=0;
            int quad_four=0;
            int j_x=(coords[j].first+1);
            int j_y=(coords[q].second+1);
            for (int k=0; k<n; k++) {
                int k_x=coords[k].first;
                int k_y=coords[k].second;
                if (k_x>j_x && k_y>j_y) {
                    quad_one++;
                } else if (k_x<j_x && k_y>j_y) {
                    quad_two++;
                } else if (k_x<j_x && k_y<j_y) {
                    quad_three++;
                } else if (k_x>j_x && k_y<j_y) {
                    quad_four++;
                }
            }
            m=min(m, max({quad_four, quad_one, quad_three, quad_two}));
        }
    }
    fout << m << endl;
}