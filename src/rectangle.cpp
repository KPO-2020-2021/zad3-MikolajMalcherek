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
rectangle::rectangle()
{
    double tab[2] = {0, 0};

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            wierzcholki[i][j] = tab;
        }
    }
}


rectangle::rectangle(Vector zmienna[SIZE][SIZE])
{
    rectangle prostokat;
    
        for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            wierzcholki[i][j] = zmienna[i][j];
        }
    }
}


Vector &rectangle::operator()(int row, int column)
{

    if (row >= SIZE)
    {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        throw "Error: Macierz jest poza zasiegiem";
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
const Vector &rectangle::operator()(int row, int column) const
{

    if (row >= SIZE)
    {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        throw  "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return wierzcholki[row][column];
}

void rectangle::check_length()
{
   double b1=wierzcholki[0][0].length(wierzcholki[0][1]);
    double b2=wierzcholki[1][0].length(wierzcholki[1][1]);

     double b3=wierzcholki[0][0].length(wierzcholki[1][0]);
    double b4=wierzcholki[0][1].length(wierzcholki[1][1]);

    if(b1==b2)
    {
            std::cout<<"sa rowne"<<std::endl;
    }
    else
    {
            std::cout<<"nie sa rowne"<<std::endl;
    }
    std::cout<<b1<<std::endl;
    std::cout<<b2<<std::endl;
        if(b3==b4)
    {
            std::cout<<"sa rowne"<<std::endl;
    }
    else
    {
            std::cout<<"nie sa rowne"<<std::endl;
    }
    std::cout<<b3<<std::endl;
    std::cout<<b4<<std::endl;
    
}
/*
std::istream &operator>>(std::istream &in, rectangle &rec){
     for (int i=0 ; i<SIZE ; i++){
        for(int j=0; j<SIZE ; j++){
            in>>rec.
        }
     }

}*/

std::ostream &operator<<(std::ostream &out, rectangle const &rec)
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            out << rec(i, j) << std::endl;
        }
    }
 

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
rectangle rectangle::operator+(Vector tmp)
{
    rectangle result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result(i, j) = this->wierzcholki[i][j] + tmp;
        }
    }
    return result;
}



/*------------------------------------------------------------| 
|                                                             |
|   Metoda rotacji prostokata o macierz sinusow i cosinusow   |
|                                                             |
|-------------------------------------------------------------*/
rectangle rectangle::rotacja(Matrix macierzsinicos)
{

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            wierzcholki[i][j] = macierzsinicos * wierzcholki[i][j];
        }
    }

    return *this;
}






/*------------------------------------------------------------| 
|                                                             |
|         Metoda przesuniecia prostokatu o dany wektor        |
|                                                             |
|-------------------------------------------------------------*/
rectangle rectangle::przesuniecie(Vector wektor_przes)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE ; ++j)
        {
            wierzcholki[i][j] = wierzcholki[i][j] + wektor_przes ;

        
        }
    }

    return *this;
}

