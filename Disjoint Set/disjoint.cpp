#include<iostream>
using namespace std;
class Disjoint
{
    int *p;
    int *Rank;
    int i;
public:
    Disjoint()
    {
        p=new int[100];
        Rank=new int[100];
        for(int j=0;j<100;j++)
        {
            p[j]=-1;
            Rank[j]=-1;
        }
        //i=0;


    }
    void Make_set(int x)
    {
        p[x]=x;
        Rank[x]=0;
        //i++;

    }
    int Find_set(int x)
    {
        if(p[x]==-1)
        {
            cout<<"The element is not found"<<endl;
            return -1;
        }
        if(p[x]==x)
        {
            return x;
        }
        else
        {
            int parent=Find_set(p[x]);
            p[x]=parent;
            return parent;
        }

    }
    void Union(int x,int y)
    {
        int rx=Find_set(x);
        int ry=Find_set(y);
        if(rx==-1||ry==-1)
            return;
        if(rx==ry)
            return;
        if(Rank[rx]>Rank[ry])
        {
            p[ry]=rx;
        }
        else if(Rank[rx]<Rank[ry])
        {
             p[rx]=ry;


        }
        else
        {
            p[ry]=rx;
            Rank[rx]++;
        }


    }
    void Print_set(int x)
    {
        int root = Find_set(x);
        for(int i=0; i<100; i++)
        {
            if(Rank[i]!=-1)
            {

            if(Find_set(i)==root)
                cout<<i<<" ";
            }
        }
    }

};
int main()
{
    Disjoint ds;
    int x,y;
    while(1)
    {
        cout<<"1.   Make Set"<<endl;
        cout<<"2.   Find Set"<<endl;
        cout<<"3.   Union Set"<<endl;
        cout<<"4.   Print"<<endl;
        cout<<"5.   Quit"<<endl;
        cout<<">>> "<<endl;
        int ch;
        cin>>ch;
        if(ch==1)
        {
            cout<<"Input value : ";
            cin>>x;
            ds.Make_set(x);
            cout<<endl;
        }
        else if(ch==2)
        {
            cout<<"You want to find : ";
            cin>>x;
            cout<<"The representative is: "<<ds.Find_set(x);
            cout<<endl;
        }
        else if(ch==3)
        {
            cout<<"Union between : ";
            cin>>x>>y;
            ds.Union(x, y);
            cout<<endl;
        }
        else if(ch==4)
        {
            cout<<"Select an element : ";
            cin>>x;
            ds.Print_set(x);
            cout<<endl;

        }
        else if(ch==5)
        {
            break;
        }
    }
}

