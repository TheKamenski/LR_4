#pragma once

#include <iostream>
#include <string>


class Bank_deposit {
	friend std::ostream& operator<<(std::ostream&, const Bank_deposit&);
	friend std::istream& operator>>(std::istream&, Bank_deposit&);
	friend bool operator<(const Bank_deposit&, const Bank_deposit&);
	friend bool operator>(const Bank_deposit&, const Bank_deposit&);

private:
	std::string name_dep;
	double sum_dep;
	std::string unit_money;
	double stavka;

public:
	Bank_deposit();
	Bank_deposit(const std::string name_dep, const double sum_dep, const std::string unit_money, const double stavka);
	Bank_deposit(const Bank_deposit& bank_dep);

};

Bank_deposit::Bank_deposit() { //
	name_dep = "";
	sum_dep = 0.0;
	unit_money = "";
	stavka = 0.0;
}

Bank_deposit::Bank_deposit(const std::string name_dep, const double sum_dep, const std::string unit_money, const double stavka) {
	this->name_dep = name_dep; //то, что в private = тому,что в скобочках)
	this->sum_dep = sum_dep;
	this->unit_money = unit_money;
	this->stavka = stavka;
}

Bank_deposit::Bank_deposit(const Bank_deposit& bank_dep) {
	this->name_dep = bank_dep.name_dep;
	this->sum_dep = bank_dep.sum_dep;
	this->unit_money = bank_dep.unit_money;
	this->stavka = bank_dep.stavka;
}

std::ostream& operator<<(std::ostream& os, const Bank_deposit& bank_dep) {
	os << "Name of deposit: " << bank_dep.name_dep << "\n";
	os << "Sum of deposit: " << bank_dep.sum_dep << "\n";
	os << "Unit of money: " << bank_dep.unit_money << "\n";
	os << "Stavka of deposit: " << bank_dep.stavka << " %\n"; // Stavka of deposit expressed as %: 
	return os;
}

std::istream& operator>>(std::istream& is, Bank_deposit& bank_dep) { 
	is >> bank_dep.name_dep;
	is >> bank_dep.sum_dep;
	is >> bank_dep.unit_money;
	is >> bank_dep.stavka;
	return is;
}

bool operator<(const Bank_deposit& bank_dep_1, const Bank_deposit& bank_dep_2) {
	return bank_dep_1.sum_dep < bank_dep_2.sum_dep;
}

bool operator>(const Bank_deposit& bank_dep_1, const Bank_deposit& bank_dep_2) {
	return bank_dep_1.sum_dep > bank_dep_2.sum_dep;
}