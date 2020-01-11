/**
VIZSGA 2020-01-14

FIGYELEM! A vizsga megkezdese elott ezt olvassa at.

A szintekhez a define tagokat kell allítani 0-rol 1-re.
Ahol kiemeleten jelezve van, azokat a kodreszeket tilos megvaltoztatni. Megvaltoztatas eseten a vizsga sikertelen.
A vizsga megvalosíthato a main.cpp jelzett reszein, illetve kulon .cpp, .h es .hpp fajlokban.
Memoriaszivargas lete eseten a vizsga elegtelen.

Online (internet, stackoverflow, diasorok stb.) es offline (jegyzetek, konyvek) segedeszkozok hasznalhatoak. Ugyanakkor a munka nem kollaboratív, így mas ember (padtars, Skype, Viber, Facebook stb.) segítsege kizarva. 
A szabalyok megsertese a vizsga automatikus sikertelenseget vonja maga utan.

A leírtakat megertettem es elfogadom: 
Nev:
Neptun kod:

----
Specifikacio:
A Galaktikus Birodalom uj csillagrombolokat keszul epíttetni az uj kíserleti uzemeben. 
Vader nagyur szeretne nyilvantartasba venni az eddig elkeszult rombolokat, erre biztosított egy C++ programleírast.
Minden csillagrombolo rendelkezik:
- egy konstans egyedi nevvel, 
- konstans maximalis/minimalis legenysegkapacitassal, 
- aktualis legenysegszammal rendelkezik
- konstans maximalis/minimalis turbolezerszammal
- aktualis turbolezerszammal
Minden csillagrombolo tud mozogni, sebezni. 
Ketfele csillagrombolo letezik:
- Imperial-osztaly: minimalis legenyseg jelenlete eseten:
    - a mozgas 1.0 warp speed
	- a tozero 100*turbolezerszam
- Executor-osztaly: rendelkezik ion agyukkal is. Minimalis legenyseg jelenlete eseten: 
    - a mozgas 1.5 warp speed
	- a tozero 150*turbolezerszam+1000*ionagyuszam
A csillagrombolokat egy flottaba szeretnenk szervezni.

2-es jegyert (SZINT_2): Keszítse el a ket csillagrombolo típus osztalydefiníciojat (Imperial, Executor)!
              Keszítsen egy flotta osztalyt, ami tartalmaz csillagrombolokat!
			  Definialja a Csillagromobolo osztalyokat!
			     - Imperial csillagrombolo konstruktora megadja a nevet, aktualis legenysegszamot es aktualis turbolezerszamot. 				      
					  A konstruktorban allítsa be a minimalis (29000) es maximalis (45000) legenysegszamot.
					  A konstruktorban allítsa be a minimalis (40) es maximalis (80) turbolezerszamot.					  
				 - Executor csillagrombolo konstruktora megadja a nevet, az aktualis legenysegszamot, aktualis turbolezerszamot es aktualis ionagyuszamot.
				      A konstruktorban allítsa be a minimalis (50000) es maximalis (350000) legenysegszamot.
					  A konstruktorban allítsa be a minimalis (1500) es maximalis (2500) turbolezerszamot.
					  A konstruktorban allítsa be a minimalis (200) es maximalis (300) ionagyu szamot.
				- Minden csillagrombolohoz hozza lehessen adni az addLegenyseg metodussal es el lehessen venni a removeLegenyseg metodussal
				    az eppen aktualis legenyseghez!
				- Minden csillagrombolorol meg lehessen allapítani, hogy uzemkepes-e (checkUzemkepes)! 
			  Implementalja a kovetkezo metodusokat a csillagrombolokhoz:
			     - double mozgas()
				 - int tuzero()
			  Implementalja a kovetkezo segedmetodusokat a CsillagRombolo osztalyhoz
			     - unsigned int getLegenyseg() const					: visszater az aktualis legenyseg szamaval
				 - std:string getName() const							: visszater az hajo nevevel
				 - void addLegenyseg(const unsigned int legenyseg)		: hozzaad legenyseg szamu legenyseget
				 - void removeLegenyseg(const unsigned int legenyseg)   : eltavolit legenyseg szamu legenyseget
				 - bool checkUzemkepes() const							: Vagyis: aktualis_legenyseg >= minimalis_legenyseg?
				 - unsigned int getMaxLegenyseg() const					: visszater a hajohoz rendelheto maximalis legenysegszammal
				 - unsigned int getMinLegenyseg() const					: visszater a hajohoz rendelheto minimalis legenysegszammal
			  A flotta csak egyszer peldanyosulhat, legyen ez az osztaly singleton (ld. Singleton design pattern).
			     - Konstruktora nem hívhato meg kívulrol
				 - Copy konstruktor es assignment le van tiltva
				 - a getInstance() nevo statikus metoduson keresztul kerheto le egy peldanya
				 - a freeInstance szabaítsa fel a getInstance altal letrehozott objektumot!
			  A flottahoz az addCsillagrombolo metodussal lehet uj csillagrombolot hozzaadni, egy Csillagrombolo mutatot varva.
			  A flottabol lekerdezheto egy csillagrombolo a nevevel (getCsillagrombolo). Ekkor terjen vissza az adott csillagrombolora mutato pointerrel.
			  A flotta adja vissza, hogy aktualisan hany darab csillagrombolo van a flottaban. (getQuantity)
			  A flotta szamontartja a tartalek legenyseget is ami kezdetben 0.
			     A flottahoz lehessen hozzarendelni tartalek legenyseget, aminek bemeno parametere egy pozitív egesz szam (rendelTartalekLegenyseg). Lehessen lekerdezni az aktualis tartaleklegenyseget!
3-as jegyert (SZINT_3): 
			 Legenyseget lehessen hozzaadni a flotta egy csillagrombolojahoz a Flotta addLegenyseg metodusaval a flottahoz rendelt tartalek legenyseg szamabol. 
			    A metodus a csillagrombolo nevet es egy darabszamot var!
			 Ugyanezt a fuggvenyt valosítsa meg ugy is, hogy egy csillagrombolora mutato pointert var!
			 Minden hozzarendeles csokkentse a flottahoz rendelt tartalek legenyseg szamat!
			 Ennek inverzet is valosítsa meg, a Flotta tartalekbaHelyez metodusaval. A metodus varja a csillagrombolo nevet es a darabszamot!
			 Szamolja azt is ki, hogy a flotta ellatasahoz mekkora legenysegre van szukseg! (getPersonnel) Ezt a csillagrombolokhoz aktualisan rendelt legenyseg es a tartalek legenyseg osszegevel kapja meg.
4-es jegyert (SZINT_4):
             Legyen a flottanak egy checkMovable metodusa, ami ellenorzi, hogy a flotta uzemkepes-e (minden hajon rendelkezesre all-e minimalis legenyseg). Terjen vissza az elso olyan hajonak a mutatojaval, ami nem uzemkepes!
			 A checkAddLegenyseg metodus ugyanazt valosítsa meg, mint az addLegenyseg (pointer argumentum), viszont dobjon kivetelt, ha a hozzarendelessel tullepnenk egy csillagrombolo kapacitasat (ErrorLegenyseg), vagy 0 ala csokkenne a flotta tartalekos legenysege (ErrorTartalekos).
			 A checkTartalekbaHelyez metodus ugyanazt valosítsa meg, mint a tartalekbaHelyez (pointer argumentum) metodus, viszont dobjon kivetelt (ErrorLegenyseg), ha a csillagrombolo minimalis legenysegkapacítasa ala mennenk!
			 A flottatol elvonhato tartalek legenyseg (checkedRemoveTartalekos), ellenorizze, hogy ne csokkenjen 0 ala a legenyseg - ha 0 ala csokkenne dobjon kivetelt (ErrorTartalekos)!
5-os jegyert (SZINT_5):
             A Flotta addCsillagromboloChecked metodusa ellenorizze, hogy a hozzaadando csillagrombolo szerepel-e a flottaban! 
			   Amennyiben szerepel, a legenyseget rendelje hozza a flottaban szereplo csillagrombolohoz! Mas attributum ne valtozzon!
			 Ehhez definialjon felul egy operator==-t, amivel ellenorzi ket csillagrombolo azonossagat! Ket csillagrombolo azonos, ha ugyanaz a nevuk!
			 A csillagrombolokat lehessen std::ostream-re kiíratni! Ugyanígy, egy flotta listazhato legyen, az osszes csillagrombolo felsorolasaval!
			   A kiiratasban legyen benne a nev, aktualis legenyseg, min. legenyseg, max. legenyseg!

Jo munkat!


*/

