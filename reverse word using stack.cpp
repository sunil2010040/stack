#include<iostream>
#include<stack>

using namespace std;

void reverse_word(string str)
{
    stack<string>st;
    for(int i=0;i<str.length();i++)
    {
        string w="";
        w+=str[i];
        st.push(w);
    }
    
    while(!st.empty())
    {
        cout<<st.top()<<"";
        st.pop();
    }cout<<endl;
}

int main()
{
    string str="hello";
    reverse_word(str);
}


OUTPUT:

olleh
