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
bool p[100][22][14];


bool odczyt(int po, int x, int y) {
    return p[po][x+1][y+1];
}
void zapis(int po, int x, int y, bool v) {
    p[po][x+1][y+1]=v;
}
int ile_somsiadow(int pokolenie, int x, int y) {
    int i=0;
    i+=odczyt(pokolenie, x-1, y-1);
    i+=odczyt(pokolenie, x-1, y);
    i+=odczyt(pokolenie, x-1, y+1);
    i+=odczyt(pokolenie, x, y-1);
    i+=odczyt(pokolenie, x, y+1);
    i+=odczyt(pokolenie, x+1, y-1);
    i+=odczyt(pokolenie, x+1, y);
    i+=odczyt(pokolenie, x+1, y+1);
    return i;
}
void rozesraj(int po) {
    for(int x=0;x<20;x++) {
        zapis(po, x, -1, odczyt(po, x, 11));
        zapis(po, x, 12, odczyt(po, x, 0));

    }
    for(int y=0;y<12;y++) {
        zapis(po, -1, y, odczyt(po, 19, y));
        zapis(po, 20, y, odczyt(po, 0, y));
    }

    zapis(po, -1, -1, odczyt(po,20, 12));
    zapis(po, 20, -1, odczyt(po,-1, 12));
    zapis(po, -1, 12, odczyt(po,20, -1));
    zapis(po, 20, 12, odczyt(po,-1, -1));

}
void wyswietl_pokolenie(int po) {
    cout<<"Pokolenie numer "<<po<<" liczac od 0"<<endl;
    for(int y=0;y<12;y++) {
        for(int x=0;x<20;x++) {
            if(odczyt(po, x, y)) cout<<"X ";
            else cout<<". ";
        }
        cout<<endl;
    }
}
int ilezywych(int pokolenie) {
    int ret=0;
    for(int x=0;x<20;x++)
        for(int y=0;y<12;y++)
            ret+=odczyt(pokolenie, x, y);
    return ret;
}
bool czyPokoleniaTakieSame(int p1, int p2) {
    bool ok=true;
    for(int x=0;x<20 && ok;x++) {
        for(int y=0;y<12 && ok;y++) {
            ok=(odczyt(p1,x,y)==odczyt(p2,x,y));
        }
    }
    return ok;
}
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
    cout<<"UWAGA: POPRAWNY WYNIK PRODUKOWANY TYLKO W 5.2!"<<endl;
    cout<<endl;
    ifstream plik;
    plik.open("gra.txt");
    memset(p, 0, sizeof(p));
    if(!plik.is_open()) return 1;
    for(int i=0;i<12;i++) {
        for(int j=0;j<20;j++) {
            char c;
            plik>>c;
            zapis(0, j, i,(c == 'X'));
        }
    }
    plik.close();
    rozesraj(0);

    for(int po=1;po<100;po++) {
        for(int y=0;y<12;y++) {
            for(int x=0;x<20;x++) {
                int som=ile_somsiadow(po-1, x, y);
                if((odczyt(po-1, x, y) && (som == 2 || som == 3)) || (!odczyt(po-1, x, y) && som == 3) )
                    zapis(po, x, y, true);
                else
                    zapis(po, x, y, false);
            }
        }
        rozesraj(po);

    }
    cout<<"TEST:"<<endl;
    cout<<"Dla przykładu z pliku – w jedenastym pokoleniu – komórka w pierwszym wierszu i dziesiątej kolumnie jest martwa i ma trzech żywych sąsiadów. "<<endl;

    cout<<"Żywi somsiedzi: "<<ile_somsiadow(10, 9, 0)<<" Komórka: "<<(odczyt(10,9,0)?"Żywa":"Martwa")<<endl;
    cout<<endl;
    cout<<"[5.1] "<<ile_somsiadow(36,18,1)<<endl;
    cout<<"[5.2] "<<ilezywych(1)<<endl;
    cout<<"[5.3] ";
    for(int i=1;i<100;i++) {
        //memcmp dawało taki sam wynik, ale troche mu nie ufałem więc napisałem funkcje samemu
        //wynik produkuje taki sam więc nie ma to znaczenia, zostawiam więc obie wersje

        //przy czym wierzę, że memcmp byłoby bardziej optymalne ale nie sprawdzałem tego

        //if(!memcmp(p[i-1],p[i],22*14 )) {
        if(czyPokoleniaTakieSame(i-1,i)) {
        
            cout<<"Pokolenie "<<i+1<<" zywych "<<ilezywych(i)<<endl;
            wyswietl_pokolenie(i-1);
            wyswietl_pokolenie(i);

            break;
        }
    }

    return 0;
}