// Ez a resz a kívant szintnek megfeleloen valtoztathato (0 vagy 1)
#define SZINT_2 1
#define SZINT_3 1
#define SZINT_4 1
#define SZINT_5 1
// Ha fejleszt, erdemes kikapcsolni az ellenorzest
#define ELLENORZES 1
// Ezt a reszt TILOS megvaltoztatni
#include <iostream>
#include <cassert>
// END TILOS

#include "csillagrombolo.h"

// Ebben a reszben szabadon lehet include-olni tovabbi fajlokat


// END INCLUDE

// Ide kerulhet az implementacio

// A vizsgafeladatot tartalmazo fuggveny. Szabadon lehet kikommentelni egyes hívasokat.
// Az assert reszek nem valtoztathatok meg. Ezek megvaltoztatasa a vizsga sikertelenseget vonja maga utan.
void vizsga()
{
	std::cout << "VIZSGA 2020-01-14\n";



#if SZINT_2
	std::cout << "-------   2-es szint -----------\n";
	// Ellenorzeskent ezt a reszt kommentelje ki! Ha ezt kikommenteli es jol implementalta a feladatot, akkor a programnak nem szabad lefordulnia!
	// CsillagRombolo cs1;
	// Csillagrombolok peldanyosítasa
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
	// Mozgas ellenorzese
	std::cout << "Vehement warp-speed: " << vehement->mozgas() << ", elvart: 1.0\n";
	assert(vehement->mozgas() == 1.0);
	std::cout << "Exactor warp-speed: " << vehement->mozgas() << ", elvart: 1.0\n";
	assert(exactor->mozgas() == 1.0);
	std::cout << "Devastator warp-speed: " << vehement->mozgas() << ", elvart: 0.0\n";
	assert(devastator->mozgas() == 0.0);
	std::cout << "Executor warp-speed: " << vehement->mozgas() << ", elvart: 1.5\n";
	assert(executor->mozgas() == 1.5);
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
	// uzemkepesseg
	std::cout << "Vehement uzemkepes: " << vehement->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(vehement->checkUzemkepes());
	std::cout << "Exactor uzemkepes: " << exactor->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(exactor->checkUzemkepes());
	std::cout << "Devastator uzemkepes: " << devastator->checkUzemkepes() << ",\t Elvart: 0\n";
	assert(!devastator->checkUzemkepes());
	std::cout << "Executor uzemkepes: " << executor->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(executor->checkUzemkepes());
#endif
	// Flotta peldanyosítasa
	// Ellenorzeskent ezt a reszt ha kikommenteli, es jol implementalta a feladatot, akkor a programnak nem szabad lefordulnia
	// Flotta flotta_peldany;
	// Flotta peldanyosítasanak ellenorzese
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
	// Ellenorizzuk mokodokepes-e a flotta
	std::cout << "A flotta nem mukodik, nincs eleg legenyseg, a kovetkezo hajon nincs eleg legenyseg: " << flotta->checkMovable()->getName() << '\n';
#if ELLENORZES
	assert(flotta->checkMovable() != nullptr);
	assert(flotta->checkMovable() == devastator);
#endif
	// Hibakezeles ellenorzes
	bool error_not_thrown = false;
	std::cout << "Eljarasok helyessegenek tesztelese: " << '\n';
	try
	{
		flotta->checkedAddLegenyseg(vehement, 15000);
		error_not_thrown = true;
	}
	catch (ErrorLegenyseg e)
	{
		std::cout << "Tul sok embert kivanunk hozzaadni egy csillagrombolohoz!" << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
	try
	{
		flotta->checkedAddLegenyseg(executor, 25000);
		error_not_thrown = true;
	}
	catch (ErrorTartalekos e)
	{
		std::cout << "Nincs eleg tartalekos a flottaban!" << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
	try
	{
		flotta->checkedTartalekbaHelyez(executor, 250000);
	}
	catch (ErrorLegenyseg e)
	{
		std::cout << "A legenyseg tartalekbahelyezesevel mukodeskeptelenne valna egy csillagrombolo! " << e.getMsg() << '\n';
	}
    // A metodusok tesztje utan adjunk hozza az egyetlen hianyzo hajohoz 
	// Ellenorizzuk mokodokepes-e a flotta	
	try
	{
		std::cout << "Devastator potlasa megfelelo mennyisegu legenyseggel: (+2000)\n";
		flotta->checkedAddLegenyseg(devastator, 2000);
		std::cout << "Devastator legenysege: " << devastator->getLegenyseg() << ", elvart legenyseg 30 000\n";
		assert(devastator->getLegenyseg() == 30000);
	}
	catch (ErrorTartalekos e)
	{
		std::cerr << "Nem szabadna semmi hibat dobni, valami gond van\n";
		return;
	}
	catch(ErrorLegenyseg e)
	{
		std::cerr << "Nem szabadna semmi hibat dobni, valami gond van\n";
		return;
	}
#if ELLENORZES
	assert(flotta->checkMovable()==nullptr);

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
