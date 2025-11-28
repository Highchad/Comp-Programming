#include <bits/stdc++.h>
using namespace std;

void print(char letter, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << letter;
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int,int> v[3];
    char letters[3] = {'A','B','C'};

    long long area = 0;

    for (int i = 0; i < 3; i++) {
        cin >> v[i].first >> v[i].second;
        // rotate each rectangle so width >= height
        if (v[i].first < v[i].second)
            swap(v[i].first, v[i].second);
        area += 1LL * v[i].first * v[i].second;
    }

    long long len = sqrt(area);
    if (len * len != area) {
        cout << "-1\n";
        return 0;
    }

    // Sort rectangles by width descending
    sort(v, v+3, [&](auto &a, auto &b){
        return a.first > b.first;
    });

    // CASE 1: All widths equal
    if (v[0].first == v[1].first && v[1].first == v[2].first) {
        if (v[0].second + v[1].second + v[2].second == len) {
            cout << len << "\n";
            for (int i = 0; i < 3; i++)
                print(letters[i], v[i].first, v[i].second);
        } else {
            cout << "-1\n";
        }
        return 0;
    }

    // CASE 2: First rectangle fills the entire width
    if (v[0].first == len) {
        long long remain = len - v[0].second;

        // Rotate the bottom two rectangles so their HEIGHT becomes remain if possible
        for (int i = 1; i < 3; i++) {
            if (v[i].second == remain) continue;
            if (v[i].first == remain)
                swap(v[i].first, v[i].second);
        }

        // Check the fit
        if (v[1].second == remain &&
            v[2].second == remain &&
            v[1].first + v[2].first == len) {

            cout << len << "\n";

            // Print the top rectangle
            print('A', v[0].first, v[0].second);

            // Print the bottom row combining B and C rowwise
            for (int row = 0; row < remain; row++) {
                for (int j = 0; j < v[1].first; j++) cout << 'B';
                for (int j = 0; j < v[2].first; j++) cout << 'C';
                cout << "\n";
            }
            return 0;
        }
    } else {
        cout << "-1\n";
    }
}
