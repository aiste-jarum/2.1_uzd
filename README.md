# 2_uzd

*Programos release'ai:*

# V2.0
- Pridėta dokumentacija, daryta su doxyen.
- Patestuoti kai kurie programos kodo gabaliukai su Catch framework.

Failai:
- 

# V1.5
- Pridėta nauja bazinė klasė "zmones", studentų klasė padaryta išvestine iš žmonių klasės.
- Žmonėms skirta bazinė klasė padaryta abstrakčiaja.

# V1.2
- Pataisyta V1.1 naudojantis "Rule of three" principu (koreguotas konstruktorius ir destruktorius).
 

# V1.1
- Sudaro failai:
1) class.cpp - užduoties realizacija naudojant klases ir asmeninį (ne vieną iš nurodytų būdų) rūšiavimui.
2) vector_old.cpp - jau anksčiau realizuota užduotis tokiu pačiu rūšiavimo algoritmu, bet su struktūromis.
3) Makefile failas, kuriame surašytos kompiliavimo komandos, naudojamos sukompiliuoti .cpp failams.

- Programos efektyvumo palyginimas, skaičiuojamas visas įrašų apdorojimo laikas (namų darbų skaičius visur vienodas): lyginamas clas.cpp ir vector_old.cpp

  |  class.cpp   |vector_old.cpp|    įrašai   |
  |--------------|--------------|-------------|
  |   7.228  s   |   7.51054 s  |  100 000    |
  |  75.2872 s   |  74.0584  s  |  1 000 000  |
  | 720.19   s   | 747.006   s  |  10 000 000 |
  
- Išvados:
Tiek naudojant struct, tiek class, programos veikimo laikas išlieka labai panašus.

- Programos efektyvumas buvo išmatuotas ir su skirtingais flag'ais(visi tyrimai su clas.cpp failu):

  |    no flag   |    -O1     |    -O2    |     -O3    |    įrašai   |
  |--------------|------------|-----------|------------|-------------|
  |   7.228  s   |   5.269 s  |  5.247 s  |   6.1138 s |   100 000   |
  |  75.2872 s   |  53.64  s  | 51.523 s  |  52.3676 s |  1 000 000  |


- Įdiegimo instrukcija:
  1) Atsisiūskite failų zip aplanką; 
  2) "extract"'inkite į kokį nors aplanką.

- Naudojimosi instrukcija:
  1) Atsidarę komandinę eilutę nueikite į aplanką, kuriame yra "extract"'intni atsisiųsti failai;
  2) Veskite norimas komandas iš žemiau esančio komadų sarašo (jos aprašytos Makefile faile).
  
- Komandinės eilutės komandos:

|Vardas     |Funkcija                                                    |
|-----------|------------------------------------------------------------|
|vector_old |kompiliuoja ir linkina vector_old.cpp failą                 |
|class      |kompiliuoja ir linkina class.cpp failą                      |
|class1     |kompiliuoja ir linkina class.cpp failą + naudoja -O1 flag'ą |
|class2     |kompiliuoja ir linkina class.cpp failą + naudoja -O2 flag'ą |
|class3     |kompiliuoja ir linkina class.cpp failą + naudoja -O3 flag'ą |
|clean      | ištrina sukompiliuotus failus                              |
  
  
  

# V1.0
- Sudaro failai (list tipo nėra):
1) vector_old.cpp  - užduoties įvykdymas savo (jau seniau padaryta) strategija su vector tipo konteineriu: rūsiuojant studentus į dvi grupes yra saugomi tik jų vektoriaus indeksai, pagal kuriuos vėliau į failus surašomi galutiniai duomenys;

2) deque_old.cpp  - užduoties įvykdymas jau anksčiau minėta strategija, tik jau su deque konteineriu;

3) vector_1_strat.cpp  - užduoties įvykdymas pagal pirmą reikalaujamą strategiją: sukuriami du nauji vector tipo konteineriai ir į juos suskirstomi studentai;

