#include"observer.h"
int observer_main() {
	weatherstation w;
	std::shared_ptr<observer> app = std::make_shared<weatherApp>(1);
	w.subscribe(app);
	w.notify();
	w.unsubscribe(app);
	return 0;
}

int main()
{
	observer_main();
}
