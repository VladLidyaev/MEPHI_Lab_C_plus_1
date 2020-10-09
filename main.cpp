#include <iostream>
#include "Tools.h"
using namespace Tools;

int main() {
    setlocale(LC_ALL,"rus");
    Element* OurElements = 0;
    int ContOrNo = 0;
    int ElementAmount = 0;
    int m;
    int n;

    bool cond = false;
    do {
        std::cout << "Введите количество строк: ";
        std::cin >> m;
        std::cout << "Введите количество столбцов: ";
        std::cin >> n;
        if ((m > 0)&&(n > 0)){
            cond = true;
        }
    } while (cond == false);

    do{
        OurElements = AddStruct(OurElements, ElementAmount);
        SetData(OurElements,ElementAmount,m,n);

        ElementAmount++;

        std::cout << "Продолжить ввод данных? (1 - Да, 0 - Нет)" << std::endl;
        std::cin >> ContOrNo;
        std::cin.get();
    } while (ContOrNo != 0);

    ShowData(OurElements, ElementAmount,m,n);
    ShowVector(OurElements,ElementAmount,m,n);

    delete [] OurElements;
    return 0;
}
