#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int MAXN=3e5+13;

    int N;
    string s;
    int arr[MAXN];
    int eH, eG; //earliest for both breeds
    int lH, lG; //latest for both breeds;
    int ans;

    cin >> N >> s;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i=0; i<N; i++) {
        if (s[i]=='H') {
            eH=i;
            break;
        }
    }
    for (int i=0; i<N; i++) {
        if (s[i]=='G') {
            eG=i;
            break;
        }
    }
    for (int i=N-1; i>=0; i--) {
        if (s[i]=='H') {
            lH=i;
            break;
        }
    }
    for (int i=N-1; i>=0; i--) {
        if (s[i]=='G') {
            lG=i;
            break;
        }
    }
    if (arr[eG]>=lG) {
        for (int i=0; i<eG; i++) {
            if (i==eH) continue;
            if (s[i]=='H' && arr[i]>=eG) {
                ans++;
            }
        }
    }
    if (arr[eH]>=lH) {
        for (int i=0; i<eH; i++) {
            if (i==eG) continue;
            if (s[i]=='G' && arr[i]>=eH) {
                ans++;
            }
        }
    }
    if ((arr[eG] >= lG || (eG <= eH && arr[eG] >= eH)) && (arr[eH] >= lH || (eH <= eG && arr[eH] >= eG)))
    {
        ans++;
    }
    cout << ans << endl;
}
