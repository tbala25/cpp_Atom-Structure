//
//  Bond.h
//  asst10
//
//  Created by Tejas Bala on 11/26/16.
//  Copyright © 2016 Tejas Bala. All rights reserved.
//

#ifndef Bond_h
#define Bond_h

#include <string>
#include "Atom.h"
#include <set>
#include <memory>

using namespace std;

namespace asst10 {
    /**
     * A Bond object. An bond has a set of atoms.
     * @author Tejas Bala
     */

    //Forward declaration of Molecule class
    class Molecule;

    class Bond {
    public:
        /**
         *Public constructor sets symbol of atom
         */
        Bond(/*set of atoms in bond*/const set<shared_ptr<Atom>>& bon);
        
        /** Destructor */
        virtual ~Bond();
        
        /**
         *@returns the set of atoms in the bond
         */
        set<shared_ptr<Atom>> getAtoms() const noexcept;
        
        /** Pure virtual function
         * Always returns false.
         */
        virtual bool shouldBreak() const noexcept = 0;
        
    protected:
        //set of smart pointers to atoms in bond
        set<shared_ptr<Atom>> atoms;
    };
}
#endif /* Bond_h */
