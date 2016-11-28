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
