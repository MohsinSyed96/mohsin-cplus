//Gallery contains Media Items:
//Media items are of two type - image & videos
//Every item has date created and size
//Every video has diff format - .mp4, mp3, avi
//Every image has diff format - .jpeg, .gif, .png
//Media items can be shared but sharing is done through diff applications
//Apps allowed -- Bluetooth, MailBox, Whatsapp -Only once at a time not together

#include <string>
#include<iostream>
using namespace std;

//Gallery
//Application
//MediaItem
//Image
//Video

//Abstraction
class IMediaItem {
protected:
	string dateCreated;
	int size;

public:
	IMediaItem(string dateCreatedArg, int sizeArg) : dateCreated(dateCreatedArg), size(sizeArg) {}
	virtual void displaydetails() = 0;
};

class IApplication {
public:
	virtual void share(IMediaItem* IMedia) = 0;
	virtual void cancel(IMediaItem* IMedia) = 0;
};


class Image : public IMediaItem {
private:
	string format;
public:
	Image(string dateCreated, int size, string format) : IMediaItem(dateCreated, size), format(format) {}
	void displaydetails() override {
		cout << "Image date created is " << dateCreated << endl;
		cout << "Size is " << size << " MB" << endl;
		cout << "Format is " << format << endl;
	}
};

class Video : public IMediaItem {
private:
	string format;
public:
	Video(string dateCreated, int size, string format) : IMediaItem(dateCreated, size), format(format) {}
	void displaydetails() override {
		cout << "Video date created is " << dateCreated << endl;
		cout << "Size is " << size << " MB" << endl;
		cout << "Format is " << format << endl;
	}
};

class WhatsApp : public IApplication {
public:
	void share(IMediaItem* IMedia) override {
		cout << "WhatsApp selected for sharing" << endl;
		IMedia->displaydetails();
	}
	void cancel(IMediaItem* IMedia) override {
		cout << "Media share through WhatsApp is canceled" << endl;
		IMedia->displaydetails();
	}
};

class Bluetooth : public IApplication {
public:
	void share(IMediaItem* IMedia) override {
		cout << "Bluetooth selected for sharing" << endl;
		IMedia->displaydetails();
	}
	void cancel(IMediaItem* IMedia) override {
		cout << "Media share through Bluetooth is canceled" << endl;
		IMedia->displaydetails();
	}
};

class Email : public IApplication {
public:
	void share(IMediaItem* IMedia) override {
		cout << "Email selected for sharing" << endl;
		IMedia->displaydetails();
	}
	void cancel(IMediaItem* IMedia) override {
		cout << "Media share through Email is canceled" << endl;
		IMedia->displaydetails();
	}
};


int main() {
	WhatsApp whatsapp;
	Bluetooth bluetooth;
	Email mail;
	Image IG1("09-05-2024", 2, ".jpg");
	Video Vd1("15-05-2024", 6, ".mp4");
	whatsapp.share(&IG1);
	bluetooth.share(&IG1);
	bluetooth.cancel(&IG1);
	mail.share(&Vd1);
	mail.cancel(&Vd1);
	whatsapp.share(&Vd1);
	return 0;
}