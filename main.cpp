#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  float a, b, c;
  cout << "a, b, c:" << endl;//Не добавлен endl
  cin >> a >> b >> c; //Отсутствовал ввод коэффициента c
  if (a == 0) //Не правильно определено условие для проверки a
  {
    cout << "Not a quadratic equation!" << endl;
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