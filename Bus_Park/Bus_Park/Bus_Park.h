#pragma once
#include "Bus.h"

class Bus_Park {
public:
    Bus_Park();
    ~Bus_Park();
    void AddBus(string numberBus, string fname, string lname, string routeNumber, size_t countPlaces);
    void printBus(string numberBus) const;
    void clear();
    Bus* findBus(string numberBus) const;
    void save(string filename) const;
private:
    Bus* root;
    void AddBus(Bus* cur, string numberBus, string fname, string lname, string routeNumber, size_t countPlaces);
    void clear(Bus* cur);
    Bus* findBus(Bus* cur, string numberBus) const;
    void save(Bus* cur, ofstream&  fcout) const;
};



