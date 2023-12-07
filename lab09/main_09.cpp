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
    cout << "\tFruits: ";
    for_each(fruits.begin(), fruits.end(), [](string fruit) {
        cout << fruit << " ";
    });
    cout << endl;
    string searchString;
    cout << "\tEnter a string to search: ";
    cin >> searchString;
    auto found = find_if(fruits.begin(), fruits.end(), [searchString](const string &fruit) {
        return fruit.find(searchString) != string::npos;
    });

    if (found != fruits.end()) {
        cout << "\tFound: " << *found << endl;
    } else {
        cout << "\tNot found" << endl;
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
            2.2, 10.7, 3.8, 8.5, 10.1, 11.2
    };
    cout << "\tNumbers before sorting by abs value: ";
    for (double &n: numbers3) {
        cout << n << " ";
    }
    cout << endl;
    sort(numbers3.begin(), numbers3.end(), [](double a, double b){
        return abs(a) < abs(b);
    });
    cout << "\tNumbers after sorting by abs value: ";
    for (double &n: numbers3) {
        cout << n << " ";
    }
    cout<<endl;

    //8.
    cout << "Exercise 8: " << endl;
    cout << "\tMonths before sorting: ";
    for (auto &month: months) {
        cout << month << " ";
    }
    cout << endl;

    for_each(months.begin(), months.end(), [](string &month) {
        transform(month.begin(), month.end(), month.begin(), ::tolower);
    });

    cout << "\tMonths after sorting: ";
    for (auto &month: months) {
        cout << month << " ";
    }
    cout << endl;

    //9.
    cout << "Exercise 9: " << endl;
    vector<char> alphabet;
    for (char i = 'a'; i <= 'z'; ++i) {
        alphabet.push_back(i);
    }
    cout << "\tAlphabet: ";
    for (char &c: alphabet) {
        cout << c << " ";
    }
    cout << endl;
    random_shuffle(alphabet.begin(), alphabet.end());
    cout << "\tAlphabet after shuffle: ";
    for (char &c: alphabet) {
        cout << c << " ";
    }
    cout << endl;

    cout << "\tMonths before sorting: ";
    for (auto &month: months) {
        cout << month << " ";
    }
    cout << endl;

    sort(months.begin(), months.end(), [&alphabet](string a, string b){
        for (int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]){
                return find(alphabet.begin(), alphabet.end(), a[i]) < find(alphabet.begin(), alphabet.end(), b[i]);
            }
        }
        return false;
    });

    cout << "\tMonths after sorting: ";
    for (auto &month: months) {
        cout << month << " ";
    }
    cout << endl;

    return 0;
}