#include<iostream>
#include<cstdlib>
using namespace std;

void max_heapify(int a[],int i)
{
    int j,max_index,max;
    int temp;
    int size=a[0];
    for(j=i;j<=size;)
    {
        if(2*j>size)
        {
            return;
        }
        if((2*j+1)>size&&!(2*j>size))
        {
            max=a[2*j];
            max_index=2*j;
        }

        else if(a[2*j]>=a[2*j+1])
        {
            max=a[2*j];
            max_index=2*j;
        }
        else
        {
            max=a[2*j+1];
            max_index=2*j+1;

        }
        if(a[j]<max)
        {
            temp=a[j];
            a[j]=max;
            a[max_index]=temp;


        }
        else
            return;

        j=max_index;


    }




}
class priority_queue
{
    int *a;
    int maximum;
    int max_size;
    int s;

public:
    priority_queue()
    {
        max_size=10;
        s=0;
        a=new int[max_size+1];
        a[0]=s;


    }
       priority_queue(int n)
    {
        max_size=n;
        s=1;
        a=new int[max_size+1];
        a[0]=s;


    }
    void insert(int);
    int FindMax();
    int ExtractMax();
    void IncreaseKey(int,int);
    void DecreaseKey(int,int);
    void Print();


};
int priority_queue::FindMax()

{
	if(s<1)
	{
		cout<<"The queue is Empty"<<endl;
		return 0;
	}

    return a[1];
}
int priority_queue::ExtractMax()
{
    if(s<1)
    {
        cout<<"Heap Underflow"<<endl;
        return -1;
    }
    int max=a[1];
    a[1]=a[s];
    s--;
    a[0]--;
    max_heapify(a,1);
    return max;
}
void priority_queue::IncreaseKey(int i,int key)
{
    int temp;
    if(key<a[i])
    {
        cout<<"New key is smaller than current key"<<endl;
        return;
    }
    a[i]=key;
    while(i>1&&(a[int(i/2)]<a[i]))
    {
       temp=a[i];
       a[i]=a[int(i/2)];
       a[int(i/2)]=temp;
       i=int(i/2) ;
    }


}

void priority_queue::insert(int key)
{
    s++;
    a[0]++;
    if(s>max_size)
    {
        a=(int*)realloc(a,(s+10)*sizeof(int));
    }
    a[s]=-1000;
    IncreaseKey(s,key);

}
void priority_queue::DecreaseKey(int i,int key)
{
    if(key>a[i])
    {
        cout<<"New key is bigger than current key"<<endl;
        return;
    }
    a[i]=key;
    max_heapify(a,i);

}
void priority_queue::Print()
{
    if(s<=0)
        cout<<"Empty"<<endl;
    for(int i=1;i<=s;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    priority_queue pq;
    int i,k;
    int c;
    while(1)
    {
        cout<<"Enter your choice : "<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Find Maximum"<<endl;
        cout<<"3.Extract Maximum"<<endl;
        cout<<"4.Increase Key"<<endl;
        cout<<"5.Decrease key"<<endl;
        cout<<"6.Print"<<endl;
        cout<<"7.Quit"<<endl;
        cin>>c;
        if(c==1)
        {
            cout<<"Enter the number you want to insert : ";
            cin>>k;
            pq.insert(k);
        }
        else if(c==2)
        {
            cout<<"The Maximum Number is "<<pq.FindMax()<<endl;
        }
        else if(c==3)
        {
            pq.ExtractMax();
        }
        else if(c==4)
        {
            cout<<"The index is : ";
            cin>>i;
            cout<<"The increased key is: ";
            cin>>k;
            pq.IncreaseKey(i,k);
        }
        else if(c==5)
        {
            cout<<"The index is : ";
            cin>>i;
            cout<<"The decreased key is: ";
            cin>>k;
            pq.DecreaseKey(i,k);
        }
        else if(c==6)
        {
            pq.Print();
        }
        else
            break;
    }
}





