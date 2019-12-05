//
//  main.cpp
//  oop_emulation_cpp
//
//  Created by Volodymyr Lysyshyn.
//  Copyright © 2019 Volodymyr Lysyshyn. All rights reserved.
//
//  OOP emulation


#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

// Base class
map<string, function<string()>> Person(string name, int age) {
    // Methods
    auto get_name = [name]() {
        return name;
    };
    
    auto get_age = [age]() {
        return to_string(age);
    };
    
    auto get_gender = []() {
        return "Unknown";
    };
    
    auto say_hello = [name]() {
        return "Hello! My name is " + name + ".";
    };
    
    // Public members
    map<string, function<string()>> map;
    map["get_name"] = get_name;
    map["get_age"] = get_age;
    map["get_gender"] = get_gender;
    map["say_hello"] = say_hello;
    
    return map;
}

// Inherited class
map<string, function<string()>> Male(string name, int age, string hair_color) {
    // Inheritance
    auto self = Person(name, age);

    // New methods of inherited class
    auto get_hair_color = [hair_color]() {
        return hair_color;
    };

    self["get_hair_color"] = get_hair_color;

    // Overriding
    self["get_gender"] = []() { return "Male"; };

    return self;
}

int main(int argc, const char * argv[]) {
    // Instance of base class
    auto person = Person("Jack", 30);
    cout << person["get_gender"]() << endl;
    
    // Instance of inherited class
    auto male = Male("Tom", 20, "brown");
    cout << male["say_hello"]() << endl;
    cout << male["get_age"]() << endl;
    cout << male["get_hair_color"]() <<  endl;
    cout << male["get_gender"]() << endl;
    
    return 0;
}
