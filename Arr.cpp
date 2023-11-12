#include<iostream>
using namespace std;
class List
{
        int *list;
        int len,chunksize;
        int current_pos=0;
    public:
       void init(int k,int x)
        {
            list=new int[x];
            len=k;
            chunksize=x;
            for(int i=0;i<k;i++)
            {
                cin>>list[i];
            }
        }
        void insert(int item)
        {
            if(len==chunksize)
            {
                chunksize*=2;
                int *tem=new int[chunksize];
                for(int i=0;i<len;i++)
                {
                    tem[i]=list[i];
                }
                delete[] list;
                list=tem;
            }
            if(len==0)
            {
                current_pos=0;
                list[len++]=item;
            }
            else
            {
                for(int i=len;i>current_pos;i--)
                {
                    list[i]=list[i-1];
                }
                list[current_pos]=item;
                len++;
            }
        }
        int remove()
        {
            if(len==0)
               {
                    cout<<"List underflow"<<endl;
                    return -1;
               }
            int rmv=list[current_pos];
            len--;
            for(int i=current_pos;i<len;i++)
            {
                 list[i]=list[i+1];
            }
            if(len==current_pos)
                current_pos--;
            return rmv;
        }
        void moveToStart()
        {
            current_pos=0;
        }
        void moveToEnd()
        {
            current_pos=len-1;
        }
        void prev()
        {
            if(current_pos > 0)
                current_pos--;
        }
        void next()
        {
            if(current_pos < len-1)
                 current_pos++;
        }
        int length()
        {
            return len;
        }
        int currPos()
        {
            return current_pos;
        }
        void moveToPos(int pos)
        {
            if(0>pos||pos>=len)
            {
                cout<<"Wrong position !!  Position should be a positive number and smaller than list's length"<<endl;
                return;
            }
            current_pos=pos;
        }
        int getValue()
        {
             if(len==0)
               {
                    cout<<"List is empty"<<endl;
                    return -1;
               }
            return list[current_pos];
        }
        void print()
        {
            cout<<"< ";
            for(int i=0;i<len;i++)
            {
                if(i==current_pos)
                    cout<<"|";
                cout<<list[i];
                if(i!=(current_pos-1)&&i!=(len-1))
                    cout<<",";
            }
            cout<<" >";
        }
};
