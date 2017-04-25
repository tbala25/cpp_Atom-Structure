//  CovalentBond.cpp
//  asst10
//
//  Created by Tejas Bala on 11/26/16.
//  Copyright © 2016 Tejas Bala. All rights reserved.
//

#include "CovalentBond.h"


#include <iostream>
#include <set>

using namespace std;
using namespace asst10;


CovalentBond::CovalentBond(const set<shared_ptr<Atom>>& bond, const double& p) : Bond(bond), polarity(p) {}

CovalentBond::~CovalentBond(){}

bool CovalentBond::shouldBreak() const noexcept {
    return false;
}


double CovalentBond::getPolarity() const noexcept {
    return CovalentBond::polarity;
}


