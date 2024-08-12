#include <bits/stdc++.h>

using namespace std;

class fenwickTree
{
    vector<int> bit;

public:
    fenwickTree(int n)
    {
        bit.resize(n + 1, 0);
    }
    void build(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            update(i + 1, arr[i]);
        }
    }
    void update(int ind, int val)
    {
        while (ind < bit.size())
        {
            bit[ind] += val;
            ind = getNext(ind);
        }
    }
    int query(int ind)
    {
        int sum = 0;

        while (ind > 0)
        {
            sum += bit[ind];
            ind = getParent(ind);
        }
        return sum;
    }
    int getNext(int ind)
    {
        return ind + (ind & -ind);
    }

    int getParent(int ind)
    {
        return ind - (ind & -ind);
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    fenwickTree ft(n);
    ft.build(arr);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int ans = ft.query(r) - ft.query(l - 1);
            cout << ans << endl;
        }
        else
        {
            int ind, val;
            cin >> ind >> val;
            int diff = val - arr[ind-1];
            ft.update(ind + 1, diff);
        }
    }
}
