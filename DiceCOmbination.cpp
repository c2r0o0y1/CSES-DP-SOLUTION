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
    cin >> n;
    vector<ll> dp(n+1);

    for(ll i = 0 ; i < n+1 ; i++)
    {
        if(i == 0)  //base case
        {
            dp[i] = 1;
        }
        else   //recursive
        {
            dp[i] = 0;
            for(ll j = 1 ; j <= 6 ; j++)
            {
                if(j <= i)
                {
                    dp[i] += dp[i-j];
                }
            }
            dp[i] = dp[i] % mod;
        }
    }
    cout << dp[n] << "\n";
}