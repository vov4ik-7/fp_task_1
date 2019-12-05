// OOP emulation

// Base class
function Person(name, age){
    // Methods
    function get_name(){
        return name;
    }

    function get_age(){
        return age;
    }

    function get_gender(){
        return 'Unknown';
    }

    function print_hello(){
        console.log(`Hello! My name is ${name}.`);
    }

    // Public members
    return {
        print_hello: print_hello,
        get_name: get_name,
        get_age: get_age,
        get_gender: get_gender
    }
}

// Inherited class
function Male(name, age, hair_color){
    // Inheritance
    let self = Person(name, age);

    // New methods of inherited class
    function get_hair_color(){
        return hair_color;
    }

    self.get_hair_color = get_hair_color;

    // Overriding
    self.get_gender = () => 'Male';

    return self
}

// Instance of base class
person = Person("Jack", 30);
console.log(person.get_gender());

// Instance of inherited class
male = Male('Tom', 20, 'brown');
male.print_hello();
console.log(male.get_age());
console.log(male.get_hair_color());
console.log(male.get_gender());
