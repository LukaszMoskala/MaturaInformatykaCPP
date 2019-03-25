#include <iostream>
#include <fstream>
#include <vector>
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
  ifstream plik;
  plik.open("Dane/dane.txt");
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

  //TODO: dopisz reszte XD
}
