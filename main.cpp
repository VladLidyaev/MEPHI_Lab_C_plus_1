#include <iostream>
#include "Tools.h"
using namespace Tools;
using namespace std;

int main() {
    setlocale(LC_ALL,"rus");
    Element* OurElements = 0;
    int ContOrNo = 0;
    int ElementAmount = 0;
    int m;
    int n;

    bool cond = false;
    do {
        cout << "Введите количество строк: ";
        cin >> m;
        cout << "Введите количество столбцов: ";
        cin >> n;
        if ((m > 0)&&(n > 0)){
            m =m/1;
            n=n/1;
            cond = true;
        } else{
            cout << "Некорреткные данные. Повторите ввод" << endl;
        }
    } while (cond == false);

    do{
        OurElements = AddStruct(OurElements, ElementAmount);
        SetData(OurElements,ElementAmount,m,n);

        ElementAmount++;

        cout << "Продолжить ввод данных? (1 - Да, 0 - Нет)" << endl;
        cin >> ContOrNo;
        cin.get();
    } while (ContOrNo != 0);

    ShowData(OurElements, ElementAmount,m,n);
    ShowVector(OurElements,ElementAmount,m,n);

    delete [] OurElements;
    return 0;
}
