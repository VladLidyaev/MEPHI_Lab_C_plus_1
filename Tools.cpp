#include <iostream>
#include "Tools.h"

namespace Tools {
    Element *AddStruct(Element *Obj, const int amount) {
        if (amount == 0) {
            Obj = new Element[amount + 1];
        } else {
            Element *tempObj = new Element[amount + 1];
            for (int i = 0; i < amount; i++) {
                tempObj[i] = Obj[i];
            }
            delete[] Obj;
            Obj = tempObj;
        }
        return Obj;
    }

    void SetData(Element *Obj, const int amount, const int m, const int n) {
        int X;
        int Y;
        int value;
        std::cout << "-----------------------" << std::endl;
        std::cout << "Введите координату X: ";
        std::cin >> X;
        std::cout << "Введите координату Y: ";
        std::cin >> Y;
        std::cout << "Введите значение элемента: ";
        std::cin >> value;
        std::cout << "-----------------------" << std::endl;
        std::cin.get();
        if ((X > n) || (Y > m)) {
            std::cout << "Некорректные данные. Повторите ввод." << std::endl;
            SetData(Obj, amount, m, n);
        } else {
            if (value != 0) {
                Obj[amount].X = X - 1;
                Obj[amount].Y = Y - 1;
                Obj[amount].value = value;
            }
        }
        std::cout << std::endl;
    }

    void ShowData(Element *Obj, const int amount, const int m, const int n) {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Исходная матрица:" << std::endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int s = 0;
                for (int k = 0; k < amount; k++) {
                    if ((Obj[k].X == j) && (Obj[k].Y == i)) {
                        s = Obj[k].value;
                    }
                }
                std::cout << s << " ";
            }
            std::cout << std::endl;
        }
    }

    bool Condition(const int value) {
        if ((value) / 10 >= 1) {
            return true;
        } else {
            return false;
        }
    }

    void ShowVector(Element *Obj, const int amount, const int m, const int n) {
        int Vector[m];
        std::cout << "-----------------------" << std::endl;
        std::cout << "Полученный вектор:" << std::endl;
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < amount; j++) {
                if ((Obj[j].Y == i) && (Condition(Obj[j].value))) {
                    sum += Obj[j].value;
                }
            }
            Vector[i] = sum;
            std::cout << Vector[i] << " ";
        }
    }
}