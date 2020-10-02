#include <iostream>
using namespace std;

struct Element{
    int X;
    int Y;
    int value;
    bool condition1;
};


Element* AddStruct(Element* Obj,const int amount);
void SetData(Element* Obj,const int amount,const int m,const int n);
void ShowData(Element* Obj,const int amount,const int m,const int n);
void ShowVector(Element* Obj,const int amount,const int m,const int n);
void ChekingForACondition(Element* Obj,const int amount,const int m,const int n);

int main() {
    setlocale(LC_ALL,"rus");
    Element* OurElements = 0;
    int ContOrNo = 0;
    int ElementAmount = 0;
    int m;
    int n;

    cout << "Введите количество строк: ";
    cin >> m;
    cout << "Введите количество столбцов: ";
    cin >> n;

    do{
        OurElements = AddStruct(OurElements, ElementAmount);
        SetData(OurElements,ElementAmount,m,n);

        ElementAmount++;

        cout << "Продолжить ввод данных? (1 - Да, 0 - Нет)" << endl;
        cin >> ContOrNo;
        cin.get();
    } while (ContOrNo != 0);

    ShowData(OurElements, ElementAmount,m,n);
    ChekingForACondition(OurElements,ElementAmount,m,n);
    ShowVector(OurElements,ElementAmount,m,n);

    delete [] OurElements;
    return 0;
}

Element* AddStruct(Element* Obj,const int amount){
    if (amount == 0){
        Obj = new Element[amount+1];
    } else {
        Element* tempObj = new Element[amount+1];
        for (int i=0; i<amount; i++){
            tempObj[i] = Obj[i];
        }
        delete [] Obj;
        Obj = tempObj;
    }
    return Obj;
}

void SetData(Element* Obj,const int amount,const int m,const int n){
    int X;
    int Y;
    int value;
    cout << "-----------------------" << endl;
    cout << "Введите координату X: ";
    cin >> X;
    cout << "Введите координату Y: ";
    cin >> Y;
    cout << "Введите значение элемента: ";
    cin >> value;
    cout << "-----------------------" << endl;
    cin.get();
    if ((X>n)||(Y>m)){
        cout << "Некорректные данные. Повторите ввод." << endl;
        SetData(Obj,amount,m,n);
    } else{
        if(value!=0){
            Obj[amount].X = X-1;
            Obj[amount].Y = Y-1;
            Obj[amount].value = value;
        }
    }
    cout << endl;
}


void ShowData(Element* Obj,const int amount,const int m,const int n){
    cout << "-----------------------" << endl;
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i<m;i++){
        for (int j = 0; j<n; j++){
            int s = 0;
            for (int k=0;k<amount;k++){
                if ((Obj[k].X == j)&&(Obj[k].Y == i)){
                    s = Obj[k].value;
                }
            }
            cout << s << " ";
        }
        cout << endl;
    }
}

void ChekingForACondition(Element* Obj,const int amount,const int m,const int n){
    for (int i=0; i<amount; i++){
        if (Obj[i].value/10 > 0){
            Obj[i].condition1 = true;
        } else{
            Obj[i].condition1 = false;
        }
    }
}

void ShowVector(Element* Obj,const int amount,const int m,const int n){
    int Vector[m];
    cout << "-----------------------" << endl;
    cout << "Полученный вектор:" << endl;
    for (int i=0; i<m;i++){
        int sum = 0;
        for (int j=0; j<amount;j++){
            if ((Obj[j].Y==i)&&(Obj[j].condition1 == true)){
                sum += Obj[j].value;
            }
        }
        Vector[i] = sum;
        cout << Vector[i] << " ";
    }
}