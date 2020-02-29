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

