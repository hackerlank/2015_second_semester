#include	"stdio.h"
#include	"myoutput.h"

MyOutput	*myOutput= NULL;

int main(int argc, char* argv[])
{
	char	c;

	while(1){
		printf("�ƹ� ���ڳ� �Է��Ͻʽÿ�:");
		scanf("%c", &c);
		fflush(stdin);

		switch(c){
			case	'a':
				myOutput->onA();
				break;
			case	'b':
				myOutput->onB();
				break;
			case	'q':
				myOutput->onQ();
				return 0;
			default:
				myOutput->onDefault();
				break;
		}

	}
	return 0;


}