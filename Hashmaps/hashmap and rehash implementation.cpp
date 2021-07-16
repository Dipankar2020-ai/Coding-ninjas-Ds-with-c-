
#include <iostream>
#include<string>
using namespace std;
template<typename V>
class mapnode
{
    public:
    string key;
    V value;
    mapnode* next;
    mapnode(string key,V value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~mapnode()
    {
        delete next;
    }
};
template<typename V>
class ourmap
{ public:
    int count;
    mapnode<V>** buckets;
    int numbuckets;
    ourmap()
    {
        count=0;
        numbuckets=5;
        buckets=new mapnode<V>* [numbuckets];
        for(int i=0;i<numbuckets;i++)
        {
            buckets[i]=NULL;
        }
    }
    ~ourmap()
    {
        for(int i=0;i<numbuckets;i++)
        {
            delete buckets[i];
        }
        delete [] buckets;
    }

   int size()
   {
       return count;
   }
   private:
   int getbucketindex(string key)
   {
       int currcoeff=1;
       int hashcode=0;
       for(int i=key.length()-1;i>=0;i--)
       {
           hashcode=hashcode+i*currcoeff;
           hashcode=hashcode%numbuckets;
           currcoeff=currcoeff*37;
           currcoeff=currcoeff%numbuckets;
       }
       return hashcode%numbuckets;
   }
        
    public:
    void insert(string key,V value)
    {
        int bucketindex=getbucketindex(key);
        mapnode<V>* head=buckets[bucketindex];
        while(head!=NULL)
        {
            if(head->key==key)
            {
                head->value=value;
            }
            head=head->next;
        }
        head=buckets[bucketindex];
        mapnode<V>* newnode=new mapnode<V>(key,value);
        newnode->next=head;
        buckets[bucketindex]=newnode;
        count++;
        double loadfactor=(1.0* count)/numbuckets;
        if(loadfactor>0.7)
        {
            rehash();
        }
    }
    V removebucket(string key)
    {
        int bucketindex=getbucketindex(key);
        mapnode<V>* head=buckets[bucketindex];
        mapnode<V>* prev=NULL;
        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(prev==NULL)
                {
                    buckets[bucketindex]=head->next;
                    
                }
                else
                {
                    prev->next=head->next;
                }
                V value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
        
    V getvalue(string key)
    {
        int bucketindex=getbucketindex(key);
        mapnode<V>* head=buckets[bucketindex];
        while(head!=NULL)
        {
            if(head->key==key)
            {
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
    public:
    double getloadfactor()
    {
        return (1.0*count)/numbuckets;
    }
    void rehash()
    {
        mapnode<V>** temp=buckets;
        buckets=new mapnode<V>* [2*numbuckets];
        for(int i=0;i<2*numbuckets;i++)
        {
            buckets[i]=NULL;
        }
        int oldbucketcount=numbuckets;
        numbuckets=numbuckets*2;
        count=0;
        for(int i=0;i<oldbucketcount;i++)
        {
            mapnode<V>* head=temp[i];
            while(head!=NULL)
            {
                string key=head->key;
                V value=head->value;
                insert(key,value);
                head=head->next;
            }
            
        }
        for(int i=0;i<oldbucketcount;i++)
        {
            mapnode<V>* head=temp[i];
            delete head;
        }
        delete [] temp;
    }
        
        
  };

int main()
{
    ourmap<int> map;
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key,value);
        cout<<map.getloadfactor()<<endl;
    }
     for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        cout<<key<<" : "<<map.getvalue(key)<<endl;
    }
    cout<<map.size()<<endl;
}