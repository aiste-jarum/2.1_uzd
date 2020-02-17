#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct studentai
{
    string vardas;
    string pavarde;
    double galutinis;
    double mediana;
    int eg;
    int vidurkis = 0;
    vector<int> Pazymiai;
    int dydis;
};

int main()
{
   int stud;
   char pasirink, gen;
   cout << "Kiek norite ivesti studentu? ";
   cin >> stud;
   studentai st [stud];
   for (int i = 0 ; i < stud; i++)
   {
       cout << "Iveskite " << i + 1 << " studento varda ir pavarde: ";
       cin >> st[i].vardas >> st[i].pavarde;

       cout << "Ar generuoti studentu pazymius atsitiktinai? (t / n): ";
       cin >> gen;
       if (gen == 'n')
       {
       int k = 1, temp, skait = 0, dydis = 1;
       cout << "Ivede namu darbu pazymi spauskite ENTER" << endl;
       cout << "Baige vesti pazymius iveskite bet koki skaiciu didesni uz 10" << endl;
       while (k == 1)
       {
            cout << "Pazymys: ";
            cin >> temp;
            if (temp > 10) break;
            else
            {
                k = 1;
                st[i].Pazymiai.push_back(temp);
                skait++;
                dydis++;
            };
       }
       cout << "Kiek studentas gavo is egzamino? ";
       cin >> st[i].eg;
       st[i].Pazymiai.push_back(st[i].eg);
       }
       else
       {
            int dyd = rand() % 10 + 1;
            for (int z = 0; z < dyd; z++) st[i].Pazymiai.push_back(rand() % 10 + 1);
            st[i].eg = rand() % 10 + 1;
            st[i].dydis = dyd + 1;
            st[i].Pazymiai.push_back(st[i].eg);
       }
   }
   cout << "Skaiciuoti studentu vidurkius ar medianas? (v / m) ";
   cin >> pasirink;
   for (int i = 0 ; i < stud; i++)
   {   int dydis = st[i].Pazymiai.size();
       if (pasirink == 'm')
    {
        double mediana;
        sort(st[i].Pazymiai.begin(), st[i].Pazymiai.end());
        if ((dydis) % 2 == 0)
            {
                double a;
                a = st[i].Pazymiai[int(dydis / 2) - 1] + st[i].Pazymiai[int(dydis / 2)];
                mediana = a / 2.0;
            }
        else mediana = st[i].Pazymiai[dydis / 2];
        st[i].mediana = mediana;
    }
    else
    {   int vidurkis = 0;
        float galvid, galutinis;
        for (int j = 0; j < dydis - 1; j++) vidurkis += (double)st[i].Pazymiai[j];
        galvid = (float) vidurkis / (float) (dydis - 1);
        st[i].galutinis = galvid * 0.4 + st[i].eg * 0.6;
    }
   }
    for (int i = 0; i < 4; i++) cout << endl;
    if (pasirink == 'v')
    cout << left << "Vardas         " << left << "Pavarde             " << "Galutinis (Vid.)" << endl;
    else cout << left << "Vardas         " << left << "Pavarde             " << "Galutinis (Med.)" << endl;
    for (int i = 0 ; i < 50; i++) cout << "-";
    cout << endl;
    for (int i = 0; i < stud; i++)
    {
        if (pasirink == 'v') cout << setw(15) << left << st[i].vardas << setw(20) << left << st[i].pavarde << setw(10) << setprecision(3) << st[i].galutinis << endl;
        else cout << setw(15) << left << st[i].vardas << setw(20) << left << st[i].pavarde << setw(10) << setprecision(3) << st[i].mediana << endl;
    }

}
