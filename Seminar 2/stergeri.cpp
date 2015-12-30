/*
    http://www.infoarena.ro/problema/stergeri
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("stergeri.in");
ofstream g ("stergeri.out");

const int NMAX = 100000 + 1;
int n, m, k;

void rezolva (int m) {
    int a, b;
    if (m) {
        f >> a >> b;
        rezolva(m - 1);
        if (a <= k) k += b - a + 1;
    }
}

int main () {
    f >> n >> m >> k;
    rezolva(m);
    g << k << '\n';
    return 0;
}
