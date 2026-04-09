#include <iostream>
#include <fstream>
using namespace std;

class Weather {
public:
    string city;
    float temp;
    string condition;

    void input() {
        cout << "Enter City: ";
        cin >> city;
        cout << "Enter Temperature: ";
        cin >> temp;
        cout << "Enter Condition: ";
        cin >> condition;
    }

    void display() {
        cout << city << " | " << temp << "°C | " << condition << endl;
    }
};

int main() {
    Weather w;
    int choice;

    cout << "1. Add Weather\n2. View Data\nChoose: ";
    cin >> choice;

    if (choice == 1) {
        ofstream file("weather.txt", ios::app);
        w.input();
        file << w.city << " " << w.temp << " " << w.condition << endl;
        file.close();
        cout << "Data saved!";
    }
    else if (choice == 2) {
        ifstream file("weather.txt");
        while (file >> w.city >> w.temp >> w.condition) {
            w.display();
        }
        file.close();
    }

    return 0;
}
