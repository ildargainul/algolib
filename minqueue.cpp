#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

typedef unsigned int index;

const int INF = 1e9 + 1;

class MinStack 
{
    private:
        stack <int> sval, smin;
    public:
        MinStack()
        {
            smin.push(INF);
        }
        int min()
        {
            return smin.top();
        }
        void push(int x)
        {
            sval.push(x);
            smin.push(::min(smin.top(), x));
        }
        void pop()
        {
            sval.pop();
            smin.pop();
        }
        size_t size()
        {
            return sval.size();
        }
        bool empty()
        {
            return sval.empty();
        }
        int top()
        {
            return sval.top();
        }
};

class MinQueue
{
    private:
        MinStack spush, spop;
    public:
        MinQueue() {}
        int min()
        {
            return ::min(spop.min(), spush.min());
        }
        void push(int x)
        {
            spush.push(x);
        }
        void pop()
        {
            if (spop.empty())
            {
                while (!spush.empty())
                {
                    spop.push(spush.top());
                    spush.pop();
                }
            } 
            spop.pop();
        }
};

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    size_t n, k;
    int x;
    MinQueue q;
    cin >> n >> k;
    for (index i = 0; i < k; i++)
    {
        cin >> x;
        q.push(x);
    }
    cout << q.min() << ' ';
    for (index i = (index) k; i < n; i++)
    {
        q.pop();
        cin >> x;
        q.push(x);
        cout << q.min() << ' ';
    }
    cout << '\n';
}

