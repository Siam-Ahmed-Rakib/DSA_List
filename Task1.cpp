//#include "Arr.cpp"
#include "LL.cpp"
int main()
{
    int K,X;
    cout<<"The initial length of the list : ";
    cin>>K;
    cout<<"The initial memory chunk size : ";
    cin>>X;
    List l;
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
        cout<<"1.Insert"<<endl;
        cout<<"2.Remove"<<endl;
        cout<<"3.Move to start"<<endl;
        cout<<"4.Move to end"<<endl;
        cout<<"5.Prev"<<endl;
        cout<<"6.Next"<<endl;
        cout<<"7.Length"<<endl;
        cout<<"8.Current position"<<endl;
        cout<<"9.Move position"<<endl;
        cout<<"10.Get current value"<<endl<<endl;
        cout<<"Enter Your choice : ";
        cin>>choice;
        if(choice==0)
            break;
        else if(choice==1)
        {
            int t;
            cout<<"Enter the element : ";
            cin>>t;
            l.insert(t);
            cout<<"The updated list : ";
            l.print();
        }
        else if(choice==2)
        {
            int t=l.remove();
            cout<<"The updated list : ";
            l.print();
            cout<<endl<<"The removed value :"<<t;
        }
        else if(choice==3)
        {
            l.moveToStart();
            cout<<"The updated list : ";
            l.print();
        }
        else if(choice==4)
        {
            l.moveToEnd();
            cout<<"The updated list : ";
            l.print();
        }
        else if(choice==5)
        {
            l.prev();
            cout<<"The updated list : ";
            l.print();
        }
        else if(choice==6)
        {
            l.next();
            cout<<"The updated list : ";
            l.print();
        }
        else if(choice==7)
        {
            int t=l.length();
            cout<<"The updated list : ";
            l.print();
            cout<<endl<<"The length of the list :"<<t;

        }
        else if(choice==8)
        {
            int t=l.currPos();
            cout<<"The updated list : ";
            l.print();
            cout<<endl<<"The current position :"<<t;
        }
        else if(choice==9)
        {
            int t;
            cout<<"Enter the position : ";
            cin>>t;
            l.moveToPos(t);
            cout<<"The updated list : ";
            l.print();
        }
        else if(choice==10)
        {
            int t=l.getValue();
            cout<<"The updated list : ";
            l.print();
            cout<<endl<<"The current value :"<<t;
        }
        else
        {
            cout<<" Wrong choice !! Try again."<<endl;
        }
        cout<<endl<<endl;
    }  
    return 0;
}

