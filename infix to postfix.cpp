#include<iostream>
#include<stack> 
#include<math.h>

using namespace std;

int precedence(char c)
{
    if(c=='^')
    {
        return 3;
    }
    
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    
    else
    {
        return -1;
    }
}

void postfix(string str)
{
    stack<char>st;
    string post;
    for(int i=0;i<str.length();i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' &&  str[i]<='Z'))
        {
            post+=str[i];
        }
        
        else if(str[i]=='(')
        {
            st.push(str[i]);
        }
        
        else if(str[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                post+=st.top();
                st.pop();
            }
            
            if(!st.empty())
            {
                st.pop();
            }
        }
        
        else
        {
            while(!st.empty() && precedence(st.top())>precedence(str[i]))
            {
                post+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        
    }
    while(!st.empty())
    {
        post+=st.top();
        st.pop();
    }
        
        
    
    cout<<post<<endl;
}

int main()
{
    string str="(a-b/c)*(a/k-l)";
    postfix(str);
}

OUTPUT:

abc/-ak/l-*
