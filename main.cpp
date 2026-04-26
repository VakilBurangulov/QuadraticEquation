#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;


//Доработал программу, теперь можно ввести квадратное уравнение без пробелов и оно решиться можно даже сложное с выражениями по обе стороны от равно квадрат нужно показать как x^2
//Пример -x^2+x+3=x^2-x-3
int main() {
    string equation;
    cout << "Enter Equation:" << endl;
    getline(cin, equation);

    string firstPart, secondPart;


    {
        bool isFoundCharEquals = false;
        for (int i = 0; i < equation.length(); i++) {
            if (equation[i] == '=') {
                if (isFoundCharEquals) {
                    cout << "Invalid input";
                    return 1;
                }
                isFoundCharEquals = true;
            }
            else if (isFoundCharEquals && equation[i] != ' ') {
                secondPart += equation[i];
            }
            else if (!isFoundCharEquals && equation[i] != ' ') {
                firstPart += equation[i];
            }
        }
    }

    float a = 0, b = 0, c = 0;
    float tempCoef = 0;
    bool isPositive = true;

    if (firstPart == "0") {
        firstPart = secondPart;
        secondPart = "0";
    }

    if (secondPart == "0") {
        for (int i = 0; i < firstPart.length(); i++) {
            if (isdigit(firstPart[i]) ) {
                if (i == 0 || firstPart[i-1] != '^') {
                    tempCoef = (firstPart[i] - '0');
                    for (int j = i+1; j < firstPart.length(); j++) {
                        if (isdigit(firstPart[j])) {
                            tempCoef *= 10;
                            tempCoef += (firstPart[j] - '0');
                        }
                        else {
                            i = j;
                            break;
                        }
                    }

                    if (i + 2 <= firstPart.length() && firstPart[i] == 'x' && firstPart[i+1] == '^') {
                        a = (isPositive) ? +tempCoef : -tempCoef;
                    }
                    else if (i + 1 <= firstPart.length() && firstPart[i] == 'x') {
                        b = (isPositive) ? +tempCoef : -tempCoef;
                    }
                    else {
                        c = (isPositive) ? +tempCoef : -tempCoef;
                    }
                }
            }

            if (firstPart[i] == '+') {
                isPositive = true;
            }
            else if (firstPart[i] == '-') {
                isPositive = false;
            }
            else if (i+1 != firstPart.length() && firstPart[i] == 'x' && firstPart[i+1] == '^') {
                if (i != 0 && firstPart[i-1] == '-') {
                    a--;
                }
                else if (i == 0 || firstPart[i-1] == '+') {
                    a++;
                }
            }
            else if (firstPart[i] == 'x') {
                if (i != 0 && firstPart[i-1] == '-') {
                    b--;
                }
                else if (i == 0 || firstPart[i-1] == '+') {
                    b++;
                }
            }
        }
    }
    else {
        float a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0;

        for (int i = 0; i < firstPart.length(); i++) {
            if (isdigit(firstPart[i]) ) {
                if (i == 0 || firstPart[i-1] != '^') {
                    tempCoef = (firstPart[i] - '0');
                    for (int j = i+1; j < firstPart.length(); j++) {
                        if (isdigit(firstPart[j])) {
                            tempCoef *= 10;
                            tempCoef += (firstPart[j] - '0');
                        }
                        else {
                            i = j;
                            break;
                        }
                    }

                    if (i + 2 <= firstPart.length() && firstPart[i] == 'x' && firstPart[i+1] == '^') {
                        a1 = (isPositive) ? +tempCoef : -tempCoef;
                    }
                    else if (i + 1 <= firstPart.length() && firstPart[i] == 'x') {
                        b1 = (isPositive) ? +tempCoef : -tempCoef;
                    }
                    else {
                        c1 = (isPositive) ? +tempCoef : -tempCoef;
                    }
                }
            }

            if (firstPart[i] == '+') {
                isPositive = true;

            }
            else if (firstPart[i] == '-') {
                isPositive = false;
            }
            else if (i+1 != firstPart.length() && firstPart[i] == 'x' && firstPart[i+1] == '^') {
                if (i != 0 && firstPart[i-1] == '-') {
                    a1--;
                }
                else if (i == 0 || firstPart[i-1] == '+') {
                    a1++;
                }
            }
            else if (firstPart[i] == 'x') {
                if (i != 0 && firstPart[i-1] == '-') {
                    b1--;
                }
                else if (i == 0 || firstPart[i-1] == '+') {
                    b1++;
                }
            }
        }

        for (int i = 0; i < secondPart.length(); i++) {
            if (isdigit(secondPart[i]) ) {
                if (i == 0 || secondPart[i-1] != '^') {
                    tempCoef = (secondPart[i] - '0');
                    for (int j = i+1; j < secondPart.length(); j++) {
                        if (isdigit(secondPart[j])) {
                            tempCoef *= 10;
                            tempCoef += (secondPart[j] - '0');
                        }
                        else {
                            i = j;
                            break;
                        }
                    }

                    if (i + 2 <= secondPart.length() && secondPart[i] == 'x' && secondPart[i+1] == '^') {
                        a2 = (isPositive) ? +tempCoef : -tempCoef;
                    }
                    else if (i + 1 <= secondPart.length() && secondPart[i] == 'x') {
                        b2 = (isPositive) ? +tempCoef : -tempCoef;
                    }
                    else {
                        c2 = (isPositive) ? +tempCoef : -tempCoef;
                    }
                }
            }

            if (secondPart[i] == '+') {
                isPositive = true;

            }
            else if (secondPart[i] == '-') {
                isPositive = false;
            }
            else if (i+1 != secondPart.length() && secondPart[i] == 'x' && secondPart[i+1] == '^') {
                if (i != 0 && secondPart[i-1] == '-') {
                    a2--;
                }
                else if (i == 0 || secondPart[i-1] == '+') {
                    a2++;
                }
            }
            else if (secondPart[i] == 'x') {
                if (i != 0 && secondPart[i-1] == '-') {
                    b2--;
                }
                else if (i == 0 || secondPart[i-1] == '+') {
                    b2++;
                }
            }
        }

        a = a1 - a2;
        b = b1 - b2;
        c = c1 - c2;
    }

    if (a == 0) //Не правильно определено условие для проверки a
    {
        float x = -c / b;
        cout << "Root: " << x << endl;
    } else if (a + c == b) { // Добавил проверку теоремы окожфициентах для возможного ускорения хода программы
        float x1 = -1.;
        float x2 = -c / a;
        if (x1 == x2) {
            cout << "Root: " << x1 << endl;
        } else {
            cout  << "Root 1, 2: " << x1 << ", " << x2 << endl;
        }

    } else if (a + b + c == 0) {
        float x1 = 1.;
        float x2 = c / a;
        if (x1 == x2) {
            cout << "Root: " << x1 << endl;
        } else {
            cout  << "Root 1, 2: " << x1 << ", " << x2 << endl;
        }
    } else { // Не нужное условие b > 0
        float discriminant = b*b - 4 * a * c;//Ошибка в формуле
        //Ненужный return
        if (discriminant > 0) //Ошибка в условии discriminant > 1, хот ядолжно быть больще 0
        {
            float x1 = (-b + sqrt(discriminant)) / (2  * a); // Ошибка в написании discriminant
            float x2 = (-b - sqrt(discriminant)) / (2 * a); //Вместо точки с запятой просто запятая + ошибка в написании discriminant + ошибка в формуле
            cout  << "Root 1, 2: " << x1 << ", " << x2 << endl;// два раза использован x1
        }
        else if (discriminant == 0)
        {
            float x = -b / (2 * a); //Неверная формула для определения единственного корня
            cout << "Root: " << x << endl;//Выводиться не x а дискриминант
        }
        else
        {
            cout << "Complex scenario is not supported!" << endl;
        }
    }
}