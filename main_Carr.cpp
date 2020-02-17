#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct studentai
{
    string vardas;
    string pavarde;
    int dydis = 1;
    double mediana;
    int eg;
    double vidurkis = 0;
    int *Pazymiai = new int[dydis];
};

int main()
{
    int stud;
    char gen;
    studentai *st = new studentai[stud];
    cout << "Kiek studentu vesite? ";
    cin >> stud;

    for (int i = 0; i < stud; i++)
    {
        int skait = 0, temp, k = 1;
        cout << "Iveskite " << i + 1 << " studento varda ir pavarde: ";
        cin >> st[i].vardas >> st[i].pavarde;

        cout << "Ar generuoti studentu pazymius atsitiktinai? (t / n): ";
        cin >> gen;

        if (gen == 'n')
        {
            cout << "Ivede namu darbu pazymi spauskite ENTER" << endl;
            cout << "Baige vesti pazymius iveskite bet koki skaiciu didesni uz 10" << endl;
            while (k == 1)
            {
            cout << "Pazymys: ";
            cin >> temp;
            if (temp > 10) break;
            else
            {   k = 1;
                st[i].Pazymiai[(st[i].dydis) - 1] = temp;
                skait++;
                st[i].dydis++;
            };
            }
            cout << "Kiek studentas gavo is egzamino? ";
            cin >> st[i].eg;
            st[i].Pazymiai[st[i].dydis - 1] = st[i].eg;
        }
        else
        {
            st[i].dydis = rand() % 100 + 1;
            for (int z = 0; z < st[i].dydis; z++) st[i].Pazymiai[z] = rand() % 10 + 1;
            st[i].eg = rand() % 10 + 1;
            st[i].Pazymiai[st[i].dydis] = st[i].eg;
        }
    }

    char pasirink;
    cout << "Skaiciuoti studentu pazymiu vidurkius ar medianas? (v / m) ";
    cin >> pasirink;
    for (int i = 0; i < stud; i++)
    {
        double mediana;
        if (pasirink == 'm')
        {
            sort(st[i].Pazymiai, st[i].Pazymiai + st[i].dydis);
            if ((st[i].dydis) % 2 == 0)
                {
                    double a;
                    a = st[i].Pazymiai[int(st[i].dydis / 2 - 1)] + st[i].Pazymiai[int(st[i].dydis / 2)];
                    mediana = a / 2.0;
                }
            else
                {mediana = st[i].Pazymiai[st[i].dydis / 2];};
            st[i].mediana = mediana;
        }
        else
        {   double galvid;
            for (int z = 0; z < (st[i].dydis - 1); z++) st[i].vidurkis += (double)st[i].Pazymiai[z];
            galvid = (float) st[i].vidurkis / (float) (st[i].dydis - 1);
            st[i].vidurkis = galvid * 0.4 + st[i].eg * 0.6;
        }
    }

    if (pasirink == 'v')
    cout << left << "Vardas         " << left << "Pavarde             " << "Galutinis (Vid.)" << endl;
    else cout << left << "Vardas         " << left << "Pavarde             " << "Galutinis (Med.)" << endl;
    for (int i = 0 ; i < 50; i++) cout << "-";
    cout << endl;
    for (int i = 0; i < stud; i++)
    {
        if (pasirink == 'v') cout << setw(15) << left << st[i].vardas << setw(20) << left << st[i].pavarde << setw(10) << setprecision(3) << st[i].vidurkis << endl;
        else cout << setw(15) << left << st[i].vardas << setw(20) << left << st[i].pavarde << setw(10) << setprecision(3) << st[i].mediana << endl;
    }
}
