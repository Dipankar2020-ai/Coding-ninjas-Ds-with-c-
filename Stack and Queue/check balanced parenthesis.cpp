
#include <iostream>
#include<stack>
using namespace std;
bool checkbalanced(string input)
{
    stack<char>s;
    char x;
    int i=0;
    for(i=0;i<input.length();i++)
    {
        if(input[i]=='('|| input[i]=='{'|| input[i]=='[')
        {
            s.push(input[i]);
            continue;
        }
        if(s.empty())
        {
            return false;
        }
        switch(input[i])
        {
            case ')':
             x=s.top();
             s.pop();
             if(x=='}'|| x==']')
             {
                 return false;
             }
             break;
             
             case '}':
              x=s.top();
              s.pop();
             if(x==')'|| x==']')
             {
                 return false;
             }
             break;
             case ']':
              x=s.top();
              s.pop();
             if(x==')'|| x=='}')
             {
                 return false;
             }
             break;
             
             
        }
    }    
        return (s.empty());
    
}

int main()
{
    string input;
    getline(cin,input);
    if(checkbalanced(input))
    {
        cout<<"it is  balanced";
    }
    else
    {
        cout<<" it is not balanced";
    }
}
