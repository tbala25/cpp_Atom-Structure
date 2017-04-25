#ifndef CovalentBond_h
#define CovalentBond_h

#include "Bond.h"

using namespace std;

namespace asst10 {
    /**
     * A CovalentBond object. An covalent bond has a set of atoms, and a double
     * polarity.
     * @author Tejas Bala
     */

    //Forward declaration of Molecule class
    //class Molecule;

    class CovalentBond: virtual public Bond {
    public:
        /**
         *Public constructor sets symbol of atom
         */
        CovalentBond(/*String to set symbol name*/const set<shared_ptr<Atom>>& bon, /*The double to set polarity*/ const double& p);
        
        /** Destructor */
        virtual ~CovalentBond();
        
        /*
         *@ returns the polarity of the bond
         */
        double getPolarity() const noexcept;
        
        /*
         *@return False
         */
        virtual bool shouldBreak() const noexcept;

    private:
        //polarity of bond
        double polarity;
    };
}
#endif /* CovalentBond_h */
