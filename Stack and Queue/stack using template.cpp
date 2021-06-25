
#include <iostream>

using namespace std;
template<typename T>

class stackarray
{
    T *data;
    int index;
  
    public:
    int totallength;
    stackarray()
    {
        data=new T[4];
        index=0;
        totallength=4;
        
    }
    void push(T value)
    {
        if(index<totallength)
        {
            data[index]=value;
            cout<<data[index]<<" ";
            index++;
        }
      if(index==totallength)
        {
            T* newdata=new T[2*totallength];
            for(int i=0;i<totallength;i++)
            {
                newdata[i]=data[i];
            }
           
            totallength*=2;
            delete [] data;
            data=newdata;
           
           
        }
    }
   T pop()
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
    T top()
    {
        return data[index-1];
    }
};

int main()
{
    stackarray<char> s;
    s.push(97);
    s.push(98);
    s.push(99);
    s.push(100);
    s.push(101);
    s.push(102);
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