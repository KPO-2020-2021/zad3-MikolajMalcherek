#include "rectangle.hh"
#include "size.hh"
#include <stdio.h>
#include <cmath>
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include "matrix.hh"








/******************************************************************************
 |  Konstruktor klasy rectangle.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
rectangle::rectangle() {
    double tab[2]={0,0};


    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
                    wierzcholki[i][j]=tab;

        }
    }
}





Vector &rectangle::operator () (int row, int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return wierzcholki[row][column];
}


/******************************************************************************
 |  Funktor prostokata                                                         |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc prostokata w danym miejscu tablicy jako stala.                  |
 */
const Vector &rectangle::operator () ( int row, int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return wierzcholki[row][column];
}



/*
std::istream &operator>>(std::istream &in, rectangle &rec){
     for (int i=0 ; i<SIZE ; i++){
        for(int j=0; j<SIZE ; j++){
            in>>rec.
        }
     }

}*/

std::ostream &operator<<(std::ostream &out, rectangle const &rec){

    for (int i=0 ; i<SIZE ; i++){
        for(int j=0; j<SIZE ; j++){
            out << rec(i,j);
        }
    }
    std::cout<<std::endl;

    return out;

}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
rectangle rectangle::operator + (Vector tmp) {
    rectangle result;
    for (int i = 0; i < SIZE*SIZE; ++i) {
        for (int j = 0; j < SIZE*SIZE; ++j) {
            result(i, j) = wierzcholki[i][j] + tmp;
        }
    }
    return result;
}


rectangle rectangle::rotacja(Matrix macierzsinicos, rectangle& prostokat)
{   




    prostokat(0,0)=macierzsinicos * prostokat(0,0);
    prostokat(0,1)=macierzsinicos * prostokat(0,1);
    prostokat(1,0)=macierzsinicos * prostokat(1,0);
    prostokat(1,1)=macierzsinicos * prostokat(1,1);
    return prostokat;
}


rectangle rectangle::przesuniecie(Vector wektor_przes, rectangle& prostokat)
{
    prostokat(0,0)=prostokat(0,0)+wektor_przes;
    prostokat(0,1)=prostokat(0,1)+wektor_przes;
    prostokat(1,0)=prostokat(1,0)+wektor_przes;
    prostokat(1,1)=prostokat(1,1)+wektor_przes;
    return prostokat;

}