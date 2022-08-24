#include <iostream>
#include <vector>
using namespace std;

enum PET_TYPE{
    DOG,
    CAT,
    HORSE,
    FISH
};

class AbstractPet{
public:
//    AbstractPet( PET_TYPE type ):_type(type){}

    virtual void doAction() = 0;

private:
    PET_TYPE _type;
    std::string name;
};

class DogClass : public AbstractPet{
public:
//    DogClass():AbstractPet(PET_TYPE::DOG){}

    virtual void doAction(){
        std::cout << "Dog's barking" << std::endl;
    }
};

class HorseClass : public AbstractPet{
public:
//    HorseClass():AbstractPet(PET_TYPE::HORSE){}

    virtual void doAction(){
        std::cout << "Horse's neighing" << std::endl;
    }
};

class CatClass : public AbstractPet{
public:
//    CatClass():AbstractPet(PET_TYPE::CAT){}

    virtual void doAction(){
        std::cout << "Cat's rowring" << std::endl;
    }
};

int main()
{
    std::vector<AbstractPet*> petVector;
//    DogClass* dog = new DogClass();
    petVector.push_back( new DogClass() );
    petVector.push_back( new HorseClass() );
    petVector.push_back( new CatClass() );

    for( auto &pet : petVector )
    {
        DogClass* testDog = dynamic_cast<DogClass*>(pet);
        CatClass* testCat = dynamic_cast<CatClass*>(pet);
        HorseClass* testHorse = dynamic_cast<HorseClass*>(pet);

        if( testDog )
            std::cout << "The pet is a dog!" << std::endl;
        if( testCat )
            std::cout << "The pet is a cat!" << std::endl;
        if( testHorse )
            std::cout << "The pet is a horse!" << std::endl;

        pet->doAction();


    }

    return 0;
}
