
#include <iostream>
using namespace std;
template <typename T,typename V>
class Pair
{

    T x;
    V y;
    public:
    void setX(T x)
    {
        this->x=x;
    }
    T getX()
    {
        return x;
    }
    void setY(V y)
    {
        this->y=y;
    }
    V getY()
    {
        return y;
    }
};



int main()
{
    Pair<Pair<int,int>,double> p1;
    p1.setY(20.20);
    Pair<int,int>p4;
    p4.setX(10);
    p4.setY(20);
    p1.setX(p4);
    cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY()<<endl;
    
   

    return 0;
}