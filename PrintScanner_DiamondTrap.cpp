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
    virtual void print(const string& content) = 0;
};

class IScanner {
public:
    virtual void scan(const string& content) = 0;
};

class Printer : public Device, public IPrinter {
public:
    Printer(string n, string m, string v) : Device(n, m, v) {
        cout << "Printer Instantiated" << endl;
    }
    ~Printer() {
        cout << "Printer Destructed" << endl;
    }
    void print(const string& content) override {
        cout << "Print " << content << endl;
    }
};

class Scanner : public Device, public IScanner {
public:
    Scanner(string n, string m, string v) : Device(n, m, v) {
        cout << "Scanner Instantiated" << endl;
    }
    ~Scanner() {
        cout << "Scanner Destructed" << endl;
    }
    void scan(const string& content) override {
        cout << "Scan " << content << endl;
    }
};

class PrintScanner : public Device, public IPrinter, public IScanner {
public:
    PrintScanner(string n, string m, string v) : Device(n, m, v) {
        cout << "PrintScanner Instantiated" << endl;
    }
    ~PrintScanner() {
        cout << "PrintScanner Destructed" << endl;
    }
    void print(const string& content) override {
        cout << "Print " << content << endl;
    }
    void scan(const string& content) override {
        cout << "Scan " << content << endl;
    }
};

class TaskManager : public IPrinter, public IScanner {
public:
    void print(const string& content) override {
        cout << "Print " << content << endl;
    }
    void scan(const string& content) override {
        cout << "Scan " << content << endl;
    }
    void InvokePrintTask(IPrinter* printerPtr, const string& content) {
        printerPtr->print(content);
    }
    void InvokeScanTask(IScanner* scannerPtr, const string& content) {
        scannerPtr->scan(content);
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