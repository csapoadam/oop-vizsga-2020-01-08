#pragma once

#include <string>
#include <vector>
#include <utility>
#include <exception>

class Termek {
private:
	std::string gyarto;
	int ar;
public:
	Termek(std::string g, int a) : gyarto(g), ar(a) {}
	virtual std::string getName() = 0;
	std::string& getGyarto() {
		return gyarto;
	}
};

class Laptop : public Termek {
public:
	Laptop(std::string gyarto, int ar) :
		Termek(gyarto, ar) {}
	virtual std::string getName() {
		std::string s(getGyarto());
		return s + " laptop";
	}
};

class Mobil : public Termek {
private:
	bool wifi;
	bool lte;
public:
	Mobil(std::string gyarto, int ar, bool wifi = true, bool lte = true) :
		Termek(gyarto, ar), wifi(wifi), lte(lte) {}
	virtual std::string getName() {
		std::string s(getGyarto());
		return s + " mobil";
	}
};

class OutOfKeszletError : public std::exception {
private:
	std::string msg;
public:
	OutOfKeszletError(std::string m) : msg(m) {}
	std::string getMsg() {
		return msg;
	}
};

class Keszlet {
private:
	Keszlet() {}
	Keszlet(const Keszlet&) = delete;
	Keszlet& operator=(const Keszlet&) = delete;
	std::vector<std::pair<Termek*, int>> keszlet_vec;
public:
	static Keszlet* GetInstance() {
		static Keszlet* instance = new Keszlet();
		return instance;
	}
	void addTermek(Termek* t, int mennyiseg) {
		keszlet_vec.push_back(std::make_pair(t, mennyiseg));
	}
	int getQuantity(Termek* t) {
		for (auto current_pair : keszlet_vec) {
			if (current_pair.first == t) {
				return current_pair.second;
			}
		}
		return 0;
	}
	void rendel(Termek* t, int mennyiseg) {
		/*int pos = 0;
		for (auto current_pair : keszlet_vec) {
			if (current_pair.first == t) {
				current_pair.second -= mennyiseg;
				keszlet_vec[pos].second = current_pair.second;
				return;
			}
			++pos;
		}
		return;*/
		for (auto it = keszlet_vec.begin(); it != keszlet_vec.end(); ++it) {
			if ( (*it).first == t ) {
				(*it).second -= mennyiseg;
				return;
			}
		}
	}
	void checkedRendel(Termek* t, int mennyiseg) {
		for (auto it = keszlet_vec.begin(); it != keszlet_vec.end(); ++it) {
			if ((*it).first == t) {
				if ((*it).second < mennyiseg) {
					throw OutOfKeszletError("nincs tobb a keszleten");
				}
				(*it).second -= mennyiseg;
				return;
			}
		}
	}
};