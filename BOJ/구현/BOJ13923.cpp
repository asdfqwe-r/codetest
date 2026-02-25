#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        set<string> rowSet;
        string charSet;
        for (int i = 0; i < 3; ++i) {
            string sortedRow = grid[i];
            sort(sortedRow.begin(), sortedRow.end());
            if (rowSet.count(sortedRow)) {
                charSet = sortedRow;
            }
            rowSet.insert(sortedRow);
        }

        int errR = -1;
        int errC = -1;

        for (int r = 0; r < n && errR == -1; ++r) {
            for (int c = 0; c < n && errR == -1; ++c) {
                char currentCh = grid[r][c];

                for (int prevC = 0; prevC < c; ++prevC) {
                    if (currentCh == grid[r][prevC]) {
                        errR = r;
                        for (int otherR = 0; otherR < n; ++otherR) {
                            if (otherR != r && grid[otherR][c] == currentCh) {
                                errC = c;
                                break;
                            }
                        }
                        if (errC == -1) {
                            errC = prevC;
                        }
                         goto error_found;
                    }
                }

                if (charSet.find(currentCh) == string::npos) {
                    errR = r;
                    errC = c;
                    goto error_found;
                }
            }
        }

    error_found:

        for (char expectedCh : charSet) {
            if (grid[errR].find(expectedCh) == string::npos) {
                cout << errR + 1 << " " << errC + 1 << " " << expectedCh << endl;
                break;
            }
        }
    }
    return 0;
}
// 알고리즘: 구현, 문자열 처리, 중복 탐지 (set)
