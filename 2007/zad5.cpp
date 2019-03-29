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
#include <sstream>
using namespace std;

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

//zwraca sume cyfr liczby w systemie binarnym
//inaczej mówiąc, liczy jedynki
int sumabin(uint32_t l) {
  string s=bitset<32>(l).to_string();
  int ile=0;
  for(int i=0;i<32;i++)
    ile+=(s[i]-'0');
  return ile;
}
int sumadec(uint32_t l) {
  stringstream ss;
  ss<<l;
  string s;
  ss>>s;
  int ile=0;
  for(uint32_t i=0;i<s.size();i++)
    ile+=(s[i]-'0');
  return ile;
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
  cout<<"UWAGA: ja się długo wykonuje!"<<endl;

  //5a
  int ile1=0,ile2=0,ile3=0;

  for(int i=2;i<=1000;i++) {
    ile1+=( prime(i) && prime(sumadec(i)) && prime(sumabin(i)) );
  }
  for(int i=100;i<=10000;i++) {
    ile2+=( prime(i) && prime(sumadec(i)) && prime(sumabin(i)) );
  }
  for(int i=1000;i<=100000;i++) {
    ile3+=( prime(i) && prime(sumadec(i)) && prime(sumabin(i)) );
  }

  //5b
  int ile4=0;
  for(int i=100;i<=10000;i++) {
    ile4+=prime(sumadec(i));
  }
  int sumasuperbpierwszych=0;
  for(int i=100;i<=10000;i++) {
    if(( prime(i) && prime(sumadec(i)) && prime(sumabin(i)) ))
      sumasuperbpierwszych+=i;
  }
  cout<<"5a 1 "<<ile1<<endl;
  cout<<"5a 2 "<<ile2<<endl;
  cout<<"5a 3 "<<ile3<<endl;
  cout<<"5b "<<ile4<<" "<<(prime(sumasuperbpierwszych) ? "TAK" : "NIE")<<endl;
}
