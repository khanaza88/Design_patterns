#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<cassert>

class observer {
public:
	virtual void update(int) = 0;
	virtual ~observer() {}
};


class weatherApp : public observer
{
private:
	int id;
	int temp;
public:
	explicit weatherApp(int  id_) noexcept{
		id = id_;
		temp = 0;
	}

	void update(int t_) override{
		temp = t_;
		std::cout << "I am weather app; current temp is " << temp << std::endl;
	}
	~weatherApp() {};
};


class subject { 
public:
	virtual void subscribe(std::shared_ptr<observer>&) = 0;
	virtual void unsubscribe(std::shared_ptr<observer>&) = 0;
	virtual void notify() = 0;
};

class weatherstation : public subject {
public:
	void subscribe(std::shared_ptr<observer>& o) override {
		observers.push_back(o);
		std::cout << "subscribed"<<std::endl;
	}
	void unsubscribe(std::shared_ptr<observer>&o) override {
		(void)std::remove(observers.begin(), observers.end(), o)=
		std::cout << "unsubscribed" <<std::endl;
	}
	void notify() override {
		for (auto& ob : observers) {
			ob->update(100);
		}
	}

private:
	int temp;
	std::vector<std::shared_ptr<observer>> observers;
};
