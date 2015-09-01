#include	"myoutput.h"

extern	MyOutput	*myOutput;
MyOutput	theApp;

MyOutput::MyOutput() {
	if(myOutput == NULL) {
		myOutput=this;
	} //이 부분을 막고나서 하면 b가 실행이 안된다 (virtual이라서, )
}

MyOutput::~MyOutput() { }

void MyOutput::onA() {
	printf("a가 출력되었습니다\n");
}
void MyOutput::onB() {
	printf("b가 출력되었습니다\n");
}
void MyOutput::onQ() {
	printf("q가 출력되었습니다\n");
}
void MyOutput::onDefault() {
	printf("의미없는 캐릭터가 입력되었습니다\n");
}


