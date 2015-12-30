/*
    http://www.infoarena.ro/problema/inv
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("inv.in");
ofstream g ("inv.out");

const int MOD = 9917;
const int NMAX = 100000 + 1;

int n;
int v[NMAX];
int aux[NMAX];

void citeste() {
    f >> n;
    for (int i = 1; i <= n; i++) f >> v[i];
}

int numara(int st, int dr, int v[]) {
    if (st >= dr) return 0;

    int m, sol;
    m = (st + dr) / 2;
    sol = (numara(st, m, v) + numara(m + 1, dr, v)) % MOD;

    int i, j, k;
    i = st;
    j = m + 1;
    k = 0;

    while (i <= m && j <= dr) {
        if (v[i] <= v[j]) {
            aux[++k] = v[i];
            i++;
        }
        else {
            aux[++k] = v[j];
            j++;
            sol = (sol + m - i + 1) % MOD;
        }
    }



    for (; i <=  m; i++) aux[++k] = v[i];
    for (; j <= dr; j++) aux[++k] = v[j];

    for (i = st, j = 1; i <= dr; i++, j++)
        v[i] = aux[j];

    return sol;
}

int main() {
    citeste();
    g << numara(1, n, v);
    return 0;
}
