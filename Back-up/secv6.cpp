/*
http://www.infoarena.ro/problema/secv6
*/

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream f ("secv6.in");
ofstream g ("secv6.out");

const int MMAX = 8192;
const int NMAX = 16000001;

int n, n_st;
int x[MMAX];

stack <int> st;

void citeste() {
    f >> n;

    int m = min(n, MMAX);
    for (int i = 0; i < m; i++)
        f >> x[i];
}

void rezolva() {
    int a;
    int rez = 0;

    for (int i = 0; i < n; i++) {
        a = i + (x[i / MMAX] ^ x[i % MMAX]);

        while (!st.empty() && st.top() < a) {
            rez++;
            st.pop();
        }
        if (st.size() >= 1) rez++;

        if (st.size() == 0 || st.top() != a) st.push(a);
    }

    g << rez << '\n';
}

int main() {
    citeste();
    rezolva();
    return 0;
}
