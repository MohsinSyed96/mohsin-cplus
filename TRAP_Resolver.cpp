// Online C++ compiler to run C++ program online
#include <string>
#include <iostream>
using namespace std;

//Diamond Problem  --- To avoid this we use Virtual inheritance
class Device {
private:
	string name;
	string model;
	string version;
protected:
	Device(string nameArg, string modelArg, string versionArg) : name{ nameArg }, model{ modelArg }, version{ versionArg } {
		cout << "Device Instantiated" << endl;
	}
	~Device() {
		cout << "Device Destructed" << endl;
	}
};

class IPrinter {
public:
	virtual void print() = 0;
};

class IScanner {
public:
	virtual void scan() = 0;
};

class Printer : public Device {
public:
	void Enter(IPrinter* obj) {
		obj->print();
	}
	Printer(string n, string m, string v) : Device(n, m, ) {
		cout << "Printer Instantiated" << endl;
	}
	~Printer() {
		cout << "Printer Destructed" << endl;
	}
	void print(string content) {
		cout << "Print" << content << endl;
	}
};

class Scanner : public Device {
public:
	void Enter(IScanner* obj) {
		obj->scan();
	}
	Scanner(string n, string m, string v) : Device(n, m, v) {
		cout << "Scanner Instantiated" << endl;
	}
	~Scanner() {
		cout << "Scanner Destructed" << endl;
	}
	void scan(string content) {
		cout << "Scan" << content << endl;
	}
};

class PrintScanner : public Device {
public:
	void Enter(IPrinter* obj) {
		obj->print();
	}
	void Enter(IScanner* obj) {
		obj->scan();
	}
	PrintScanner(string n, string m, string v) : Device{ n,m,v } {
		cout << "PrintScanner Instantiated" << endl;
	}
	~PrintScanner() {
		cout << "PrintScanner Destructed" << endl;
	}
};

class TaskManager: public IPrinter, public IScanner {
public:
	void print() {}
	void scan() {}
	void InvokePrintTask(IPrinter* printerPtr, string content) {
		printerPtr->print();
	}
	void InvokeScanTask(IScanner* scannerPtr, string content) {
		scannerPtr->scan();
	}
};

int main() {
	Printer HPPrinter("", "", "");
	Scanner HPScanner("", "", "");
	PrintScanner HPPrintScanner("", "", "");
	TaskManager taskMgr;
	taskMgr.InvokePrintTask(&HPPrinter, "Doc.pdf");
	taskMgr.InvokeScanTask(&HPScanner, "Doc.pdf");
	taskMgr.InvokePrintTask(&HPPrintScanner, "Doc.pdf");
	taskMgr.InvokeScanTask(&HPPrintScanner, "Doc.pdf");
}