#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

void prefix(string str)
{
    stack<int>st;
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]>='0'&& str[i]<='9')
        {
            st.push(str[i]-'0');
        }
        
        else
        {
            int opr1=st.top();
            st.pop();
            int opr2=st.top();
            st.pop();
            
            switch (str[i])
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
                    st.push(opr1/opr2);
                    break;     
            }
        }
    }
    cout<<st.top();
}

int main()
{
    string str="-+7*45+20";
    prefix(str);
}


OUTPUT:

25