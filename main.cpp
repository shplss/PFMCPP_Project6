/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) { }  //1
    int value;                                       //2
    std::string name;                                //3
};

struct C                                             //4
{
    T* compare(T* a, T* b)                           //5
    {
        if(a != nullptr && a != nullptr) {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float valFloat1{ 0 }, valFloat2{ 0 };
    float valueUpdate(float* updVal)      //12
    {
        if(updVal != nullptr)
        {
            std::cout << "U's valFloat1 value: " << valFloat1 << std::endl;
            valFloat1 = *updVal;
            std::cout << "U's valFloat1 updated value: " << valFloat1 << std::endl;
            while( std::abs(valFloat2 - valFloat1) > 0.001f )
            {
                valFloat2 += valFloat1 / 2.0f;
            }
            std::cout << "U's valFloat2 updated value: " << valFloat2 << std::endl;
            return valFloat2 * valFloat1;
        }
        return 0.0f;
    }
};

struct D
{
    static float valueUpdate(U* that, float* updVal)        //10
    {
        if(that != nullptr && updVal != nullptr)
        {
            std::cout << "U's valFloat1 value: " << that->valFloat1 << std::endl;
            that->valFloat1 = *updVal;
            std::cout << "U's valFloat1 updated value: " << that->valFloat1 << std::endl;
            while( std::abs(that->valFloat2 - that->valFloat1) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
              that->valFloat2 += that->valFloat1 / 2.0f;
            }
            std::cout << "U's valFloat2 updated value: " << that->valFloat2 << std::endl;
            return that->valFloat2 * that->valFloat1;
        }
        return 0.0f;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T var1(5, "var1");                                             //6
    T var2(3, "var2");                                             //6
    
    C f;                                            //7
    auto* smaller = f.compare(&var1, &var2);                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << D::valueUpdate(&u1,&updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.valueUpdate( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
