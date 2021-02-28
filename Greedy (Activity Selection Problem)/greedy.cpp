#include<bits/stdc++.h>
using namespace std;
int* Activity_selection(int a[], int s[], int f[], int n) {
  int* A = new int[n];
  A[0] = 0;
  A[1] = a[1];
  int k=1;
  int j = 1;

  for(int i=2; i<=n; i++) {
    if(s[i] >= f[k]) {
      j++;
      A[j] = a[i];
      k=i;
    }
  }
  A[0] = j;
  return A;
}

int partition(int arr[],int a[],int s[], int p, int r)
{
    int x = arr[r];
    int i = p-1;
    for(int j=p; j<r; j++)
    {
        if(arr[j]<=x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
     temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
     temp = s[i+1];
    s[i+1] = s[r];
    s[r] = temp;
    return i+1;
}

void quickSort(int arr[],int a[],int s[], int p, int r)
{
    if(p<r)
    {
        int q = partition(arr,a,s, p, r);
        quickSort(arr,a,s, p, q-1);
        quickSort(arr,a,s, q+1, r);
    }
}
int main()
{
    int n,*s,*f,*a;
    srand(time(0));
    cout<<"The number of events: ";
    cin>>n;
    s=new int[n+1];
    f=new int[n+1];
    a=new int[n+1];
    s[0]=0,f[0]=0,a[0]=0;
    for(int i=1;i<n+1;i++)
    {
        f[i]=rand()%1000;
        a[i]=i;
        s[i]=(rand()%(f[i]-2))+1;
    }
   /* for(int i=1;i<n+1;i++)
    {
        cout<<s[i]<<" "<<f[i]<<" "<<a[i]<<endl;
    }
    */

    quickSort(f,a,s,1,n);
    cout<<"Start  Finish  Activity"<<endl;
    for(int i=1;i<n+1;i++)
    {
        cout<<s[i]<<"      "<<f[i]<<"     "<<a[i]<<endl;
    }
    cout<<endl;

   int nr;
   int *r=Activity_selection(a,s,f,n);
   nr=r[0];
   cout<<"The Solution is:"<<endl;
   for(int i=1;i<nr+1;i++)
    cout<<r[i]<<" ";







}
