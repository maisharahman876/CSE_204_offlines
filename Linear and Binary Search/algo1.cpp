#include<iostream>
#include<ctime>
#include<cstdlib>


using namespace std;



int linear(int a[],int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return i;
        }
    }
    return -1;
}
int binary(int a[],int n,int x)
{
    int f,l,mid;
    f=0;
    l=n-1;

    while(f<=l)
    {
         mid=(f+l)/2;
         if(a[mid]==x)
            return mid;
         else if(x<a[mid])
         {
             l=mid-1;
         }
         else
            f=mid+1;
    }
    return -1;
}
int main()
{
    int n;
    cout<<" Enter size of the array : ";
    cin>>n;
    int a[n];
    int i,x,index;
    int j,k,temp;
     srand(time(0));
     x=rand();

    for(i=0;i<n;i++)
    {

        a[i]=rand();


    }

  for (j=0;j<n;j++)
  {
      for(k=j+1;k<n;k++)
      {
          if(a[j]>a[k])
          {
              temp=a[j];
              a[j]=a[k];
              a[k]=temp;
          }
      }
  }
 clock_t start = clock();
index=linear(a,n,x);
 clock_t stop = clock();
        double elapsed = (double)(stop - start) * 1000000.0 / CLOCKS_PER_SEC;

cout << "Duration of linear search " <<elapsed << endl;
 clock_t start1 = clock();
index= binary(a,n,x);
 clock_t stop1 = clock();
        double elapsed1 = (double)(stop1 - start1) * 1000000.0 / CLOCKS_PER_SEC;

cout << "Duration of Binary search " <<elapsed1 << endl;





}
