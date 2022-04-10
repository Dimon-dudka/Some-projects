#include <iostream>
#include<string>
#include<vector>
#include<deque>

using namespace std;

bool NeedBrackets(char last, char current);

struct Making {
    int numer=0;
    char symbol=0;
};

int main() {
    
    int num(0), kol(0);
    cin >> num>>kol;

    vector<Making> operations(kol);
    for (int i = 0; i < kol; i++) {
        cin >> operations[i].symbol >> operations[i].numer;
    }

    deque<string> expression;
    expression.push_back(to_string(num));

    char last_type = '*';

    for (const auto& operation : operations) {
        if (NeedBrackets(last_type, operation.symbol)) {
            expression.push_front("(");
            expression.push_back(")");
        }
        expression.push_back(" ");
        expression.push_back(string(1, operation.symbol));
        expression.push_back(" ");
        expression.push_back(to_string(operation.numer));

        last_type = operation.symbol;
    }

    for (const string& s : expression) {
        cout << s;
    }

    return 0;
}

bool NeedBrackets(char last, char current) {
    return (last == '+' || last == '-') && (current == '*' || current == '/');
}