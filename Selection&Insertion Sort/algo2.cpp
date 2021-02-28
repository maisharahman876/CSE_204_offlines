#include<iostream>
#include<cstdlib>
#include<ctime>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;


void insertion(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;

        }
        a[j+1]=key;
    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection(int arr[], int n)
{
    int i, j, min_idx;


    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;


        swap(&arr[min_idx], &arr[i]);
    }
}


void revArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
int n,i,j,l=10;
double sum=0.0,sum1=0.0;
cout<<"Size of the Array : "<<endl;
cin>>n;
int *a= new int[n];
int *b=new int[n];
l=10;
double s1=0.0,s2=0.0,s3=0.0,s4=0.0,s5=0.0,s6=0.0;
srand(time(0));
while(l--)
{

 for(i=0;i<n;i++)
    {

        a[i]=rand();
         b[i]=a[i];

    }

    insertion(a,n);

    clock_t sta1 = clock();
    insertion(a,n);
    clock_t st1 = clock();
    double best = (double)(st1 - sta1) * 1000.0 / CLOCKS_PER_SEC;
    s1+=best;

    revArray(a,0,n-1);
    clock_t sta2 = clock();
    insertion(a,n);
    clock_t st2 = clock();
    double worst = (double)(st2 - sta2) * 1000.0 / CLOCKS_PER_SEC;
   s2+=worst;
   s3+=worst/2.0;



    selection(b,n);



    clock_t start1 = clock();
    selection(b,n);
    clock_t stop1 = clock();
    double best1= (double)(stop1 - start1) * 1000.0 / CLOCKS_PER_SEC;
   s4+=best1;

    revArray(b,0,n-1);
    clock_t start2 = clock();
    selection(b,n);
    clock_t stop2 = clock();
    double worst1= (double)(stop2 - start2) * 1000.0 / CLOCKS_PER_SEC;
    s5+=worst1;
    s6+=worst1/2.0;

}
cout<<"Time of insertion sort Best Case: "<<s1/10.0<<endl;
 cout<<"Time of insertion sort worst Case: "<<s2/10.0<<endl;

    cout<<"Time of insertion sort Average Case: "<<s3/10.0<<endl;
     cout << "Duration of Selection Sort best case" <<s4/10.0<< endl;
cout << "Duration of Selection Sort worst case " <<s5/10.0<< endl;

cout << "Duration of Selection Sort Average case " <<s6/10.0<< endl;






}

