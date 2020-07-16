//
// Created by sarra on 11/6/2019.
//

#ifndef INHERTANCE2_POLYGON_H
#define INHERTANCE2_POLYGON_H


class Polygon {
public:
    void set_values (int a, int b);
    virtual int area ();
protected:
    int width, height;
};




#endif //INHERTANCE2_POLYGON_H
