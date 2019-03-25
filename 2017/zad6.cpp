/*
Copyright (C) 2019 Łukasz Konrad Moskała

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

//Pisałem to tak dawno że nie mam pojęcia jak to działa, także ten no...
#include <iostream>
#include <fstream>
using namespace std;
int obraz[320][200];

int abs(int in)
{
  if(in < 0)
    return -in;
  else
    return in;
}

int main()
{
  ifstream plik;
  plik.open("dane.txt");
  for(int y=0; y<200; y++)
  {
    for(int x=0; x<320; x++ )
    {
      plik>>obraz[x][y];
    }
  }
  plik.close();
  int mi=255;
  int ma=0;
  for(int x=0; x<320; x++)
  {
    for(int y=0; y<200; y++)
    {
      if(obraz[x][y] > ma)
        ma=obraz[x][y];
      if(obraz[x][y] < mi)
        mi=obraz[x][y];
    }
  }
  cout<<"6.1:"<<endl;
  cout<<"     Najjaśniejszy pixel:  "<<ma<<endl;
  cout<<"     Najciemniejszy pixel: "<<mi<<endl;
  int ns=0;
  for(int y=0; y<200; y++)
  {
    for(int x=0; x<320; x++)
    {
      if(obraz[x][y] != obraz[319-x][y])
      {
        ns++;
        break;
      }
    }
  }
  cout<<"6.2:"<<endl;
  cout<<"     Wiersze do usuniecia aby obraz miał pionową oś symetrii: "<<ns<<endl;
  int kontrastujace=0;
  for(int x=0; x<320; x++)
  {
    for(int y=0; y<200; y++)
    {
      bool g=false;
      if(x > 0)
        if(abs(obraz[x][y]-obraz[x-1][y]) > 128)
          g=true;
      if(x < 319)
        if(abs(obraz[x][y]-obraz[x+1][y]) > 128)
          g=true;
      if(y > 0)
        if(abs(obraz[x][y]-obraz[x][y-1]) > 128)
          g=true;
      if(y < 199)
        if(abs(obraz[x][y]-obraz[x][y+1]) > 128)
          g=true;
      if(g) kontrastujace++;
    }
  }
  int obecny=0;
  int najwiekszy=0;
  for(int x=0;x<320;x++) {
    for(int y=0;y<199;y++) {
      if(obraz[x][y+1] == obraz[x][y]) obecny++;
      else {
        if(obecny+1 > najwiekszy)
        najwiekszy=obecny+1;
        obecny=0;
      }
    }
  }
  cout<<"6.3: "<<endl;
  cout<<"      Kontrastujace piksele: "<<kontrastujace<<endl;
  cout<<"      Najdłuższa linia pionowa: "<<najwiekszy<<" pikseli"<<endl;

}
