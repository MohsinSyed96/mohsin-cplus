#include <string>
#include <iostream>
using namespace std;

// using macro 
#define ADD(operandOne, operandTwo) (string(operandOne) + string(operandTwo))

// Template function for addition
template<typename T>
T add(T operandOne, T operandTwo) {
	return operandOne + operandTwo;
}

class A {

};

int main() {
	cout << ADD("Real ", "Madrid") << endl;
	int result = add<int>(100, 200);
	cout << result << endl;
	string strResult = add<string>("ABC", "EFG");
	cout << strResult << endl;
	return 0;
}