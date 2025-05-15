#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    if (a + b > n)
    {
        cout << "NO" << endl;
        return;
    }
    else if ((a == 0 && b > 1) || (b == 0 && a > 1))
    {
        cout << "NO" << endl;
        return;
    }
    int k = n - (a + b);
    // cout<<"Value of k is "<<k<<endl;
    // cout<<"Value of a is "<<a<<endl;
    // cout<<"Value of b is "<<b<<endl;
    vector<int> first, second;
    for (int i = 1; i <= k; i++)
    {
        // play the first k elements for tie
        first.push_back(i);
        second.push_back(i);
    }
    // cout<<"first k elements in both the arrays are "<<endl;
    // for (int i = 0; i < first.size(); i++)
    // {
    //     cout << first[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < second.size(); i++)
    // {
    //     cout << second[i] << " ";
    // }
    // cout << endl;


    int smallest_a = k + 1, biggest_a = n;
    int smallest_b = k + 1, biggest_b = n;
    // cout<<"Smallest a and biggest a is "<<smallest_a<<" "<<biggest_a<<endl;
    // cout<<"smallest b and biggest b is "<<smallest_b<<" "<<biggest_b<<endl; 
    // take top a elements for first in ascending order and bottom a elements for b in ascending order inorder to avoid middle spurious tie
    vector<int> temp_a, temp_b;
    for (int i = 0; i < a; i++)
    {
        temp_a.push_back(biggest_a--);
        temp_b.push_back(smallest_b++);
    }
    // cout<< "desceding order of numbers in temp_a and temp b"<<endl;
    // for(int i=0;i<temp_a.size();i++){
    //     cout<<temp_a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<temp_b.size();i++){
    //     cout<<temp_b[i]<<" ";
    // }
    // cout<<endl;
    
    // push the elements of temp in reverse order, so as to get the ascending order
    int i=0;
    while (temp_a.size())
    {
        first.push_back(temp_a.back());
        second.push_back(temp_b[i++]);
        temp_a.pop_back();
        // temp_b.pop_back();
    }
    temp_b.clear();
    
    // now do the same for b scores
    for (int i = 0; i < b; i++)
    {
        temp_b.push_back(biggest_b--);
        temp_a.push_back(smallest_a++);
    }
    // cout<< "desceding order of numbers in temp_a and temp b"<<endl;
    // for(int i=0;i<temp_a.size();i++){
    //     cout<<temp_a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<temp_b.size();i++){
    //     cout<<temp_b[i]<<" ";
    // }
    // cout<<endl;
    i = 0;
    while (temp_a.size() && temp_b.size())
    {
        first.push_back(temp_a[i++]);
        second.push_back(temp_b.back());
        // temp_a.pop_back();
        temp_b.pop_back();
    }
    // see if a valid solution, no elements appears more than once , and the score of both the arrays is same as origina
    vector<bool> visited_a(n + 1, false), visited_b(n + 1, false);
    if (first.size() < n || second.size() < n)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < first.size(); i++)
    {
        if (visited_a[first[i]] || visited_b[second[i]])
        {
            cout << "NO" << endl;
            return;
        }
        if (first[i] > second[i])
        {
            // one point to a
            a--;
        }
        else if (second[i] > first[i])
        {
            // one point to b
            b--;
        }
        visited_a[first[i]] = true;
        visited_b[second[i]] = true;
    }
    // *******************************************************
    // for (int i = 0; i < first.size(); i++)
    // {
    //     cout << first[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < second.size(); i++)
    // {
    //     cout << second[i] << " ";
    // }
    // cout << endl;
    // ******************************************************
    if (a || b)
    {
        // if there is scome score remaining
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < first.size(); i++)
    {
        cout << first[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < second.size(); i++)
    {
        cout << second[i] << " ";
    }
    cout << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}