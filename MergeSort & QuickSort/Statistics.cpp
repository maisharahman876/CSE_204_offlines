#include <bits/stdc++.h>
#include<time.h>
using namespace std;

void reverseArr(int arr[], int n)
{
    for(int i=0; i<n/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

void merge(int arr[], int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int *L = new int[n1+1];
    int *R = new int[n2+1];

    for(int i=0; i<n1; i++)
    {
        L[i] = arr[p+i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i] = arr[q+i+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    for(int k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int partition(int arr[], int p, int r)
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
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1;
}

void quickSort(int arr[], int p, int r)
{
    if(p<r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}
int main()
{
    auto t1=chrono::high_resolution_clock::now();
    auto t2=chrono::high_resolution_clock::now();
    double t, total;
    srand(time(NULL));
    int *arr,*arr1,c,n,i;

    int size_array[]= {10,50,100,1000,2000,5000,10000};
    c=sizeof(size_array)/sizeof(size_array[0]);

//best
    for( i=0; i<c; i++)
    {
        n=size_array[i];
        arr=new int[n];
        arr1=new int[n];
        for(int j=0; j<n; j++)
        {
            //cout<<"8";
            arr[j] = rand()%1000000;
            arr1[j]=arr[j];

        }

        quickSort(arr,0,n-1);


        for(int k=0; k<100; k++)
        {
            t1 = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total+=t;
        }

        t=total/100;
        cout<<fixed<<" Time needed for Best case for Merge Sort size "<<n<<" time "<<t<<endl;



    }
    cout<<endl;
    for( i=0; i<c; i++)
    {
        n=size_array[i];
        arr=new int[n];
        arr1=new int[n];
        for(int j=0; j<n; j++)
        {
            //cout<<"8";
            arr[j] = rand()%1000000;
            arr1[j]=arr[j];

        }
        total=0;
        for(int k=0; k<100; k++)
        {
            t1 = chrono::high_resolution_clock::now();
            quickSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total+=t;
        }
        t=total/100;
        cout<<fixed<<" Time needed for Best case for Quick Sort size: "<<n<<" time: "<<t<<endl;
    }
    cout<<endl;
//worst
    for( i=0; i<c; i++)
    {
        n=size_array[i];
        arr=new int[n];
        arr1=new int[n];
        for(int j=0; j<n; j++)
        {
            //cout<<"8";
            arr[j] = rand()%1000000;
        }

        quickSort(arr,0,n-1);
        reverseArr(arr, n);
        for(int m=0; m<n; m++)
            arr1[m] = arr[m];


        for(int k=0; k<100; k++)
        {
            for(int m=0; m<n; m++)
                arr[m] = arr1[m];
            t1 = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total+=t;
        }

        t=total/100;
        cout<<fixed<<" Time needed for Worst case for Merge Sort size "<<n<<" time "<<t<<endl;



    }
    cout<<endl;
    for( i=0; i<c; i++)
    {
        n=size_array[i];
        arr=new int[n];
        arr1=new int[n];
        for(int j=0; j<n; j++)
        {
            //cout<<"8";
            arr[j] = rand()%1000000;
        }
        quickSort(arr,0,n-1);
        reverseArr(arr, n);
        for(int m=0; m<n; m++)
            arr1[m] = arr[m];
        total=0;
        for(int k=0; k<100; k++)
        {
            for(int m=0; m<n; m++)
                arr[m] = arr1[m];
            t1 = chrono::high_resolution_clock::now();
            quickSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total+=t;
        }
        t=total/100;
        cout<<fixed<<" Time needed for Worst case for Quick Sort size: "<<n<<" time: "<<t<<endl;
    }
    cout<<endl;

//avg
    for( i=0; i<c; i++)
    {
        n=size_array[i];
        arr=new int[n];
        arr1=new int[n];
        for(int j=0; j<n; j++)
        {
            //cout<<"8";
            arr[j] = rand()%1000000;
            arr1[j]=arr[j];

        }
        for(int k=0; k<100; k++)
        {
            for(int m=0; m<n; m++)
                arr[m] = arr1[m];
            t1 = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total+=t;
        }

        t=total/100;
        cout<<fixed<<" Time needed for avg case for Merge Sort size "<<n<<" time "<<t<<endl;



    }
    cout<<endl;
    for( i=0; i<c; i++)
    {
        n=size_array[i];
        arr=new int[n];
        arr1=new int[n];
        for(int j=0; j<n; j++)
        {
            //cout<<"8";
            arr[j] = rand()%1000000;
            arr1[j]=arr[j];

        }
        total=0;
        for(int k=0; k<100; k++)
        {
            t1 = chrono::high_resolution_clock::now();
            quickSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total+=t;
        }
        t=total/100;
        cout<<fixed<<" Time needed for avg case for Quick Sort size: "<<n<<" time: "<<t<<endl;
    }


}
