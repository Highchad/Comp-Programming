#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> daisy(n);
    for(int &d : daisy) { cin >> d; }

    int average_photo=0;

    for(int i=0; i<daisy.size(); i++) {
        for(int j=i; j<daisy.size(); j++) {
            double average=0;
            for(int what=i; what<=j; what++) { average += daisy[what]; }
            average /= j-i+1;
            for(int index=i; index<=j; index++) {
                if(daisy[index]==average) {
                    average_photo++;
                    break;
                }
            }
        }
    }
    cout << average_photo << endl;
}