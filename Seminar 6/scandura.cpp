#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("scandura.in");
ofstream g ("scandura.out");

const int NMAX = 1000000 + 1;

int n, m;

int start1, start2;
int sfarsit1, sfarsit2;

long long q1[NMAX];
long long q2[NMAX];


void citeste() {
    f >> n >> m;
    for (int i = 1; i <= n; i++) f >> q1[i];
}

void init_cozi() {
    start1 = 1;
    sfarsit1 = n;

    start2 = 1;
    sfarsit2 = 0;
}


bool isnt_empty(int start, int sfarsit) {
    return start <= sfarsit;
}

void rezolva() {
    init_cozi();

    long long suma = 0, sol = 0;

    int rest = (n - 1) % (m - 1);
    int lungimi_ramase = n;


    if (rest != 0) {
        for (int i = 1; i <= rest + 1; i++)
            suma += q1[i];

        q2[++sfarsit2] = suma;
        start1 = rest + 2;
        sol += suma;
        lungimi_ramase = lungimi_ramase - rest;
    }

    while (lungimi_ramase > 1) {
        suma = 0;
        for (int i = 1; i <= m && lungimi_ramase; i++) {
            if (isnt_empty(start1, sfarsit1) && isnt_empty(start2, sfarsit2)) {
                if (q1[start1] < q2[start2]) {
                    suma += q1[start1];
                    ++start1;
                }
                else {
                    suma += q2[start2];
                    ++start2;
                }

            }
            else {
                if (isnt_empty(start1, sfarsit1)) {
                    suma += q1[start1];
                    ++start1;
                }
                else {
                    suma += q2[start2];
                    ++start2;
                }
            }
            lungimi_ramase--;
        }
        lungimi_ramase++;

        sol += suma;
        q2[++sfarsit2] = suma;
    }

    g << sol << '\n';
}


int main() {
    citeste();
    rezolva();
}
