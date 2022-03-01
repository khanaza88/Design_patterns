#include"observer.h"
#include"decorator.h"
#include"command.h"

int observer_main() {
	weatherstation w;
	std::shared_ptr<observer> app = std::make_shared<weatherApp>(1);
	w.subscribe(app);
	w.notify();
	w.unsubscribe(app);
	return 0;
}

void decorator_main() {
	std::shared_ptr<beverage> b = std::make_shared<coffee>();
	std::cout << "cost of coffee : " << b->cost()<<std::endl;
	std::shared_ptr<beverage> bs = std::make_shared<sugar>(b);
	std::cout << "cost of coffee + sugar : " << bs->cost()<<std::endl;
	std::shared_ptr<beverage> bsc = std::make_shared<cream>(bs);
	std::cout << "cost of coffee + sugar + cream : " << bsc->cost()<<std::endl;

}

void command_main() {
	FanOn f1 = Fan();
	FanOff f2 = Fan();
	execute& e1(f1);
	execute& e2(f2);
	e1.run();
	e2.run();
}
int main()
{
	command_main();
}
