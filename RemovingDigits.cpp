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

set<int> dig(int num)
{
    set<int> dig;

    while(num)
    {
        dig.insert(num%10);
        num /= 10;
    }

    return  dig;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n+1);

    dp[0] = 0;

    for(int i = 1 ; i < n+1 ; i++)
    {
        dp[i] = 1e9;

        set<int> sd = dig(i);

        for(int j : sd)
        {
            dp[i] = min(dp[i], 1+dp[i-j]);
        }
    }
    cout << dp[n] << "\n";
}