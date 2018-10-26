#include <TObject.h>
#include <iostream>

class MyEvent : public TObject
{
	public:
	
	Int_t nTracks;
	Double_t fV2;
	MyEvent();
	
	ClassDef(MyEvent, 1);
};


ClassImp(MyEvent)

MyEvent::MyEvent():
TObject(),
	nTracks(-1),
	fV2(-1)
{
	
}

void TestMyEvent() {
	MyEvent* event = new MyEvent();
	std::cout<< event->fV2<<endl;
}