4) deque_1_stratt.cpp  - užduoties įvkdymas jau anksčiau minėta strategija, bet jau su deque tipo konteineriais;

5) vector_2_strat.cpp - užduoties įvykdymas pagal antrą reikalaujamą strategiją: iš jau esamo sarašo į naujai sukurtą konteinerį išrenkami "vargšiukai" ir iš7 seno konteinerio ištrinami, o "kietekai" paliekami sename konteineryje;

6) deque_2_strat.cpp  - užduoties įvykdymas jau anksčiau minėta strategija, bet su deque tipo konteineriais;

7) vector_2_alg.cpp  - programos failo vector_2_strat.cpp efektyvumo tobulinimas. Panaudotas std::remove_if algoritmas, kartu su std::clear algoritmu greitesniam duomenų ištrynimui iš seno vektoriaus konteinerio, kuriame paliekami studentai "kietekai";

Kitų vektoriaus užduoties įvykdymo failų neišėjo patobulinti su pasiūlytais algoritmais, nes tai padarius rūšiavimo laikas tik pailgėjo (algoritmų neapsimokėjo taikyti);

8) Makefile failas, kuriame surašytos kompiliavimo komandos, naudojamos sukompiliuoti .cpp failams.

- Programos efektyvumo palyginimai:
  - Skirtingų strategijų (namų darbų skaičius visur vienodas):
 
  |vector_old.cpp|deque_old.cpp|vector_1_strat.cpp|deque_1_stratt.cpp|vector_2_strat.cpp|deque_2_strat.cpp|įrašai    |
  |--------------|-------------|------------------|------------------|------------------|-----------------|----------|
  |   0 s        |   0 s       |      0.002 s     |     0.00099 s    |      0.079 s     |     0.032 s     |1 000     |
  |   0 s        |   0.00099 s |      0.0099 s    |     0.011 s      |      7.8 s       |     2.913 s     |10 000    |
  |   0 s        |   0.01 s    |      0.0857 s    |     0.107 s      |    774.598 s     |   315.495 s     |100 000   |
  |   0.0305 s   |   0.08 s    |      0.981 s     |     1.114 s      |      ???? s      |     ???? s      |1 000 000 |
  |   0.3290 s   |   0.853 s   |      bad_alloc   |     bad_alloc    |      ???? s      |     ???? s      |10 000 000|
    
   -Išvados: 
   1) Seniau naudotu būdu surūšiuoti studentus užtrunka labai mažą laiko tarpą, vektoriaus konteineris 2-3 kartus efektyvesnis už deką;
   2) vector_1_strat.cpp ir deque_1_strat.cpp užtrunka kelis kartus ilgiau, nei sena strategija ir neefektyviai naudoja atmintį (10 mil. įrašų neapdoroja dėl atminties trūkumo).
   3) vector_2_strat.cpp ir deque_2_strat.cpp užtrunka itin ilgai, neaišku, ar sugeba apskaičiuoti 10 mil. kiekį įrašų, nes labai ilgai reikia laukti programos veikimo pabaigos. Vektoriaus tipo konteineriai 2-3 kartus ekeftyvesni, nei deko studentų rūšiavime.
   
   -Nenaudojant ir naudojant algoritmus su vektoriaus konteineriais:
vector_old.cpp ir vector_1_strat.cpp nurodytų algoritmų panaudoti neišėjo, nes vector_old.cpp studentų grupavimo algoritmas buvo per paprastas keitimui, o panaudojus nurodytus algoritmus faile vector_1_strat.cpp rūšiavimo laikas pailgėjo; todėl bus lyginami vector_2_strat.cpp (paprastas sprendimas) ir vector_2_alg.cpp (prieš tai minėtas sprendimas,bet jau su algoritmais) failai.

 |įrašai      |vector_2_start.cpp| vector_2_alg.cpp|
 |------------|------------------|-----------------|
 |1 000       |    0.079 s       |   0 s           |
 |10 000      |    7.8 s         |   0.012985 s    |
 |100 0000    |  774.598 s       |   0.128923 s    |
 |1 000 000   |    ????? s       |   1.22802 s     |
 |10 000 000  |    ????? s       |   bad_alloc     |
 
 -Išvados:
 vector_2_alg.cpp panaudotas std::remove_if algoritmas, kartu su std::clear algoritmu žymiai pagreitina studentų rūšiavimą, palyginus su vector_2_start.cpp faile naudojamu tik std::clear agoritmu. 
 
