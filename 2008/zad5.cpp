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
using namespace std;
string slowa[1000];

string odwroc(const string& s) {
  string ret="";
  for(uint32_t j=0;j<s.size();j++) {
    ret+=s[s.size()-1-j];
  }
  return ret;
}
bool sprawdzPalindrom(const string& s) {
  bool ok=true;
  for(uint32_t i=0;i<s.size() && ok;i++)
    ok=(s[i] == s[s.size()-1-i]);
  return ok;
}
int main() {
  ifstream plik;
  plik.open("slowa.txt");
  if(!plik.is_open())
    return 1;
  for(int i=0;i<1000;i++) {
    plik>>slowa[i];
  }
  plik.close();

  ofstream out;

  //5a
  out.open("hasla_a.txt");
  string najdl="";
  string najkr="";
  uint32_t dl=0;
  uint32_t dl2=555555;
  for(int i=0;i<1000;i++) {
    string haslo=odwroc(slowa[i]);
    if(haslo.size() > dl) {
      dl=haslo.size();
      najdl=haslo;
    }
    if(haslo.size() < dl2) {
      dl2=haslo.size();
      najkr=haslo;
    }
    out<<haslo<<endl;
  }
  out.close();
  out.open("slowa_a.txt");
  out<<"Najdłuższe: "<<najdl<<" długość: "<<dl<<endl;
  out<<"Najkrótsze: "<<najkr<<" długość: "<<dl2<<endl;
  out.close();
  //5b
  out.open("hasla_b.txt");
  ofstream out2;
  out2.open("slowa_b.txt");
  out2<<"1 ";
  uint32_t sumadl=0;
  //te 4 zmienne z poprzedniego podpunktu wykorzystujemy
  najdl="";
  najkr="";
  dl=0;
  dl2=555555;
  for(int i=0;i<1000;i++) {
    string palindrom="";
    string reszta="";
    for(uint32_t j=slowa[i].size();j>=0;j--) {
      palindrom=slowa[i].substr(0, j);
      if(sprawdzPalindrom(palindrom)) {
        reszta=slowa[i].substr(j);
        break;
      }
    }
    string haslo=odwroc(reszta)+slowa[i];
    out<<haslo<<endl;
    if(haslo.size() == 12)
      out2<<haslo<<" ";
    sumadl+=haslo.size();
    if(haslo.size() > dl) {
      dl=haslo.size();
      najdl=haslo;
    }
    if(haslo.size() < dl2) {
      dl2=haslo.size();
      najkr=haslo;
    }
  }
  out2<<endl;
  out2<<"2 "<<najdl<<" "<<najkr<<endl;
  out2<<"3 "<<sumadl<<endl;

  out2.close();
  out.close();
  cout<<"wyniki w plikach: "<<endl;
  cout<<" slowa_*.txt"<<endl;
  cout<<" hasla_*.txt"<<endl;
}
