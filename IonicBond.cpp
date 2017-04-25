//  IonicBond.cpp
//  asst10
//
//  Created by Tejas Bala on 11/26/16.
//  Copyright © 2016 Tejas Bala. All rights reserved.
//

#include "IonicBond.h"


#include <iostream>
#include <set>

using namespace std;
using namespace asst10;


IonicBond::IonicBond(const set<shared_ptr<Atom>>& bond, const int& c) : Bond(bond), charge(c){}

IonicBond::~IonicBond() {}

bool IonicBond::shouldBreak() const noexcept {
    return false;
}

int IonicBond::getCharge() const noexcept{
    return IonicBond::charge;
}
