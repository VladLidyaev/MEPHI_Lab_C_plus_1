namespace Tools{

    struct Element{
        int X;
        int Y;
        int value;
    };

    Element* AddStruct(Element* Obj,const int amount);
    void SetData(Element* Obj,const int amount,const int m,const int n);
    void ShowData(Element* Obj,const int amount,const int m,const int n);
    bool Condition(const int value);
    void ShowVector(Element* Obj,const int amount,const int m,const int n);

}