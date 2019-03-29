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
string szyfruj(const string& tj, const string& klucz) {
  uint32_t iKlucz=0;
  string out="";
  for(uint32_t i=0;i<tj.size();i++) {
    int c=(tj[i]+klucz[iKlucz++]-64);
    if(c > 90)
      c-=26;
    out+=c;
    if(iKlucz == klucz.size())
      iKlucz=0;
  }
  return out;
}
string odszyfruj(const string& sz, const string& klucz) {
  uint32_t iKlucz=0;
  string out="";
  for(uint32_t i=0;i<sz.size();i++) {
    int c=(sz[i]-klucz[iKlucz++]+64);
    if(c < 65)
      c+=26;
    out+=c;
    if(iKlucz == klucz.size())
      iKlucz=0;
  }
  return out;
}
int main() {
  ifstream tj, klucze1, sz, klucze2;
  ofstream wynik4a, wynik4b;

  tj.open("tj.txt");
  klucze1.open("klucze1.txt");
  wynik4a.open("wynik4a.txt");
  if(!tj.is_open() || !klucze1.is_open() || !wynik4a.is_open())
    return 1;
  while(tj.good() && klucze1.good()) {
    string d,u;
    tj>>d;
    klucze1>>u;
    wynik4a<<szyfruj(d,u)<<endl;
  }
  tj.close();
  klucze1.close();
  wynik4a.close();

  sz.open("sz.txt");
  klucze2.open("klucze2.txt");
  wynik4b.open("wynik4b.txt");
  if(!sz.is_open() || !klucze2.is_open() || !wynik4b.is_open())
    return 1;
  while(sz.good() && klucze2.good()) {
    string p,a;
    sz>>p;
    klucze2>>a;
    wynik4b<<odszyfruj(p,a)<<endl;
  }
  sz.close();
  klucze2.close();
  wynik4b.close();

  cout<<"Wyniki w wynik4*.txt"<<endl;
}
