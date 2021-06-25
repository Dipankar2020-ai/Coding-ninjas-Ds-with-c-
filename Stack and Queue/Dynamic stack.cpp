
#include <iostream>

using namespace std;
class stackarray
{
    int *data;
    int index;
  
    public:
    int totallength;
    stackarray()
    {
        data=new int[4];
        index=0;
        totallength=4;
        
    }
    void push(int value)
    {
        if(index<totallength)
        {
            data[index]=value;
            cout<<data[index]<<" ";
            index++;
        }
      if(index==totallength)
        {
            int* newdata=new int[2*totallength];
            for(int i=0;i<totallength;i++)
            {
                newdata[i]=data[i];
            }
           
            totallength*=2;
            delete [] data;
            data=newdata;
           
           
        }
    }
    int pop()
    {
        if(index!=0)
        {
             index--;
        return data[index];
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }
       
    }
    int length()
    {
        return index;
    }
    bool isempty()
    {
        return (index==0);
    }
    int top()
    {
        return data[index-1];
    }
};

int main()
{
    stackarray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<endl;
    cout<<s.pop()<<endl;
    cout<<s.length()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
     
    
    

    return 0;
}