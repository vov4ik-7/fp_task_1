# OOP emulation


# Base class
def Person(name, age):
    # Methods
    def get_name():
        return name

    def get_age():
        return age

    def get_gender():
        return 'Unknown'

    def print_hello():
        print('Hello! My name is {}.'.format(name))

    # Public members
    return {
        'print_hello': print_hello,
        'get_name': get_name,
        'get_age': get_age,
        'get_gender': get_gender
    }


# Inherited class
def Male(name, age, hair_color):

    # Inheritance
    self = Person(name, age)

    # New methods of inherited class
    def get_hair_color():
        return hair_color

    self['get_hair_color'] = get_hair_color

    # Overriding
    self['get_gender'] = lambda: 'Male'

    return self


if __name__ == "__main__":
    # Instance of base class
    person = Person('Jack', 30)
    print(person['get_gender']())

    # Instance of inherited class
    male = Male('Tom', 20, 'brown')
    male['print_hello']()
    print(male['get_age']())
    print(male['get_hair_color']())
    print(male['get_gender']())
