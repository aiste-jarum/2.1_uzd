#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>


struct studentai
{
    std::string vardas;
    std::string pavarde;
    double galutinis;
    double mediana;
    int eg;
    int vidurkis = 0;
    std::vector<int> Pazymiai;
    int dydis;
};

void Vidurkis (studentai st[], int i, int dyd);
void Mediana (studentai st[], int x, int i);
void Sort (int x, studentai st[], studentai temp);
void Print (int x, studentai st[]);
void Rand_pazymiai (int x, studentai st[]);

int main()
{
    const char DUOM[] = "duom.txt";
    int stud;
    std::string gen;
    std::string ivedimas;
    std::cout << "Duomenys bus ivedami rankiniu budu ar yra failas? (rank / fail)" <<std::endl;
    std::cin >> ivedimas;
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




void Rand_pazymiai (int x, studentai st[]) //generuoja atsitiktinius pazymius
{
    int dyd = rand() % 10 + 1;
    for (int z = 0; z < dyd; z++) st[x].Pazymiai.push_back(rand() % 10 + 1);
    st[x].eg = rand() % 10 + 1;
    st[x].dydis = dyd + 1;
    st[x].Pazymiai.push_back(st[x].eg);

}


void Print (int x, studentai st[]) //spauzdina atsakyma i ekrana
{
    for (int i = 0; i < 4; i++) std::cout << std::endl;
    std::cout << std::left << "Vardas         " << std::left << "Pavarde             " << "Galutinis (Vid.) Galutinis (Med.)" << std::endl;
    for (int i = 0 ; i < 68; i++) std::cout << "-";
    std::cout << std::endl;
    for (int i = 0; i < x; i++)
        {
            std::cout << std::setw(15) << std::left << st[i].vardas << std::setw(20) << std::left << st[i].pavarde;
            std::cout << std::setw(15) << std::setprecision(3) << std::right << st[i].galutinis;
            std::cout << std::setw(17) << std::setprecision(3) << std::right << st[i].mediana<<std::endl;
        }
}

void Sort (int x, studentai st[], studentai temp)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x-1; j++)
        {
            if (st[j].pavarde > st[j+1].pavarde) //studentai rikiuojami pagal pavardes
            {
                temp = st[j];
                st[j] = st[j+1];
                st[j+1] = temp;
            }
        }

    }

}

void Mediana (studentai st[], int x, int i)
{
    double mediana;
    sort(st[i].Pazymiai.begin(), st[i].Pazymiai.end());
    if (x % 2 == 0)
    {
        double a;
        a = st[i].Pazymiai[int(x / 2) - 1] + st[i].Pazymiai[int(x / 2)];
        mediana = a / 2.0;
    }
    else mediana = st[i].Pazymiai[x / 2];
    st[i].mediana = mediana;
}

void Vidurkis (studentai st[], int i, int dyd)
{
    double vidurkis = 0;
    float galvid, galutinis;
    for (int j = 0; j < dyd; j++) vidurkis += (double)st[i].Pazymiai[j];
    vidurkis -= st[i].eg;
    galvid = vidurkis / (float) (dyd - 1);
    st[i].galutinis = galvid * 0.4 + st[i].eg * 0.6;
}


