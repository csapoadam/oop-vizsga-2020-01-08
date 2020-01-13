#pragma once

#include <string>
#include <map>
#include <exception>

class CsillagRombolo
{
protected:
	const std::string name;
	const unsigned int min_legenyseg;
	const unsigned int max_legenyseg;
	unsigned int current_legenyseg;
	const unsigned int min_turbolezer;
	const unsigned int max_turbolezer;
	unsigned int current_turbolezer;
public:
	
	CsillagRombolo(
		const std::string name,		
		const int min_legenyseg,
		const int max_legenyseg,
		const int current_legenyseg,
		const int min_turbolezer,
		const int max_turbolezer,
		const int current_turbolezer) :
		name(name),
		min_legenyseg(min_legenyseg),
		max_legenyseg(max_legenyseg),
		current_legenyseg(current_legenyseg),
		min_turbolezer(min_turbolezer),
		max_turbolezer(max_turbolezer),
		current_turbolezer(current_turbolezer)
	{

	}

	virtual unsigned int tuzero() = 0;

	unsigned int getLegenyseg()
	{
		return current_legenyseg;
	}

	const std::string getName()
	{
		return name;
	}

	void addLegenyseg(const unsigned int legenyseg)
	{
		current_legenyseg += legenyseg;
	}

	void removeLegenyseg(const unsigned int legenyseg)
	{
		current_legenyseg -= legenyseg;
	}

	bool checkUzemkepes() const
	{
		return current_legenyseg >= min_legenyseg;
	}

	unsigned int getMaxLegenyseg() const
	{
		return max_legenyseg;
	}

	unsigned int getMinLegenyseg() const
	{
		return min_legenyseg;
	}

	friend bool operator==(CsillagRombolo& cs0, CsillagRombolo& cs1);
	friend std::ostream& operator<<(std::ostream& o, const CsillagRombolo& cs);
};


std::ostream& operator<<(std::ostream& o, const CsillagRombolo& cs)
{	
	o << cs.name << '\t' << cs.current_legenyseg << '\t' << " " << cs.min_legenyseg << " "<< cs.max_legenyseg;
	return o;
}



bool operator==(CsillagRombolo& cs0, CsillagRombolo& cs1)
{
	return cs0.name.compare(cs1.name)==0;
}

class Imperial: public CsillagRombolo
{
protected:

public:
	Imperial(const std::string name, unsigned int current_legenyseg, unsigned int current_turbolezer) : 
		CsillagRombolo(name, 29000, 45000, current_legenyseg, 40, 80, current_turbolezer)
	{

	}

	

	virtual unsigned int tuzero()
	{
		if (checkUzemkepes())
		{
			return current_turbolezer * 100;
		}
		return 0;
	}

	
};

class Executor : public CsillagRombolo
{
private:
	const unsigned int min_ion_agyu;
	const unsigned int max_ion_agyu;
	unsigned int current_ion_agyu;
protected:

public:	
	Executor(const std::string name, unsigned int current_legenyseg, unsigned int current_turbolezer, unsigned int current_ion_agyu) : 
		CsillagRombolo(name, 50000, 350000, current_legenyseg, 1500, 2500, current_turbolezer), 
			min_ion_agyu(200), max_ion_agyu(350), current_ion_agyu(current_ion_agyu)
	{

	}

	

	virtual unsigned int tuzero()
	{
		if (checkUzemkepes())
		{
			return current_turbolezer * 150 + current_ion_agyu * 1000;
		}
		return 0;
	}
};

class ErrorLegenyseg : public std::exception
{
private:
	std::string msg;
public:
	ErrorLegenyseg(std::string msg) : msg(msg) {}
	std::string getMsg()
	{
		return msg;
	}
};

class ErrorTartalekos : public std::exception
{
private:
	std::string msg;
public:
	ErrorTartalekos(std::string msg) : msg(msg) {}

	std::string getMsg()
	{
		return msg;
	}
};

class Flotta
{
protected:
	std::map<std::string, CsillagRombolo*> csillagrombolok;
	Flotta(): tartaleklegenyseg(0) {};
	Flotta(Flotta&) = delete;
	Flotta& operator=(const Flotta&) = delete;
	unsigned int tartaleklegenyseg;
public:
	static Flotta* getInstance()
	{
		static Flotta* instance = new Flotta();
		return instance;
	}

	static void freeInstance()
	{
		delete getInstance();
	}

	unsigned int getTartalekLegenyseg()
	{
		return tartaleklegenyseg;
	}

