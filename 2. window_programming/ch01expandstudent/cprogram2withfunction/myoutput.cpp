#include <stdio.h>
#include	"myoutput.h"

void onA() {
	printf("a가 출력되었습니다\n");
}

void onB() {
			printf("b가 출력되었습니다\n");
				}
int onQ() {
	printf("q가 출력되었습니다\n");
	return 0;
}
				
int onDefault() {
		printf("의미없는 캐릭터가 입력되었습니다\n");
		return 0;	
}

