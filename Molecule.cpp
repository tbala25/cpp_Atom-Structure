//  Molecule.cpp
//  asst10
//
//  Created by Tejas Bala on 11/26/16.
//  Copyright © 2016 Tejas Bala. All rights reserved.
//

#include "Molecule.h"
#include "Bond.h"
#include <iostream>
#include <set>
#include <map>
#include <functional>

using namespace std;
using namespace asst10;


Molecule::Molecule(const string& name) {
    Molecule::name = name; //sets name
}

Molecule::~Molecule() {}

string Molecule::getName() const noexcept {
    return Molecule::name; //gives name of molecule
}

void Molecule::addBond(const shared_ptr<Bond> bond) noexcept {
    
    set<shared_ptr<Atom>> b = bond->getAtoms();

    for(shared_ptr<Atom> a : b) {
        try{
            a->setMolecule(shared_from_this()); //sets each atom to this molecule
        }
        catch(exception e) {
            cout << e.what(); //catches exception thrown by Atom::setMolecule
        }
        shared_ptr<Atom> point = a;

        Molecule::atoms.insert(point); //adds unique atoms to set
    }
    Molecule::bonds.insert(shared_ptr<Bond>(bond)); //inserts given bond into set of bonds
}

set<shared_ptr<Atom>> Molecule::getAtoms() const noexcept {

    return Molecule::atoms; //returns set of unique atoms in Molecule
}

            
string Molecule::getFormula() const noexcept {
    string formula; //string of formula to be returned at the end
    typedef map<string, int> MapType; // <symbol,atom count>
    MapType sortedAtoms; //hash map to print formula

    for(auto a : Molecule::atoms) { //iterates through set
        
        if(sortedAtoms.find(a->getSymbol()) == sortedAtoms.end()) { //if symbol isn't in set
            sortedAtoms.insert(pair<string, int>(a->getSymbol(),1)); //add it with value 1
        }
        else {
            sortedAtoms.find((a->getSymbol()))->second++; //else iterate value
        }
    }

    for(map<string,int>::iterator it = sortedAtoms.begin(); it != sortedAtoms.end(); it++) {
        // iterate through hashmap
        if(it->second == 1) { //if value = 1
            formula += it->first; //only print symbol
        }
        else {
            formula += it->first + to_string(it->second); //else print symbol and count
        }
    }
    return formula;
}


