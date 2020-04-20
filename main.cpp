#include <iostream>
#include <conio.h>
#include <vector>
#include "Samochody.h"
#include <fstream>
#include <algorithm>
#include <string>


using namespace std;

void Nawigacja(vector<Samochody> & Dane);
void WyswietlanieListy( const vector<Samochody> & Dane);

void Sortowanie(vector <Samochody> & Dane,const int & nr) // Funkcja sluży do sortowania danych w wektorze, po odpowiednio przypisanym numerze.
{
    switch(nr)
    {
        case 1:
            sort(Dane.begin(), Dane.end(),
                 [](Samochody &s1, Samochody &s2) -> bool { return s1.ZwrocMarke() < s2.ZwrocMarke(); });
            break;
        case 2:
            sort(Dane.begin(), Dane.end(),
                 [](Samochody & s1, Samochody &s2) -> bool { return s1.ZwrocModel() < s2.ZwrocModel(); });
            break;
        case 3:
            sort(Dane.begin(), Dane.end(),[](Samochody & s1, Samochody &s2) -> bool { return s1.ZwrocRocznik() < s2.ZwrocRocznik(); });
            break;
        case 4:
            sort(Dane.begin(), Dane.end(),[](Samochody & s1, Samochody &s2) -> bool { return s1.ZwrocPojemnosc() < s2.ZwrocPojemnosc(); });
            break;
        case 5:
            sort(Dane.begin(), Dane.end(),
                 [](Samochody & s1, Samochody &s2) -> bool { return s1.ZwrocPrzebieg() < s2.ZwrocPrzebieg(); });
            break;
        case 6:
            sort(Dane.begin(), Dane.end(),
                 [](Samochody & s1, Samochody &s2) -> bool { return s1.ZwrocTypSkrzyniBiegow() < s2.ZwrocTypSkrzyniBiegow(); });
            break;
        default:
            break;
    }
}



void UsuwanieZKatalogu(vector <Samochody> & Dane,const int & nr) // Funkcja tlumaczy numer wyswietlany na rzeczywisty numer w tablicy i odpowiednio usuwa

{
    if(nr>=1 && nr <= Dane.size() + 1)
    Dane.erase(Dane.begin()+nr-1);

}

void DodawanieDoKatalogu(vector <Samochody> &Dane) // Funkcja wypytuje o kolejne dane uzytkownika po czym dodaje nowy obiekt do wektora
{
    std::string marka;
    std::string model;
    unsigned int rocznik;
    double pojemnosc;
    unsigned int przebieg;
    std::string typSkrzyniBiegow;

    cout << "Podaj Marke: ";
    cin >> marka;
    cout << endl;

    cout << "Podaj Model: ";
    cin >> model;
    cout << endl;

    cout << "Podaj Rocznik: ";
    cin >> rocznik;
    cout << endl;

    cout << "Podaj Pojemnosc: ";
    cin >> pojemnosc;
    cout << endl;

    cout << "Podaj Przebieg: ";
    cin >> przebieg;
    cout << endl;

    cout << "Podaj Typ Skrzyni Biegow: ";
    cin >> typSkrzyniBiegow;
    cout << endl;

    Dane.push_back(Samochody(marka,model,rocznik,pojemnosc,przebieg,typSkrzyniBiegow));



}

void WyswietlanieWarunkowe(const vector<Samochody> & Dane, const double Pojemnosc) // Wyswietlanie warunkowe samochodow ktore maja wieksza pojemnosc niz podana
{
    cout << "Marka, Model, Rocznik, Pojemnosc, Przebieg, Typ Skrzyni Biegow" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for(int i = 0; i<Dane.size(); i++)
    {
        if(Dane[i].ZwrocPojemnosc() >= Pojemnosc)
        {
            cout << i+1;
            cout << ". ";
            cout << Dane[i];
        }
    }
    cout << "--------------------------------------------------------------" << endl;
}


void WyswietlanieModelu(const vector<Samochody> & Dane, const string &model) // Wyswietla odpowiedni model samochodu z wektora
{
    cout << "Marka, Model, Rocznik, Pojemnosc, Przebieg, Typ Skrzyni Biegow" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for(int i = 0; i<Dane.size(); i++)
    {
        if(model == Dane[i].ZwrocModel())
        {
            cout << i+1;
            cout << ". ";
            cout << Dane[i];
        }

    }
    cout << "--------------------------------------------------------------" << endl;

}

void WyswietlanieListy( const vector<Samochody> &Dane) // Wyswietla caly wektor
{
    cout << "Marka, Model, Rocznik, Pojemnosc, Przebieg, Typ Skrzyni Biegow" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for(int i = 0; i<Dane.size(); i++)
    {
        cout << i+1;
        cout << ". ";
        cout << Dane[i];
    }
    cout << "--------------------------------------------------------------" << endl;
}

void DodanieDoWektora( vector<Samochody> & Dane,  const string & Samochod) // Funkcja, ktora wywoluje deserializacja danych aby dodawac kolejne
                                                                            // elementy do wektora
{
    int j = 0;
    string Data[6];
    for (auto & i : Data) {
        while (Samochod[j] != ' ' && j != Samochod.length()) {
            i += Samochod[j];
            j++;
        }
        j++;

    }

    unsigned int rocznik = atof(Data[2].c_str());
    unsigned int przebieg = atof(Data[4].c_str());
    double pojemnosc = atof(Data[3].c_str());

    Dane.push_back(Samochody(Data[0], Data[1], rocznik, pojemnosc, przebieg, Data[5]));

}

