#include	"stdio.h"

class	MyOutput{

public:
	MyOutput();
	~MyOutput();
	void	onA();
	virtual	void	onB(); //virtual함수의 찾아보시오
	void	onQ();
	void	onDefault();
};
