#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>

#define PI 3.14159265


class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector operator * (Vector tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;

    Matrix obliczaniesinicos(double a,Matrix &macierzsinicos);
};


std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);