#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int countreversals(string input)
{
    int len=input.length();
    int leftbraces=0,rightbraces=0;
    if(len%2!=0)
    {
        return -1;
    }
    for(int i=0;i<len;i++)
    {
        if(input[i]=='{')
        {
            leftbraces++;
        }
        else
        {
            if(leftbraces==0)
            {
                rightbraces++;
            }
            else
            {
                leftbraces--;
            }
        }
    }
    int ans=ceil(leftbraces/2)+ceil(rightbraces/2);
    return ans;
}

int main() {
    // Write C++ code here
    string input;
    getline(cin,input);
    cout<<countreversals(input);
    return 0;
}