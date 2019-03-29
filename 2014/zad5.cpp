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
string napisy[1000];

//nieoptymalna funkcja sprawdzająca czy liczba jest pierwsza
bool prime(int num) {
  if(num == 1)
    return false;
  for(int i=2;i<num;i++) {
    if(num%i == 0)
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
  plik.open("NAPIS.TXT");
  if(!plik.is_open())
    return 1;
  for(int i=0;i<1000;i++) {
    plik>>napisy[i];
  }
  plik.close();
  //5a
  int ilepierwszych=0;
  for(int i=0;i<1000;i++) {
    int sa=0;
    for(uint32_t j=0;j<napisy[i].size();j++)
      sa+=napisy[i][j];
    ilepierwszych+=prime(sa);
  }
  cout<<"5A) "<<ilepierwszych<<endl;
  //5b
  cout<<"5B)"<<endl;
  for(int i=0;i<1000;i++) {
    bool ok=true;
    for(uint32_t j=1;j<napisy[i].size() && ok;j++)
      ok=(napisy[i][j] > napisy[i][j-1]);
    if(ok)
      cout<<"\t"<<napisy[i]<<endl;
  }
  //5c
  cout<<"5C)"<<endl;
  //teraz możemy zniszczyć dane bo już i tak nie będą potrzebne
  for(int i=0;i<1000;i++) {
    bool b=false;
    for(int j=i+1;j<1000;j++) {
      if(napisy[j].size() > 0 && napisy[i] == napisy[j]) {
        if(!b)
          cout<<"\t"<<napisy[i]<<endl;
        napisy[j]=""; //wymazujemy żeby więcej nie pojawił się
        b=true;
      }
    }
  }

}
