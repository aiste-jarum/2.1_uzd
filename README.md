# 2_uzd

*Programos release'ai:*

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
