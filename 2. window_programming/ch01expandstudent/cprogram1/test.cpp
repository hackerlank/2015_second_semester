#include	"stdio.h"

//���ڸ� �Է¹ް� �ϰ�, q�� ���������� ���α׷��� �����ϰ�,�������� ���ѷ����� ����. 
//
int main(int argc, char* argv[])
{
	char	c;
	while(1){
		printf("�ƹ� ���ڳ� �Է��Ͻʽÿ�:");
		scanf("%c", &c);
		fflush(stdin); //fflush�� �������� �� ã�ƺ���!
		switch(c){
			case	'a':
				printf("a�� ��µǾ����ϴ�\n");
				break;
			case	'b':
				printf("b�� ��µǾ����ϴ�\n");
				break;
			case	'q':
				printf("q�� ��µǾ����ϴ�\n");
				return 0;
			default:
				printf("�ǹ̾��� ĳ���Ͱ� �ԷµǾ����ϴ�\n");
				break;
		}

	}
	return 0;

}