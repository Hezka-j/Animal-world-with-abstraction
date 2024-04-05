#include <iostream>
#include<typeinfo>
using namespace std;
class Lion;
class Bison;
class Wildebeest;
class Wolf;
class Continent{};
class Africa : public Continent{
    Wildebeest* wildebeest;
    Lion* lion;
};

class NorthAmerica : public Continent{
    Wolf* wolf;
    Bison* bison;
 
};

__interface ISwim{
    void Swim();
};

__interface IFly{
    void Fly();
};

__interface IRun {
    void Run();
};

__interface IJump {
    void Jump();
};

__interface IConjure {
    void Conjure();
};

class Herbivore abstract : public IRun, public ISwim, public IFly, public IJump{
    double weight;
    bool life = true;
public:
    virtual ~Herbivore() {}

    virtual void Run() {}

    virtual void Jump() {}

    virtual void Swim() {}

    virtual void Fly() {}
    
    virtual void SetWeight(double weight)
    {
        this->weight = weight;
    }

    virtual double GetWeight() const
    {
        return weight;
    }

    virtual void SetLife(bool life)
    {
        this->life = life;
    }

    virtual bool GetLife() const
    {
        return life;
    }

    virtual void Eat() {
        cout << "Herbivore eats grass\n";
        weight += 10;
    }

    void CallEat() {
        cout << "Herbivore eats grass\n";
        weight += 10;
    }

    virtual void Print()
    {
        cout << "Herbivore\n";
    }

    friend class Client;
};

class Alicorn : public Herbivore, public ISwim, public IFly, public IJump, public IConjure {
    double weight = 80 + rand() % (300 - 80) * 0.1;
    bool life = true;
public:
    virtual ~Alicorn() {}

    virtual void Fly()
    {
        cout << "Fly\n";
    }

    virtual void Conjure()
    {
        cout << "Magic\n";
    }

    virtual void Jump()
    {
        cout << "Jump\n";
    }

    virtual void Swim()
    {
        cout << "Swim\n";
    }

    virtual void Run()
    {
        cout << "run\n";
    }

    virtual void SetWeight(double weight)
    {
        this->weight = weight;
    }

    virtual double GetWeight() const
    {
        return weight;
    }

    virtual void SetLife(bool life)
    {
        this->life = life;
    }

    virtual bool GetLife() const
    {
        return life;
    }

    virtual void Eat() {
        cout << "Alicorn eats grass\n";
        weight += 10;
    }

    virtual void Print()
    {
        cout << "Alicorn\n";
    }

    friend class Client;
};

class Wildebeest : public Herbivore{
    double weight = 80 + rand() % (300 - 80) * 0.1;
    bool life = true;
public:
    virtual ~Wildebeest(){}

    virtual void Jump()
    {
        cout << "Jump\n";
    }

    virtual void Swim()
    {
        cout << "Swim\n";
    }

    virtual void Run()
    {
        cout << "run\n";
    }

    virtual void Fly() {}

    virtual void SetWeight(double weight)
    {
        this->weight = weight;
    }

    virtual double GetWeight() const
    {
        return weight;
    }

    virtual void SetLife(bool life)
    {
        this->life = life;
    }

    virtual bool GetLife() const
    {
        return life;
    }

    virtual void Eat() {
        cout << "Wildebeest eats grass\n";
        weight += 10;
    }

    virtual void Print()
    {
        cout << "Wildebeest\n";
    }

    friend class Client;
};

class Bison : public Herbivore {
    double weight = 400 + rand() % (1200 - 400) * 0.1;
    bool life = true;
public:
    virtual ~Bison(){}

    virtual void Run()
    {
        cout << "Run\n";
    }

    virtual void Swim()
    {
        cout << "Swim\n";
    }

    virtual void Jump() {}

    virtual void Fly() {}

    virtual void SetWeight(double weight)
    {
        this->weight = weight;
    }

    virtual double GetWeight() const
    {
        return weight;
    }

    virtual void SetLife(bool life)
    {
        this->life = life;
    }

