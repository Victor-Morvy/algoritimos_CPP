#include <iostream>

using namespace std;

class ClasseMae2{
public:
	void showMsg()
	{
		cout << "classe Mae2" << endl;	
	}
		
};

class ClasseFilha2 : public ClasseMae2{
public:
	void showMsg()
	{
		cout << "classe Filha2" << endl;
	}
		
};

void foo2(ClasseMae2* a)
{
	a->showMsg();
}

class ClasseMae{
public:
	virtual void showMsg()
	{
		cout << "Classe mae" << endl;
	}
};

class ClasseFilha : public ClasseMae{
public:
	void showMsg()
	{
		cout << "classe filha" << endl;
	}
};

void foo(ClasseMae* cm)
{
	cm->showMsg();
}

int main()
{
	ClasseMae c;
	ClasseFilha d;
	
	foo(&c);
	foo(&d);
	
	ClasseMae2 c2;
	ClasseFilha2 d2;
	
	foo2(&c2);
	foo2(&d2);
	
	return 0;
}
