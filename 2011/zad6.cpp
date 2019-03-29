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
#include <bitset>
using namespace std;
uint32_t liczby[1000];
//musimy mieć liczby w postaci stringa do podpunktu C
string liczbystr[1000];
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
  plik.open("liczby.txt");
  if(!plik.is_open())
    return 1;
  for(int i=0; i<1000; i++)
  {
    string s;
    plik>>s;
    liczby[i]=strtoul(s.c_str(), NULL, 2);
    liczbystr[i]=s;
  }
  plik.close();

  //6a
  int parzyste=0;
  for(int i=0;i<1000;i++)
    parzyste+=(liczby[i]%2 == 0);
  cout<<"6A) "<<parzyste<<endl;

  //6b
  uint32_t max=0;
  for(int i=0;i<1000;i++) {
    if(liczby[i] > max)
      max=liczby[i];
  }
  cout<<"6B) "<<max<<" "<<bitset<16>(max)<<endl;
  //6c
  uint16_t ile=0;
  uint32_t suma=0;
  for(int i=0;i<1000;i++) {
    if(liczbystr[i].size() == 9) {
      ile++;
      suma+=liczby[i];
    }
  }
  cout<<"6C) "<<ile<<" liczb, suma: "<<bitset<16>(suma)<<endl;


}
