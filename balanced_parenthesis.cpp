#include<iostream>
#include<stack> 
#include<math.h>

using namespace std;

void balanced_parenthesis(string str)
{
    stack<char>st;
    for(int i=0;i<str.length();i++)
    {
        if(st.empty())
        {
            st.push(str[i]);
        }
        
        else if((st.top()=='(' && str[i]==')') 
        || (st.top()=='{' && str[i]=='}') 
        || (st.top()=='[' && str[i]==']'))
        {
            st.pop();
        }
        
        else
        {
            st.push(str[i]);
        }
    }
    
    if(st.empty())
    {
        cout<<"balanced";
    }
    
    else
    {
        cout<<"unbalanced";
    }
}

int main()
{
    string str="{([])}";
    balanced_parenthesis(str);
}

OUTPUT:

balanced
