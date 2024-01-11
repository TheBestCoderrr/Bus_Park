#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bus {
public:
    explicit Bus(string numberBus, string fname, string lname, string routeNumber, size_t countPlaces, Bus* left = nullptr, Bus* right = nullptr) :
        numberBus(numberBus), fname(fname), lname(lname), routeNumber(routeNumber), countPlaces(countPlaces), left(left), right(right) {}
    void print() const {
        cout << "Number bus: " << numberBus << endl;
        cout << "Driver: " << fname << ' ' << lname << endl;
        cout << "Route number: " << routeNumber << endl;
        cout << "Count places: " << countPlaces << endl;
        cout << endl;
    }
    void setNumberBus(string numberBus) { this->numberBus = numberBus; }
    string getNumberBus() const { return numberBus; }
    void setFname(string fname) { this->fname = fname; }
    string getFname() const { return fname; }
    void setLname(string lname) { this->lname = lname; }
    string getLname() const { return lname; }
    void setRouteNumber(string routeNumber) { this->routeNumber = routeNumber; }
    string getRouteNumber() const { return routeNumber; }
    void setCountPlaces(size_t countPlaces) { this->countPlaces = countPlaces; }
    size_t getCountPlaces() const { return countPlaces; }
    Bus* getLeft() const { return left; }
    void setLeft(Bus* left) { this->left = left; }
    Bus* getRight() const { return right; }
    void setRight(Bus* right) { this->right = right; }
private:
    string numberBus;
    string fname;
    string lname;
    string routeNumber;
    size_t countPlaces;
    Bus* left;
    Bus* right;
};


