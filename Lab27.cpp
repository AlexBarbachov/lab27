#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
using namespace std;


void menu(map<string, tuple<int, string, string>>& villagerColors);
void increaseFriendship(map<string, tuple<int, string, string>>& villagerColors);
void decreaseFriendship(map<string, tuple<int, string, string>>& villagerColors);
void displayVillagers(map<string, tuple<int, string, string>>& villagerColors);


int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = make_tuple(7, "Cat", "Meow");
    villagerColors["Raymond"] = make_tuple(3, "Wolf", "Howl");
    villagerColors.insert({"Marshal", make_tuple(9, "Dog", "Bark")});

    menu(villagerColors);
    return 0;
}


void menu(map<string, tuple<int, string, string>>& villagerColors)
{
    int choice;
    
    while (choice != 4)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Increase Friendship level" << endl;
        cout << "2. Decrease Friendship level" << endl;
        cout << "3. Search for villager" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1: 
                increaseFriendship(villagerColors);
                break;
            case 2:
                decreaseFriendship(villagerColors);
                break;
            case 4:
                break;
            default: 
                cout << "Invalid choice. Try again." << endl;
                break; 
        }
    }    
}


void increaseFriendship(map<string, tuple<int, string, string>>& villagerColors)
{
    string name;
    cout << "Enter villager name to increase friendship level: ";
    cin >> name;
    auto it = villagerColors.find(name);
    if (it != villagerColors.end())
    {
        int lvl = get<0>(it->second);
        get<0>(it->second) = min(lvl + 1, 10);
        cout << name << "'s friendship level increased to" << get<0>(it->second) << "." << endl;
    }
    else
    {
        cout << "Villager not found." << endl;
    }
    displayVillagers(villagerColors);
}

void decreaseFriendship(map<string, tuple<int, string, string>>& villagerColors)
{
    string name;
    cout << "Enter villager name to decrease friendship level: ";
    cin >> name;
    auto it = villagerColors.find(name);
    if (it != villagerColors.end())
    {
        int lvl = get<0>(it->second);
        get<0>(it->second) = max(lvl - 1, 0);
        cout << name << "'s friendship level decreased to" << get<0>(it->second) << "." << endl;
    }
    else
    {
        cout << "Villager not found." << endl;
    }
    displayVillagers(villagerColors);
}

void displayVillagers(map<string, tuple<int, string, string>>& villagerColors)
{
    cout << "\nVillager's details" << endl;
    for (auto const& [name, detail] : villagerColors)
    {
        cout << name << ": ["
            << get<0>(detail) << ", "
            << get<1>(detail) << ", "
            << get<2>(detail) << "]" << endl;
    }
    cout << endl;
}