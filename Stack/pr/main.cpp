
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define pll pair<int, char>

int main()
{

    vector<pll> v;

    pair<pll, int> prr;

    pll pr;
    pr.first = 23;
    pr.second = 'a';

    cout << pr.first << " " << pr.second << endl;

    prr.first.first = 12;
    prr.first.second = 'b';
    prr.second = 12;

    cout << prr.first.first << " " << prr.first.second << " " << prr.second << endl;

    v.push_back({1, 'b'});
    v.push_back({1, 'b'});
    v.push_back({1, 'b'});
    v.push_back({1, 'b'});
    v.push_back({1, 'b'});

    for (auto x : v)
        cout << x.first << " " << x.second << endl;
}
