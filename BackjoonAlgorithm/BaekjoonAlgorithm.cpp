#include <iostream>



class interface_a
{
	virtual void init() = 0;
};

class interface_b : public interface_a
{
	virtual void undo() = 0;
};

class interface_s
{
	virtual void execute() = 0;
};
class concrete : public interface_b
{
public:
	// interface_b을(를) 통해 상속됨
	virtual void init() override
	{
		std::cout << "init\n";
	}
	virtual void undo() override
	{
		std::cout << "undo\n";
	}
};

int main()
{
	concrete _concrete;
	_concrete.undo();

}