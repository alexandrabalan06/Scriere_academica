#include <iostream>

using namespace std;

void bubblesort(int v[],int n)
{   bool sortat=false;
    while(!sortat)
    {   sortat=true;
        for(int i=0;i<n-1;i++)
        {   if(v[i]>v[i+1])
            {  swap(v[i],v[i+1]);
                sortat=false;
            }
        }
    }
}
void insertionsort(int v[], int n) {
    int i,j,key;
    for (i=1;i<n;i++)
    {
        key=v[i];
        j=i-1;
        while(j>=0&&v[j]>key) {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }
}
void selectionSort(int v[],int n)
 {
    int i,j,poz;
    for(i=0;i<n-1;i++)
    {   poz=i;
        for(j=i+1;j<n;j++)
        { if(v[j]<v[poz])
            {
                poz=j;
            }
        }
        if(poz!=i)
        {
            swap(v[poz],v[i]);
        }
    }
}
void interclasare(int v[],int s,int m,int d)
{
    int n1=m-s+1;
    int n2=d-m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i=0;i<n1;i++)
    {
        L[i]=v[s+i];
    }
    for (int j=0;j<n2;j++)
    {
        R[j]=v[m+1+j];
    }

    int i=0,j=0,k;
     k=s;
    while(i<n1&&j<n2)
    {
        if (L[i]<=R[j])
        {
            v[k]=L[i];
            i++;
        }
       else
        {
            v[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        v[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {   v[k]=R[j];
        j++;
        k++;
    }
    delete L[];
    delete R[];
}
void mergesort(int v[],int s,int d)
 {      if (s<d)
    {   int m=(s+d)/2;
        mergesort(v,s,m);
        mergesort(v,m+1,d);
        interclasare(v,s,m,d);
    }
}

void quicksort(int v[],int st,int dr)
 {    if(st<dr)
  {     int mijloc=(st+dr)/2;
        swap(v[mijloc], v[dr]);
        int pivot=v[dr];
        int i=st-1;
        for (int j=st;j<=dr-1;j++)
        { if(v[j]<pivot)
            {   i++;
                swap(v[i], v[j]);
            }
        }
        swap(v[i+1],v[dr]);
        int pi=i+1;
        quicksort(v,st,pi-1);
        quicksort(v,pi+1,dr);
    }
}
void countingSort(int v[], int n)
{
    if(n==0)
        return;
    int mx=v[0];
    for(int i=1;i<n;i++)
       if(v[i]>mx)
    {
        mx=v[i];
    }
    int* fr=new int[mx+1]();
    for(int i=0;i<n;i++)
        {
            fr[v[i]]++;
        }
    int idx=0;
    for(int i=0;i<=mx;i++)
        {
            while(fr[i]-->0)
            {
                v[idx++]=i;
            }
        }
        delete []fr;
}

