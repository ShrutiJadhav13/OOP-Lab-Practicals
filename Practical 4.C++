#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Vehicle
{
protected:
    string vno;
    string brand;
    double rent;

public:
    // Constructor
    Vehicle(string num, string b, double rentv)
    {
        vno = num;
        brand = b;
        rent = rentv;
    }
    // Pure Virtual Function
    virtual void displayDetails() = 0;
    // Pure virtual function for rental calculation
    virtual double calculateRent(int days) = 0;
    // Virtual Destructor
    virtual ~Vehicle()
    {
        cout << "\nVehicle destructor called." << endl;
    }
};

// Derived Class: Car
class Car : public Vehicle
{
    int VCapacity;

public:
    Car(string num, string b, double rent, int seats)
        : Vehicle(num, b, rent)
    {
        VCapacity = seats;
    }
    void displayDetails()
    {
        cout << "\n--- Car Details ---" << endl;
        cout << "Vehicle Number : " << vno << endl;
        cout << "Brand          : " << brand << endl;
        cout << "Rent per Day   : Rs. " << rent << endl;
        cout << "Seating Capacity: " << VCapacity << endl;
    }
    double calculateRent(int days)
    {
        return rent * days;
    }
    ~Car()
    {
        cout << "\nCar destructor called." << endl;
    }
};

// Derived Class: Bike
class Bike : public Vehicle
{
    string bikeType;

public:
    Bike(string num, string b, double rent, string type)
        : Vehicle(num, b, rent)
    {
        bikeType = type;
    }
    void displayDetails()
    {
        cout << "\n--- Bike Details ---" << endl;
        cout << "Vehicle Number : " << vno << endl;
        cout << "Brand          : " << brand << endl;
        cout << "Rent per Day   : Rs. " << rent << endl;
        cout << "Bike Type      : " << bikeType << endl;
    }
    double calculateRent(int days)
    {
        return rent * days;
    }
    ~Bike()
    {
        cout << "\nBike destructor called." << endl;
    }
};

// Derived Class: Truck
class Truck : public Vehicle
{
    double loadCapacity;

public:
    Truck(string num, string b, double rent, double load)
        : Vehicle(num, b, rent)
    {
        loadCapacity = load;
    }
    void displayDetails()
    {
        cout << "\n--- Truck Details ---" << endl;
        cout << "Vehicle Number : " << vno << endl;
        cout << "Brand          : " << brand << endl;
        cout << "Rent per Day   : Rs. " << rent << endl;
        cout << "Load Capacity  : " << loadCapacity << " tons" << endl;
    }
    double calculateRent(int days)
    {
        return rent * days;
    }
    ~Truck()
    {
        cout << "\nTruck destructor called." << endl;
    }
};

// Main Function
int main()
{
    int days;
    cout << "===== VEHICLE RENTAL SYSTEM =====" << endl;
    cout << "\nEnter rental duration (in days): ";
    cin >> days;

    // Dynamic memory allocation using new
    Vehicle *v1 = new Car("MH12AB1234", "Honda City", 2500, 5);
    Vehicle *v2 = new Bike("MH12XY5678", "Royal Enfield", 1000, "Cruiser");
    Vehicle *v3 = new Truck("MH12TR9012", "Tata", 5000, 10);

    // Runtime Polymorphism
    v1->displayDetails();
    cout << "Total Rent for " << days << " days: Rs. "
         << v1->calculateRent(days) << endl;
    v2->displayDetails();
    cout << "Total Rent for " << days << " days: Rs. "
         << v2->calculateRent(days) << endl;

    v3->displayDetails();
    cout << "Total Rent for " << days << " days: Rs. " << v3->calculateRent(days) << endl;

    // Deallocation using delete
    delete v1;
    delete v2;
    delete v3;

    cout << "\nAll vehicle objects deleted successfully." << endl;
    return 0;
}

Output
===== VEHICLE RENTAL SYSTEM =====

Enter rental duration (in days): 5

--- Car Details ---
Vehicle Number : MH12AB1234
Brand          : Honda City
Rent per Day   : Rs. 2500
Seating Capacity: 5
Total Rent for 5 days: Rs. 12500

--- Bike Details ---
Vehicle Number : MH12XY5678
Brand          : Royal Enfield
Rent per Day   : Rs. 1000
Bike Type      : Cruiser
Total Rent for 5 days: Rs. 5000

--- Truck Details ---
Vehicle Number : MH12TR9012
Brand          : Tata
Rent per Day   : Rs. 5000
Load Capacity  : 10 tons
Total Rent for 5 days: Rs. 25000

Car destructor called.

Vehicle destructor called.

Bike destructor called.

Vehicle destructor called.

Truck destructor called.

Vehicle destructor called.

All vehicle objects deleted successfully.
