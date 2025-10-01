export module X;  // library A

namespace X
{

export struct Z
{
	int i = 42;
	void add()
	{
		i = i + 7;
	}
};

}
