#include <iostream>
#include <locale>

using namespace std;
class Mapping
{
	int M[33];
public:
	Mapping() 
	{
		Clear();
	}
	void Assign(char d, int Md) 
	{
		M[d - 'а'] = Md;
	}
	bool Compute(char d, int& r)
	{
		if (M[d - 'а'] >= 0)
		{
			r = M[d - 'а'];
			return true;
		}
		else
			return false;
	}
	void Clear()
	{ 
		for (int i = 0; i < 33; i++) M[i] = -1;
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
	Mapping test = Mapping();
	test.Assign('а', 1);
	test.Assign('б', 2);
	test.Assign('в', 3);
	int Md;
	test.Clear();
	cout << test.Compute('б', Md) << endl;
	return 0;
}