	void addCsillagrombolo(CsillagRombolo* csillagrombolo)
	{
		csillagrombolok[csillagrombolo->getName()] = csillagrombolo;
	}

	void addCsillagromboloChecked(CsillagRombolo* csillagrombolo)
	{
		const auto v = csillagrombolok.find(csillagrombolo->getName());
		if (csillagrombolok.find(csillagrombolo->getName()) == csillagrombolok.end())
		{
			addCsillagrombolo(csillagrombolo);
		}
		else 
		{
			v->second->addLegenyseg(csillagrombolo->getLegenyseg());
		}
	}

	

	CsillagRombolo* getCsillagRombolo(std::string name)
	{
		for (const auto& cs : csillagrombolok)
		{
			if (cs.first.compare(name) == 0)
			{
				return cs.second;
			}
		}
		//return csillagrombolok.find(name);
		return nullptr;
	}

	void addTartalekLegenyseg(const unsigned int legenyseg)
	{
		tartaleklegenyseg += legenyseg;
	}

	unsigned int getQuantity()
	{
		return csillagrombolok.size();
	}

	void addLegenyseg(const std::string name, unsigned int legenyseg)
	{
		for (auto& cs : csillagrombolok)
		{
			if (cs.first.compare(name) == 0)
			{
				cs.second->addLegenyseg(legenyseg);
				tartaleklegenyseg -= legenyseg;
			}			
		}
	}

	void tartalekbaHelyez(const std::string name, unsigned int legenyseg)
	{
		for (auto& cs : csillagrombolok)
		{
			if (cs.first.compare(name) == 0)
			{
				cs.second->removeLegenyseg(legenyseg);
				tartaleklegenyseg += legenyseg;
			}
		}
	}

	void addLegenyseg(CsillagRombolo* csillagromobolo, unsigned int legenyseg)
	{
		csillagromobolo->addLegenyseg(legenyseg);
		tartaleklegenyseg -= legenyseg;		
	}

	void tartalekbaHelyez(CsillagRombolo* csillagromobolo, unsigned int legenyseg)
	{
		csillagromobolo->removeLegenyseg(legenyseg);
		tartaleklegenyseg += legenyseg;
	}

	unsigned int getOsszesLegenyseg() const
	{
		unsigned int osszes_legenyseg = 0;
		for (const auto& v : csillagrombolok)
		{
			osszes_legenyseg += v.second->getLegenyseg();
		}
		osszes_legenyseg += tartaleklegenyseg;
		return osszes_legenyseg;
	}

	CsillagRombolo* checkImmobility()
	{
		for (const auto& v : csillagrombolok)
		{
			if (!v.second->checkUzemkepes())
			{
				return v.second;
			}
		}
		return nullptr;
	}

	void addLegenysegChecked(CsillagRombolo* csillagromobolo, unsigned int legenyseg)
	{
		if (legenyseg < tartaleklegenyseg)
		{
			if (legenyseg + csillagromobolo->getLegenyseg() > csillagromobolo->getMaxLegenyseg())
			{
				throw ErrorLegenyseg("Tullepi a max kapacsitast a: " + csillagromobolo->getName());
			}
			else
			{
				addLegenyseg(csillagromobolo, legenyseg);
			}
		}
		else
		{
			throw ErrorTartalekos("Hianyzik tartalekos!");
		}
	}

	void tartalekbaHelyezChecked(CsillagRombolo* csillagromobolo, unsigned int legenyseg)
	{
		if (csillagromobolo->getLegenyseg() < csillagromobolo->getMinLegenyseg() + legenyseg)
		{
			throw ErrorLegenyseg("Mukodeskeptelenne valna az: " + csillagromobolo->getName());
		}
		else
		{
			tartalekbaHelyez(csillagromobolo, legenyseg);
		}
	}

	void removeTartalekosChecked(unsigned int legenyseg)
	{
		if (tartaleklegenyseg < legenyseg )
		{
			throw ErrorTartalekos("Nincs eleg tartalekos!");
		}
		else
		{
			tartaleklegenyseg -= legenyseg;
		}
	}

	friend std::ostream& operator<<(std::ostream& o, const Flotta& f);
};

std::ostream& operator<<(std::ostream& o, const Flotta& f)
{
	o << "Galaktikus kiserleti flotta\n";
	for (const auto& v : f.csillagrombolok)
	{
		o << *v.second << '\n';
	}
	return o;
}