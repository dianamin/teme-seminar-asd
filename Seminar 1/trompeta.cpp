/*
    http://www.infoarena.ro/problema/trompeta
*/

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream f ("trompeta.in");
ofstream g ("trompeta.out");

const int NMAX = 1000000;

int n, m, lg;
char s[NMAX + 1];

void rezolva () {
    bool ok;
    char a;
    while (n > 0) {
        f >> a;
        while (lg != 0 && lg + n > m && s[lg - 1] < a) {
            lg--;
        }
        s[lg] = a;
        lg++;
        n--;
    }

    while (lg > m) lg--;

}

int main () {
    f >> n >> m;
    rezolva ();
    s[lg] = '\0';
    g << s << '\n';
    return 0;
}
