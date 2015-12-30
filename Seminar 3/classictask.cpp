/*
    http://www.infoarena.ro/problema/classictask
*/

#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

ifstream f ("classictask.in");
ofstream g ("classictask.out");

unsigned long long a, b, c;

unsigned long long inmultire(unsigned long long a, unsigned long long b) {
    if (b) {
        unsigned long long x = inmultire (a, b / 2);
        if (b % 2 == 1) return ((x + x) % c + a) % c;
        else return (x + x) % c;
    }
    return 0;
}

unsigned long long exponentiere(unsigned long long a, unsigned long long b) {
    if (b) {
        unsigned long long x = exponentiere (a, b / 2), y = inmultire(x, x);
        if (b % 2 == 1) return inmultire(y, a) % c;
        else return y % c;
    }
    return 1;
}

int main () {
    f >> a >> b >> c;
    g << exponentiere(a, b) << '\n';
    return 0;
}
