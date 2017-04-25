//
//  Atom.h
//  asst10
//
//  Created by Tejas Bala on 11/26/16.
//  Copyright © 2016 Tejas Bala. All rights reserved.
//

#ifndef Atom_h
#define Atom_h

#include <string>
#include <memory>

using namespace std;

namespace asst10 {
    /**
     * An Atom object. An atom has  asymbol and a molecule. An atom is part
     * of a molecule.
     * @author Tejas Bala
     */
    //Forward declaration of Molecule class
    class Molecule;
    class Atom {
    public:
        /**
         *Public constructor sets symbol of atom
         */
        Atom(/*String to set symbol name*/const string& sym);

        /**
         *@Return the symbol of the atom
         */
        string getSymbol() const noexcept;

        /**
         *@Return a weak pointer to the Molecule 
         */
        weak_ptr<Molecule> getMolecue() const noexcept;

        /**
         *Sets the molecule  of the atom
         *@param mole is the specified molecule
         @throws logic error if trying to set to a different molecule once molecule is set
         */
        void setMolecule(/*String to set molecule identifier*/const shared_ptr<Molecule> mole);


    private:
        /**
         *String symbol of atom
         */
        string symbol;
        /**
         *Molecule of atom
         */
        weak_ptr<Molecule> mol;
    };
}
#endif /* Atom_h */
