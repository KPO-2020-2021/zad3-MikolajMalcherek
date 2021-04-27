
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "size.hh"
#include <stdio.h>
#include "rectangle.hh"


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


  CHECK(odpowiedz==wynik);
  

}

TEST_CASE("vector - operator []")
{
  double zmienna[]={5,7};
  Vector test = Vector(zmienna);

  WARN_THROWS(test[6]);
}




TEST_CASE("rectangle - konstruktor bezparametryczny rectangle")
{
  Vector wektor=Vector();
  rectangle zmienna=rectangle();
  for (int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      CHECK(zmienna(i,j)==wektor);
    }
  }
}


TEST_CASE("rectangle - konstruktor parametryczny")
{
  double tab1[2]={2,3};
  double tab2[2]={3,3};
  double tab3[2]={3,8};
  double tab4[2]={2,8};
  
  Vector zmienna1=Vector(tab1);
  Vector zmienna2=Vector(tab2);
  Vector zmienna3=Vector(tab3);
  Vector zmienna4=Vector(tab4);
  Vector tablicawektor[2][2];
  tablicawektor[0][0]=zmienna1;
  tablicawektor[0][1]=zmienna2;
  tablicawektor[1][0]=zmienna3;
  tablicawektor[1][1]=zmienna4;
 rectangle prostokat=rectangle(tablicawektor);

  for (int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      CHECK(prostokat(i,j)==tablicawektor[i][j]);
    }
  }

}



TEST_CASE("rectangle - operator +")
{
  double tab1[2]={2,3};


  Vector zmienna1=Vector(tab1);

  rectangle prostokat=rectangle();

  prostokat+zmienna1;

  for (int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      CHECK(prostokat(i,j)==zmienna1);
    }
  }
}

TEST_CASE("rectangle - operator <<")
{
  double tab1[2]={2,3};
  double tab2[2]={3,3};
  double tab3[2]={3,8};
  double tab4[2]={2,8};
  
  Vector zmienna1=Vector(tab1);
  Vector zmienna2=Vector(tab2);
  Vector zmienna3=Vector(tab3);
  Vector zmienna4=Vector(tab4);
  Vector tablicawektor[2][2];
  tablicawektor[0][0]=zmienna1;
  tablicawektor[0][1]=zmienna2;
  tablicawektor[1][0]=zmienna3;
  tablicawektor[1][1]=zmienna4;
  rectangle prostokat=rectangle(tablicawektor);

  
  std::ostringstream out;

  out<<prostokat;


  CHECK("2 3 \n3 3 \n3 8 \n2 8 \n"==out.str());

}

TEST_CASE("rectangle - operator ()")
{
  double tab1[2]={2,3};
  double tab2[2]={3,3};
  double tab3[2]={3,8};
  double tab4[2]={2,8};
  
  Vector zmienna1=Vector(tab1);
  Vector zmienna2=Vector(tab2);
  Vector zmienna3=Vector(tab3);
  Vector zmienna4=Vector(tab4);
  Vector tablicawektor[2][2];
  tablicawektor[0][0]=zmienna1;
  tablicawektor[0][1]=zmienna2;
  tablicawektor[1][0]=zmienna3;
  tablicawektor[1][1]=zmienna4;
  rectangle prostokat=rectangle(tablicawektor);


  Vector wynik=Vector(tab1);

  CHECK(prostokat(0,0)==wynik);
}


TEST_CASE("rectangle - przesuniecie")
{
  double tab1[2]={2,3};
  double tab2[2]={3,3};
  double tab3[2]={3,8};
  double tab4[2]={2,8};
  
  Vector zmienna1=Vector(tab1);
  Vector zmienna2=Vector(tab2);
  Vector zmienna3=Vector(tab3);
  Vector zmienna4=Vector(tab4);
  Vector tablicawektor[2][2];
  tablicawektor[0][0]=zmienna1;
  tablicawektor[0][1]=zmienna2;
  tablicawektor[1][0]=zmienna3;
  tablicawektor[1][1]=zmienna4;
  rectangle prostokat=rectangle(tablicawektor);
  rectangle prostokat2 = prostokat;
  Vector przesuniecie = Vector(tab1);
  prostokat = prostokat.przesuniecie(przesuniecie);

  for (int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      CHECK(prostokat(i,j)==prostokat2(i,j)+przesuniecie);
    }
  }
}


TEST_CASE("Matrix - konstruktor bezparametryczny")
{
  double tablica[2][2];
  tablica[0][0]=1;
  tablica[0][1]=0;
  tablica[1][0]=0;
  tablica[1][1]=1;
  Matrix macierz=Matrix();
  for (int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
  CHECK(macierz(i,j)==tablica[i][j]);
    }
  }
}


TEST_CASE("Matrix - konstruktor parametryczny")
{
  double tablica[2][2];
  tablica[0][0]=5;
  tablica[0][1]=8;
  tablica[1][0]=3;
  tablica[1][1]=6;
  Matrix macierz=Matrix(tablica);
  for (int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
  CHECK(macierz(i,j)==tablica[i][j]);
    }
  }
}

TEST_CASE("Matrix - operator * ")
{
  double tablicawek[2]={1,2};
  double tablica[2][2];
  tablica[0][0]=2;
  tablica[0][1]=1;
  tablica[1][0]=3;
  tablica[1][1]=1;
  Vector wektor=Vector(tablicawek);
  Matrix macierz=Matrix(tablica);
  Vector wynik=macierz*wektor;
  double tablicawyniku[2]={4,5};
  Vector wynikkoncowy=Vector(tablicawyniku);

  CHECK(wynikkoncowy==wynik);

}

TEST_CASE("Matrix - operator () ")
{
  double tablica[2][2];
  tablica[0][0]=5;
  tablica[0][1]=8;
  tablica[1][0]=3;
  tablica[1][1]=6;
  Matrix macierz=Matrix(tablica);
  double zmienna = macierz(1,1);

  CHECK(zmienna==tablica[1][1]);
}

/*
TEST_CASE("Matrix - wyliczanie wyznacznika macierzy")
{
  double tablica[2][2];
  tablica[0][0]=2;
  tablica[0][1]=1;
  tablica[1][0]=3;
  tablica[1][1]=1;
  Matrix macierz=Matrix(tablica);
  double wyznacznik = macierz.wyznacznikgaussa();
  double wynik=5;

  CHECK(wynik==wyznacznik);

}
*/