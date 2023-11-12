#include "Arr.cpp"
#include<cmath>
int main()
{
    int m,n;
    cin>>m>>n;
    List A,B;
    A.init(m,m);
    B.init(n,n);
    if(m>n)
    {
        B.moveToStart();
        while(A.length()!=B.length())
        {
            B.insert(0);
        }
    }
    else if(m<n)
    {
        A.moveToStart();
        while(A.length()!=B.length())
        {
            A.insert(0);
        }
    }

    A.moveToEnd();
    B.moveToEnd();
    int sum=0;
    int i=0;
    while(true)
    {
        sum+=(A.getValue()+B.getValue())*pow(10,i);
        if(A.currPos()==0)
            break;
        A.prev();
        B.prev();
        i++;
    }
    cout<<sum<<endl;
    return 0;
}