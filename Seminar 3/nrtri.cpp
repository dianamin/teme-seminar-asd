/*
    http://www.infoarena.ro/problema/nrtri
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f ("nrtri.in");
ofstream g ("nrtri.out");

const int NMAX = 800 + 1;
int n, v[NMAX];

void citeste () {
    f >> n;
    for (int i = 1; i <= n; i++) f >> v[i];
}

void rezolva () {
    int sol = 0;
    for (int i = 1; i < n; i++)
    for (int j = i + 1; j < n; j++) {
        int k = j + 1;
        while (k <= n && v[k] <= v[i] + v[j]) k++, sol++;
    }
    g << sol << '\n';
}

int main () {
    citeste();
    sort(v + 1, v + n + 1);
    rezolva ();
    return 0;
}
