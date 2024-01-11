#include "Bus_Park.h"
#include <fstream>

Bus_Park::Bus_Park() :root(nullptr) {}
Bus_Park::~Bus_Park() { clear(); }

void Bus_Park::AddBus(string numberBus, string fname, string lname, string routeNumber, size_t countPlaces)
{
    if (root)
        AddBus(root, numberBus, fname, lname,  routeNumber, countPlaces);
    else
        root = new  Bus(numberBus, fname, lname, routeNumber, countPlaces);
}

void Bus_Park::printBus(string numberBus) const
{
    Bus* bus = findBus(root, numberBus);
    if (!bus) {
        cout << "Bus not found" << endl;
        return;
    }
    bus->print();
}

void Bus_Park::clear()
{
    clear(root);
    root = nullptr;
}

Bus* Bus_Park::findBus(string numberBus) const { return  findBus(root, numberBus); }

void Bus_Park::save(string filename) const
{
    ofstream  fcout(filename, ios::out | ios::app);
    if (!fcout.is_open()) throw exception("file not opened");
    save(root, fcout);
    fcout.close();
}

void Bus_Park::save(Bus* cur, ofstream& fcout) const
{
    if (!cur) return;
    save(cur->getLeft(), fcout);
    save(cur->getRight(), fcout);
    fcout << cur->getNumberBus() << endl;
    fcout << cur->getFname() << endl;
    fcout << cur->getLname() << endl;
    fcout << cur->getRouteNumber() << endl;
    fcout << cur->getCountPlaces() << endl;
}

void Bus_Park::AddBus(Bus* cur, string numberBus, string fname, string lname, string routeNumber, size_t countPlaces)
{
    if (cur->getNumberBus() == numberBus) throw exception("Can't add 2 identical bus");
    if (cur->getNumberBus() < numberBus)
        if (cur->getRight())
            AddBus(cur->getRight(), numberBus, fname, lname, routeNumber, countPlaces);
        else
            cur->setRight(new  Bus(numberBus, fname, lname, routeNumber, countPlaces));
    else
        if (cur->getLeft())
            AddBus(cur->getLeft(), numberBus, fname, lname, routeNumber, countPlaces);
        else
            cur->setLeft(new  Bus(numberBus, fname, lname, routeNumber, countPlaces));
}

void Bus_Park::clear(Bus* cur)
{
    if (!cur) return;
    clear(cur->getLeft());
    clear(cur->getRight());
    delete cur;
}
Bus* Bus_Park::findBus(Bus* cur, string numberBus) const
{
    if (!cur) return nullptr;
    if (cur->getNumberBus() == numberBus) return cur;
    if (cur->getNumberBus() < numberBus) return findBus(cur->getRight(), numberBus);
    return findBus(cur->getLeft(), numberBus);
}


