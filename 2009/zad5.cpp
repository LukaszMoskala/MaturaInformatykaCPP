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
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct para_t {
  string a;
  string b;
};
std::vector<para_t> pary;

bool palindrom(const string &s) {
  bool ok=true;
  for(uint32_t i=0; i<s.size() && ok ;i++)
    ok=(s[i] == s[s.size()-1-i]);
  return ok;
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
  plik.open("dane.txt");
  if(!plik.is_open())
    return 1;
  while(plik.good()) {
    para_t p;
    plik>>p.a>>p.b;
    if(p.a.size() > 0 && p.b.size() > 0) {
      pary.push_back(p);
    }
  }
  plik.close();
  cout<<"[*] Wczytano "<<pary.size()<<" par"<<endl;

  //PODPUNKT A:
  //zliczanie palindromów
  int palindromy=0;
  for(uint32_t i=0;i<pary.size();i++)
    palindromy+=((int)palindrom(pary[i].a)+(int)palindrom(pary[i].b));
  cout<<"[A] "<<palindromy<<" palindromów"<<endl;
  //PODPUNKT B:
  //słowo B zawarte jest w słowie A
  int bwa=0;
  for(uint32_t i=0;i<pary.size();i++)
    bwa+=(pary[i].a.find(pary[i].b) != string::npos);
  cout<<"[B] "<<bwa<<" par spełnia warunek (B zawiera się w A)"<<endl;

  //podpunkty C i D są połączone
  //szczerze to w dupie mam poprawne rozwiązanie i robię to tak, żeby
  //działało jak najwolniej. Jest to swojego rodzaju trening pisania złego kodu
  //wszystko sprawdzane jest metodą brute-force xD

  int podpunkt_c=0;

  ofstream podpunkt_d;
  podpunkt_d.open("slowa.txt");

  char buf[64];
  for(uint32_t i=0;i<pary.size();i++) {
    //będzie troche dojenia więc wyciągamy sobie 1 element z tablicy
    para_t p=pary[i];
    string dobre=p.b+p.a;
    //łoooo tutaj będziemy robić rzeczy xD
    for(uint32_t i=16-p.b.size();i<16+p.a.size();i++) {
      memset(buf,' ', sizeof(buf));
      buf[sizeof(buf)-1]=0;
      strncpy(&buf[16],p.a.c_str(),p.a.size());
      strncpy(&buf[i],p.b.c_str(),p.b.size());
      string out(buf);
      if(out.find(p.a) != string::npos && out.find(p.b) != string::npos) {
        //usuń te spacje ze stringa
        std::string::iterator end_pos = remove(out.begin(), out.end(), ' ');
        out.erase(end_pos, out.end());
        //jak jest krótszy od tego co mamy to zapisz go
        if(out.size() < dobre.size())
          dobre = out;
      }
    }
    podpunkt_c+=(dobre.size() == p.a.size()+p.b.size());
    podpunkt_d<<dobre<<endl;
  }
  cout<<"[C] Istnieje "<<podpunkt_c<<" takich par"<<endl;
  podpunkt_d.close();
}
