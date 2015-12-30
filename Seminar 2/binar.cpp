/*
    http://www.infoarena.ro/problema/binar
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f ("binar.in");
ofstream g ("binar.out");

const int NMAX = 2000 + 1;

int n, m;
char v[NMAX][NMAX];
int crt_order[2][NMAX], order[NMAX];

void citeste() {
    f >> n >> m;
    f.getline(v[0], NMAX);
    for (int i = 0; i < n; i++) {
        f.getline(v[i], NMAX);
    }
}

void rezolva() {
    int nr0, nr1, nr;
    for (int i = 0; i < m; i++) order[i] = i;
    for (int i = n - 1; i >= 0; i--) {
        nr0 = 0; nr1 = 0; nr = 0;
        for (int j = 0; j < m; j++) {
          //  cout << order[j] << ' ';
            if (v[i][order[j]] == '0') {
                //cout << nr0 << ' ';
                crt_order[0][nr0++] = order[j];
                //nr0++;
               // cout << nr0 << ' ' << crt_order[0][nr0 - 1] << ' ' << 0 << endl;
            }
            else {
                crt_order[1][nr1++] = order[j];
                //nr1++;
                //cout << 1 << endl;
            }
        }
        for (int j = 0; j < nr0; j++) order[nr++] = crt_order[0][j]/*, cout << crt_order[0][j] << ' '*/;
        for (int j = 0; j < nr1; j++) order[nr++] = crt_order[1][j]/*, cout << crt_order[1][j] << ' '*/;
        //cout << endl;
    }
}

void scrie() {
    for (int i = 0; i < m; i++) g << order[i] + 1 << ' ';
}

int main() {
    citeste();
    rezolva();
    scrie();
    return 0;
}
