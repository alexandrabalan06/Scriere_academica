# Scriere_academica
Acest proiect reprezintă un studiu de performanță pentru 5 dintre cei mai cunoscuți algoritmi de sortare. Pentru a asigura o testare precisă am utilizat luat următoarele decizii:

Cronometrare de înaltă precizie:

Am folosit biblioteca chrono (mai exact high_resolution_clock) pentru a măsura cu exactitate timpii de execuție. Rezultatele au fost convertite și afișate uniform în milisecunde (ms), cu o precizie de 4 zecimale.

Toți vectorii au fost alocați dinamic pentru a evita erorile de tip "Stack Overflow" la seturi masive de date (ex. 1.000.000 elemente)

Numerele aleatoare sunt generate folosind o sămânță fixă. Astfel, setul de date este 100% identic la fiecare rulare, având o comparație perfect echitabilă.

Optimizări Custom:

"Bubble Sort" a fost optimizat pentru a parcurge lista o singură dată în cazul unei liste deja sortate.

"Quick Sort" utilizează pivotul din mijloc pentru a preveni worst-case-ul O(n^2) pe listele invers sortate. 

 
Rezultatele Testelor

Testele au fost rulate pentru 3 cazuri distincte:
1. Numere complet aleatoare.
2. Listă deja sortată crescător.
3. Listă sortată descrescător (inversată).

Testul 1: Liste Mici (n = 100 elemente)
Pe seturi foarte mici de date, algoritmii simpli sunt adesea mai eficienți din cauza "overhead-ului" (costul de structură și apeluri recursive) prezent la algoritmii complecși.

|    Algoritm     |     Aleator  | Crescător  | Descrescător |
|-----------------|--------------|------------|--------------|
|   Bubble Sort   |  0.0527 ms   |  0.0012 ms |  0.0695 ms   |
| Insertion Sort  |  *0.0082 ms* |*0.0007 ms* |  0.0175 ms   |
| Selection Sort  | 0.0197 ms    | 0.0105 ms  |  0.0152 ms   |
| Merge Sort      | 0.0249 ms    | 0.0091 ms  | 0.0103 ms    |
| Quick Sort      | 0.0146 ms    | 0.0049 ms  | *0.0094 ms*  |

Testul 2: (n = 10.000 elemente)
Se poate observa deja eficiența O(nlog(n))

| Algoritm       | Aleator     | Crescător  | Descrescător |
|----------------|-------------|------------|--------------|
| Bubble Sort    | 407.2462 ms | *0.0229 ms*| 387.6538 ms  |
| Insertion Sort | 41.4705 ms  | 0.0367 ms  | 88.0050 ms   |
| Selection Sort | 68.8503 ms  | 82.7158 ms | 71.2732 ms   |
| Merge Sort     | 1.8137 ms   | 0.7687 ms  | 0.7732 ms    |
| Quick Sort     | *1.4037 ms* | 0.4876 ms  | *0.5998 ms*  |

Testul 3: (n = 100.000 elemente)
La acest nivel, algoritmii de complexitate O(n^2) devin ineficienți. (Bubble Sort a necesitat ~46 de secunde).

| Algoritm       | Aleator       | Crescător    | Descrescător  |
|----------------|---------------|--------------|---------------|
| Bubble Sort    | 46007.7885 ms | 0.2468 ms    | 35969.1089 ms |
| Insertion Sort | 4340.2034 ms  | 0.4434 ms    | 8274.2897 ms  |
| Selection Sort | 6781.1667 ms  | 6562.3171 ms | 6853.6814 ms  |
| Merge Sort     | 20.7306 ms    | 8.7965 ms    | 9.6214 ms     |
| Quick Sort     | *17.4419 ms*  | *5.9730 ms*  | *7.0637 ms*   |

Testul 4: (n= 500.000 elemente)
 Algoritmii de clasa O(n^2) au fost excluși din cauza timpului de execuție . Bătălia s-a dat strict între Merge Sort și Quick Sort.

| Algoritm     | Aleator       | Crescător    | Descrescător |
|--------------|---------------|--------------|--------------|
| *Merge Sort* | 116.5289 ms   | 61.4302 ms   | 54.7023 ms   |
| *Quick Sort* | *91.3451 ms*  | *36.6275 ms* | *41.8945 ms* |

n = 1.000.000 elemente
| Algoritm       | Aleator         | Crescător      | Descrescător   |
|----------------|-----------------|----------------|----------------|
| **Merge Sort** | 346.2269 ms     | 234.6862 ms    | 222.0082 ms    |
| **Quick Sort** |  *198.8193 ms*  | *71.4851 ms*   |  *81.4734 ms*  |

Concluzii Majore

1. Pe seturi foarte mici de date algoritmii simpli (Insertion Sort) sunt mai eficienți decât cei complecși, deoarece nu consumă timp cu apeluri recursive și alocare de memorie.
2. Optimizările salvează vieți: Implementarea condiției de oprire la Bubble Sort i-a transformat complexitatea din O(n^2) în O(n) pentru cel mai bun caz, executând o listă de 100.000 elemente în doar 0.24 ms.
3. Selection Sort execută mereu același număr de comparații matematice indiferent de starea inițială a listei, dovedind o rigiditate absolută în execuție.
4. La nivelul de 1 milion de elemente, deși atât Merge Sort cât și Quick Sort sunt algoritmi O(nlog(n)), `Quick Sort` a fost de aproape două ori mai rapid.
