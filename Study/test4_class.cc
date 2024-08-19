#include <iostream>

class Pet
{
public:
    Pet(std::string Name);
    ~Pet();
    static int getCount();

protected:
    std::string name;

private:
    static int count;
};

class Dog : public Pet
{
public:
    Dog(std::string Name);
};

class Cat : public Pet
{
public:
    Cat(std::string Name);
};

int Pet::count = 0;

Pet::Pet(std::string Name)
{
    name = Name;
    count++;
    std::cout << name << "born\n";
}

Pet::~Pet()
{
    count--;
    std::cout << "dead+1\n";
}

int Pet::getCount()
{
    return count;
}

Dog::Dog(std::string Name) : Pet(Name)
{
}

Cat::Cat(std::string Name) : Pet(Name)
{
}

int main()
{
    Dog dog("aaa");
    Cat cat("bbb");

    std::cout << Pet::getCount() << "s\n";
}