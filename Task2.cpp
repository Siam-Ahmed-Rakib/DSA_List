//#include "Arr.cpp"
#include "LL.cpp"
List l;
void clear()
{
    while(l.length())
    {
        l.remove();
    }
}
void append(int item)
{
    if(!l.length())
        l.insert(item);
    else
    {
         int c=l.currPos();
        l.moveToEnd();
        l.insert(item);
        l.next();
        int d=l.remove();
        l.insert(d);
        l.moveToPos(c);
    }
}
int Search(int item)
{
    int c=l.currPos();
    l.moveToStart();
    int r=-1;
    while(l.currPos()<l.length()-1)
    {
        if(l.getValue()==item)
            {
                r=l.currPos();
                break;
            }
            l.next();
    }
    if(l.getValue()==item)
            {
                r=l.currPos();
            }
    l.moveToPos(c);
    return r;
}
int main()
{
    int K,X;
    cout<<"The initial length of the list : ";
    cin>>K;
    cout<<"The initial memory chunk size : ";
    cin>>X;
    cout<<"Enter initial elements : ";
    int c;
    l.init(K,X);
    cout<<"The current position is : ";
    cin>>c;
    l.moveToPos(c);
    cout<<"The initial list : ";
    l.print();
    cout<<endl<<endl;
    while(1)
    {
        int choice;
        cout<<"0.Exit"<<endl;
        cout<<"1.Clear"<<endl;
        cout<<"2.Append"<<endl;
        cout<<"3.Search"<<endl<<endl;
        cout<<"Enter Your choice : ";
        cin>>choice;
        if(choice==0)
            break;
        else if(choice==1)
        {
            clear();
            cout<<"The updated list : ";
            l.print();
        }
        else if(choice==2)
        {
            int t;
            cout<<"Enter the element : ";
            cin>>t;
            append(t);
            cout<<"The updated list : ";
            l.print();
        }
        else if(choice==3)
        {
            int t;
            cout<<"Enter the element : ";
            cin>>t;
            int s=Search(t);
            cout<<"The updated list : ";
            l.print();
            cout<<endl<<"The position of the element :"<<s;
        }
        else
        {
            cout<<" Wrong choice !! Try again."<<endl;
        }
        cout<<endl<<endl;
    }  
    return 0;
}

