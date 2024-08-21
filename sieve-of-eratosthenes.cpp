// jai shree ram

#include <bits/stdc++.h>

using namespace std;

// tc -> N*(log(log N))
void sieve()
{
    int n;
    cin >> n;
    int prime[n + 1];
    for(int  i = 2 ; i <= n ; i++) prime[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
    return;
}

int main()
{
    sieve();
}
