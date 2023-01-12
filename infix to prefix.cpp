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

string prefix(string str)
{
    stack<char>st;
    string pre;
    for(int i=0;i<str.length();i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' &&  str[i]<='Z'))
        {
            pre+=str[i];
        }
        
        else if(str[i]=='(')
        {
            st.push(str[i]);
        }
        
        else if(str[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                pre+=st.top();
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
                pre+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        
    }
    while(!st.empty())
    {
        pre+=st.top();
        st.pop();
    }
    return pre;
}

string reverse_word(string str)
{
    stack<string>st;
    string word;
    for(int i=0;i<str.length();i++)
    {
        string w="";
        w+=str[i];
        st.push(w);
    }
    
    while(!st.empty())
    {
        word+=st.top();
        st.pop();
    }
    return word;
}

string change_bracket(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            str[i]=')';
        }
        
        else if(str[i]==')')
        {
            str[i]='(';
        }
    }
    return str;
}

int main()
{
    string str="(a-b/c)*(a/k-l)";
    str=reverse_word(str);
    str=change_bracket(str);
    str=prefix(str);
    str=reverse_word(str);
    cout<<str;
}

OUTPUT:

*-a/bc-/akl