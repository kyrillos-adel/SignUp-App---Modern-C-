
#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;


class Person {
    public:
    
    int age;
    string name;
};

array <Person, 100> records;
int record_no = 0;

void add_record()
{
    Person p;

    cout << "Please enter your name: ";
    cin >> p.name;

    cout << "Please enter your age: ";
    cin >> p.age;

    records[record_no].name = p.name;
    records[record_no].age = p.age;

    record_no++;

    cout << "\nUser record added successfully!\n\n";
}

void fetch_rec()
{
    int id = 0;

    cout << "Please enter user ID: ";
    cin >> id;

    cout << "ID: " << id << "\nname: " << records[id].name
         << "\nage: " << records[id].age << "\n\n";
}

enum class option
{
    ADD_RECORD = 1,
    FETCH_RECORD = 2,
    QUIT = 3
};

istream & operator >> (istream & input_stream, option & result)
{
    int int_option;

    input_stream >> int_option;

    result = static_cast<option>(int_option);
}

int main()
{
    bool repeat = true;
    
    option op;

    cout << "User SignUp Application\n\n";

    while (repeat)
    {
        cout << "Please select an option:\n1: Add Record\n2: Fetch Record\n3: Quit\n\nEnter option: ";
    
        cin >> op;

        cout << "\n";

        switch (op)
        {
        case option::ADD_RECORD:
            add_record();
            break;
        
        case option::FETCH_RECORD:
            fetch_rec();
            break;

        default:
            repeat = false;
            break;
        }
    }
    

    return 0;
}