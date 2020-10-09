#include <iostream>
#include <cmath>
using namespace std;

struct Coord{
    float X;
    float Y;
};

class Object{
private:
    float param_a,param_b,param_c;

public:

    void SetDataParam(float new_param_a,float new_param_b,float new_param_c){
        param_a = new_param_a;
        param_b = new_param_b;
        param_c = new_param_c;
    }

    void GetData(){
        cout << "Уравнение Цепной Линии: y=a*(Cosh((x+b)/a))+c, где a=" << param_a << " ,b=" << param_b << " ,c=" << param_c << endl;
    }

    float GetOrd(float Abs){
        float val = cosh((Abs+param_b)/param_a);
        float Ord = param_a*val+param_c;
        return Ord;
    }

    float GetLen(float Abs1,float Abs2){
        if (Abs1<Abs2){
            int value = Abs1;
            Abs1 = Abs2 + param_b;
            Abs2 = value + param_b;
        } else{
            Abs1 += param_b;
            Abs2 += param_b;
        }

        float dop1 = sinh(Abs1/param_a);
        float dop2 = sinh(Abs2/param_a);
        return (param_a*(dop1-dop2)) ;
    }

    float GetRadius(float Abs){
        Abs += param_b;
        return ((GetOrd(Abs))*(GetOrd(Abs))/param_a);
    }

    Coord GetCentrCoord(float Abs){
        float Radius = GetRadius(Abs);
        float Ord = GetOrd(Abs);
        float delta_x = 0.001;
        float delta_y = Ord - GetOrd(Abs + delta_x);
        Coord point;
        point.X = (Radius/(sqrt(delta_x*delta_x +delta_y*delta_y)))*delta_y+Abs;
        point.Y = (Radius/(sqrt(delta_x*delta_x +delta_y*delta_y)))*delta_x+Ord;
        return point;
    }

    float GetSq(float Abs1, float  Abs2){
        if (Abs1<Abs2){
            int value = Abs1;
            Abs1 = Abs2 + param_b;
            Abs2 = value + param_b;
        }
        else{
            Abs1 += param_b;
            Abs2 += param_b;
        }
        float val1 = sinh(Abs1/param_a);
        float val2 = sinh(Abs2/param_a);
        return (param_a*(param_a*(val1-val2)) + (Abs1-Abs2)*param_c);
    }

};

Object ans_1(Object Line){
    float a,b,c;
    cout << "Введите параметр a (!=0) из уравнения y=a*(Cosh((x+b)/a))+c" << endl;
    cin >> a;
    cout << "Введите параметр b из уравнения y=a*(Cosh((x+b)/a))+c" << endl;
    cin >> b;
    cout << "Введите параметр c из уравнения y=a*(Cosh((x+b)/a))+c" << endl;
    cin >> c;
    Line.SetDataParam(a,b,c);
    return Line;
};

void ans_3(Object Line){
    float Abs;
    cout << "Введите абсциссу: " << endl;
    cin >> Abs;
    cout << "Значение ординаты : " << Line.GetOrd(Abs) << endl;
};

void ans_4(Object Line){
    float Abs1,Abs2;
    cout << "Введите первую абсциссу: " << endl;
    cin >> Abs1;
    cout << "Введите вторую абсциссу: " << endl;
    cin >> Abs2;
    cout << "Длина дуги кривой, ограниченная точками с введёнными абсциссами : " << Line.GetLen(Abs1,Abs2) << endl;
};

void ans_5(Object Line){
    float Abs;
    cout << "Введите абсциссу: " << endl;
    cin >> Abs;
    cout << "Радиус кривизны кривой в точке с введённой абсциссой : " << Line.GetRadius(Abs) << endl;
};

void ans_6(Object Line){
    float Abs;
    cout << "Введите абсциссу: " << endl;
    cin >> Abs;
    cout << "Кординаты центра кривизны кривой в точке с введённой абсциссой : X = " << Line.GetCentrCoord(Abs).X << " , Y = " << Line.GetCentrCoord(Abs).Y << endl;
};

void ans_7(Object Line){
    float Abs1,Abs2;
    cout << "Введите первую абсциссу: " << endl;
    cin >> Abs1;
    cout << "Введите вторую абсциссу: " << endl;
    cin >> Abs2;
    cout << "Площадь под кривой, ограниченная точками с введёнными абсциссами : " << Line.GetSq(Abs1,Abs2) << endl;
};

int main() {
    setlocale(LC_ALL,"rus");
    int Ans ;
    Object Line;
    do {
        cout << "0: Прекратить работу. \n  1: Задать параметры кривой. \n  2: Просмотр параметров кривой. \n  3: Получить ординату по значению абсциссы. \n  4: Получить длину дуги кривой, ограниченной данными абсциссами. \n  5: Получить радиус кривизны к точке с данной абсциссой. \n  6: Получить координаты центра кривизны в точке с данной абсциссой. \n  7: Получить площадь под линией между точками с данными абсциссами. " << endl;
        cin >> Ans;
        if ((Ans > 0)&&(Ans < 8)){
            cout << "============" << endl;
            switch (Ans) {
                case 1:
                    Line = ans_1(Line);
                    break;
                case 2:
                    Line.GetData();
                    break;
                case 3:
                    ans_3(Line);
                    break;
                case 4:
                    ans_4(Line);
                    break;
                case 5:
                    ans_5(Line);
                    break;
                case 6:
                    ans_6(Line);
                    break;
                case 7:
                    ans_7(Line);
                    break;
            }
            cout << "============" << endl;
        } else {
            if (Ans != 0){
                cout << "!!! Некорректный выбор. Повторите ввод." << endl;
            }
        }
    } while (Ans != 0);
    return 0;
}
