#include "matrix.hh"
#include <iostream>
#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>






/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
                if(i==j)
                {
                    value[i][j]=1;
                }
                else
                {
                    value[i][j] = 0;
                }
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator * (Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}


/*-------------------------------------------------------------------------------------------------------     
|                                                                                                        |
|        Obliczanie sinusa oraz cosinusa zadanego do obrotu kata i wpisanie tych wartosci do macierzy,   |
|          ktora wykorzystamy w mainie przed uzyciem metody rotacji w pliku naglowkowym rectangle.cpp    | 
|                                                                                                        |
|--------------------------------------------------------------------------------------------------------*/

Matrix Matrix::obliczaniesinicos(double a,Matrix &macierzsinicos)
{


    macierzsinicos(0,0)= cos(a*PI/180);
    macierzsinicos(0,1)= -sin(a*PI/180);
    macierzsinicos(1,0)= sin(a*PI/180);
    macierzsinicos(1,1)= cos(a*PI/180);



    return macierzsinicos;
}







/*-------------------------------------------------------------------------------------------------------     
|                                                                                                        |
|       Obliczanie wyznacznika metoda Gaussa, w ktorej macierz stopniowo zamieniamy na diagonalna        |   
|                                                                                                        |
|--------------------------------------------------------------------------------------------------------*/
double Matrix::wyznacznikgaussa()
{
     double ratio;
	 int i,j,k;


	 for(i=0;i<=SIZE-2;i++)
	 {
		  if(value[i][i] == 0.0)
		  {
			   std::cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(j=i+1;j<=SIZE;j++)
		  {
			   ratio = value[j][i]/value[i][i];

			   for(k=0;k<=SIZE;k++)
			   {
			  		value[j][k] = value[j][k] - ratio*value[i][k];
			   }
		  }
	 }

    for(int g=0;g<SIZE;g++)
    {
        for(int l=0;l<SIZE;l++)
        {
            std::cout << value[g][l] << " ";
        }
        std::cout << std::endl;
    }

    double wyznacznik = value[0][0];
    
    for (int h=0;h<SIZE;h++)
    {
        wyznacznik=value[h][h];
    }
    std::cout << wyznacznik ;
    return wyznacznik;
}
