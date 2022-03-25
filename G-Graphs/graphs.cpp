#include<bits/stdc++.h>

using namespace std;

pair<double, double> addition(double a, double b, double c, double d) {
    double real, imaginary;
    real = a + c;
    imaginary = b + d;
    return {real, imaginary};
}

pair<double, double> subtraction(double a, double b, double c, double d) {
    double real, imaginary;
    real = a - c;
    imaginary = b - d;
    return {real, imaginary};

}

pair<double, double> multiplication(double a, double b, double c, double d) {
    double real, imaginary;
    real = a * c - b * d;
    imaginary = a * d + b * c;
    return {real, imaginary};
}

pair<double, double> division(double a, double b, double c, double d) {
    double real, imaginary, denominator;
    denominator = c * c + d * d;
    real = multiplication(a, b, c, -d).first;
    imaginary = multiplication(a, b, c, -d).second;
    return {real / denominator, imaginary / denominator};
}

bool valid(string &str) {
    regex valid(
            "[(][\\-]?[0-9]+(\\.[0-9]+)?[\\+\\-][\\-]?[0-9]+(\\.[0-9]+)?[i][)][\\s][\\+\\-\\*\\/][\\s][(][\\-]?[0-9]+(\\.[0-9]+)?[\\+\\-][\\-]?[0-9]+(\\.[0-9]+)?[i][)]");
    return regex_match(str, valid);
}

int main() {
    while (true) {
        double a, b, c, d;
        char op;
        cout << "Enter the expression in the following form\n(a+bi) + (c+di)\n";
        while (true) {
            string exp;
            cin.clear(), cin.sync();
            while (exp.empty())getline(cin, exp);
            if (valid(exp)) {
                string first_number = exp.substr(1, exp.find(')') - 2), second_number = exp.substr(exp.rfind('(') + 1,
                                                                                                   exp.rfind(')') - 2);
                string real1, imaginary1;
                int i = 1;
                for (; i < first_number.size(); i++) {
                    if (first_number[i] == '+' || first_number[i] == '-')break;
                    real1 += first_number[i];
                }
                real1 = first_number[0] + real1;
                imaginary1 = first_number.substr(i + 1, first_number.size() - 1);
                a = stof(real1), b = stof(imaginary1);
                if (first_number[i] == '-') {
                    b = -b;
                }
                string real2, imaginary2;
                i = 1;
                for (; i < second_number.size(); i++) {
                    if (second_number[i] == '+' || second_number[i] == '-')break;
                    real2 += second_number[i];
                }
                real2 = second_number[0] + real2;
                imaginary2 = second_number.substr(i + 1, second_number.size() - 1);
                c = stof(real2), d = stof(imaginary2);
                if (second_number[i] == '-') {
                    d = -d;
                }
                for (int j = 0; j < exp.size(); ++j) {
                    if ((exp[j] == '+' || exp[j] == '-' || exp[j] == '*' || exp[j] == '/') && j > exp.find(')')) {
                        op = exp[j];
                        break;
                    }
                }
                break;
            }
            cout << "Enter the expression in the following form\n(a+bi) + (c+di)\n";
        }
        cout << "\n= ";
        if (op == '+') {
            cout << "(" << addition(a, b, c, d).first << ((addition(a, b, c, d).second >= 0) ? "+" : "")
                 << addition(a, b, c, d).second << "i)";
        } else if (op == '-') {
            cout << "(" << subtraction(a, b, c, d).first << ((subtraction(a, b, c, d).second >= 0) ? "+" : "")
                 << subtraction(a, b, c, d).second << "i)";
        } else if (op == '*') {
            cout << "(" << multiplication(a, b, c, d).first << ((multiplication(a, b, c, d).second >= 0) ? "+" : "")
                 << multiplication(a, b, c, d).second << "i)";
        } else {
            cout << "(" << division(a, b, c, d).first << ((division(a, b, c, d).second >= 0) ? "+" : "")
                 << division(a, b, c, d).second << "i)";
        }
        char option;
        cout << "\nWould you like to continue or not ('n','y'):\n";
        cin >> option;
        while (cin.fail() || (option != 'n' && option != 'y')) {
            cin.clear();
            cin.sync();
            cout << "Would you like to continue or not ('n','y'):\n";
            cin >> option;
        }
        if (option == 'n') {
            cout << "\nThanks or using FCAI Complex Number Calculator.";
            return 0;
        }
    }
}
