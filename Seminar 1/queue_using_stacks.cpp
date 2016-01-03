#include <iostream>
#include <stack>

using namespace std;

int stiva_curenta;
stack <int> stiva[2];

void push(int x) {
    stiva[0].push(x);
    cout << "Elementul " << x << " a fost adaugat in coada.\n";
}

void pop() {
    if (stiva[0].empty()) {
        cout << "Stiva este goala\n";
        return;
    }

    while(!stiva[0].empty()) {
        stiva[1].push(stiva[0].top());
        stiva[0].pop();
    }

    cout << "Elementul " << stiva[1].top() << " a fost scos din coada\n";

    stiva[1].pop();
    while(!stiva[1].empty()) {
        stiva[0].push(stiva[1].top());
        stiva[1].pop();
    }
}


int main() {
    int operatie, x;

    cout << "1 x = introduce elementul x in coada\n2 = scoate un element din coada\n";

    while(cin >> operatie) {
        if (operatie == 1) {
            cin >> x;
            push(x);
        }
        else pop();
    }
}
