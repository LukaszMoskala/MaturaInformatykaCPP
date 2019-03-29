//UWAGA: TEN KOD PISAŁEM NA DŁUGO PRZED STWORZENIEM TEGO REPOZYTORIUM
//WYBACZCIE MI BŁĘDY KTÓRE TU PEWNIE SĄ
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
#include <sstream>
#include <vector>
using namespace std;
vector<string> dane;
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
  ifstream f;
  f.open("dane.txt");
  if(!f.is_open())
    return 1;
  string s;
  while(f.good()) {
    f>>s;
    if(s.length() >0)
      dane.push_back(s);
  }
  f.close();
  //Podpunkt A:
  //pierwsza cyfra równa ostatniej cyfrze
  //przetwarzamy to na stringach, bo tak jest wygodniej
  int a=0;
  for(uint32_t i=0;i<dane.size();i++) {
    uint32_t ost=dane[i].length()-1;
    a+=(dane[i][0] == dane[i][ost]);
  }
  cout<<"[A] "<<a<<endl;
  //Podpunkt B:
  //ten sam warunek co wyżej tylko w systemie dziesiętnym
  int b=0;
  for(uint32_t i=0;i<dane.size();i++) {
    //Przetwarzamy stringa na inta
    unsigned long long int dec=strtoull(dane[i].c_str(),NULL,8);
    //... I z powrotem na stringa tym razem w postaci 10-tkowej
    stringstream ss;
    ss<<dec;
    string s=ss.str();
    int ost=s.length()-1;
    b+=(s[0] == s[ost]);
  }
  cout<<"[B] "<<b<<endl;
  //podpunkt C:
  //rozpoczynając od najbardziej znaczącej cyfry w zapisie ósemkowym,
  //każda kolejna cyfra tej liczby nie jest mniejsza od cyfry poprzedzającej
  int c=0;
  unsigned long long int maxv=0;
  unsigned long long int minv=2000000;
  for(uint32_t i=0;i<dane.size();i++) {
    bool ok=true;
    for(uint32_t j=1;ok && j<dane[i].length();j++) {
      //porówniania na stringach bo można xD
      ok=(dane[i][j] >= dane[i][j-1]);
    }
    if(ok) {
      c++;
      unsigned long long int tmp=strtoull(dane[i].c_str(),NULL,8);
      if(tmp > maxv)
        maxv=tmp;
      if(tmp < minv)
        minv=tmp;
    }
  }

  cout<<"[C] liczba - "<<c<<endl;
  cout<<"    Najmniejsza - "<<minv<<endl;
  cout<<"    Największa - "<<maxv<<endl;
  return 0;
}
