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
string slowa[200][5];
int main() {
  ifstream plik;
  ofstream out;
  plik.open("anagram.txt");
  if(!plik.is_open())
    return 1;
  for(int i=0;i<200;i++) {
    for(int j=0;j<5;j++) {
      plik>>slowa[i][j];
    }
  }
  plik.close();

  //4a
  out.open("odp_4a.txt");
  for(int i=0;i<200;i++) {
    if(slowa[i][0].size() == slowa[i][1].size() &&
       slowa[i][0].size() == slowa[i][2].size() &&
       slowa[i][0].size() == slowa[i][3].size() &&
       slowa[i][0].size() == slowa[i][4].size()) {
      for(int j=0;j<5;j++)
        out<<slowa[i][j]<<' ';
      out<<endl;
      }
  }
  out.close();
  //4b
  out.open("odp_4b.txt");
  for(int i=0;i<200;i++) {
    uint8_t wystapienia[5][26];
    memset(wystapienia, 0, sizeof(wystapienia));
    for(int j=0;j<5;j++) {
      for(uint32_t k=0;k<slowa[i][j].size();k++) {
        wystapienia[j][slowa[i][j][k]-'a']++;
      }
    }
    if(!memcmp(wystapienia[0],wystapienia[1],26) &&
       !memcmp(wystapienia[0],wystapienia[2],26) &&
       !memcmp(wystapienia[0],wystapienia[3],26) &&
       !memcmp(wystapienia[0],wystapienia[4],26)) {
      for(int j=0;j<5;j++)
        out<<slowa[i][j]<<' ';
      out<<endl;
    }
  }
  out.close();
  cout<<"Odpowiedzi w plikach odp_4*.txt"<<endl;
}
