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
string binarne[500];

//sprawdzanie czy ciąg jest dwucykliczny jest proste:
//jeżeli nie ma parzystej długości - nie jest
//jeżeli ma:
//  dzielimy go na 2 połowy
//  jeżeli pierwsza połowa jest taka sama jak druga, to jest
bool czyDwucykliczny(const string& s) {
  if(s.size()%2) {
    return false;
  }
  return (s.substr(0, s.size()/2) == s.substr(s.size()/2));
}

bool BCDpoprawny(const string& s) {
  //długość musi być wielokrotnością 4
  if(s.size()%4) {
    return false;
  }
  for(uint32_t i=0;i<s.size();i+=4) {
    if(strtol(s.substr(i, 4).c_str(), NULL, 2) > 9)
      return false;
  }
  return true;
}

int main() {
  cout<<"Copyright (C) 2019 Łukasz Konrad Moskała ukasz_moskala8@tlen.pl"<<endl;
  cout<<"This program comes with ABSOLUTELY NO WARRANTY."<<endl;
  cout<<"This is free software, and you are welcome to redistribute it"<<endl;
  cout<<"under certain conditions; Read attached license file for details."<<endl;
  cout<<endl;
  cout<<"You should have received a copy of the GNU General Public License"<<endl;
  cout<<"along with this program.  If not, see <https://www.gnu.org/licenses/>."<<endl;
  cout<<endl;
  ifstream plik;
  plik.open("binarne.txt");
  if(!plik.is_open())
    return 1;
  for(int i=0;i<500;i++) {
    plik>>binarne[i];
  }
  plik.close();
  //4.1

  //indeks najdłuższego dwucyklicznego
  int iNajdlDWU=0;
  int ileDwucyklicznych=0;
  for(int i=0;i<500;i++) {
    if(czyDwucykliczny(binarne[i])) {
      ileDwucyklicznych++;
      if(binarne[i].size() > binarne[iNajdlDWU].size()) {
        iNajdlDWU=i;
      }
    }
  }
  cout<<"[4.1] "<<ileDwucyklicznych<<" "<<binarne[iNajdlDWU]<<" "<<binarne[iNajdlDWU].size()<<endl;
  //4.2
  uint32_t najkrotszy=999999;
  int dodupy=0;
  for(int i=0;i<500;i++) {
    if(!BCDpoprawny(binarne[i])) {
      dodupy++;
      if(binarne[i].size() < najkrotszy)
        najkrotszy=binarne[i].size();
    }
  }
  cout<<"[4.2] "<<dodupy<<" "<<najkrotszy<<endl;

  //4.3
  uint32_t max=0;
  int iMax=0;
  for(int i=0;i<500;i++) {
    //musimy sprawdzić czy string jest dłuższy niż 16 bitów, ALE
    //musimy najpierw usunąć z niego zera z początku
    string s=binarne[i].erase(0, min(binarne[i].find_first_not_of('0'), binarne[i].size()-1));
    if(s.size() > 16)
      continue;
    uint32_t l=strtoul(s.c_str(), NULL, 2);
    if(l > max) {
      max=l;
      iMax=i;
    }
  }
  cout<<"[4.3] "<<binarne[iMax]<<" "<<max<<endl;
}
