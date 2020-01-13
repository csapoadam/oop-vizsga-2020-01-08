/*
FIGYELEM! A vizsga megkezdése előtt ezt olvassa át.
-	A különböző szintekhez (2,3,4,5) a #define makrókat kell állítani 0-ról 1-re.
-	Ahol kiemeleten jelezve van, azokat a kódrészeket tilos megváltoztatni. Megváltoztatás esetén a vizsga sikertelen.
-	A vizsga megvalósítható a main.cpp jelzett részein, illetve külön .cpp, .h és .hpp fájlokban.
-	Memóriaszivárgás léte esetén a vizsga elégtelen (delete részek megváltoztatásával).
-	Online (internet, stackoverflow, diasorok stb.) és offline (jegyzetek, könyvek) segédeszközök használhatóak. Ugyanakkor a munka nem kollaboratív, így más ember (padtárs, Skype, Viber, Facebook stb.) segítsége kizárva.
-	A main.cpp-ben sok assert függvényhívást láthat. Ez egy makró, ami egy feltételt vizsgál és annak nem teljesülése esetén futásidejű hibát dob. Az Ön implementációjának tesztelésére és a jegy meghatározására szolgál. Az assert feltételek megváltoztatása TILOS. Az assert részek ideiglenesen az #define ELLENORZES makró 0-ra állításával kapcsolhatók ki, ami ajánlott is a fejlesztés során.
-	A szabályok megsértése a vizsga automatikus sikertelenségét vonja maga után.
A leírtakat megértettem és elfogadom:
Név:
Neptun kód:
Specifikáció
A Galaktikus Birodalom új csillagrombolókat készül építtetni az új kísérleti üzemében. Vader nagyúr szeretné nyilvántartásba venni az eddig elkészült rombolókat, erre biztosított egy C++ programleírást.

2-es jegyért (SZINT_2)
-	Definiálja a CsillagRombolo osztályt! Az osztálynak legyen egy konstans neve. Az Imperial és az Executor osztályokat ebből származtassa. Konstansként legyen definiálva a maximális/minimális legénység és maximális/minimális turbólézerszám. Az osztály jegyezze mennyi az aktuális legénység és turbólézer. A CsillagRombolo ne legyen példányosítható.
    -	Implementálja a következő absztrakt metódust:
		-	int tuzero()
	-	Implementálja a következő segédmetódusokat a CsillagRombolo osztályhoz
		-	unsigned int getLegenyseg(): visszatér az aktuális legénység számával
		-	std:string getName(): visszatér a hajó nevével
		-	void addLegenyseg(unsigned int legenyseg): hozzáad legenyseg számú legénységet
		-	void removeLegenyseg(unsigned int legenyseg): eltávolit legenyseg számú legénységet
		-	bool checkUzemkepes(): Vagyis: aktualis_legenyseg >= minimalis_legenyseg?
		-	unsigned int getMaxLegenyseg(): visszatér a hajóhoz rendelhető maximális legénységszámmal
		-	unsigned int getMinLegenyseg(): visszatér a hajóhoz rendelhető minimális legénységszámmal
-	Készítse el a két származtatott csillagromboló típus osztálydefinícióját: Imperial, Executor!
	-	Imperial-osztály: Konstruktora megadja a nevet, aktuális legénységszámot és aktuális turbólézerszámot.
		-	Konstruktorban állítsa be a minimális (29000) és maximális (45000) legénységszámot.
		-	A konstruktorban állítsa be a minimális (40) és maximális (80) turbólézerszámot.
		-	Megfelelő számú legénység jelenléte esetén: Tűzerő 100*turbolezerszam
	-	Executor-osztály: rendelkezik ion ágyúkkal is, ezt jelezze konstans attribútumokkal. Konstruktora megadja a nevet, az aktuális legénységszámot, aktuális turbólézerszámot és aktuális ionágyúszámot.
		-	A konstruktorban állítsa be a minimális (1500) és maximális (2500) turbólézerszámot.
		-	A konstruktorban állítsa be a minimális (50000) és maximális (350000) legénységszámot.
		-	A konstruktorban állítsa be a minimális (200) és maximális (300) ionágyú számot.
		-	Megfelelő számú legénység jelenléte esetén a Tűzerő 150*turbolezerszam+1000*ionagyuszam
-	Készítsen egy flotta osztályt, ami tartalmaz csillagrombolókat! A Flotta csak egyszer példányosulhat, legyen ez az osztály singleton (ld. Singleton design pattern). A flotta tartsa számon a tartalék legénységet is, ami kezdetben 0.
	-	Konstruktora nem hívható meg kívülről. Copy konstruktor és assignment legyen letiltva.
	-	A getInstance() nevű statikus metóduson keresztül érhető el az egyetlen példányra mutató pointer. A freeInstance szabadítsa fel az egyetlen példányt
	-	Az addCsillagrombolo metódussal lehet új csillagrombolót hozzáadni, egy CsillagRombolo mutatót várva argumentumként.
	-	A flottából lekérdezhető egy csillagromboló a nevével (getCsillagrombolo). Ekkor térjen vissza az adott csillagrombolóra mutató pointerrel.
	-	A flotta adja vissza, hogy aktuálisan hány darab csillagromboló van a flottában. (getQuantity)
	-	A flottához lehessen hozzárendelni tartalék legénységet, aminek bemenő paramétere egy pozitív egész szám (rendelTartalekLegenyseg). Lehessen lekérdezni az aktuális tartaléklegénységet!

3-as jegyért (SZINT_3)
-	Legénységet lehessen hozzáadni a flotta egy csillagrombolójához a Flotta addLegenyseg metódusával a flottához rendelt tartalék legénység számából. A metódus a csillagromboló nevét és egy darabszámot vár!
-	Ugyanezt a függvényt valósítsa meg úgy is, hogy egy csillagrombolóra mutató pointert vár!
-	Minden hozzárendelés csökkentse a flottához rendelt tartalék legénység számát!
-	Ennek inverzét is valósítsa meg, a Flotta tartalekbaHelyez metódusával. A metódus várja a csillagromboló nevét és a darabszámot!
-	Számolja azt is ki, hogy mekkora a flotta teljes legénysége! (getPersonnel) Ezt a csillagrombolókhoz aktuálisan rendelt legénység és a tartalék legénység összegével kapja meg.
4-es jegyért (SZINT_4)
-	Legyen a flottának egy checkImmobility metódusa, ami ellenőrzi, hogy a flotta üzemképes-e (minden hajón rendelkezésre áll-e minimális legénység). Térjen vissza az első olyan hajónak a mutatójával, ami nem üzemképes, vagy nullpointerrel, ha nincs ilyen!
-	A addLegenysegChecked metódus ugyanazt valósítsa meg, mint a Flotta::addLegenyseg (pointer argumentum), viszont dobjon kivételt, ha a hozzárendeléssel túllépnénk egy csillagromboló kapacitását (ErrorLegenyseg), vagy 0 alá csökkenne a flotta tartalékos legénysége (ErrorTartalekos).
-	A tartalekbaHelyezChecked metódus ugyanazt valósítsa meg, mint a tartalekbaHelyez (pointer argumentum) metódus, viszont dobjon kivételt (ErrorLegenyseg), ha a csillagromboló minimális legénységkapacitása alá mennénk!
-	A flottától elvonható tartalék legénység (removeTartalekosChecked), ellenőrizze, hogy ne csökkenjen 0 alá a legénység - ha 0 alá csökkenne, dobjon kivételt (ErrorTartalekos)!
5-ös jegyért (SZINT_5)
-	A Flotta addCsillagromboloChecked metódusa ellenőrizze, hogy a hozzáadandó csillagromboló szerepel-e a flottában!
-	Amennyiben szerepel, a legénységet rendelje hozzá a flottában szereplő csillagrombolóhoz! Más attribútum ne változzon!
-	Ehhez definiáljon felül egy operator==-t, amivel ellenőrzi két csillagromboló azonosságát! Két csillagromboló azonos, ha ugyanaz a nevük!
-	A csillagrombolókat lehessen std::ostream-re kiíratni! Ugyanígy, egy flotta listázható legyen, az összes csillagromboló felsorolásával!  A kiíratásban legyen benne a név, aktuális legénység, min. legénység, max. legénység!

*/


