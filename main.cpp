#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include "sortari.h"

using namespace std;

int main() {
    int n;
    int tip;
    cout << "Cate elemente testam? (ex: 50000): ";
    cin>>n;
    cout<< "\nTipul listei:\n";
    cout<< "1. Numere aleatoare \n";
    cout<< "2. Lista crescatoare\n";
    cout<< "3. Lista descrescatoare \n";
    cin>>tip;

    int* vbubble=new int[n];
    int* vinsertion=new int[n];
    int* vselection=new int[n];
    int* vmerge=new int[n];
    int* vquick=new int[n];

    srand(1);

    //generarea datelor in memorie
    for(int i=0;i<n;i++) {
        int nr=0;
        if(tip==1)
            nr=rand()%100000;
        else
         if(tip==2) nr=i+1;
        else
         if(tip==3) nr=n-i;

        vbubble[i]=nr;
        vinsertion[i]=nr;
        vselection[i]=nr;
        vmerge[i]=nr;
        vquick[i]=nr;
    }



    chrono::time_point<chrono::high_resolution_clock> start, end;
    chrono::duration<double, milli> durata;

    // timp bubble sort
    start = chrono::high_resolution_clock::now();
    //bubblesort(vbubble, n);
    end = chrono::high_resolution_clock::now();
    durata = end - start;
    double t_bubble = durata.count();

    // timp insertion sort
    start = chrono::high_resolution_clock::now();
    //insertionsort(vinsertion, n);
    end = chrono::high_resolution_clock::now();
    durata = end - start;
    double t_insertion = durata.count();

    // timp selection sort
    start = chrono::high_resolution_clock::now();
    //selectionSort(vselection, n);
    end = chrono::high_resolution_clock::now();
    durata = end - start;
    double t_selection = durata.count();

    // timp merge sort
    start = chrono::high_resolution_clock::now();
    mergesort(vmerge, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    durata = end - start;
    double t_merge = durata.count();

    // timp quicksort
    start = chrono::high_resolution_clock::now();
    quicksort(vquick, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    durata = end - start;
    double t_quick = durata.count();

    cout<<fixed<<setprecision(4);
    cout << "rezultate("<<n<<" elemente)\n";
    if (tip==1) cout << "Tip lista: aleatoare\n";
    else if (tip==2) cout << "Tip lista: sortata crescator \n";
    else if (tip==3) cout << "Tip lista: sortata descrescator \n";
    cout<< "--------------------------------------------------------\n";

    cout<< "ALGORITMI O(n^2):\n";
    cout<< "Bubble Sort-timp: " << t_bubble << " ms\n";
    cout<< "Insertion Sort-timp: " << t_insertion << " ms\n";
    cout<< "Selection Sort-timp: " << t_selection << " ms\n";
    cout<< "--------------------------------------------------------\n";
    cout<< "ALGORITMI O(n log n):\n";
    cout<< "Merge Sort-timp: " << t_merge << " ms\n";
    cout<< "Quick Sort-timp: " << t_quick << " ms\n";
    cout<< "---------------------------------------------------------\n";

    // eliberarea memoriei
    delete[] vbubble;
    delete[] vinsertion;
    delete[] vselection;
    delete[] vmerge;
    delete[] vquick;

    return 0;
}
