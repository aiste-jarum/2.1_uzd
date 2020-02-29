#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "vardef.h"
#include "fuctions.h"
#include "fuctions.cpp"


int main()
{
    const char DUOM[] = "duom.txt";
    int stud;
    std::string gen;
    std::string ivedimas;

    try
    {
    std::cout << "Duomenys bus ivedami rankiniu budu ar yra failas? (rank / fail)" <<std::endl;
    std::cin >> ivedimas;
    if ((ivedimas.compare("rank")) != 0 && ivedimas.compare("fail") != 0) throw 0;
    }
    catch (...) {std::cout << "IVESKITE TEISINGA PASIRINKIMA." << std::endl; };

    std::cout << "Keliu studentu duomenis norite apdoroti? ";
    std::cin >> stud;
    studentai st [stud];
    if (ivedimas == "rank")
    {
            std::cout << "Ar generuoti studentu pazymius atsitiktinai? (t / n): ";
            std::cin >> gen;

        for (int i = 0 ; i < stud; i++)
        {
            std::cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde: ";
            std::cin >> st[i].vardas >> st[i].pavarde;

            if (gen == "n")
            {
                int k = 1, temp, skait = 0, dydis = 1;
                std::cout << "Ivede namu darbu pazymi spauskite ENTER" << std::endl;
                std::cout << "Baige vesti pazymius iveskite bet koki skaiciu didesni uz 10." << std::endl;
                while (k == 1)
                {
                    std::cout << "Pazymys: ";
                    std::cin >> temp;
                    if (temp > 10) break;
                    else
                    {
                        k = 1;
                        st[i].Pazymiai.push_back(temp);
                        skait++;
                        dydis++;
                    };
            }
            std::cout << "Kiek studentas gavo is egzamino? ";
            std::cin >> st[i].eg;
            st[i].Pazymiai.push_back(st[i].eg);
            }
            else Rand_pazymiai(i, st);
        }
   }
   else
   {
        std::ifstream duom (DUOM);
        try
        {
            if (!duom) throw 0;
        }
        catch (...) {std::cout << "FAILAS NEEGZISTUOJA" << std::endl; };
        std::string temp;
        int ndkiek = -3, laik;
        while (temp.front() != 'E')
        {
            duom >> temp;
            ndkiek++;
        }
        int i;
        for (i = 0; i < stud; i++)
        {
            duom >> st[i].vardas >> st[i].pavarde;
            for (int j = 0; j < ndkiek; j++)
            {
                duom >> laik;
                st[i].Pazymiai.push_back(laik);
            }
            duom >> st[i].eg;
            st[i].Pazymiai.push_back(st[i].eg);
        }
        duom.close();
   }
   for (int i = 0 ; i < stud; i++)
   {    int dydis = st[i].Pazymiai.size();
        Mediana (st, dydis, i);
        Vidurkis (st, i, dydis);
   }

    studentai temp;
    Sort (stud, st, temp);
    Print (stud, st);
}

