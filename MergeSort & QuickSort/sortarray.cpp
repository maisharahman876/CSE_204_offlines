
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
    srand (time(NULL));
    int choice, n;
    int *arr, *new_arr;
    auto t1=chrono::high_resolution_clock::now();
    auto t2=chrono::high_resolution_clock::now();
    double t, total;

    while(1)
    {
        printf("1. Generate average case\n");
        printf("2. Generate best case\n");
        printf("3. Generate worst case\n");
        printf("4. Apply Merge sort\n");
        printf("5. Apply Quicksort\n");
        printf("6. Print array\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Number of elements: ");
            scanf("%d", &n);

            arr = new int[n];
            for(int i=0; i<n; i++)
                arr[i] = rand()%10000000;
            new_arr = new int[n];
            for(int i=0; i<n; i++)
                new_arr[i]=arr[i];
            break;

        case 2:
            printf("Number of elements: ");
            scanf("%d", &n);

            arr = new int[n];
            for(int i=0; i<n; i++)
                arr[i] = rand()%100000;
            quickSort(arr,0,n-1);

            new_arr = new int[n];
            for(int i=0; i<n; i++)
                new_arr[i]=arr[i];
            break;

        case 3:
            printf("Number of elements: ");
            scanf("%d", &n);

            arr = new int[n];
            for(int i=0; i<n; i++)
                arr[i] = rand()%100000;
           quickSort(arr,0,n-1);
            reverseArr(arr,n);
            new_arr = new int[n];
            for(int i=0; i<n; i++)
                new_arr[i]=arr[i];
            break;

        case 4:
            printf("Applying merge sort\n");
            for(int i=0; i<n; i++)
                arr[i]=new_arr[i];
            if(n>=5000)
            {
                t1 = chrono::high_resolution_clock::now();
                mergeSort(arr, 0, n-1);
                t2 = chrono::high_resolution_clock::now();
                t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            }
            else
            {
                total = 0;
                for(int i=0; i<100; i++)
                {

                    t1 = chrono::high_resolution_clock::now();
                    mergeSort(arr, 0, n-1);
                    t2 = chrono::high_resolution_clock::now();
                    t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
                    total += t;
                }
                t = total/100;
            }

            cout<<"Time taken to finish: "<<t<<" nanosec"<<endl;
            break;

        case 5:
            printf("Applying quicksort\n");
            for(int i=0; i<n; i++)
                arr[i]=new_arr[i];
            if(n>=5000)
            {
                t1 = chrono::high_resolution_clock::now();
                quickSort(arr, 0, n-1);
                t2 = chrono::high_resolution_clock::now();
                t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            }
            else
            {
                total = 0;
                for(int i=0; i<100; i++)
                {
                     for(int i=0; i<n; i++)
                       arr[i]=new_arr[i];
                    t1 = chrono::high_resolution_clock::now();
                    quickSort(arr, 0, n-1);
                    t2 = chrono::high_resolution_clock::now();
                    t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
                    total += t;
                }
                t = total/100;
            }

            cout<<"Time taken to finish: "<<t<<" nanosec"<<endl;
            break;

        case 6:
            printf("Array\n");
            for(int i=0; i<n; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
            break;
        }
    }
}
