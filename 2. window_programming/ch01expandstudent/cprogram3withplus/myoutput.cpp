#include	"myoutput.h"

extern	MyOutput	*myOutput;
MyOutput	theApp;

MyOutput::MyOutput() {
	if(myOutput == NULL) {
		myOutput=this;
	} //�� �κ��� ������ �ϸ� b�� ������ �ȵȴ� (virtual�̶�, )
}

MyOutput::~MyOutput() { }

void MyOutput::onA() {
	printf("a�� ��µǾ����ϴ�\n");
}
void MyOutput::onB() {
	printf("b�� ��µǾ����ϴ�\n");
}
void MyOutput::onQ() {
	printf("q�� ��µǾ����ϴ�\n");
}
void MyOutput::onDefault() {
	printf("�ǹ̾��� ĳ���Ͱ� �ԷµǾ����ϴ�\n");
}


