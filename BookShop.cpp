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
    int n,x;

    cin >> n >> x;

    vector<int> prices(n), pages(n);

    for(int& i : prices)
    {
        cin >> i;
    }

    for(int& i : pages)
    {
        cin >> i;
    }

    vector<vector<int>> dp(n+1 , vector<int>(x+1));

    for(int i = 1 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < x+1 ; j++)
        {   
            dp[i][j] = dp[i-1][j];
            if(j >= prices[i-1])
            {
                dp[i][j] = max(dp[i][j], pages[i-1] + dp[i-1][j-prices[i-1]]);     //0/1 Knapsackx
            }
        }
    }

    cout << dp[n][x] <<  "\n";
}