#include <iostream>
#include <vector>
using namespace std;

class tryCall
{
public:
    virtual void Call() = 0;
};

class Cynamoon
{
public:
    Cynamoon( int value ):_value(value){};

    int _value;

    void Call()
    {
        int* value = new int( _value );

        MyCynamoonFunction( value );

        delete value;

    }

    void MyCynamoonFunction( void* r )
    {
        int* value = /*static_cast<int*>*/(int*)(r);
        if( value )
        {
            cout << _value++ << " " << *value++ << endl;
            *value += 1;
        }
        else
            cout << _value << " only" << endl;
    }
};

class Melt
{
public:
    Melt(): _name("Moises"){};
    Melt(std::string name) : _name(name){};

    int myValue = 0;

    void yell(void*)
    {
        static int value = 0;
        cout<< "HELLO HELLO HELLO IS ANYBODY IN THERE???? " << value << " " << myValue++ << endl;
        value++;
    }

    void Call()
    {
        yell(0);
    }

private:
    std::string _name;

};

template <typename T >
class Functor : public tryCall
{
public:
//    typedef void (T::*function_type)(int);
    typedef void (T::*function_type)( void* );

    Functor(T* object, function_type function, void* function_param)
        : object_(object)  // save the object on which to call the function later on
        , function_(function)  // save the function pointer
        , params_(function_param)  // save the parameter passed at the function
    {
    }

    Functor(T* object, function_type function)
        : object_(object)  // save the object on which to call the function later on
        , function_(function)  // save the function pointer
        , params_(nullptr)  // save the parameter passed at the function
    {
    }

    void Call()
    {
        if( params_ )
            (object_->*function_)(params_);
        else
            (object_->*function_)(0);
    }

private:
    // The object to call the function on
    T* object_;

    // The function pointer
    function_type function_;

    void* params_;

};

int main(void){
    int* value = new int(15);

    Cynamoon cynamoon(1555);
    Cynamoon cynamoon2(25);
    Cynamoon cynamoon3(17);

    Melt* m = new Melt;
    Melt* m2 = new Melt("Trevor");

    Functor func = Functor(m, &Melt::yell);
    Functor func2(m2, &Melt::yell);
    Functor func3(&cynamoon3, &Cynamoon::MyCynamoonFunction, 0);
    Functor func4(&cynamoon2, &Cynamoon::MyCynamoonFunction, new int(20));
    Functor func5(&cynamoon, &Cynamoon::MyCynamoonFunction, (void*)value);
    Functor func6(&cynamoon2, &Cynamoon::MyCynamoonFunction, (void*)value);
    Functor func7(m2, &Melt::yell);

    std::vector<tryCall*> functions;

    functions.push_back( &func );
    functions.push_back( &func2 );
    functions.push_back( &func3 );
    functions.push_back( &func4 );
    functions.push_back( &func5 );
    functions.push_back( &func6 );
    functions.push_back( &func7 );

    for( int i = 0; i < 10; i++ )
    {
        for( auto& f : functions )
        {
            f->Call();

        }
        std::cout << " ======================== " << std::endl;
    }

    return 0;
}
