#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//Variables globales
int gsize2;
int S = 0;
int D = 0;
int available = 0;

#include "Objects.hpp"
using namespace std;

void clear_screen(char fill = ' ') { 
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void moveFigure(){
    char moveOption;
    cin >> moveOption;
    cout << endl;

    if(moveOption == 'A' || moveOption == 'a'){
        if(D!=0){
            D--;
        }
    }

    if(moveOption == 'W' || moveOption == 'w'){
        if(S!=0){
            S--;
        }
    }

    if(moveOption == 'S' || moveOption == 's'){
        S++;
    }

    if(moveOption == 'D' || moveOption == 'd'){
        D++;
    }
}

void drawSquare(int a, int b){
    int size, full;

    if(available==0){
        cout << "What size is the Square: ";
        cin >> a;
        cout << "Is the Square Full: " << endl << "0)No  1)Yes" << endl;
        cin >> b;
        size = a;
        full = b;
        clear_screen();
    }

    Figure *vector1[50];
    vector1[available] = new Square(size, full, 1);
    vector1[available] -> figureSetter(size ,full);
    vector1[available] -> draw(1);
    available++;
}

void drawTriangle(int a, int b){
    int size, full;

    if(available==0){
        cout << "What size is the Triangle: ";
        cin >> a;
        cout << "Is the Triangle Full: " << endl << "0)No  1)Yes" << endl;
        cin >> b;
        size = a;
        full = b;
        clear_screen();
    }

    Figure *vector2[50];
    vector2[available] = new Triangle(size, full, 2);
    vector2[available] -> figureSetter(size ,full);
    vector2[available] -> draw(2);
    available++;
}

void drawRectangle(int a, int b, int c){
    int size, full, size2;

    if(available==0){
        cout << "What first size of the Rectangle: ";
        cin >> a;
        cout << "What second size of the Rectangle: ";
        cin >> b;
        cout << "Is the Rectangle Full: " << endl << "0)No  1)Yes" << endl;
        cin >> c;
        size = a;
        full = c;
        size2 = b;
        gsize2 = b;
        clear_screen();
    }

    Figure *vector3[50];
    vector3[available] = new Rec(size, full, size2, 3);
    vector3[available] -> figureSetter(size ,full);
    vector3[available] -> draw(3);
    available++;
}

void menu(){
    int op, size, full, size2;

    cout << "What figure do u want to draw: " << endl << "-------------------------" << endl;
    cout << "1.- Square" << endl << "2.- Triangle" << endl << "3.- Rectangle" << endl;
    cin >> op;

    while (op<1 || op>3){
        cout << "Thats not an option, please select one of the above" << endl;
        cin >> op;
    }

    switch (op){
        case 1:{
            while(1){
                drawSquare(size, full);
                moveFigure();
                clear_screen();
            } 
        }break;
    
        case 2:{
            while(1){
                drawTriangle(size, full);
                moveFigure();
                clear_screen();
            }
        }break;
    
        case 3:{
            while(1){
                drawRectangle(size, full, size2);
                moveFigure();
                clear_screen();
            }
        }break;
    }
}

int main(){
    menu();
}