#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>

class observer {
public:
	virtual void update(int) = 0;
};


class weatherApp : public observer
{
private:
	int id;
	int temp;
public:
	explicit weatherApp(int  id_){
		id = id_;
		temp = 0;
	}

	virtual void update(int t_) override{
		temp = t_;
		std::cout << "I am weather app; current temp is " << temp << std::endl;
	}
};


class subject { 
public:
	virtual void subscribe(std::shared_ptr<observer>&) = 0;
	virtual void unsubscribe(std::shared_ptr<observer>&) = 0;
	virtual void notify() = 0;
};

class weatherstation : public subject {
public:
	virtual void subscribe(std::shared_ptr<observer>& o) override {
		observers.push_back(o);
		std::cout << "subscribed"<<std::endl;
	}
	virtual void unsubscribe(std::shared_ptr<observer>&o) override {
		std::remove(observers.begin(), observers.end(), o);
		std::cout << "unsubscribed" <<std::endl;
	}
	virtual void notify() override {
		for (auto& ob : observers) {
			int t = 100; // or call the function to get the value
			ob->update(100);
		}
	}


private:
	int temp;
	std::vector<std::shared_ptr<observer>> observers;
};

int main() {
	weatherstation w;
	std::shared_ptr<observer> app = std::make_shared<weatherApp>(1);
	w.subscribe(app);
	w.notify();
	w.unsubscribe(app);
	return 0;
}