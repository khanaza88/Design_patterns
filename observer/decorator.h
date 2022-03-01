#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<cassert>

class beverage {
public:
	virtual double cost() const noexcept	= 0;
	virtual ~beverage() = default;
};

class coffee : public beverage {
public:
	double cost() const noexcept override {
		return 1;
	}
	virtual ~coffee() = default;

};

class tea : public beverage {
public:
	double cost() const noexcept override {
		return 2;
	}
	virtual ~tea() = default;
};

class cream : public beverage{
private:
	std::shared_ptr<beverage> b;
public:
	cream(std::shared_ptr<beverage> b_)noexcept {
		b = b_;
	}
	
	double cost() const noexcept override {
		return (0.5 + b->cost());
	}
	virtual ~cream() = default;
};

class sugar : public beverage
{
private:
	std::shared_ptr<beverage> b;
public:
	sugar(std::shared_ptr<beverage> b_) noexcept{
		b = b_;
	}
	
	double cost() const noexcept override {
		return (0.6 + b->cost());
	}

	virtual ~sugar() = default;
	
};
