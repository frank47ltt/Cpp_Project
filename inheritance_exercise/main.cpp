#include <iostream>
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;



int main () {
    Rectangle r;
    Triangle t;
    Polygon poly;
    Polygon * ppoly1 = &r;
    Polygon * ppoly2 = &t;
    Polygon * ppoly3 = &poly;
    ppoly1->set_values (4,5);
    ppoly2->set_values (4,5);
    ppoly3->set_values (4,5);
    cout << ppoly1->area() << '\n';
    cout << ppoly2->area() << '\n';
    cout << ppoly3->area() << '\n';
    return 0;
}