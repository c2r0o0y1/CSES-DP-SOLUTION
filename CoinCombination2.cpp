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

    vector<int> coins(n);

    for(int& i : coins)
    {
        cin >> i;
    }

    vector<int> dp(x+1);

    dp[0] = 1;

    for(int  i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < x+1 ; j++)
        {
            if(coins[i] <= j)
            {
                dp[j] += dp[j-coins[i]];
                dp[j] %= mod;
            }
        }
    }

    cout << dp[x] << "\n";
}