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
    ll n;
    ll x;
    cin >> n >> x;

    vector<ll> coins(n);

    for(ll& i: coins)
    {
        cin >> i;
    }

    vector<ll> dp(x+1);

    for(ll i = 0 ; i < x+1 ; i++)
    {
        if(i == 0)  //if sum == 0 there is one way (base case)
        {
            dp[i] = 1;
        }
        else
        {
            for(ll j = 0 ; j < n ; j++)
            {
                if(coins[j] <= i)
                {
                    dp[i] = dp[i] + dp[i-coins[j]];
                }
            }
            dp[i] %= mod;
        }
    }

    cout << dp[x] << "\n";
}