#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int LENMAX = 1000;

int brackets_cnt;
char brackets[LENMAX];

void citeste() {
    cin >> brackets;
    brackets_cnt = strlen(brackets);
}

bool parantezele_sunt_ok() {
    stack <char> stiva;

    for (int i = 0; i < brackets_cnt; i++) {
        if (brackets[i] == '(') {
            stiva.push(brackets[i]);
            continue;
        }
        if (brackets[i] != ')') return false;
        if (stiva.empty()) return false;
        stiva.pop();
    }

    return stiva.empty();
}

int main() {
    citeste();

    if (parantezele_sunt_ok()) cout << "Sirul e parantezat corect\n";
    else cout << "Sirul nu e parantezat corect\n";

    return 0;
}
