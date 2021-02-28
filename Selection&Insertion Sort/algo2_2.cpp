#include <bits/stdc++.h>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;


void powerSet(string str,int index = -1, string curr = "")
{


    int n = str.length();

    if (index == n)
    {

        return;
    }

    cout <<" {"<<curr<<"}" << "\n";


    for (int i = index + 1; i < n; i++) {

        curr += str[i];
        powerSet(str, i, curr);

        curr.erase(curr.size() - 1);
    }
    return;
}


int main()
{
    int n,i;

    cout<<"Enter The Size of the Set  : ";
    cin>>n;
     string str;
     str.resize(n);
     string s ="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
     int l = s.length();
     srand(time(0));
 for(i=0;i<n;i++)
    {

        str[i]=s[rand()%l];

    }
    cout<<"The given set is :"<<"{"<<str<<"}"<<endl;
    clock_t start=clock();
    powerSet(str);
    clock_t stop=clock();
     double e = (double)(stop - start)  / CLOCKS_PER_SEC;
    cout<<"The time needed : "<<e<<endl;
    return 0;



}
