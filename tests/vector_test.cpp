
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "size.hh"
#include <stdio.h>


TEST_CASE("vector - konstruktor bezparametryczny Vector()")
{
  Vector test = Vector();
  for(int i=0;i<SIZE;i++){
  CHECK(test[i]==0);
  }
}

TEST_CASE("vector - konstruktor parametryczny wektora")
{
  double zmienna[]={5,7};
  Vector test = Vector(zmienna);

  for(int i=0; i<SIZE; i++){
  CHECK(test[i]==zmienna[i]);
  }

}


TEST_CASE("vector - operator +")
{
  double zmienna[]={5,7};
  Vector test = Vector(zmienna);

  double zmienna2[]={8,9};
  Vector test2 = Vector(zmienna2);

  Vector wynik=test+test2;

  double tab_odpowiedz[]={13,16};
  Vector odpowiedz=Vector(tab_odpowiedz);

  for(int i=0; i<SIZE; i++){
  CHECK(odpowiedz[i]==wynik[i]);
  }

}

TEST_CASE("vector - operator -")
{
  double zmienna[]={5,7};
  Vector test = Vector(zmienna);

  double zmienna2[]={8,9};
  Vector test2 = Vector(zmienna2);

  Vector wynik=test-test2;

  double tab_odpowiedz[]={-3,-2};
  Vector odpowiedz=Vector(tab_odpowiedz);

  for(int i=0; i<SIZE; i++){
  CHECK(odpowiedz[i]==wynik[i]);
  }

}


TEST_CASE("vector - operator <<")
{
  double zmienna[]={5,7};
  Vector test = Vector(zmienna);

  std::ostringstream out;

  out<<test;


  CHECK(out.str()=="5 7 ");


}

TEST_CASE("vector - operator >>")
{
  double zmienna[]={5,7};
  Vector test = Vector(zmienna);

  std::istringstream in;

  in>>test;
  std::ostringstream out;
  out << test;
  CHECK(out.str()=="5 7 ");


}

TEST_CASE("vector - operator ==")
{
  double zmienna[]={5,7};
  Vector test = Vector(zmienna);

  double zmienna2[]={8,9};
  Vector test2 = Vector(zmienna2);

  Vector wynik=test+test2;

  double tab_odpowiedz[]={13,16};
  Vector odpowiedz=Vector(tab_odpowiedz);

  for(int i=0; i<SIZE; i++){
  CHECK(odpowiedz[i]==wynik[i]);
  }

}

TEST_CASE("vector - operator []")
{
  double zmienna[]={5,7};
  Vector test = Vector(zmienna);

    Vector test2;
    double wynik;
    double wynik1;
    double wynik2;
    test2[0]=5;
    test[1]=3;
    test[2]=7;


  for(int i=0; i<SIZE; i++){
  CHECK(test[i]=zmienna[i]);
  }

}
