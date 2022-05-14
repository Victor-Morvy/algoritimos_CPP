#include <iostream>>
#include <string>

//Last call with no arguments in the recursive call
void printar()
{
	std::cout << "\n endCalled" << std::endl;
}

//Head tail concept
template<typename Head, typename ... Tail>
void printar(Head param, const Tail&... rest)
{
	std::cout << param << " ";
	//it will call recursivelly
	output( rest... );	
}

int main()
{	
	printar( "Uma mistura de", 3, "bonecos alegres e", 2 ,"gemas ascendentes é mais do que", 9, "suficientes.");
	
	return 0;	
}