    virtual bool GetLife() const
    {
        return life;
    }

    virtual void Eat() {
        cout << "Bison eats grass\n";
        weight += 10;
    }

    virtual void Print()
    {
        cout << "Bison\n";
    }

    friend class Client;
};

class Carnivore abstract : public IRun, public ISwim, public IFly, public IJump {
public:
    virtual void Run(){}

    virtual void Swim() {}

    virtual void Fly() {}

    virtual void Jump() {}

    virtual void SetPower(int power) {}
    
    virtual int GetPower() const {
        return 0;
    }

    virtual ~Carnivore(){}

    virtual void Eat(Herbivore* animal)
    {
        const type_info& type = typeid(animal);
        cout << "Eats " << type.name() << "\n";
    }

    virtual void Print()
    {
        cout << "Carnivore\n";
    }

    friend class Client;
};

class Wolf : public Carnivore{
    int power = 50 + rand() % (200 - 50);
public:
    virtual ~Wolf(){}

    virtual void Jump()
    {
        cout << "Jump\n";
    }

    virtual void Swim()
    {
        cout << "Swim\n";
    }

    virtual void Run()
    {
        cout << "run\n";
    }

    virtual void Fly() {}
    
    virtual void SetPower(int power) {
        this->power = power;
    }

    virtual int GetPower() const {
        return power;
    }

    virtual void Eat(Herbivore* animal) {
        if(animal->GetLife())
        {
            if (power >= animal->GetWeight()) power += 10;
            else power -= 10;
            animal->SetLife(false);
            cout << "Wolf eats ";
            animal->Print();
        }
    }
    virtual void Print()
    {
        cout << "Wolf\n";
    }
    friend class Client;
};

class Lion : public Carnivore{
    int power = 100 + rand() % (500 - 100);
public:
    virtual ~Lion() {}

    virtual void Jump()
    {
        cout << "Jump\n";
    }

    virtual void Swim()
    {
        cout << "Swim\n";
    }

    virtual void Run()
    {
        cout << "run\n";
    }

    virtual void Fly(){}

    virtual void SetPower(int power) {
        this->power = power;
    }

    virtual int GetPower() const {
        return power;
    }

    virtual void Eat(Herbivore* animal) {
        if(animal->GetLife())
        {
            if (power >= animal->GetWeight()) power += 10;
            else power -= 10;
            animal->SetLife(false);
            cout << "Lion eats ";
            animal->Print();
        }
    }
    virtual void Print()
    {
        cout << "Lion\n";
    }
    friend class Client;
};

class Client {
public:
    void FeedHerbivore(Herbivore* herbivore) {
        herbivore->Eat();
    }

    void FeedCarnivore(Carnivore* carbivore, Herbivore* herbivore) {
        carbivore->Eat(herbivore);
    }

    void FeedAllHerbivores() {
        void (Herbivore:: *eat)() = &Wildebeest::CallEat;
        
        /*const type_info& type = typeid(eat);*/
        //Herbivore* temp = new Herbivore;
        //const type_info& type_wildebeest = typeid(Wildebeest);
        //const type_info& type_bison = typeid(Bison);
        (Wildebeest().*eat)();
        
        //(temp->*eat)();
    }
};
int main()
{
    srand(time(0));
    /*Alicorn a;
    a.Print();*/
    const int count = 3;
    Herbivore* herbivores[count] = {};
    Carnivore* carnivores[count] = {};
    for (int i = 0; i < count; i++)
    {
        int random_number = rand() % 3;        
        if (random_number == 0) {
            herbivores[i] = new Wildebeest;
            carnivores[i] = new Wolf;
        }
        else if (random_number == 1)
        {
            herbivores[i] = new Bison;
            carnivores[i] = new Lion;
        }
        else
            herbivores[i] = new Alicorn;
        herbivores[i]->Print();
        if(random_number != 2)
            carnivores[i]->Print();
    }
    /*herbivores[0] = new Alicorn;
    herbivores[0]->Print();*/
    Client a;
    a.FeedAllHerbivores();
}
