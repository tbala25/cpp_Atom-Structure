//
//  Atom.cpp
//  asst10
//
//  Created by Tejas Bala on 11/26/16.
//  Copyright © 2016 Tejas Bala. All rights reserved.
//

#include "Atom.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <set>
#include <memory>

using namespace std;
using namespace asst10;

Atom::Atom(const string& sym) {
    Atom::symbol = sym; //sets atom symbol
}


string Atom::getSymbol() const noexcept {
    return Atom::symbol; //returns symbol
}

weak_ptr<Molecule> Atom::getMolecue() const noexcept {
    return Atom::mol; //returns molecule
}

void Atom::setMolecule(const shared_ptr<Molecule> mole) {
    weak_ptr<Molecule> molWp;
    molWp = mole;
    
    if(Atom::mol.expired()) { //check if ptr is null
        Atom::mol = molWp;
    }
    else if(Atom::mol.lock() != mole) {
        //throw error
        throw logic_error("Molecule already set");
    }

}
