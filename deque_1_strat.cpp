#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <deque>

using namespace std::chrono;

struct studentai
{
    std::string vardas = "Vardas_";
    std::string pavarde = "Pavarde_";
    double galutinis;
    double mediana;
    int eg;
    int vidurkis = 0;
    std::vector<int> Pazymiai;
    int dydis;
};

int main()
{
    int stud = 1000;
    srand(time(NULL));
    int dyd = 5;
    std::cout << "Kiekvienam studentui generuojami " << dyd << " namu darbu pazymiai ir egzamino pazymys." << std::endl;
    std::cout << std::endl;
    for (int ciklas = 0; ciklas < 5; ciklas++)
    {
        std::deque<studentai> st(stud);
        for (int i = 0; i < stud; i++)
        {
            std::string sk;
            if (i+1 < 10000000) sk.append("0");
            if (i+1 < 1000000) sk.append("0");
            if (i+1 < 100000) sk.append("0");
            if (i+1 < 10000) sk.append("0");
            if (i+1 < 1000) sk.append("0");
            if (i+1 < 100) sk.append("0");
            if (i+1 < 10) sk.append("0");
            std::string laik = std::to_string(i+1);
            sk.append(laik);
            st[i].vardas.append(sk);
            st[i].pavarde.append(sk);

            for (int z = 0; z < dyd; z++) st.at(i).Pazymiai.push_back(rand() % 10 + 1);
            st.at(i).eg = rand() % 10 + 1;
            st.at(i).dydis = dyd + 1;
            st.at(i).Pazymiai.push_back(st.at(i).eg);
        }

    std::string duomenys = "Duomenys_";
    std::string kiekis = std::to_string(stud);
    duomenys.append(kiekis);
    duomenys.append(".txt");
    std::ofstream duom (duomenys);
    duom << "Vardas                  Pavarde                    ";
    for (int i = 1; i <= dyd; i++) duom << "ND" << i << "    ";
    duom << "Egzaminas" << std::endl;
    for (int i = 0; i < stud; i++)
    {
        duom << std::setw(20) << std::left << st[i].vardas << std::setw(20) << std::left << st[i].pavarde << " ";
        for (int j = 0; j < dyd; j++) duom << std::setw(8) << std::left << st[i].Pazymiai[j];
        duom << "  " << st[i].eg << std::endl;
    }
    duom.close();
    st.clear();
    st.shrink_to_fit();
    std::deque<studentai> naujas(stud);
    std::ifstream duomuo (duomenys);
    std::string laikinas;
    for (int z = 0; z < 3 + dyd; z++) duomuo >> laikinas;
    for (int z = 0; z < stud; z++)
    {
        duomuo >> naujas[z].vardas >> naujas[z].pavarde;
        for (int k = 0; k < dyd; k++)
        {
            int t;
            duomuo >> t;
            naujas[z].Pazymiai.push_back(t);
        }
        duomuo >> naujas[z].eg;
    }

    for (int i = 0; i < stud; i++)
    {
        int dydis = naujas[i].Pazymiai.size();
        double mediana;
        sort (naujas[i].Pazymiai.begin(), naujas[i].Pazymiai.end());
        if ((dydis) % 2 == 0)
        {
            double a;
            a = naujas[i].Pazymiai[int(dydis/2) - 1] + naujas[i].Pazymiai[int (dydis/2)];
            mediana = a / 2.0;
        }
        else mediana = naujas[i].Pazymiai[dydis / 2];
        naujas[i].mediana = mediana;

        int vidurkis = 0;
        float galvid, galutinis;
        for (int j = 0; j < dydis - 1; j++) vidurkis += (double) naujas[i].Pazymiai[j];
        galvid = (float) vidurkis / (float) (dydis - 1);
        naujas[i].galutinis = galvid * 0.4 + naujas[i].eg * 0.6;

    }
    auto start2 = high_resolution_clock::now();
    std::vector<studentai> varg;
    std::vector<studentai> kiet;
    int vargk=0, kietk=0;
    for (int i = 0; i < stud; i++)
    {
        if(naujas[i].galutinis < 5.0)
            {
                varg.push_back (naujas[i]);
                vargk++;
            }
        else
            {
                kiet.push_back (naujas[i]);
                kietk++;
            }
    }

    auto end2 = high_resolution_clock::now();
    duration<double> diff2 = end2 - start2;

    std::cout << "Failas " << stud << " surusiuotas i 2 grupes per " << diff2.count() << " s\n";

    std::string failasb = "Vargsiukai_";
    std::string failasg = "Kietakai_";
    std::string studb = std::to_string(vargk);
    std::string studg = std::to_string(kietk);
    failasb.append(studb);
    failasg.append(studg);
    failasb.append(".txt");
    failasg.append(".txt");

    std::ofstream rez1 (failasb);
    rez1 << std::left << "Vardas                  " << std::left << "Pavarde               " << "Galutinis (Vid.)/Galutinis(Med.)" << std::endl;
    for (int i = 0 ; i < 60; i++) rez1 << "-";
    rez1 << std::endl;
    for (int i = 0; i < varg.size() - 1; i++)
    {
        rez1 << std::setw(20) << std::left << varg[i].vardas << std::setw(20) << std::left << varg[i].pavarde
        << std::setw(10) << std::right << std::setprecision(3) << varg[i].galutinis << std::setw(15) << std::right
        << std::setprecision(3) << varg[i].mediana << std::endl;
    }
    rez1.close();

    std::ofstream rez2 (failasg);
    rez2 << std::left << "Vardas                  " << std::left << "Pavarde               " << "Galutinis (Vid.)/Galutinis(Med.)" << std::endl;
    for (int i = 0 ; i < 60; i++) rez2 << "-";
    rez2 << std::endl;
    for (int i = 0; i < kiet.size() - 1; i++)
    {
        rez2 << std::setw(20) << std::left << kiet[i].vardas << std::setw(20) << std::left << kiet[i].pavarde
        << std::setw(10) << std::right << std::setprecision(3) << kiet[i].galutinis << std::setw(15) << std::right
        << std::setprecision(3) << kiet[i].mediana << std::endl;
    }
    rez2.close();
    std::cout << std::endl;
    naujas.clear();
    naujas.shrink_to_fit();
    stud *= 10;

    }
}
