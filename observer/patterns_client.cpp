#include"observer.h"
#include"decorator.h"
#include"command.h"
#include"adapter.h"
#include"Template.h"

int observer_main() {
	weatherstation w{};
	constexpr int id{ 1 };
	std::shared_ptr<observer> app = std::make_shared<weatherApp>(id);
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

void adapter_main() {
	// create a turkey
	Turkey&& wt = WildTurkey();
	const Duck&& d = TurkeyAdapter(wt);
	d.quack(); // should print gobble 
}
void template_main() {
	PrepareDrink &&chai = PrepareChai();
	PrepareDrink &&coffee= PrepareCoffee();
	std::shared_ptr<PrepareDrink> spChai = std::make_shared<PrepareChai>();
	chai.prepare_drink();
	coffee.prepare_drink();
	spChai->prepare_drink();
}
int main()
{
	//command_main();
	//adapter_main();
	template_main();
}
