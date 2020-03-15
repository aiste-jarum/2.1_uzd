# 2_uzd

*Programos release'ai:*

V0.5

- V0.4 pagrindu parašyta programa, skirta stebėti veiksmų spartą skiriantis studentų struktūros tipui. Naudojami skirtingi tipai: vector, deque, (list nėra).
- Įkeltos vector ir deque programos versijos ir jų veikimo trukmės screenshot'ai.
- Sparta lyginama generuojant skirtingą skaičių namų darbų pažymių studentams.


             ----------------------------------------------------------------------
             |                             VECTOR                                 |
             |--------------------------------------------------------------------|
             |    1 namų darbas     |   2 namų darbai      |    3 namų darbai     |
             |--------------------------------------------------------------------|
             |   N       /  G       |    N      /  G       |     N     /    G     | Nuskaitymas/grupavimas 
             | 0.002992 s/  0 s     | 0.00399  s/0.001001 s| 0.006961 s/    0    s| 1000 įrašų  
             | 0.030917 s/  0 s     | 0.038896 s/     0   s| 0.060837 s/0.000997 s| 10000 įrašų
             | 0.342219 s/0.001995 s| 0.376203 s/0.002992 s| 0.792901 s/0.00399  s| 100000 įrašų  
             | 3.37417  s/0.18949  s| 4.45665  s/0.027924 s| 5.87952  s/0.02992  s| 1000000 įrašų
             |34.8439   s/0.21445  s|43.9385   s/0.318296 s|68.9828   s/0.369882 s| 10000000 įrašų
             ______________________________________________________________________
                        
                        
                        
                        
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
  - Įrašų apdorojimo laikas yra lygiagretus įrašų skaičiui (jeigu įrašų kiekis padidėja 10 kartų, tai ir jų apdorojimas užtruks apie ą0 kartų ilgiau).
  - Deque užtrunka apie 3-4 kartus ilgiau grupuojant įrašus į grupes, nei vector.
  - Deque įrašų nuskaitymo laikas didėja lėčiau, nei vector, daugėjant įrašų skaičiui. Deque užtrunka ilgiau nuskaitant po 1 namų darbą, bet skaitant 3 pralenkia vector konteinerį. 
  
- Testavimo sistema:
  - Intel (R) Core(TM) i5-8265U CPU @ 1.60 GHz;
  - 8.00 GB RAM;
  - WDC PC SN520 SDAPNUW-256G-1002 SSD;
                        
                        
                        
            




V0.4

- Naudojant V0.1 pagrindą programa perrašyta taip, kad pati pilnai generuotų studentų sąrašų failus (1000, 10.000, 100.000, 1.000.000, 10.000.000 įrašų dydžio), juos nuskaitytų, padarytų skaičiavimus, studentus pagal vidurkius surūšiuotų į "gerus" ir "blogus" ir juos išvestų į 2 skirtingus failus.
- Naudojama chrono bibliteka skaičiuoti kiek laiko užtrunka: 1) sąrašų generavimas; 2) jų nuskaitymas; 3) rūšiavimas į 2 grupes; 4) išvedimas į 2 atskirus failus. Į ekraną išvedamos veiklų trukmės sekundėmis. (failų repozitorijoje įkelti 2 pavyzdžiai su skirtingu kiekiu generuojamų namų darbų pažymių)
- Programai baigus darbą yra gaunami 5 (skirtingo dydžio) duomenų failai, 5 "gerų studentų" failai ir 5 "blogų studentų" failai. Failo pavadinime yra parašyta kiek gerų ir blogų studentų buvo atrinkta kiekvienu atvėju. (failų repozitorijoje yra įkeltas gaunamų failų pavadinimų pavyzdys).


V0.3

- Atliktas refactoring'as: nauji duomenų tipai ir funkcijos perkeltos į atskirus .h ir .cpp failus.
- Exception handling: programa praneša apie kai kuriuos neteisingus įvestus duomenis, neegzistuojančius duomenų failus.

V0.2

- Pridėta funkcija nuskaityti studentų vardus, pavardes ir jų pažymius iš tekstinio failo.
- Dabar skaičiuojama ir išvedama ir vidurkis, ir mediana.
- Rezultatai į ekraną išvedami išrikiuoti abėcėlės tvarka pagal pavardes (+senas apipavidalinimas).

V0.1 

- Programa skaičiuoja pažymių ir egzamino vidurkį (pagal formulę VIDURKIS = nd pažymys * 0,4 + egzamino pažymys * 0,6).
- Programa skaičiuoja visų pažymių (nd + egzamino) medianą.
- Galima įvesti ne vieno, bet daug studentų pažymius, kadangi kiekvieno studento informacijai naudojama struktūra.
- Užduotis realizuota dviem būdais: 1) saugant namų darbų pažymius masyve dinaminėje atmintyje; 2) saugant namų darbų pažymius vektoriuje. Dėl naudojamo dinaminio masyvo / vektoriaus nereikia iš anksto žinoti namų darbų pažymių kiekio.
- Yra galimybė įvedus studento vardą ir pavardę sugeneruoti namų darbų ir egzamino pavyzdžius atsitiktinai.
- Rezultatai į ekraną išvedami apipavidalinti (lygiuoti), vidurkiai / medianos išvedamos 2 skaičių po kablelio tikslumu.
