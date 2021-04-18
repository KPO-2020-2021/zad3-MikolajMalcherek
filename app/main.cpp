// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "../include/lacze_do_gnuplota.hh"
#include "rectangle.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150

#define PI 3.14159265


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

rectangle prostokat;


void PrzykladZapisuWspolrzednychDoStrumienia( std::ostream& StrmWy, rectangle prostokat)
{




   //---------------------------------------------------------------
   // To tylko przyklad !!!
   // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych 
   // zmiennych do reprezentowania wspolrzednych!
   //
  /*double  x1, y1, x2, y2, x3, y3, x4, y4; 

  x1 = y1 = 10;
  x2 = x1 + DL_DLUGI_BOK;  y2 = y1;
  x3 = x2;  y3 = y2 + DL_KROTKI_BOK;
  x4 = x3 - DL_DLUGI_BOK; y4 = y3;*/






       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << prostokat(0,0) << std::endl;
       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << prostokat(0,1) << std::endl;
       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << prostokat(1,0) << std::endl;
       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << prostokat(1,1) << std::endl;
       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << prostokat(0,0) << std::endl;
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku(const char  *sNazwaPliku, rectangle prostokat)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, prostokat);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;
  // std::system("cat ../LICENSE");
  // do zadania Rotacja 2D






std::cout << "o - obrot prostokata o zadany kat" << std::endl;
std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
std::cout << "m - wyswietl menu" << std::endl;
std::cout << "u - wyswietl prostokat" << std::endl;
std::cout << "k - koniec dzialania programu" << std::endl;








rectangle prostokat;
double wie1[]={20.0, 20.0};
double wie2[]={300.0, 20.0};
double wie3[]={300.0, 200.0};
double wie4[]={20.0, 200.0};
prostokat(0,0)=Vector(wie1);
prostokat(0,1)=Vector(wie2);
prostokat(1,0)=Vector(wie3);
prostokat(1,1)=Vector(wie4);





/*
  std::cout << "Prostokat:" << std::endl;
  rectangle prost1=rectangle();
  std::cout << "Prostokat - konstruktor bezparametryczny:\n" << tmpM1 << std::endl;
  rectangle argumentsM() = tmpV2;
  Matrix tmpM2 = Matrix(argumentsM);
  std::cout << "Matrix - konstruktor parametryczny:\n" << tmpM2 << std::endl;
*/
    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);




Matrix macierzsinicos;
double kat;
int ileobrotow;
char wybor;
Vector wektor_przes;
while(1){
       std::cout << "Podaj opcje dzialania:" << std::endl;
       std::cin >> wybor;
switch(wybor)
{
       case 'o':
              std::cout << "Podaj wartosc kata:" << std::endl;
              std::cin >> kat;
              std::cout << sin(kat*PI/180) << std::endl;

              std::cout << "Ile razy ma byc wykonany obrot?" << std::endl;
              std::cin >> ileobrotow;
              
              for(int i = 0 ; i<ileobrotow ; i++)
              {
              macierzsinicos.obliczaniesinicos(kat,macierzsinicos);
              std::cout << "Macierz: " << std::endl;
              std::cout << macierzsinicos;


              

              prostokat.rotacja(macierzsinicos,prostokat);

              std::cout << prostokat;

              }



              break;
       case 'p':     
                     std::cout << "Podaj wartosci wektora(np. 1-enter 1-enter):" << std::endl;
                     std::cin >> wektor_przes;
                     prostokat.przesuniecie(wektor_przes, prostokat);
              break;
       case 'w':
                     std::cout << "Wierzcholki:" << prostokat << std::endl;
              break;
       case 'm':
                     std::cout << "o - obrot prostokata o zadany kat" << std::endl;
                     std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
                     std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
                     std::cout << "m - wyswietl menu" << std::endl;
                     std::cout << "u - wyswietl prostokat" << std::endl;
                     std::cout << "k - koniec dzialania programu" << std::endl;
                     
              break;
       case 'k':
              return 0;
              break;
       case 'u':
              PrzykladZapisuWspolrzednychDoStrumienia(std::cout,prostokat);
  if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat",prostokat)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');
   //----------------------------------------------------------
   // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
   //

       
       default:
              break;

}
}




  // Z bazy projektu-wydmuszki Boiler Plate C++:
  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.


  /*Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;*/



}



