#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

const int mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < n+1 ; j++)
        {
            if(i == 1 && j == 1)
            {
                dp[i][j] = 1;
            }
            else if(grid[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
        }
    }

    cout << dp[n][n] << "\n";
}