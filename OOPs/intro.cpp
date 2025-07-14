#include<iostream>

using namespace std;
class Hero {
    // Properties
    public:
    char name[100];
    int health;
    char level;

    int getHealth() { // Getter for health
        return health;
    }
    void setHealth(int h) { // Setter for health
        health = h;
    }
    char getLevel() { // Getter for level
        return level;
    }
    void setLevel(char ch) { // Setter for level
        level = ch;
    }
};

int main(){

    Hero Ramesh;
    Ramesh.setHealth(80); // Setting health using setter
    cout << "Ramesh's health is : " << Ramesh.getHealth() << endl; // Accessing the health property of Ramesh object using getter
    //  Ramesh.health = 70; // Assigning value to health property of Ramesh object
    Ramesh.level = 'A'; // Assigning value to level property of Ramesh object 
    
    cout << "Health is : " << Ramesh.health << endl; // Accessing the health property of Ramesh object
    cout << "Level is : " << Ramesh.level << endl; // Accessing the health property of Ramesh object
   

    
    // Creating an object of Hero class
    // cout << "Size : " << sizeof(h1) << endl; 
    // Displaying the size of the object



    return 0;
}