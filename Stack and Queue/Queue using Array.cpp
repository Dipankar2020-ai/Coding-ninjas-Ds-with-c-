
#include <iostream>

using namespace std;
template<typename T>
class queue
{
   T *data;
    int size;
    int nextindex;
    int firstindex;
    int capacity;
    public:
    bool isEmpty()
    {
        return (size==0);
    }
    int length()
    {
        return size;
    }
    queue(T value)
    {
        data=new T[value];
        nextindex=0;
        firstindex=-1;
        capacity=value;
        size=0;
        
    }
    void enqueue(T value)
    {
        if(size<capacity)
        {
             data[nextindex]=value;
            nextindex=(nextindex+1)%capacity;
           
            //nextindex++;
            size++;
        }
        else
        {
            cout<<"QUEUE IS FULL"<<endl;
        }
        if(firstindex==-1)
        {
            firstindex=0;
        }
    
            
        
        
    }
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
        }
         int ans=data[firstindex];
        firstindex=(firstindex+1)%capacity;
       
        //firstindex++;
        size--;
        return ans;
        
    }
   T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty";
        }
        int ans=data[firstindex];
        return ans;
    }
};

int main()
{
    //cout<<"Hello World";
    queue<int> q(4);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(60);
    q.enqueue(70);
    cout<<q.front()<<endl;
     cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
       cout<<q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.length()<<endl;
    

    return 0;
}
