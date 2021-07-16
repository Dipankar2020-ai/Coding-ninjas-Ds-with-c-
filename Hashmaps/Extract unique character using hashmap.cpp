
#include <iostream>
#include<unordered_map>
using namespace std;
void uniquecharacter(char* str)
{
    int index=0;
    unordered_map<char,int>map;
    for(int i=0;str[i]!='\0';i++)
    {
        if(map[str[i]]==0)
        {
            str[index++]=str[i];
            map[str[i]]++;
        }
    }
    str[index]='\0';
    //return str;
}

int main()
{
    char str[50];
    cin>>str;
    uniquecharacter(str);
    cout<<str;

    return 0;
}