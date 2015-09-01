#include	"stdio.h"
#include	"myoutput.h"
int main(int argc, char* argv[])
{
	char	c;
	while(1){
		printf("아무 문자나 입력하십시오:");
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