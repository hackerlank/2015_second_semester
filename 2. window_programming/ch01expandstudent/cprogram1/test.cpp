#include	"stdio.h"

//문자를 입력받게 하고, q가 나왔을때는 프로그램을 종료하고,나버지는 무한루프를 돈다. 
//
int main(int argc, char* argv[])
{
	char	c;
	while(1){
		printf("아무 문자나 입력하십시오:");
		scanf("%c", &c);
		fflush(stdin); //fflush가 무엇인지 꼭 찾아봐라!
		switch(c){
			case	'a':
				printf("a가 출력되었습니다\n");
				break;
			case	'b':
				printf("b가 출력되었습니다\n");
				break;
			case	'q':
				printf("q가 출력되었습니다\n");
				return 0;
			default:
				printf("의미없는 캐릭터가 입력되었습니다\n");
				break;
		}

	}
	return 0;

}