- Įdiegimo instrukcija:
  1) Atsisiūskite failų zip aplanką; 
  2) "extract"'inkite į kokį nors aplanką.

- Naudojimosi instrukcija:
  1) Atsidarę komandinę eilutę nueikite į aplanką, kuriame yra "extract"'intni atsisiųsti failai;
  2) Veskite norimas komandas iš žemiau esančio komadų sarašo (jos aprašytos Makefile faile).
 
- Komandinės eilutės komandos:

|Vardas     |Funkcija                                   |
|-----------|-------------------------------------------|
|vector_old |kompiliuoja ir linkina vector_old.cpp failą|
|deque_old  |---------------//----- deque_old.cpp failą |
|vector1    |----------//----- vector_1_strat.cpp failą |
|deque1     |-------------//--- deque_1_strat.cpp failą |
|vector2    |---------//------ vector_2_strat.cpp failą |
|deque2     |--------//-------- deque_2_strat.cpp failą |
|vector2_alg|-----------//------ vector_2_alg.cpp failą |
|clean      | ištrina sukompiliuotus failus             |



# V0.5

- V0.4 pagrindu parašyta programa, skirta stebėti veiksmų spartą skiriantis studentų struktūros tipui. Naudojami skirtingi tipai: vector, deque, (list nėra).
- Įkeltos vector ir deque programos versijos ir jų veikimo trukmės screenshot'ai.
- Sparta lyginama generuojant skirtingą skaičių namų darbų pažymių studentams.


                                          VECTOR                                 
            
             |    1 namų darbas     |   2 namų darbai      |    3 namų darbai     |Irašų skaičius         |
             |----------------------|----------------------|----------------------|-----------------------|
             |   N       /  G       |    N      /  G       |     N     /    G     |Nuskaitymas/Grupavimas |
             | 0.002992 s/  0 s     | 0.00399  s/0.001001 s| 0.006961 s/    0    s| 1 000                 |
             | 0.030917 s/  0 s     | 0.038896 s/     0   s| 0.060837 s/0.000997 s| 10 000                | 
             | 0.342219 s/0.001995 s| 0.376203 s/0.002992 s| 0.792901 s/0.00399  s| 100 000               |
             | 3.37417  s/0.18949  s| 4.45665  s/0.027924 s| 5.87952  s/0.02992  s| 1 000 000             |
             |34.8439   s/0.21445  s|43.9385   s/0.318296 s|68.9828   s/0.369882 s| 10 000 000            |
                        
                        
                        
                        
             ----------------------------------------------------------------------
             |                             DEQUE                                  |
             |--------------------------------------------------------------------|
             |    1 namų darbas     |   2 namų darbai      |    3 namų darbai     |
             |--------------------------------------------------------------------|
             |   N       /  G       |    N      /  G       |     N     /    G     | Nuskaitymas/grupavimas
             | 0.003988 s/  0 s     | 0.003989 s/     0   s| 0.004994 s/    0    s| 1000 įrašų 
             | 0.032924 s/  0 s     | 0.042881 s/0.000999 s| 0.05865  s/    0    s| 10000 įrašų
             | 0.404587 s/0.007978 s| 0.647964 s/0.010971 s| 0.751307 s/0.007978 s| 100000 įrašų 
             | 3.80412  s/0.07803  s| 5.03027  s/0.08497  s| 5.69316  s/0.090594 s| 1000000 įrašų
             |40.1279   s/0.882708 s|55.9054   s/1.01355  s|59.3479   s/0.958949 s| 10000000 įrašų
             ______________________________________________________________________
                        
