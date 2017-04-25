//  Bond.cpp
//  asst10
//
//  Created by Tejas Bala on 11/26/16.
//  Copyright © 2016 Tejas Bala. All rights reserved.
//

#include "Bond.h"


#include <iostream>
#include <set>

using namespace std;
using namespace asst10;


Bond::Bond(const set<shared_ptr<Atom>>& bond) {
    Bond::atoms = bond;
}

Bond::~Bond() {}


set<shared_ptr<Atom>> Bond::getAtoms() const noexcept{
    return Bond::atoms; //set of pointers to atoms
}


