//#include "Arr.cpp"
#include "LL.cpp"
List *garrage;
int cars_num,gar_num,max_car;
void show()
{
    for(int i=0;i<gar_num;i++)
    {
        if(garrage[i].length())
        {
            garrage[i].moveToStart();
            while(garrage[i].currPos() < garrage[i].length()-1)
            {
                cout<<garrage[i].getValue()<<" ";
                garrage[i].next();
            } 
            cout<<garrage[i].getValue();
        }
        cout<<endl;
    }
}
void req()
{
    for(int i=0;i<gar_num;i++)
    {
        if(garrage[i].length())
        {
            int smallest_index,value;
            garrage[i].moveToStart();
            smallest_index=0;
            value=garrage[i].getValue();
            garrage[i].next();
            while(garrage[i].currPos() < garrage[i].length()-1)
            {
                if(value>garrage[i].getValue())
                {
                    smallest_index=garrage[i].currPos();
                    value=garrage[i].getValue();
                }
                garrage[i].next();
            } 
           if(value>garrage[i].getValue())
             {
                smallest_index=garrage[i].currPos();
                value=garrage[i].getValue();
             }
             garrage[i].moveToPos(smallest_index);
             garrage[i].remove();
             return;
        }
    }
}
void ret(int p)
{
    for(int i=gar_num-1;i>=0;i--)
    {
        if(garrage[i].length()<max_car)
        {
            int largest_index,value;
            garrage[i].moveToStart();
            largest_index=0;
            value=garrage[i].getValue();
            garrage[i].next();
            while(garrage[i].currPos() < garrage[i].length()-1)
            {
                if(value<garrage[i].getValue())
                {
                    largest_index=garrage[i].currPos();
                    value=garrage[i].getValue();
                }
                garrage[i].next();
            } 
           if(value<garrage[i].getValue())
             {
                 largest_index=garrage[i].currPos();
                value=garrage[i].getValue();
             }
             garrage[i].moveToPos(largest_index+1);
             garrage[i].insert(p);
             return;
        }
    }
}
int main()
{
    int X,Y,Z;
    cout<<"Enter the number of cars: ";
    cin>>X;
    cout<<"Enter the number of garages: ";
    cin>>Y;
    cout<<"Enter the maximum number of parking spots in a garage: ";
    cin>>Z;
    garrage=new List[Y];
    cars_num=X;
    gar_num=Y;
    max_car=Z;
    cout<<"Enter car and garrage list: "<<endl;
    for(int j=0;j<gar_num;j++)
    {
        int i;
        cin>>i;
        i-=1;
        int n;
        cin>>n;
        garrage[i].init(n,Z);
    }
    cout<<"Initial CRS status : "<<endl;
    show();
    while(1)
    {
        int choice;
        cout<<"1.req"<<endl;
        cout<<"2.ret"<<endl;
        cout<<"3.end"<<endl;
        cout<<"Enter Your choice : ";
        cin>>choice;
        if(choice==3)
            break;
        else if(choice==1)
        {
            req();
        }
        else if(choice==2)
        {
            int p;
            cout<<"Enter car's number : ";
            cin>>p;
            ret(p);
        }
        cout<<"Updated CRS status : "<<endl;
        show();
    }
    return 0;
}