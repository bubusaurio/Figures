#include <iostream>
using namespace std;

class Figure{
    private: //Atributtes
        int size;
        int full;
    public: //Metods
        Figure(int, int); //Constructor
        void showProperties();
        void figureSetter(int, int);
        int getSize();
        int getFull();
        virtual void draw(int);
};

//Constructor, Initialize atributtes
Figure::Figure(int _size, int _full){
    size = _size;
    full = _full;
}

//Setter
void Figure::figureSetter(int a, int b){
    size = a;
    full = b;
}

//Getters
int Figure::getSize(){
    return size;
}

int Figure::getFull(){
    return full;
}

void Figure::showProperties(){
    cout << "The size is: " << size << endl;
    cout << "Is it full: " << full << endl;
}

void Figure::draw(int figureType){
    int j, i, counterS, counterD;

    if (figureType == 1){
        for(counterS = 0; counterS<S; counterS++){
            cout << endl;
        }
        if(full == 0){
            for (size_t i = 0; i<size; i++){
                for(counterD = 0; counterD<D; counterD++){
                    cout << "  ";
                }
                for (size_t j = 0; j<size; j++){
                    if(i == 0 || i == (size-1) || j == 0 || j == (size-1)){
                        cout << "* ";
                    }
                    else{
                        cout << "  ";
                    }
                }
                cout << endl;
            }
        }
        else{
            for (size_t i = 0; i<size; i++){
                for(counterD = 0; counterD<D; counterD++){
                    cout << "  ";
                }
                for (size_t j = 0; j<size; j++){
                    cout << "* ";
                }
                cout << endl;
            }
        }
    }

    if (figureType == 2){
        for(counterS = 0; counterS<S; counterS++){
            cout << endl;
        }
        if(full == 0){
            for(size_t i = 0; i<size; i++){
                for(counterD = 0; counterD<D; counterD++){
                    cout << "  ";
                }
                for(size_t j = 0; j<(size-(size-i)); j++){
                    if(i == 0 || i == (size-1) || j == 0 || j == ((size-(size-i))-1)){
                        cout << "* ";
                    }
                    else{
                        cout << "  ";
                    }
                }
                cout << endl;
            } 
        }
        else{
            for(size_t i = 0; i<size; i++){
                for(counterD = 0; counterD<D; counterD++){
                    cout << "  ";
                }
                for(size_t j = 0; j<(size-(size-i)); j++){
                    cout << "* ";
                }
                cout << endl;
            }   
        }
          
    }

    if (figureType == 3){
        for(counterS = 0; counterS<S; counterS++){
            cout << endl;
        }
        if(full == 0){
            for (size_t i = 0; i<size; i++){
                for(counterD = 0; counterD<D; counterD++){
                    cout << "  ";
                }
                for (size_t j = 0; j<gsize2; j++){
                    if(i == 0 || i == (size-1) || j == 0 || j == (gsize2-1)){
                        cout << "* ";
                    }
                    else{
                        cout << "  ";
                    }
                }
                cout << endl;
            }
        }
        else{
            for (size_t i = 0; i<size; i++){
                for(counterD = 0; counterD<D; counterD++){
                    cout << "  ";
                }
                for (size_t j = 0; j<gsize2; j++){
                    cout << "* ";
                }
                cout << endl;
            }
        }
    }
}

class Square : public Figure{
    private:
        int type;
    public:
        Square(int, int, int);
        int getType();
        void draw();
};

Square::Square(int _size, int _full, int _type) : Figure(_size, _full){
    _type = 1;
    type = _type;
}

int Square::getType(){
    return type;
}

void Square::draw(){
    Figure::draw(getType());
}

class Triangle : public Figure{
    private:
        int type;
    public:
        Triangle(int, int, int);
        int getType();
        void draw();
};

Triangle::Triangle(int _size, int _full, int _type) : Figure(_size, _full){
    _type = 2;
    type = _type;
}

int Triangle::getType(){
    return type;
}

void Triangle::draw(){
    Figure::draw(getType());
}

class Rec : public Figure{
    private:
        int type;
        int size2;
    public:
        Rec(int, int, int, int);
        int getType();
        int getSize2();
        int setSize2(int);
        void draw();
};

Rec::Rec(int _size, int _full, int _size2, int _type) : Figure(_size, _full){
    _type = 2;
    type = _type;
    size2 = _size2;
}

int Rec::getType(){
    return type;
}

void Rec::draw(){
    Figure::draw(getType());
}



