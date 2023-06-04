#include "MagicalContainer.hpp"
namespace ariel
{
        MagicalContainer::MagicalContainer(/* args */){}
        MagicalContainer::~MagicalContainer(){}
        void MagicalContainer::addElement(int){}
        int MagicalContainer::size(){return 0;}
        void  MagicalContainer::removeElement(int){}



        MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer){}
        MagicalContainer::AscendingIterator::~AscendingIterator(){}
        MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){return AscendingIterator(MagicalContainer());}
        MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){return AscendingIterator(MagicalContainer());}
        MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator& something){return *this; }
        MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){return *this;}
        bool   MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator& obj2)const{return true;}
        int    MagicalContainer::AscendingIterator::operator*()const{return 0;}





    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer){}
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){return SideCrossIterator(MagicalContainer());}
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){return SideCrossIterator(MagicalContainer());}
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator& something){return *this;}
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){return *this;}
    bool   MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator& obj2)const{return true;}
    int    MagicalContainer::SideCrossIterator::operator*()const{return 0;}
    
    


     MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer){}
    MagicalContainer::PrimeIterator::~PrimeIterator(){}
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){return PrimeIterator(MagicalContainer());}
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){return PrimeIterator(MagicalContainer());}
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator& something){return *this;}
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){return *this;}
    bool   MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator& obj2)const{return true;}
    int   MagicalContainer::PrimeIterator::operator*()const{return 0;}
    
    
} // namespace ariel
