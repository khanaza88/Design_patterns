#pragma once
#include<memory>
#include<vector>
#include<algorithm>
#include<cassert>
#include<iostream>

class PrepareDrink {
	virtual void boil_liquid() const = 0;
	virtual void add_ingredient() const = 0;
	virtual void storage_mechanism() const = 0;
	
public:
	// This is the template method, non-virtual, available to all the derived class. 
	// The method this function calls are private and virutal that needs to be implemented in the derived class 
	// and will differ according to the functionality the derived class is designed to provide.
	void prepare_drink(){
		boil_liquid();
		add_ingredient();
		storage_mechanism();
	}
	
	virtual ~PrepareDrink() = default;
};


class PrepareCoffee : public PrepareDrink {

	void boil_liquid() const override {
		std::cout << "Boil water for 10 minutes" << std::endl;
	}
	void add_ingredient() const override {
		std::cout << "add coffee according to the strength needed" << std::endl;
	}
	void storage_mechanism() const override {
		std::cout << " it is better to store it in a coffee pot" << std::endl;
	}
public:
	virtual ~PrepareCoffee() = default;
};

class PrepareChai: public PrepareDrink {

	void boil_liquid() const override {
		std::cout << "Boil Milk for 10 minutes" << std::endl;
	}
	void add_ingredient() const override {
		std::cout << "add sugar, ginger, and tea " << std::endl;
	}
	void storage_mechanism() const override {
		std::cout << " it is better to store it in a Tea pot" << std::endl;
	}
public:
	virtual ~PrepareChai() = default;

};
