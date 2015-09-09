#include	"youroutput.h"

extern	MyOutput	*myOutput;

// 이것은 반드시 선언되어야 합니다.
YourOutput	theApp;

YourOutput::YourOutput()
{
	myOutput= this;
}

YourOutput::~YourOutput(){ }

//myOutput에서 virtual이라는 키워드를 주었음
void YourOutput::onB(){
	printf("bbb\n");
}

//myOutput에서 virtual이라는 키워드를 주지 않았음.
void YourOutput::onA() {
	printf("aaaaaaaaaaa\n");
}
