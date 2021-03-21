#include "std_lib_facilities.h"

struct Person{
    Person(string first_name, string last_name, int age): my_first_name(first_name), my_last_name(last_name), my_age(age) {
        if (age < 0 || age > 150)
            error("The age is invalid");
        else
        {
            my_age = age;
        }

        string name = first_name + last_name;
        for(char i : name)
            switch (i)
            {
            case ';' :
            case ':' :
            case '"' :
            case '\'' :
            case '[' :
            case ']' :
            case '*' :
            case '&' :
            case '^' :
            case '%' :
            case '$' :
            case '#' :
            case '@' :
            case '!' :
                error("The name is invalid");
                break;
            
            default:
                my_first_name = first_name;
                my_last_name = last_name;
                break;
            }
    }

    string first_name() const {return my_first_name;}

    string last_name() const {return my_last_name;}

    int age() const {return my_age;}

    private:
    string my_first_name;
    string my_last_name;
    int my_age;
};

ostream &operator<<(ostream &o, Person &p) {
    o << p.first_name() << ' ' << p.last_name() << ' ' << p.age() << '\n';
    return o;
}

istream &operator>>(istream &i, Person &p) {
    string tmp_first_name;
    string tmp_last_name;
    int tmp_age;

    i >> tmp_first_name;
    i >> tmp_last_name;
    i >> tmp_age;

    p = Person{tmp_first_name, tmp_last_name, tmp_age};

    return i;
}

int main () {

    Person p ("Goofy", "dog", 63);
    cout << p;
    cin >> p;
    cout << p;

    vector<Person> pv;
    while (cin >> p)
    {
        pv.push_back(p);
    }
    
    for(Person p : pv)
        cout<< p;

    return 0;
}