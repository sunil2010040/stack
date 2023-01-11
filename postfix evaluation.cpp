#include<iostream>
#include<stack> 
#include<math.h>

using namespace std;

void postfix(string str)
{
    stack<int>st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            st.push(str[i]-'0');
        }
        
        else
        {
            int opr2=st.top();
            st.pop();
            
            int opr1=st.top();
            st.pop();
            
            switch(str[i])
            {
                case '+':
                    st.push(opr1+opr2);
                    break;
                    
                case '-':
                    st.push(opr1-opr2);
                    break;
                
                case '*':
                    st.push(opr1*opr2);
                    break;
                    
                case '/':
                    st.push(opr1/opr2);
                    break; 
                
                case '^':
                    st.push(opr1^opr2);
                    break;
            }
        }
    }
    cout<<st.top()<<endl;
}

int main()
{
    string str="46+2/5*7+";
    postfix(str);
}

OUTPUT:

32