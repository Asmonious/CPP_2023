#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    //1.
    cout << "Exercise 1: " << endl;
    vector<string> fruits{
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };
    for_each(fruits.begin(), fruits.end(), [](string fruit) {
        cout << fruit << " ";
    });
    cout << endl;
    string searchString;
    cout << "Enter a string to search: ";
    cin >> searchString;
    auto found = find_if(fruits.begin(), fruits.end(), [searchString](const string &fruit) {
        return fruit.find(searchString) != string::npos;
    });

    if (found != fruits.end()) {
        cout << "Found: " << *found << endl;
    } else {
        cout << "Not found" << endl;
    }

    //2.
    cout << "Exercise 2: " << endl;
    vector<int> numbers{
            2, 4, 6, 8, 10, 11
    };
    cout << "\tNumbers: ";
    for (int &n: numbers) {
        cout << n << " ";
    }
    auto result = all_of(numbers.begin(), numbers.end(), [](int number) {
        return (number % 2 == 0);
    });

    if (result) {
        cout << " - All numbers are even" << endl;
    } else {
        cout << " - Not all numbers are even" << endl;
    }


    //3.
    cout << "Exercise 3: " << endl;
    for_each(numbers.begin(), numbers.end(), [](int &number) {
        return number *= 2;
    });
    cout << "\tNumbers after duplication: ";
    for (int &n: numbers) {
        cout << n << " ";
    }
    cout << endl;

    //4.
    cout << "Exercise 4: " << endl;
    vector<string> months{
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    cout << "\tMonths with 5 characters: ";
    for_each(months.begin(), months.end(), [](string month) {
        if (month.size() == 5) {
            cout << month << " ";
        }
    });

    //5.
    cout << endl << "Exercise 5: " << endl;
    vector<double> numbers2{
            2.5, 4.5, 6.5, 8.5, 10.5, 11.5
    };
    cout << "\tNumbers: ";
    for (double &n: numbers2) {
        cout << n << " ";
    }
    cout << endl;
    sort(numbers2.begin(), numbers2.end(), [](double a, double b) {
        return (int) a > (int) b;
    });

    cout << "\tNumbers after sorting: ";
    for (double &n: numbers2) {
        cout << n << " ";
    }
    cout << endl;

    //6.
    cout << "Exercise 6: " << endl;
    vector<pair<string,int>> monthTemp;
    monthTemp.emplace_back("January", -1);
    monthTemp.emplace_back("February", 0);
    monthTemp.emplace_back("March", 3);
    monthTemp.emplace_back("April", 12);
    monthTemp.emplace_back("May", 11);

    cout << "\tMonths before sorting: ";
    for (auto &month: monthTemp) {
        cout << month.first << " ";
    }
    cout << endl;

    sort(monthTemp.begin(), monthTemp.end(), [](pair<string,int> a, pair<string,int> b) {
        return a.second < b.second;
    });

    cout << "\tMonths after sorting by temperature: ";
    for (auto &month: monthTemp) {
        cout << month.first << " ";
    }

    //7.
    cout << endl << "Exercise 7: " << endl;
    vector<double> numbers3{
            2.2, 4.7, 6.8, 8.5, 10.1, 11.2
    };
    cout << "\tNumbers before sorting by abs value: ";
    for (double &n: numbers3) {
        cout << n << " ";
    }
    sort(numbers3.begin(), numbers.end(), [](double a, double b){
        return abs(a) < abs(b);
    });
    return 0;
}