#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>

using namespace std::chrono;

class studentai
{
private:
    std::string vardas;
    std::string pavarde;
    double galutinis;
    double mediana;
    int eg;
    int vidurkis;
    std::deque<int> Pazymiai;
    int dydis;
public:
    studentai()
    {
        vidurkis = 0;
    };
    virtual ~studentai(){};
    std::string getvardas() {return vardas;}
    std::string getpavarde() {return pavarde;}
    double getgalutinis() {return galutinis;}
    double getmediana() {return mediana;}
    int geteg() {return eg;}
    int getvidurkis() {return vidurkis;}
    int getdydis() {return dydis;}
    int getpazymiai(int i) {return Pazymiai[i];}
    void clearpazymiai () {Pazymiai.clear();}
    void setvardas (std:: string v) {vardas = "Vardas_"; vardas.append(v);}
    void setvardas2 (std:: string v) {vardas = v;}
    void setpavarde (std::string p) {pavarde = "Pavarde_"; pavarde.append(p);}
    void setpavarde2 (std::string p) {pavarde = p;}
    void setgalutinis (double g) {galutinis = g;}
    void setmediana (double m) {mediana = m;}
    void seteg (int e) {eg = e;}
    void setvidurkis (int v) {vidurkis = v;}
    void setdydis (int d) {dydis = d;}
    void setpazymiai (int p) {Pazymiai.push_back(p);}
    int getsize () {return Pazymiai.size();}
    std::deque<int>::iterator begining () {return Pazymiai.begin();}
    std::deque<int>::iterator ending () {return Pazymiai.end();}
};

int main()
{
    auto start2 = high_resolution_clock::now();
    int stud = 1000;
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();


    int dyd = 5;
    std::cout << "Kiekvienam studentui generuojami " << dyd << " namu darbu pazymiai ir egzamino pazymys." << std::endl;
    std::cout << std::endl;
    for (int ciklas = 0; ciklas < 5; ciklas++)
    {   std::default_random_engine eng (seed);
        std::vector<studentai> st(1);

        std::string duomenys = "Duomenys_";
        std::string kiekis = std::to_string(stud);
        duomenys.append(kiekis);
        duomenys.append(".txt");
        std::ofstream duom (duomenys);
        duom << "Vardas                  Pavarde                  ";
        for (int i = 1; i <= dyd; i++) duom << "ND" << i << "   ";
        duom << "Egzaminas" << std::endl;


        for (int i = 0; i < stud; i++)
        {

            std::string sk;
            if (i+1 < 10000000) sk.append("0");
            if (i+1 < 1000000) sk.append("0");
            if (i+1 < 100000) sk.append("0");
            if (i+1 < 10000) sk.append("0");
            if (i+1 < 1000) sk.append("0");
            if (i+1 < 100) sk.append ("0");
            if (i+1 < 10) sk.append("0");
            std::string laik = std::to_string(i+1);
            sk.append(laik);
            st[0].setvardas(sk);
            st[0].setpavarde(sk);
            for (int z = 0; z < dyd; z++)
                {st[0].setpazymiai(eng()%10+1); /*std::cout << st[0].getpazymiai(z)<<" ";*/}
            //std::cout << std::endl;
            st[0].seteg(eng()%10+1);
            st[0].setdydis(dyd + 1);
            st[0].setpazymiai(st[0].geteg());


            duom << std::setw(20) << std::left << st[0].getvardas() <<
            std::setw(20) << std::left << st[0].getpavarde() << " ";

            for (int j = 0; j < dyd; j++)
                duom << std::setw(8) << std::left << st[0].getpazymiai(j);
            duom << " " << st[0].geteg() << std::endl;
            st[0].clearpazymiai();

    }
    duom.close();

    std::string failasb = "Vargsiukai_";
    std::string failasg = "Kietakai_";
    std::string studb = std::to_string(stud);
    std::string studg = std::to_string (stud);
    failasb.append(studb);
    failasg.append(studg);
    failasb.append(".txt");
    failasg.append(".txt");

    std::ofstream rez1 (failasb);
    rez1 << std::left << "Vardas                  "
    << std::left << "Pavarde               " <<
    "Galutinis (Vid.)/Galutinis(Med.)" << std::endl;
    for (int i = 0; i < 60; i++) rez1 << "-";
    rez1 << std::endl;

    std::ofstream rez2 (failasg);
    rez2 << std::left << "Vardas                  " << std::left
    << "Pavarde               " <<
    "Galutinis (Vid.)/Galutinis(Med.)" << std::endl;
    for (int i = 0; i < 60; i++) rez2 << "-";
    rez2 << std::endl;


    std::vector<studentai> naujas (1);
    std::ifstream duomuo (duomenys);
    std::string laikinas;
    for (int z = 0; z < 3+ dyd; z++) duomuo >> laikinas;
    std::string temp = "";
    for (int i = 0; i < stud; i++)
    {

            duomuo >> temp;
            naujas[0].setvardas2(temp);
            duomuo >> temp;
            naujas[0].setpavarde2(temp);
            for (int k = 0; k < dyd; k++)
            {
                int t;
                duomuo >> t;
                naujas[0].setpazymiai(t);
            }
            int tempeg;
            duomuo >> tempeg;
            naujas[0].seteg(tempeg);

        int dydis = naujas[0].getsize();
        double mediana;
        std::sort (naujas[0].begining(), naujas[0].ending());
        if ((dydis % 2) == 0)
        {
            double a;
            a = naujas[0].getpazymiai(int (dydis/2) - 1) +
            naujas[0].getpazymiai(int (dydis/2));
            mediana = a /2.0;
        }
        else mediana = naujas[0].getpazymiai(dydis / 2);
        naujas[0].setmediana(mediana);

        int vidurkis = 0;
        float galvid, galutinis;
        for (int j = 0; j < dydis ; j++)
            vidurkis += (double) naujas[0].getpazymiai(j);
        galvid = (float) vidurkis / (float) dydis;
        naujas[0].setgalutinis(galvid * 0.4 + naujas[0].geteg() * 0.6);




        if (naujas[0].getgalutinis() < 5.0)
        {
        rez1 << std::setw(20) << std::left <<
        naujas[0].getvardas() << std::setw(20) <<
        std::left << naujas[0].getpavarde()
        << std::setw(10) << std::right << std::setprecision (3)
        << naujas[0].getgalutinis() << std::setw(15)
        << std::right << std::setprecision(3)
        << naujas[0].getmediana() << std::endl;
        }
        else
        {
        rez2 << std::setw(20) << std::left << naujas[0].getvardas()
        << std::setw(20) << std::left << naujas[0].getpavarde()
        << std:: setw(10) << std::right << std::setprecision(3) <<
        naujas[0].getgalutinis() << std::setw(15) << std::right
        <<std::setprecision(3) << naujas[0].getmediana() << std::endl;
        }
        naujas[0].clearpazymiai();
    }


    rez1.close();
    rez2.close();
    std::cout << std::endl;
    auto end2 = high_resolution_clock::now();
    duration<double> diff2 = end2 - start2;
    std::cout << "Failas " << stud << " apdorotas ir isvesti rezultatai per " << diff2.count() << " s\n";
    if (ciklas < 4)
    {
        naujas.clear();
        naujas.shrink_to_fit();
    }
    stud *= 10;
    }

}
