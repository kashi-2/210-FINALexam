/*
    Akashdeep Singh
    COMSC-210 || Final Part 1
*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

void print_range(const map<string, int>& airports, int low, int high);

int main() {

    // Milestone 1
    map<string, int> airports;

    ifstream fin("210-final-1-SP26.txt");

    if (!fin) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string origin, destination;

    while (fin >> origin >> destination) {

        if (airports.find(origin) == airports.end())
            airports[origin] = 0;

        if (airports.find(destination) == airports.end())
            airports[destination] = 0;

        airports[origin]++;
        airports[destination]++;
    }

    fin.close();

    cout << "All airport traffic counts:" << endl;

    for (auto airport : airports)
        cout << airport.first << " " << airport.second << endl;

    cout << endl;

    // Milestone 2
    int max_count = 0;

    for (auto airport : airports) {

        if (airport.second > max_count)
            max_count = airport.second;
    }

    cout << "Busiest airport(s) with count "
         << max_count << ":" << endl;

    for (auto airport : airports) {

        if (airport.second == max_count)
            cout << airport.first << " "
                 << airport.second << endl;
    }

    cout << endl;

    return 0;
}