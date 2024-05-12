#include <iostream>
using namespace std;

class ErrorInfo {
public:
	string methodName;
	string lineNum;
	string message;
};

int divFunc(int numerator, int divisor)
{
	int result;
	cout << "Div begin" << endl;
	if (divisor <= 0) {
		ErrorInfo errorDetails;
		errorDetails.methodName = "divFunc";
		errorDetails.lineNum = "13";
		errorDetails.message = "Divisor value cannot be zero or negative";
		throw errorDetails;
	}
	result = (numerator / divisor);
	cout << "Div end" << endl;
	return result;
}

void init() {
	cout << "Init begin" << endl;
	try{
	int result = divFunc(10, 0);
	cout << "Init end" << ":" << result << endl;
	}
	catch (ErrorInfo& exobj) {
		cout << "Method name : " << exobj.methodName << endl;
		cout << "Line number : " << exobj.lineNum << endl;
		cout << "Message is : " << exobj.message << endl;
	}
}

int main() {
	cout << "Main begin" << endl;
	init();
	cout << "Main end" << endl;
}