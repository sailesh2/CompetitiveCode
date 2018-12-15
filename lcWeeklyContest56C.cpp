#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    int LCSubStr(vector<int> X, vector<int> Y, int m, int n)
    {
        int LCSuff[m+1][n+1];
        int result = 0;
        for (int i=0; i<=m; i++)
        {
            for (int j=0; j<=n; j++)
            {
                if (i == 0 || j == 0)
                    LCSuff[i][j] = 0;

                else if (X[i-1] == Y[j-1])
                {
                    LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                    result = max(result, LCSuff[i][j]);
                }
                else LCSuff[i][j] = 0;
            }
        }
        return result;
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        return LCSubStr(A,B,A.size(),B.size());
    }
};
