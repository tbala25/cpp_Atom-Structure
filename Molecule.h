//
//  Molecule.h
//  asst10
//
//  Created by Tejas Bala on 11/26/16.
//  Copyright © 2016 Tejas Bala. All rights reserved.
//

#ifndef Molecule_h
#define Molecule_h

#include <string>
#include <set>
#include "Atom.h"
#include <functional>

using namespace std;

namespace asst10 {
    /**
     * A Molecule object. A Molecule is made up of bonds of Atoms. A Molecule has a name.
     * @author Tejas Bala
     */
    
    class Bond;
  
    class Molecule: public std::enable_shared_from_this<Molecule> {
    public:
        /**
         *Public constructor sets name of Molecule
         */
        Molecule(/*String to set molecule name*/const string& name);
        /**
         *Molecule destructor .
         */
        ~Molecule();

        /**
         *@return name of Molecule
         */
        string getName() const noexcept;

        /**
         *Adds a bond to the molecule. Also adds unique molecules to a set of Atoms.
         *@param bond is a set of Atoms
         */
        void addBond(/*Set of atoms that will be inserted into set*/const shared_ptr<Bond> bond) noexcept;

        /**
         *@returns set of atoms in molecule
         */
        set<shared_ptr<Atom>> getAtoms() const noexcept;

        /**
         *@return the string formula of the molecule
         *Does this by iterating through the set of atoms and creating a hash set.
         *The hash set has the symbol as the key and molecule count as the value.
         */
        string getFormula() const noexcept;


        /*
         *@param a is the pointer to an atom
         *@return number of bonds that specified atom is in
         */
        int boundCount(const Atom* a) const noexcept;
        

    private:
        /**
         *name of Molecule
         */
        string name;
        /**
         *Bonds of Molecule
         */
        set<shared_ptr<Bond>> bonds;
        /**
         *Unique atoms in molecule
         */
        set<shared_ptr<Atom>> atoms;
        
        
    };
}
#endif /* Molecule_h */
