#include	"youroutput.h"

extern	MyOutput	*myOutput;

// �̰��� �ݵ�� ����Ǿ�� �մϴ�.
YourOutput	theApp;

YourOutput::YourOutput()
{
	myOutput= this;
}

YourOutput::~YourOutput(){ }

//myOutput���� virtual�̶�� Ű���带 �־���
void YourOutput::onB(){
	printf("bbb\n");
}

//myOutput���� virtual�̶�� Ű���带 ���� �ʾ���.
void YourOutput::onA() {
	printf("aaaaaaaaaaa\n");
}
