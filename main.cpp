/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */
struct A{};

struct HeapA
{
    A* pointerToA;
    HeapA(){ pointerToA = new A();}
    ~HeapA(){ delete pointerToA;}
};










 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers named 'value'
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's valu.e
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
     
 5) Don't let your heap-allocated owned type leak!
 
 6) replace your main() with the main() below.
    It has some intentional mistakes that you need to fix to match the expected output
    i.e. don't forget to dereference your pointers to get the value they hold.

 7) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
/*
int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt.value << std::endl;
    std::cout << "Initial value of it: " << it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}

*/
/*
your program should generate the following output EXACTLY.
This includes the warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 
you'll learn to solve the conversion warnings in the next project part.

18 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!





*/



#include <iostream>
struct FloatType;
struct DoubleType;
struct IntType;

struct FloatType
{

    float* valuePtr;
    
    FloatType(float fvalue) : valuePtr(new float(fvalue)) {}
    ~FloatType(){delete valuePtr; valuePtr = nullptr;}    

    FloatType& add(float rhs);
    FloatType& subtract(float rhs);
    FloatType& multiply(float rhs);
    FloatType& divide(float rhs);

    FloatType& add( const FloatType& rhs );
    FloatType& subtract( const FloatType& rhs );
    FloatType& multiply( const FloatType& rhs );
    FloatType& divide( const FloatType& rhs );
    
    FloatType& add( const DoubleType& rhs );
    FloatType& subtract( const DoubleType& rhs );
    FloatType& multiply( const DoubleType& rhs );
    FloatType& divide( const DoubleType& rhs );
    
    FloatType& add( const IntType& rhs );
    FloatType& subtract( const IntType& rhs );
    FloatType& multiply( const IntType& rhs );
    FloatType& divide( const IntType& rhs );
};

struct DoubleType
{
    
    double* valuePtr;
    DoubleType(float dvalue) : valuePtr(new double(dvalue)) {}
    ~DoubleType(){delete valuePtr; valuePtr = nullptr;}

    DoubleType& add(double rhs );
    DoubleType& subtract(double rhs );
    DoubleType& multiply(double rhs );
    DoubleType& divide(double rhs );
    
    DoubleType& add( const FloatType& rhs );
    DoubleType& subtract( const FloatType& rhs );
    DoubleType& multiply( const FloatType& rhs );
    DoubleType& divide( const FloatType& rhs );
    
    DoubleType& add( const DoubleType& rhs );
    DoubleType& subtract( const DoubleType& rhs );
    DoubleType& multiply( const DoubleType& rhs );
    DoubleType& divide( const DoubleType& rhs );
    
    DoubleType& add( const IntType& rhs );
    DoubleType& subtract( const IntType& rhs );
    DoubleType& multiply( const IntType& rhs );
    DoubleType& divide( const IntType& rhs );
};

struct IntType
{
    int* valuePtr;
    IntType(int ivalue) : valuePtr(new int(ivalue)) {}
    ~IntType(){delete valuePtr; valuePtr = nullptr;}

    IntType& add(int rhs );
    IntType& subtract(int rhs );
    IntType& multiply(int rhs );
    IntType& divide(int rhs );
    
    IntType& add( const FloatType& rhs );
    IntType& subtract( const FloatType& rhs );
    IntType& multiply( const FloatType& rhs );
    IntType& divide( const FloatType& rhs );
    
    IntType& add( const DoubleType& rhs );
    IntType& subtract( const DoubleType& rhs );
    IntType& multiply( const DoubleType& rhs );
    IntType& divide( const DoubleType& rhs );
    
    IntType& add( const IntType& rhs );
    IntType& subtract( const IntType& rhs );
    IntType& multiply( const IntType& rhs );
    IntType& divide( const IntType& rhs );
};

FloatType& FloatType::add(float rhs)
{
    *valuePtr += rhs;
    return *this;
}

FloatType& FloatType::subtract(float rhs)
{
    *valuePtr -= rhs;
    return *this;
}

 FloatType& FloatType::multiply(float rhs)
{
    *valuePtr *= rhs;
    return *this;
}

FloatType& FloatType::divide(float rhs)
{
    *valuePtr /= rhs;
    return *this;
}

FloatType& FloatType::add(const FloatType& rhs)
{
    return add(*rhs.valuePtr);
}

FloatType& FloatType::subtract(const FloatType& rhs)
{
     return subtract(*rhs.valuePtr);
}

 FloatType& FloatType::multiply(const FloatType& rhs)
{
    return multiply(*rhs.valuePtr);
}

FloatType& FloatType::divide(const FloatType& rhs)
{
    return divide(*rhs.valuePtr);
}

FloatType& FloatType::add(const DoubleType& rhs)
{
    return add(*rhs.valuePtr);
}

FloatType& FloatType::subtract(const DoubleType& rhs)
{
    return subtract(*rhs.valuePtr);
}

 FloatType& FloatType::multiply(const DoubleType& rhs)
{
    return multiply(*rhs.valuePtr);
}

FloatType& FloatType::divide(const DoubleType& rhs)
{
    return divide(*rhs.valuePtr);
}

FloatType& FloatType::add(const IntType& rhs)
{
    return add(*rhs.valuePtr);
}

FloatType& FloatType::subtract(const IntType& rhs)
{
    return subtract(*rhs.valuePtr);
}

 FloatType& FloatType::multiply(const IntType& rhs)
{
    return multiply(*rhs.valuePtr);
}

