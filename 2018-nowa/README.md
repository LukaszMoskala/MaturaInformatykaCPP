# Linki
[Link do arkusza](https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2018/formula_od_2015/informatyka/MIN-R2_1P-182.pdf)

[Link do danych](https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2018/formula_od_2015/informatyka/Dane_PR2.zip)

[Link do odpowiedzi](https://www.cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2018/formula_od_2015/Zasady_oceniania/MIN-R2_1P-182_zasady_oceniania.pdf)

# Zadanie 4
Na początku wczytujemy z pliku wszystkie dane do tablicy `sygnaly`.
Możemy bezpiecznie przyjąć stały rozmiar tablicy 1000 elementów, ponieważ jest
to opisane w zadaniu. Ze względu na to, wczytujemy używając pętli `for`.
# Zadanie 4.1
Musimy wyświetlić dziesiątą litere co czterdziestego słowa.
Program pisany jest w `C++` więc dziesiąta litera ma indeks `9`, a słowa
spełniające warunek, mają indeksy `39`, `79`, `119` i tak dalej.

Tworzymy więc pętle `for`, która przypisuje do `int i` wartość `39` i po każdej
iteracji powiększa ją o `40`.

W zadaniu jest napisane `Każde co czterdzieste słowo ma co najmniej 10 znaków.`
także nie musimy się przejmować długością słów.
# Zadanie 4.2
Tworzymy zmienne `max` i `imax` zawierające odpowiednio największą ilość liter
w słowie, oraz indeks tego słowa.
Tablica `uint8_t litery[256]` służy do obliczania ile różnych liter zawiera
słowo. Fragment programu który wypełnia zawartość tej tablicy jest taki sam
jak w przypadku sortowania koszykowego.

Po wypełnieniu tablicy, liczymy ile jej elementów ma wartości niezerowe -
fragment `ile+=(litery[i] > 0);`. Jeżeli wartość ta jest większa niż
dotychczasowa największa wartość, ustawiamy `max=ile` i `imax=i`.

Na samym końcu wyświetlamy słowo (`sygnaly[imax]`) oraz liczbę różnych liter
tego słowa (`max`).
# Zadanie 4.3
Jednak nie chce mi się tego dokumentować, jak komuś się nudzi to polecam
spróbować
