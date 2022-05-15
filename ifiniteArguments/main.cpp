#include <iostream>>
#include <string>

//Last call with no arguments in the recursive call
void printar()
{
	std::cout << "\nendCalled" << std::endl;
}

//Head tail concept
template<typename Head, typename ... Tail>
void printar(Head param, const Tail&... rest)
{
	
	std::cout << param << " ";
	//char word[] = "Uma mistura de";
	//std::cout << param << " : " << sizeof(word) << std::endl;
	
	//it will call recursivelly
	printar( rest... );	
}


int main()
{	
	printar( "Uma mistura de", 3, "bonecos alegres e", 2 ,"gemas ascendentes é mais do que", 9, "suficientes.");
	
	
	return 0;	
}
