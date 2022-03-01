#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<cassert>

class Duck {
public:
	virtual void quack() const = 0;
	virtual ~Duck() = default;
};

class WildDuck : public Duck {
public:
	void quack() const override{
		std::cout << "Wild quack" << std::endl;
	}

	virtual ~WildDuck() = default;
};

class Turkey {
public:
	virtual void gobble() const = 0;
	virtual ~Turkey() = default;
};

class WildTurkey : public Turkey {
public:
	void gobble() const override {
		std::cout << "Wild gobble" << std::endl;
	}

	virtual ~WildTurkey() = default;
};
// Make turkey part of Duck interface
class TurkeyAdapter : public Duck {

private:
	const Turkey& t;
public:
	TurkeyAdapter(Turkey& t_) noexcept :t{ t_ } {}
	//implement the pure Duck interface
	void quack() const override {
		t.gobble();
	}
	virtual ~TurkeyAdapter() = default;
};

