#include	"stdio.h"
#include	"myoutput.h"
int main(int argc, char* argv[])
{
	char	c;
	while(1){
		printf("�ƹ� ���ڳ� �Է��Ͻʽÿ�:");
		scanf("%c", &c);
		fflush(stdin);

		switch(c){
			case	'a':
				onA();
				break;
			case	'b':
				onB();
				break;
			case	'q':
				onQ();
				return 0;
			default:
				onDefault();
				break;
		}

	}
	return 0;


}