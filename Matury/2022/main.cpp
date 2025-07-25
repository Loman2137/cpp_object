#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

vector<int> kontener;
int liczba{};
set<vector<int>> trojki;
set<vector<int>> piatki;
set<vector<int>> zasobnik3;
set<vector<int>> zasobnik5;
int z4_1ile{}, z4_1num{};
int z4_2roz{}, z4_2pop_roz{}, z4_2num{};
set<int>pierwsze_pop; set<int>pierwsze; int z4_2liczpier;

void show3(vector<int>ciag) {
    for (int i = 0; i < ciag.size(); ++i) {
        for (int j = 0; j < ciag.size(); ++j) {
            for (int k = 0; k < ciag.size(); ++k) {
                vector<int>tab{ciag[i],ciag[j],ciag[k]};
                if (adjacent_find(tab.begin(), tab.end(),greater_equal<>())==tab.end())
                    zasobnik3.insert(tab);
            }
        }
    }
}
void show5(vector<int>ciag) {
    for (int i = 0; i < ciag.size(); ++i) {
        for (int j = 0; j < ciag.size(); ++j) {
            for (int k = 0; k < ciag.size(); ++k) {
                for (int l = 0; l < ciag.size(); ++l) {
                    for (int m = 0; m < ciag.size(); ++m) {
                        vector<int>tab{ciag[i],ciag[j],ciag[k], ciag[l],ciag[m]};
                        if (adjacent_find(tab.begin(), tab.end(),greater_equal<>())==tab.end())
                            zasobnik5.insert(tab);
                    }
                }
            }
        }
    }
}

int main() {

    fstream wczytanie("Dane_2205/liczby.txt", ios::in); //ios::in jest domyślny
    fstream zapisanie("Dane_2205/wyniki4.txt", ios::out); //ios::out ma domyślnie nadpisywanie wartości
    fstream zapisanie2("Dane_2205/trojki.txt", ios::out); //ios::out ma domyślnie nadpisywanie wartości
    cout<<"kompilacja"<<endl;

    while (wczytanie >> liczba) {
        kontener.push_back(liczba);

        //4.1
         string h = to_string(liczba);
         if (h[0]==h[h.size()-1]) {
             z4_1ile++;
             if (z4_1num == 0)
                 z4_1num=liczba;
         }

        //4.2
        int zamiennik = liczba;
        z4_2roz=0;
        pierwsze.clear();
        for (int i = 2; i <= zamiennik;) {
            if (zamiennik%i == 0) {
                zamiennik = zamiennik / i;
                z4_2roz++;
                pierwsze.insert(i);
                if (z4_2roz>z4_2pop_roz) {
                    z4_2pop_roz=z4_2roz;
                    z4_2num = liczba;
                }
                if (pierwsze.size()>pierwsze_pop.size()) {
                    pierwsze_pop=pierwsze;
                    z4_2liczpier = liczba;
                }
            }
            else
                i++;
        }
    }
    sort(kontener.begin(), kontener.end());

    for (size_t i = 0; i < kontener.size()-3; i++) {
        vector<int>tmp;
        for (size_t j = i; j < kontener.size(); j++) {
            if (kontener[j]%kontener[i]==0)
                tmp.push_back(kontener[j]);
        }
        if (tmp.size()>=3)
            trojki.insert(tmp);
        if (tmp.size()>=5)
            piatki.insert(tmp);
    }
    for (auto& x: trojki) {
        show3(x);
    }for (auto& x: piatki) {
        show5(x);
    }
    for (auto x: zasobnik3) {
        for (auto y: x) {
            zapisanie2<<y<<" ";
        }
        zapisanie2<<"\n";
    }


    zapisanie << z4_1ile<<" "<<z4_1num<<endl;
    zapisanie << z4_2num << " " << z4_2pop_roz<<" "<<z4_2liczpier<<" "<< pierwsze_pop.size()<<endl;
    zapisanie << "a)" <<  zasobnik3.size()<< endl <<"b)"<< zasobnik5.size();
    wczytanie.close();
    zapisanie.close();
}//to sie wysłało?