- Testo pastebėjimai:
  - Tiek vector, tiek deque įrašų apdorojimo laikas didėja didėjant kiekvieno studento gautų namų darbų pažymių skaičiui. Skirtumai žmogaus akimi pastebimi tik prie didesnių įrašų kiekio.
  - Įrašų apdorojimo laikas yra lygiagretus įrašų skaičiui (jeigu įrašų kiekis padidėja 10 kartų, tai ir jų apdorojimas užtruks apie 10 kartų ilgiau).
  - Deque užtrunka apie 3-4 kartus ilgiau grupuojant įrašus į grupes, nei vector.
  - Deque įrašų nuskaitymo laikas didėja lėčiau, nei vector, daugėjant įrašų skaičiui. Deque užtrunka ilgiau nuskaitant po 1 namų darbą, bet skaitant 3 pralenkia vector konteinerį. 
  
- Testavimo sistema:
  - Intel (R) Core(TM) i5-8265U CPU @ 1.60 GHz;
  - 8.00 GB RAM;
  - WDC PC SN520 SDAPNUW-256G-1002 SSD;
                        
                        
                        
            




# V0.4

- Naudojant V0.1 pagrindą programa perrašyta taip, kad pati pilnai generuotų studentų sąrašų failus (1000, 10.000, 100.000, 1.000.000, 10.000.000 įrašų dydžio), juos nuskaitytų, padarytų skaičiavimus, studentus pagal vidurkius surūšiuotų į "gerus" ir "blogus" ir juos išvestų į 2 skirtingus failus.
- Naudojama chrono bibliteka skaičiuoti kiek laiko užtrunka: 1) sąrašų generavimas; 2) jų nuskaitymas; 3) rūšiavimas į 2 grupes; 4) išvedimas į 2 atskirus failus. Į ekraną išvedamos veiklų trukmės sekundėmis. (failų repozitorijoje įkelti 2 pavyzdžiai su skirtingu kiekiu generuojamų namų darbų pažymių)
- Programai baigus darbą yra gaunami 5 (skirtingo dydžio) duomenų failai, 5 "gerų studentų" failai ir 5 "blogų studentų" failai. Failo pavadinime yra parašyta kiek gerų ir blogų studentų buvo atrinkta kiekvienu atvėju. (failų repozitorijoje yra įkeltas gaunamų failų pavadinimų pavyzdys).


# V0.3

- Atliktas refactoring'as: nauji duomenų tipai ir funkcijos perkeltos į atskirus .h ir .cpp failus.
- Exception handling: programa praneša apie kai kuriuos neteisingus įvestus duomenis, neegzistuojančius duomenų failus.

# V0.2

- Pridėta funkcija nuskaityti studentų vardus, pavardes ir jų pažymius iš tekstinio failo.
- Dabar skaičiuojama ir išvedama ir vidurkis, ir mediana.
- Rezultatai į ekraną išvedami išrikiuoti abėcėlės tvarka pagal pavardes (+senas apipavidalinimas).

# V0.1 

- Programa skaičiuoja pažymių ir egzamino vidurkį (pagal formulę VIDURKIS = nd pažymys * 0,4 + egzamino pažymys * 0,6).
- Programa skaičiuoja visų pažymių (nd + egzamino) medianą.
- Galima įvesti ne vieno, bet daug studentų pažymius, kadangi kiekvieno studento informacijai naudojama struktūra.
- Užduotis realizuota dviem būdais: 1) saugant namų darbų pažymius masyve dinaminėje atmintyje; 2) saugant namų darbų pažymius vektoriuje. Dėl naudojamo dinaminio masyvo / vektoriaus nereikia iš anksto žinoti namų darbų pažymių kiekio.
- Yra galimybė įvedus studento vardą ir pavardę sugeneruoti namų darbų ir egzamino pavyzdžius atsitiktinai.
- Rezultatai į ekraną išvedami apipavidalinti (lygiuoti), vidurkiai / medianos išvedamos 2 skaičių po kablelio tikslumu.