void deserializacjaDanych(vector<Samochody> & Dane) // Funkcja odczytuje z pliku dane oraz dodaje je do wektora
{
    if(Dane.empty())
    {
        fstream plik;
        string Samochod;
        try {
            plik.open("Dane.txt", ios::in);
        }
        catch (...) {
            cout << "Baza danych nie istnieje" << endl;
        }

        while (getline(plik, Samochod)) {
            DodanieDoWektora(Dane, Samochod);

        }
        plik.close();

    }
}

void serializacjaDanych(const vector<Samochody> & Dane) // Funkcja zapisuje dane w pliku
{
    fstream plik;
    try {


        plik.open("Dane.txt", ios::out);
    } catch(...)
    {
        cout << "Blad przy zapisywaniu katalogu" << endl;
    }

    for(const auto & i : Dane)
    {
    plik << i;
    }

    plik.close();
}

void Nawigacja(vector<Samochody> & Dane)
{
    bool CzyPrawidlowy = false;
    string model;
    char WyborMenu;

    while(!CzyPrawidlowy) {
    cout << "Witaj w katalogu samochodowym. Dokonaj wyboru opcji: " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "1. WCZYTAJ KATALOG Z PLIKU" << endl;
    cout << "2. ZAPISZ OBECNY KATALOG DO PLIKU" << endl;
    cout << "3. DODAJ NOWY SAMOCHOD" << endl;
    cout << "4. WYSWIETLANIE LISTY SAMOCHODOW" << endl;
    cout << "5. WYSWIETL DANE WYBRANEGO SAMOCHODU" << endl;
    cout << "6. WYSWIETL SAMOCHODY O POJEMNOSCI WIEKSZEJ NIZ WYBRANA" << endl;
    cout << "7. SORTUJ SAMOCHODY PO WYBRANYM PARAMETRZE" << endl;
    cout << "8. USUN SAMOCHOD O PODANYM ID" << endl;
    cout << "9. WYJSCIE" << endl;
    cout << "-----------------------------------------------------" << endl;
        cout << "Wybierz opcje: ";
        WyborMenu = getch();
        getch();
        cout << endl;
        switch (WyborMenu) {
            case '1':
                cout << "Wczytywanie katalogu z pliku" << endl;
                deserializacjaDanych(Dane);
                break;
            case '2':
                cout << "Zapisanie obecnego katalogu do pliku" << endl;
                serializacjaDanych(Dane);
                break;
            case '3':
                cout << "Dodawanie nowego samochodu" << endl;
                cout << "--------------------------" << endl;
                DodawanieDoKatalogu(Dane);
                cout << "Samochod zostal dodany do kolekcji" << endl;
                break;
            case '4':
                cout << "Wyswietlanie listy samochodow" << endl;
                WyswietlanieListy(Dane);
                cout << "Aby wrocic do menu glownego wcisnij dowolny klawisz: ";
                getch();
                getch();
                cout << endl;
                break;
            case '5':
                cout << "Jakiego modelu samochodu chcesz wyswietlic dane" << endl;
                cin >> model;
                WyswietlanieModelu(Dane,model);
                cout << "Aby wrocic do menu glownego wcisnij dowolny klawisz: ";
                getch();
                getch();
                cout << endl;

                break;
            case '6':
                double pojemnosc;
                cout << "Podaj minimalna pojemnosc, ktora cie interesuje: ";
                cin >> pojemnosc;
                WyswietlanieWarunkowe(Dane,pojemnosc);
                cout << "Aby wrocic do menu glownego wcisnij dowolny klawisz: ";
                getch();
                getch();
                cout << endl;
                break;
            case '7':
                int wybor;
                cout << "Po jakim parametrze chcesz posortowac samochody ?" << endl;
                cout << "1. Marka" << endl;
                cout << "2. Model" << endl;
                cout << "3. Rocznik" << endl;
                cout << "4. Pojemnosc" << endl;
                cout << "5. Przebieg" << endl;
                cout << "6. Typ Skrzyni Biegow" << endl;
                cout << "Podaj wartosc: ";
                cin >> wybor;
                if(wybor<=6 && wybor >=1)
                {
                    Sortowanie(Dane, wybor);
                    WyswietlanieListy(Dane);
                }
                else
                {
                    cout << "Podano zly parametr";
                }
                cout << "Aby wrocic do menu glownego wcisnij dowolny klawisz: ";
                getch();
                getch();
                cout << endl;

                break;
            case '8':
                int id;
                cout << "Podaj numer ID samochodu, ktory chcesz usunac: ";
                cin >> id;
                UsuwanieZKatalogu(Dane, id);
                break;


            case '9':
                cout << "Wylaczanie programu" << endl;
                exit(0);
                break;
            default:
                cout << "Kliknieto zly przycisk" << endl;
                break;

        }

    }


}




int main() {
    vector<Samochody> Dane;
    Nawigacja(Dane);
}
