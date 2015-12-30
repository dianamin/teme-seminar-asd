/*
    http://www.infoarena.ro/problema/alee
*/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream f ("alee.in");
ofstream g ("alee.out");

const int NMAX = 175;

int n, m, ai, aj, bi, bj;
queue < pair <int, int> > q;
int alee[NMAX+1][NMAX+1];

void citeste () {
    f>>n>>m;
    int x, y;
    for (int i=1; i<=m; i++) {
        f>>x>>y;
        alee[x][y]=-1;
    }
    f>>ai>>aj>>bi>>bj;
}


void update (int i, int j, int pas) {
    if (i>0 && i<=n)
        if (j>0 && j<=n)
            if (alee[i][j]==0) {
                alee[i][j]=pas;
                q.push (make_pair (i, j));
            }
}


void lee () {
    int i, j, pas;
    q.push (make_pair (ai, aj));
    alee[ai][aj]=1;
    while (!q.empty () && alee[bi][bj]==0) {
        i=q.front ().first;
        j=q.front ().second;
        q.pop ();
        pas=alee[i][j]+1;
        update (i-1, j, pas);
        update (i, j+1, pas);
        update (i+1, j, pas);
        update (i, j-1, pas);
    }
    g<<alee[bi][bj];
}


int main () {
    citeste ();
    lee ();

    return 0;
}
