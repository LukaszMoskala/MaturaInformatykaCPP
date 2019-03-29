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

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip> //setprecision
#include <cmath>
using namespace std;
struct PUNKT_T {
  int x;
  int y;
} punkty[10000];

int liczwkole(int ile) {
  int ret=0;
  for(int i=0;i<ile;i++) {
    ret+=( ((punkty[i].x - 200)*(punkty[i].x - 200) +
           (punkty[i].y - 200)*(punkty[i].y - 200)) <= 200*200 );
  }
  return ret;
}

double liczpi(int ile) {
  return (1600.0*(double)liczwkole(ile))/(200.0*200.0*(double)ile)*100.0;
}

int main()
{
  cout<<"Copyright (C) 2019 Łukasz Konrad Moskała ukasz_moskala8@tlen.pl"<<endl;
  cout<<"This program comes with ABSOLUTELY NO WARRANTY."<<endl;
  cout<<"This is free software, and you are welcome to redistribute it"<<endl;
  cout<<"under certain conditions; Read attached license file for details."<<endl;
  cout<<endl;
  cout<<"You should have received a copy of the GNU General Public License"<<endl;
  cout<<"along with this program.  If not, see <https://www.gnu.org/licenses/>."<<endl;
  cout<<endl;
  ifstream plik;
  plik.open("punkty.txt");
  if(!plik.is_open())
    return 1;
  for(int i=0;i<10000;i++) {
    //prawdopodobnie można w jednej linii to zapisać, ale
    //wole nie ryzykować że kompilator postanowi to wczytać w odwrotnej
    //kolejności
    plik>>punkty[i].x;
    plik>>punkty[i].y;
  }
  plik.close();

  //4.1
  //Wypisz  współrzędne  tych  punktów,  które  należą  do  brzegu  koła
  //(okręgu),  oraz  podaj  liczbępunktów należących do wnętrza koła
  //(brzeg koła nie należy do wnętrza koła).

  //dodatkowo, wyliczane są tu rzeczy potrzebne do następnego podpunktu

  int w_kole=0;
  int w_kole_1k=0;
  int w_kole_5k=0;
  int na_okregu=0;
  cout<<"[4.1] Na okręgu: "<<endl;
  for(int i=0;i<10000;i++) {
    if( ((punkty[i].x - 200)*(punkty[i].x - 200) +
        (punkty[i].y - 200)*(punkty[i].y - 200)) == 200*200 ) {
      cout<<"                ("<<punkty[i].x<<','<<punkty[i].y<<")"<<endl;
      na_okregu++;
    }
  }
  cout<<"      W kole: "<<liczwkole(10000)-na_okregu<<endl;

  //4.2

  //P*Nk/(r^2*n)=pi

  //to *100.0 jest bo nie chciało wyjść xD więc żeby wyniki miały sens to
  //dopisałem
  cout<<"[4.2] "<<setprecision(5)<<(1600.0*liczwkole(1000))/(200.0*200.0*1000)*100.0<<endl;
  cout<<"      "<<setprecision(5)<<(1600.0*liczwkole(5000))/(200.0*200.0*5000)*100.0<<endl;
  cout<<"      "<<setprecision(5)<<(1600.0*liczwkole(10000))/(200.0*200.0*10000)*100.0<<endl;

  cout<<"[4.3] Generuje plik 'dupa.txt', zaimportuj go do LibreOffice żeby zrobić wykres"<<endl;
  ofstream dupa;
  dupa.open("dupa.txt");
  for(int i=1;i<=1700;i++) {
    dupa<<i<<"\t"<<abs(M_PI-liczpi(i))<<endl;
  }
  dupa.close();
  cout<<"     E1000="<<setprecision(3)<<abs(M_PI-liczpi(1000))<<endl;
  cout<<"     E1700="<<setprecision(3)<<abs(M_PI-liczpi(1700))<<endl;


}