FloatType& FloatType::divide(const IntType& rhs)
{
    return divide(*rhs.valuePtr);
}

DoubleType& DoubleType::add(double rhs)
{
    *valuePtr += rhs;
    return *this;
}

DoubleType& DoubleType::subtract(double rhs)
{
    *valuePtr -= rhs;
    return *this;
}

 DoubleType& DoubleType::multiply(double rhs)
{
    *valuePtr *= rhs;
    return *this;
}

DoubleType& DoubleType::divide(double rhs)
{
    *valuePtr /= rhs;
    return *this;
}

DoubleType& DoubleType::add(const FloatType& rhs)
{
    return add(*rhs.valuePtr);
}

DoubleType& DoubleType::subtract(const FloatType& rhs)
{
    return subtract(*rhs.valuePtr);
}

 DoubleType& DoubleType::multiply(const FloatType& rhs)
{
    return multiply(*rhs.valuePtr);
}

DoubleType& DoubleType::divide(const FloatType& rhs)
{
    return divide(*rhs.valuePtr);
}

DoubleType& DoubleType::add(const DoubleType& rhs)
{
    return add(*rhs.valuePtr);
}

DoubleType& DoubleType::subtract(const DoubleType& rhs)
{
    return subtract(*rhs.valuePtr);
}

 DoubleType& DoubleType::multiply(const DoubleType& rhs)
{
    return multiply(*rhs.valuePtr);
}

DoubleType& DoubleType::divide(const DoubleType& rhs)
{
    return divide(*rhs.valuePtr);
}

DoubleType& DoubleType::add(const IntType& rhs)
{
    return add(*rhs.valuePtr);
}

DoubleType& DoubleType::subtract(const IntType& rhs)
{
    return subtract(*rhs.valuePtr);
}

 DoubleType& DoubleType::multiply(const IntType& rhs)
{
    return multiply(*rhs.valuePtr);
}

DoubleType& DoubleType::divide(const IntType& rhs)
{
    return divide(*rhs.valuePtr);
}

IntType& IntType::add(int rhs)
{
    *valuePtr += rhs;
    return *this;
}

IntType& IntType::subtract(int rhs)
{
    *valuePtr -= rhs;
    return *this;
}

 IntType& IntType::multiply(int rhs)
{
    *valuePtr *= rhs;
    return *this;
}

IntType& IntType::divide(int rhs)
{
    if(rhs != 0)
    {
        *valuePtr /= rhs;
        return *this;
    }
    else
    {
        std::cout << "dividing by 0 is not allowed in this type ! " << std::endl;
        return *this;
    }
}

IntType& IntType::add(const FloatType& rhs)
{
    return add(*rhs.valuePtr);
}

IntType& IntType::subtract(const FloatType& rhs)
{
    return subtract(*rhs.valuePtr);
}

IntType& IntType::multiply(const FloatType& rhs)
{
    return multiply(*rhs.valuePtr);
}

IntType& IntType::divide(const FloatType& rhs)
{
    return divide(*rhs.valuePtr);
}

IntType& IntType::add(const DoubleType& rhs)
{
    return add(*rhs.valuePtr);
}

IntType& IntType::subtract(const DoubleType& rhs)
{
    return subtract(*rhs.valuePtr);
}

IntType& IntType::multiply(const DoubleType& rhs)
{
    return multiply(*rhs.valuePtr);
}

IntType& IntType::divide(const DoubleType& rhs)
{
    return divide(*rhs.valuePtr);
}

IntType& IntType::add(const IntType& rhs)
{
    return add(*rhs.valuePtr);
}

IntType& IntType::subtract(const IntType& rhs)
{
    return subtract(*rhs.valuePtr);
}

IntType& IntType::multiply(const IntType& rhs)
{
    return multiply(*rhs.valuePtr);
}

IntType& IntType::divide(const IntType& rhs)
{
    return divide(*rhs.valuePtr);
}

#include <iostream>

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ).valuePtr << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ).valuePtr << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ).valuePtr << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f).valuePtr << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0).valuePtr << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0).valuePtr << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0).valuePtr << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(5.f).valuePtr << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2).valuePtr << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2).valuePtr << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2).valuePtr << std::endl;
    std::cout << "IntType divide result=" << it.divide(3).valuePtr << std::endl << std::endl;
    std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)).valuePtr << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f).valuePtr << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt.valuePtr << std::endl;
    std::cout << "Initial value of it: " << it.valuePtr << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(it).divide(5.0f).add(ft).valuePtr) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0).valuePtr << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0).valuePtr << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0).valuePtr << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}

/*

int main()
{
    FloatType ft;
    DoubleType dt;
    IntType it;

    auto resultFt = ft.add(1.5f, 4.5f);
    std::cout << "result of FloatType::add() = "<< resultFt << std::endl;

    auto resultDt = dt.add(2500, 40000);
    std::cout << "result of DoubleType::add() = " << resultDt << std::endl;

    auto resultIt = it.divide(4, 2);
    std::cout << "result of IntType::divide() = " << resultIt << std::endl;

    resultIt = it.divide(5, 0);
    std::cout << "result of IntType::divide() = " << resultIt << std::endl;

    std::cout << "good to go !" << std::endl;
}

*/