// Ez a resz a kivant szintnek megfeleloen valtoztathato (0 vagy 1)
#define SZINT_2 1
#define SZINT_3 0
#define SZINT_4 0
#define SZINT_5 0
// Ha fejleszt, erdemes kikapcsolni az ellenorzest
#define ELLENORZES 1
// Ezt a reszt TILOS megvaltoztatni
#include <iostream>
#include <cassert>
// END TILOS


// Ebben a reszben szabadon lehet include-olni tovabbi fajlokat
#include "csillagrombolo.h"


// END INCLUDE

// Ide kerulhet az implementacio

// A vizsgafeladatot tartalmazo fuggveny. Szabadon lehet kikommentelni egyes hivasokat.
// Az assert reszek nem valtoztathatok meg. Ezek megvaltoztatasa a vizsga sikertelenseget vonja maga utan.
void vizsga()
{
	std::cout << "VIZSGA 2020-01-14\n";
#if SZINT_2
	std::cout << "-------   2-es szint -----------\n";
	// Ellenorzeskent ezt a reszt kommentelje ki! Ha ezt kikommenteli es jol implementalta a feladatot, akkor a programnak nem szabad lefordulnia!
	// CsillagRombolo cs1;
	// Csillagrombolok peldanyositasa
	Imperial* vehement = new Imperial("Vehement", 37000, 80);
	Imperial* exactor =  new Imperial("Exactor", 32000, 70);
	Imperial* devastator = new Imperial("Devastator", 28000, 35);
	Executor* executor = new Executor("Executor", 290000, 2500, 250);	
#if ELLENORZES
	// Csillagrombolok ellenorzese
	std::cout << "Vehement legenysege: " << vehement->getLegenyseg() << ",\t elvart: 37 000\n";
	assert(vehement->getLegenyseg() == 37000);
	std::cout << "Exactor legenysege: " << exactor->getLegenyseg() << ",\t elvart: 32 000\n";
	assert(exactor->getLegenyseg() == 32000);	
	std::cout << "Devastator legenysege: " << devastator->getLegenyseg() << ",\t elvart: 28 000\n";
	assert(devastator->getLegenyseg() == 28000);
	std::cout << "Executor legenysege: " << executor->getLegenyseg() << ",\t elvart: 290 000\n";
	assert(executor->getLegenyseg() == 290000);
	// Legenyseg hozzaadasa (Vehement)
	vehement->addLegenyseg(1000);
	std::cout << "Vehement legenysege (+1000): " << vehement->getLegenyseg() << ",\t elvart: 38000\n";
	assert(vehement->getLegenyseg()==38000);
	vehement->removeLegenyseg(1000);
	std::cout << "Vehement legenysege (-1000): " << vehement->getLegenyseg() << ",\t elvart: 37000\n";
	assert(vehement->getLegenyseg() == 37000);
	// Legenyseg hozzaadasa (Executor)
	executor->addLegenyseg(1000);
	std::cout << "Executor legenysege (+1000): " << executor->getLegenyseg() << ",\t elvart: 291 000\n";
	assert(executor->getLegenyseg() == 291000);
	executor->removeLegenyseg(1000);
	std::cout << "Executor legenysege (-1000): " << executor->getLegenyseg() << ",\t elvart: 290 000\n";
	assert(executor->getLegenyseg() == 290000);
	// Sebzes ellenorzese
	assert(vehement->tuzero() == 100 * 80);
	assert(exactor->tuzero() == 100 * 70);
	assert(devastator->tuzero() == 0);
	assert(executor->tuzero() == 150 * 2500 + 250 * 1000);
	// Segedmetodusok ellenorzese
	assert(vehement->getMinLegenyseg() == 29000);
	assert(vehement->getMaxLegenyseg() == 45000);
	assert(executor->getMinLegenyseg() == 50000);
	assert(executor->getMaxLegenyseg() == 350000);
	// Uzemkepesseg
	std::cout << "Vehement uzemkepes: " << vehement->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(vehement->checkUzemkepes());
	std::cout << "Exactor uzemkepes: " << exactor->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(exactor->checkUzemkepes());
	std::cout << "Devastator uzemkepes: " << devastator->checkUzemkepes() << ",\t Elvart: 0\n";
	assert(!devastator->checkUzemkepes());
	std::cout << "Executor uzemkepes: " << executor->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(executor->checkUzemkepes());
#endif
	// Flotta peldanyositasa
	// Ellenorzeskent ezt a reszt ha kikommenteli, es jol implementalta a feladatot, akkor a programnak nem szabad lefordulnia
	// Flotta flotta_peldany;
	// Flotta peldanyositasanak ellenorzese
	Flotta* flotta = Flotta::getInstance();
	Flotta* flotta2 = Flotta::getInstance();
#if ELLENORZES
	assert(flotta == flotta2);
	if (flotta == flotta2)
	{
		std::cout << "A kiserleti telepen csak egy flotta hozhato letre\n";
	}
	assert(flotta->getTartalekLegenyseg() == 0);
#endif
	// Csillagrombolok hozzaadasa
	flotta->addCsillagrombolo(vehement);
	flotta->addCsillagrombolo(exactor);
	flotta->addCsillagrombolo(devastator);
	flotta->addCsillagrombolo(executor);
	// Csillagrombolo kiolvasasa
#if ELLENORZES
	assert(flotta->getCsillagRombolo("Vehement") != nullptr);
	assert(flotta->getCsillagRombolo("Executor") != nullptr);
	assert(flotta->getCsillagRombolo("Exactor") != nullptr);
	assert(flotta->getCsillagRombolo("Devastator") != nullptr);
	assert(flotta->getCsillagRombolo("Millenium Falcon") == nullptr);
	assert(flotta->getCsillagRombolo("Vindicator") == nullptr);
#endif
	// Flotta tartalek legenyseg hozzaadasa
	flotta->addTartalekLegenyseg(20000);
#if ELLENORZES
	std::cout << "Flottahoz rendelt tartaleklegenyseg: " << flotta->getTartalekLegenyseg() << ", elvart legenyseg: 20 000\n";
	assert(flotta->getTartalekLegenyseg() == 20000);
#endif
	// Flotta ellenorzese
#if ELLENORZES
	std::cout << "Flottaban levo hajok: " << flotta->getQuantity() << ", elvart hajoszam: 4\n";
	assert(flotta->getQuantity() == 4);
	std::cout << "-----------------------\n";
#endif


#if SZINT_3	
	std::cout << "-------   3-as szint -----------\n";
	flotta->addLegenyseg("Executor", 10000);
	flotta->addLegenyseg(vehement, 1000);
#if ELLENORZES
	std::cout << "Vehement legenysegenek feltoltese a tartalekbol (+1000): " << vehement->getLegenyseg() << ", elvart: 38 000\n";
	assert(vehement->getLegenyseg() == 38000);
	std::cout << "Executor legenysegenek feltoltese a tartalekbol (+10000): " << executor->getLegenyseg() << ", elvart: 300 000\n";
	assert(executor->getLegenyseg() == 300000);
	std::cout << "Maradek tartaleklegenyseg " << flotta->getTartalekLegenyseg() << ", 9 000\n";
	assert(flotta->getTartalekLegenyseg() == 9000);
#endif
	flotta->tartalekbaHelyez("Executor", 10000);
#if ELLENORZES
	// Tartalekba helyezes utan
	std::cout << "Tartalekba helyezes az executorrol (-10000): " << executor->getLegenyseg() << ", elvart: 290 000\n";
	assert(executor->getLegenyseg() == 290000);
	assert(flotta->getTartalekLegenyseg() == 19000);
#endif
	// A szukseges legenyseg ellenorzese
	std::cout << "A flotta ellatasahoz szukseges legenyseg: " << flotta->getOsszesLegenyseg() << ", elvart teljes legenyseg: 407 000\n";
#if ELLENORZES
	assert(flotta->getOsszesLegenyseg() == 407000);
#endif
	std::cout << "------------------\n";
#endif // SZINT_3



#if SZINT_4
	std::cout << "-------   4-es szint -----------\n";
	// Ellenorizzuk mukodokepes-e a flotta
	std::cout << "A flotta nem mukodik, nincs eleg legenyseg, a kovetkezo hajon nincs eleg legenyseg: " << flotta->checkImmobility()->getName() << '\n';
#if ELLENORZES
	assert(flotta->checkImmobility() != nullptr);
	assert(flotta->checkImmobility() == devastator);
#endif
	// Hibakezeles ellenorzes
	bool error_not_thrown = false;
	std::cout << "Eljarasok helyessegenek tesztelese: " << '\n';
	try
	{
		flotta->addLegenysegChecked(vehement, 15000);
		error_not_thrown = true;
	}
	catch (ErrorLegenyseg e)
	{
		std::cout << "Tul sok embert kivanunk hozzaadni egy csillagrombolohoz!" << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
	try
	{
		flotta->addLegenysegChecked(executor, 25000);
		error_not_thrown = true;
	}
	catch (ErrorTartalekos e)
	{
		std::cout << "Nincs eleg tartalekos a flottaban!" << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
	try
	{
		flotta->tartalekbaHelyezChecked(executor, 250000);
		error_not_thrown = true;
	}
	catch (ErrorLegenyseg e)
	{
		std::cout << "A legenyseg tartalekbahelyezesevel mukodeskeptelenne valna egy csillagrombolo! " << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
	try
	{
		flotta->removeTartalekosChecked(90000);
		error_not_thrown = true;
	}
	catch (ErrorTartalekos e)
	{
		std::cout << "Nincs ennyi tartalekos a flottahoz rendelve!" << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
    // A metodusok tesztje utan adjunk hozza az egyetlen hianyzo hajohoz 
	// Ellenorizzuk mukodokepes-e a flotta	
	try
	{
		std::cout << "Devastator potlasa megfelelo mennyisegu legenyseggel: (+2000)\n";
		flotta->addLegenysegChecked(devastator, 2000);
		std::cout << "Devastator legenysege: " << devastator->getLegenyseg() << ", elvart legenyseg 30 000\n";
		assert(devastator->getLegenyseg() == 30000);
	}
	catch (ErrorTartalekos e)
	{
		std::cerr << "Nem szabadna semmi hibat dobni, valami gond van\n";
		assert(false);
		return;
	}
	catch(ErrorLegenyseg e)
	{
		std::cerr << "Nem szabadna semmi hibat dobni, valami gond van\n";
		assert(false);
		return;
	}
#if ELLENORZES
	assert(flotta->checkImmobility()==nullptr);

	std::cout << "A flotta mukodik, minden hajo uzemkepes" << '\n';
	std::cout << "------------------\n";
#endif
#endif // SZINT_4




#if SZINT_5
	std::cout << "-------   5-os szint -----------\n";
	Imperial* vehement2 = new Imperial("Vehement", 2000, 80);
	assert(*vehement == *vehement2);
	flotta->addCsillagromboloChecked(vehement2);
#if ELLENORZES
	std::cout << "A flotta hajoszama: " << flotta->getQuantity() << ", elvart hajoszam: 4\n";
	assert(flotta->getQuantity()==4);
	std::cout << "A Vehement legenysege (+2000): " << vehement->getLegenyseg() << ", elvart legenyseg: 40000 \n";
	assert(vehement->getLegenyseg()==40000);
#endif
	std::cout << *vehement << '\n';
	std::cout << *executor << '\n';
	std::cout << *flotta << '\n';
	std::cout << "------------------\n";
	
	delete vehement2;
#endif // SZINT_5


	delete vehement;
	delete exactor;
	delete devastator;
	delete executor;
	flotta->freeInstance();
	
#endif // SZINT_2
}

// Ezt a reszt TILOS megvaltoztatni
int main(int argc, char** argv)
{
	vizsga();
	return 0;
}
// END TILOS
