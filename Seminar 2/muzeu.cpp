/*
    http://www.infoarena.ro/problema/muzeu
*/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream f ("muzeu.in");
ofstream g ("muzeu.out");


const int NMAX = 250;

int n;
queue < pair <int, int> > q;
char a[NMAX+1][NMAX+1];
int sol[NMAX+1][NMAX+1];

void citeste () {
    f>>n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) {
            f>>a[i][j];
            if (a[i][j]=='P') {
                q.push (make_pair (i,j));
                sol[i][j]=-3;
            }
            if (a[i][j]=='#')
                sol[i][j]=-2;
        }
}

void update (int i, int j, int pas) {
    if (i>0 && i<=n)
        if (j>0 && j<=n)
            if (a[i][j]=='.' && sol[i][j]==0) {
                sol[i][j]=pas;
                q.push (make_pair (i, j));
            }
}

void lee () {
    int i, j, pas;
    while (!q.empty ()) {
        i=q.front ().first;
        j=q.front ().second;
        q.pop ();
        if (sol[i][j]==-3) pas=1;
        else pas=sol[i][j]+1;
        update (i-1, j, pas);
        update (i, j+1, pas);
        update (i+1, j, pas);
        update (i, j-1, pas);
    }
}

void scrie () {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
           if (sol[i][j]==0) sol[i][j]=-1;
            else if (sol[i][j]==-3) sol[i][j]=0;
            g<<sol[i][j]<<' ';
        }
        g<<'\n';
    }
}

int main () {
    citeste ();
    lee ();
    scrie ();
    return 0;
}
