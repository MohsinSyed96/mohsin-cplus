#include <string>
using namespace std;

//Abstraction
class IEngine {
public:
	virtual void start() = 0;
	virtual void stop() = 0;
};

//Low level module
class MPFIEngine: public IEngine {
public:
	void start(){}
	void stop(){}
};

class GDIEngine: public IEngine{
public:
	void start() {}
	void stop() {}
};

class StallinEngine: public IEngine {
public:
	void start() {}
	void stop() {}
}; 

//High level module
class XUV3XO {
	//Dependency Abstract
	IEngine* engine;
public:
	//Constructor Dependency Injection
	XUV3XO(IEngine* engineArg) : engine{ engineArg } {}
	void drive() {
		this->engine->start();
	}
	void halt() {
		this->engine->stop();
	}
	~XUV3XO() {}
};

int main() {
	MPFIEngine napEngine;
	GDIEngine turboEngine;
	XUV3XO car{ &napEngine };
	car.drive();
	XUV3XO turboSeries{ &turboEngine };
	return 0;
}

//car uses engine
//car depends on egine
//If the car object is deleted then engine also has to be deleted because it is a death relationship where car contains the engine.