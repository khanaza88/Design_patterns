#pragma once
//ok
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<cassert>

class Fan {
public:
	void FanStart() const { std::cout << "fan started"; }
	void Fanstop() const { std::cout << "fan stopped"; }
};
class Heater{
public:
	void HeaterStart() const { std::cout << "Heater started"; }
	void Heaterstop() const { std::cout << "Heater stopped"; }
};

class execute {
public:
	virtual void run() = 0;
};

class FanOn : public execute
{
	Fan f;
public:
	FanOn(const Fan& f_)noexcept:f{f_}{}
	void run() override{ f.FanStart(); }
	virtual ~FanOn() = default;
};
class FanOff : public execute
{
	Fan f;
public:
	FanOff(const Fan& f_) noexcept:f{f_}{}
	void run() override{ f.Fanstop();}
	virtual ~FanOff() = default;
};

class HeaterOn : public execute {
	Heater h;
public:
	HeaterOn(Heater& h_) noexcept:h{h_}{}

	void run() override{
		h.HeaterStart();
	}
	virtual ~HeaterOn() = default;
};
class HeaterOff : public execute {
	Heater h;
public:
	HeaterOff(Heater& h_) noexcept:h{h_}{}

	void run() override{
		h.Heaterstop();
	}

	virtual ~HeaterOff() = default;
};