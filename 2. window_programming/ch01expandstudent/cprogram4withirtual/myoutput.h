#include	"stdio.h"

class	MyOutput{

public:
	MyOutput();
	~MyOutput();
	void	onA();
	virtual	void	onB();
	void	onQ();
	void	onDefault();
};
