#include	"stdio.h"

class	MyOutput{

public:
	MyOutput();
	~MyOutput();
	void	onA();
	virtual	void	onB(); //virtual�Լ��� ã�ƺ��ÿ�
	void	onQ();
	void	onDefault();
};
