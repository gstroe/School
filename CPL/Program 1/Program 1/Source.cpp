#include <iostream>
using namespace std;

namespace Food1
{
	class Bacon
	{
		long m_int;
	public:
		Bacon();
		long Getint();
	};

	Bacon::Bacon()
	{
		m_int = 1;
	}

	long Bacon::Getint()
	{
		return m_int;
	}
}

namespace Food2
{
	class Bacon
	{
		long m_int;
	public:
		Bacon();
		long Getint();
	};

	Bacon::Bacon()
	{
		m_int = 2;
	}

	long Bacon::Getint()
	{
		return m_int;
	}
}

namespace Food3 
{
	class Bacon
	{
		long m_int;
	public:
		Bacon();
		long Getint();
	};

	Bacon::Bacon()
	{
		m_int = 3;
	}

	long Bacon::Getint()
	{
		return m_int;
	}
}


int main()
{
	// innitiate food
	Food1::Bacon meat1;
	Food2::Bacon meat2;
	Food3::Bacon meat3;

	// print meat
	cout << "Should print the bacon numbers in order (1-3):   " << meat1.Getint() << " " << meat2.Getint() << " " << meat3.Getint() << endl;

	// let user see the numbers
	system("pause");
	
}
