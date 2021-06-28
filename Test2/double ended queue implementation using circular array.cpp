
#include <iostream>
#define n 5
int dequearray[n];
int f=-1,r=-1;
using namespace std;
void enqueuefront(int element)
{
    if((f==r+1)||(f==0 && r==n-1))
    {
        printf("Queue is full");
    }
    else if(f==-1 && r==-1)
    {
       f=r=0;
       dequearray[f]=element;
    
    }
    else if(f==0)
    {
        f=n-1;
        dequearray[f]=element;
    
    }
    else
    {
        f--;
        dequearray[f]=element;
        
    }
    
}
void enqueuerear(int element)
{
    if((f==r+1)||(f==0 && r==n-1))
    {
        printf("Queue is full");
    }
    else if(f==-1 && r==-1)
    {
       f=r=0;
       dequearray[r]=element;
    
    }
    else if(r==n-1)
    {
        r=0;
        dequearray[r]=element;
        
    }
    else
    {
        r++;
        dequearray[r]=element;
    }
    
}
void display()
{
    int i=f;
    while(i!=r)
    {
        printf(" %d",dequearray[i]);
        i=(i+1)%n;
    }
    printf(" %d",dequearray[i]);
    
}
int getfront()
{
    if(r==-1 && f==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        return dequearray[f];
    }
}
int getrear()
{
    if(r==-1 && f==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        return dequearray[r];
    }
    
}
void dequefront()
{
    if(r==-1 && f==-1)
    {
        printf("Queue is empty\n");
    }
    if(f==r)
    {
        f=r=-1;
    }
    else if(f==n-1)
    {
        printf("%d\n",dequearray[f]);
        f=0;
    }
    else
    {
        printf("%d\n",dequearray[f]);
        f++;
        
        
    }
    
}
void dequerear()
{
    if(r==-1 && f==-1)
    {
        printf("Queue is empty\n");
    }
    else if(f==r)
    {
      printf("%d\n",dequearray[r]);
       f=r=-1;
    }
    else if(r==0)
    {
        printf("%d\n",dequearray[r]);
        r=n-1;
        
    }
    else
    {
         printf("%d\n",dequearray[r]);
         r--;
    }
}

int main()
{
    
     enqueuefront(10);
     enqueuefront(20);
     enqueuerear(30);
     enqueuerear(40);
     enqueuerear(50);
     display();
     cout<<endl;
     cout<<getfront()<<endl;
     cout<<getrear()<<endl;
     dequefront();
     dequefront();
     dequerear();
     dequerear();
     dequerear();
    dequerear();
     
     cout<<endl;
    

     

    return 0;
}