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

bool czywiecejzer(const string& s) {
  uint8_t t[2] = {0,0};
  for(uint32_t i=0;i<s.size();i++) {
    t[int(s[i]-'0')]++;
  }
  return (t[0] > t[1]);
}
bool dwabloki01(const string& s) {
  if(s[0] == '1')
    return false;
  if(s[s.size()-1] == '0')
    return false;
  return (s.substr(s.find_first_not_of('0')).find('0') == string::npos);
}
size_t najdluzszyblokzer(const string& s) {
  size_t ml=0;
  for(uint32_t i=0;i<s.size();i++) {
    size_t cl=s.substr(i).find_first_not_of('0');
    if(cl != string::npos && cl > ml)
      ml=cl;
    if(cl == string::npos && s.size()-i > ml)
      ml=s.size()-i;
  }
  return ml;
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
  plik.open("slowa.txt");
  if(!plik.is_open())
    return 1;
  for(int i=0;i<1000;i++) {
    plik>>slowa[i];
  }
  plik.close();

  //4.1
  int iwz=0;
  for(int i=0;i<1000;i++) {
    iwz+=czywiecejzer(slowa[i]);
  }
  cout<<"[4.1] "<<iwz<<endl;
  //4.2
  int dwb=0;
  for(int i=0;i<1000;i++) {
    dwb+=dwabloki01(slowa[i]);
  }
  cout<<"[4.2] "<<dwb<<endl;
  //4.3
  size_t nbz=0;
  for(int i=0;i<1000;i++) {
    size_t c=najdluzszyblokzer(slowa[i]);
    if(c > nbz)
      nbz=c;
  }
  cout<<"[4.3] długość: "<<nbz<<endl;
  string tenBlokZer="";
  for(size_t i=0;i<nbz;i++) {
    tenBlokZer+='0';
  }
  for(int i=0;i<1000;i++) {
    if(slowa[i].find(tenBlokZer) != string::npos) {
      cout<<"\t"<<slowa[i]<<endl;
    }
  }

}
