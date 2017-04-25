//
//  main.cpp
//  asst10
//
//  Created by Tejas Bala on 11/28/16.
//  Copyright © 2016 Tejas Bala. All rights reserved.
//

#include <iostream>
#include "Atom.h"
#include "Molecule.h"
#include "IonicBond.h"
#include "CovalentBond.h"
#include <set>
#include <memory>
using namespace std;
using namespace asst10;

/**
 * \namespace asst10 Creates smart pointers of atoms, molecules and bonds. 
 * The program creates atoms, bond and molecules.
 * It then prints the formulas of water, salt and benzyne and catches an exception.
 *@author Tejas Bala
 */

/**
 * Main program for the tenth assignment.
 * @return The exit status. Normal status is 0.
 */

int main() {
    //WATER
    //create pointers
    shared_ptr<Atom> hyd1 = make_shared<Atom>("H");
    shared_ptr<Atom> hyd2 = make_shared<Atom>("H");
    shared_ptr<Atom> o = make_shared<Atom>("O");

    //create bonds
    set<shared_ptr<Atom>> ho1;
    set<shared_ptr<Atom>> ho2;
    ho1.insert(hyd1);
    ho1.insert(o);
    ho2.insert(hyd2);
    ho2.insert(o);
    
    //create water molecule and add bonds
    shared_ptr<Molecule> water = make_shared<Molecule>("water");
    shared_ptr<Bond> oh1 = make_shared<CovalentBond>(ho1,3);
    shared_ptr<Bond> oh2 = make_shared<CovalentBond>(ho2,3);
    water->addBond(oh1);
    water->addBond(oh2);

    //print water formula
    cout << "\n water formula: " + water->getFormula() + "\n";
    cout<< hyd1->getSymbol() + "\n";
    cout<< hyd2->getSymbol() + "\n";
    cout<< o->getSymbol() + "\n";
    
    
    //SALT
    //create pointers
    shared_ptr<Atom> na = make_shared<Atom>("Na");
    shared_ptr<Atom> cl = make_shared<Atom>("Cl");
    
    //create bonds
    set<shared_ptr<Atom>> nacl;
    nacl.insert(na);
    nacl.insert(cl);
    
    //create salt molecule and add bonds
    shared_ptr<Molecule> salt = make_shared<Molecule>("salt");
    shared_ptr<Bond> sb = make_shared<IonicBond>(nacl,5);
    salt->addBond(sb);
    
    //print salt formula
    cout << "\n salt formula: " + salt->getFormula() + "\n";
    cout<< na->getSymbol() + "\n";
    cout<< cl->getSymbol() + "\n";

    
    //BENZENE
    //create pointers
    shared_ptr<Atom> c1 = make_shared<Atom>("C");
    shared_ptr<Atom> c2 = make_shared<Atom>("C");
    shared_ptr<Atom> c3 = make_shared<Atom>("C");
    shared_ptr<Atom> c4 = make_shared<Atom>("C");
    shared_ptr<Atom> c5 = make_shared<Atom>("C");
    shared_ptr<Atom> c6 = make_shared<Atom>("C");
    shared_ptr<Atom> h1 = make_shared<Atom>("H");
    shared_ptr<Atom> h2 = make_shared<Atom>("H");
    shared_ptr<Atom> h3 = make_shared<Atom>("H");
    shared_ptr<Atom> h4 = make_shared<Atom>("H");
    shared_ptr<Atom> h5 = make_shared<Atom>("H");
    shared_ptr<Atom> h6 = make_shared<Atom>("H");

    //create bonds
    set<shared_ptr<Atom>> allC;
    allC.insert(c1);
    allC.insert(c2);
    allC.insert(c3);
    allC.insert(c4);
    allC.insert(c5);
    allC.insert(c6);
    set<shared_ptr<Atom>> hc1;
    hc1.insert(c1);
    hc1.insert(h1);
    set<shared_ptr<Atom>> hc2;
    hc1.insert(c2);
    hc1.insert(h2);
    set<shared_ptr<Atom>> hc3;
    hc1.insert(c3);
    hc1.insert(h3);
    set<shared_ptr<Atom>> hc4;
    hc1.insert(c4);
    hc1.insert(h4);
    set<shared_ptr<Atom>> hc5;
    hc1.insert(c5);
    hc1.insert(h5);
    set<shared_ptr<Atom>> hc6;
    hc1.insert(c6);
    hc1.insert(h6);

    //create benzene molecule and add bonds
    shared_ptr<Molecule> benzene = make_shared<Molecule>("benzene");
    shared_ptr<Bond> a = make_shared<CovalentBond>(allC,2);
    benzene->addBond(a);
    shared_ptr<Bond> b1 = make_shared<CovalentBond>(hc1,4);
    benzene->addBond(b1);
    shared_ptr<Bond> b2 = make_shared<CovalentBond>(hc2,4);
    benzene->addBond(b2);
    shared_ptr<Bond> b3 = make_shared<CovalentBond>(hc3,4);
    benzene->addBond(b3);
    shared_ptr<Bond> b4 = make_shared<CovalentBond>(hc4,4);
    benzene->addBond(b4);
    shared_ptr<Bond> b5 = make_shared<CovalentBond>(hc5,4);
    benzene->addBond(b5);
    shared_ptr<Bond> b6 = make_shared<CovalentBond>(hc6,4);
    benzene->addBond(b6);
    
    //print benzene formula
    cout << "\n benzene formula: " + benzene->getFormula() + "\n";
    cout<< h1->getSymbol() + "\n";
    cout<< h2->getSymbol() + "\n";
    cout<< h3->getSymbol() + "\n";
    cout<< h4->getSymbol() + "\n";
    cout<< h5->getSymbol() + "\n";
    cout<< h6->getSymbol() + "\n";
    cout<< c1->getSymbol() + "\n";
    cout<< c2->getSymbol() + "\n";
    cout<< c3->getSymbol() + "\n";
    cout<< c4->getSymbol() + "\n";
    cout<< c5->getSymbol() + "\n";
    cout<< c6->getSymbol() + "\n";

    
    //try to reset oxygen's molecule from water to Empty
    try {
        o->setMolecule(make_shared<Molecule>("mt"));
    }
    catch(exception e) {
        cout << "tried to change but: ";
        cout << e.what(); //print exception
    }
    
    return 0;
}
