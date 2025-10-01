export module X;  // library B

namespace X
{

export struct Z
{
	int i = 3;
	void add()
	{
		i = i + 17;
	}
};

}
