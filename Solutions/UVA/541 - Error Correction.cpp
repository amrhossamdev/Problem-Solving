#include <bits/stdc++.h>

// Created by @amrhossamdev
using namespace std;
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)                ((v).begin()), ((v).end())
#define pb                    push_back
#define MP                    make_pair
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};


int main() {
    fast
    int n;

    while (cin >> n && n != 0) {
        int evenR = 0, evenC = 0;
        int sum = 0;
        int arr[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += arr[i][j];
            }
            if (sum % 2 == 0) {
                evenR++;
            }
            sum = 0;
        }
        sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += arr[j][i];
            }
            if (sum % 2 == 0) {
                evenC++;
            }
            sum = 0;
        }
        if (evenR == n && evenC == n) {
            cout << "OK" << endl;
        } else if (n - evenR == 1 || n - evenC == 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    sum += arr[i][j];
                }
                if (sum % 2 != 0) {
                    sum = 0;
                    int r = i;
                    int c = 0;
                    for (int k = 0; k < n; ++k) {
                        for (int l = 0; l < n; ++l) {
                            sum += arr[l][k];
                        }
                        if (sum % 2 != 0) {
                            c = k;
                            cout << "Change bit " << "(" << r + 1 << "," << c + 1 << ")" << "\n";
                            break;
                        }
                    }
                    break;
                }
            }
        } else if (evenR > 1 || evenC > 1) cout << "Corrupt" << endl;
    }

    return 0;
}
