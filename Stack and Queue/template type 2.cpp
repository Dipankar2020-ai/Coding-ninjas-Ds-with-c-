
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
    Pair<int,double> p1;
    p1.setX(10.20);
    p1.setY(20.30);
    cout<<p1.getX()<<" "<<p1.getY()<<" ";
    /*Pair<double>p2;
    p2.setX(10.20);
    p2.setY(20.30);
    cout<<p2.getX()<<" "<<p2.getY()<<" ";*/

    return 0;
}