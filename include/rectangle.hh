#include "size.hh"
#include <stdio.h>
#include <cmath>
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include "matrix.hh"

class rectangle{
    private:
        Vector wierzcholki[SIZE][SIZE];
    public:
    rectangle(Vector [SIZE][SIZE]);

    rectangle();


    rectangle operator + (Vector tmp);


    const Vector &operator () ( int row,  int column) const;

    Vector &operator () (int row,  int column);

    rectangle rotacja(Matrix macierzsinicos, rectangle& prostokat);

    rectangle przesuniecie(Vector wektor_przes, rectangle& prostokat);
};


std::istream &operator>>(std::istream &in, rectangle &mat);

std::ostream &operator<<(std::ostream &out, rectangle const &mat);


