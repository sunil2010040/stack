#include<iostream>
#include<queue>
using namespace std;

class stack 
{
    
    int N;
    queue<int>q1;
    queue<int>q2;
    public:
    stack()
    {
        N=0;
    }
    
    void push(int x)
    {
        q2.push(x);
        N++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int>temp;
        temp=q1;
        q1=q2;
        q2=temp;
        
    }
    
    void pop()
    {
        q1.pop();
        N--;
    }
    
    void top()
    {
        cout<< q1.front()<<endl;
    }
    
    void size()
    {
        cout<< N<<endl;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    st.top();
    st.size();
    
    st.pop();
    st.pop();
    
    st.top();
    
    st.size();
    
    return 0;
}

OUTPUT:

5
5
3
3


