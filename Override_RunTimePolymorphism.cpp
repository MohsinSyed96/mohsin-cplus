#include <string>
#include <iostream>
using namespace std;

// If base class is not virtual then it will be shadowing and it calls Base class method otherwise it will be RunTime polymorphism and calls derived class method.
// accept has different versions of itself but will be assigned during runtime --> When Runtime polymorphism is implemented, this is called Strategy pattern. Otherwise it is a Template pattern.
class TextBox {
public:
	virtual void accept(string text) {
		cout << "Textbox accepted" << endl;
	}
};

class NumericTextBox : public TextBox {
public:
	void accept(string text) override {
		cout << "Numeric Textbox accepted" << endl;
	}
};

class MaskedTextBox : public TextBox {
public:
	void accept(string text) override {
		cout << "Masked Textbox accepted" << endl;
	}
};

int main() {
	TextBox nameTextBox;
	nameTextBox.accept("Tom");

	NumericTextBox ageTextBox;
	ageTextBox.accept("25");

	TextBox* BasePtr = &ageTextBox;
	BasePtr->accept("35");

	MaskedTextBox phoneNumTextBox;
	BasePtr = &phoneNumTextBox;
	BasePtr->accept("+91-123456789");
}