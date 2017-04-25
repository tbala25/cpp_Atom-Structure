#ifndef IonicBond_h
#define IonicBond_h

#include "Bond.h"

using namespace std;

namespace asst10 {
    /**
     * An IonicBond object. An ionic bond has a set of atoms and an integer charge.
     * @author Tejas Bala
     */

    //Forward declaration of Molecule class
    //class Molecule;

    class IonicBond: public Bond {
    public:
        /**
         *Public constructor sets symbol of atom
         */
        IonicBond(/*String to set symbol name*/const set<shared_ptr<Atom>>& bon, /*Integer to set charge*/ const int& c);
        
        /** Destructor */
        virtual ~IonicBond();
        
        /*
         *@ returns the charge of the bond
         */
        int getCharge() const noexcept;
        
        /*
         *@return False
         */
        virtual bool shouldBreak() const noexcept;

    private:
        //charge of bond
        int charge;
    };
}
#endif /* IonicBond_h */
