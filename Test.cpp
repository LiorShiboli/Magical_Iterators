#include "sources/MagicalContainer.hpp"
#include "doctest.h"
using namespace ariel;
TEST_SUITE("container"){
    TEST_CASE("build"){
        MagicalContainer container= MagicalContainer();
        CHECK_EQ(container.size(),0);
    }
    TEST_CASE("adding elements"){
        MagicalContainer container= MagicalContainer();
        CHECK_EQ(container.size(),0);
        container.addElement(69);
        CHECK_EQ(container.size(),1);
        for (int i = 0; i < 90; i++)
        {
            container.addElement(i);
        }
        CHECK_EQ(container.size(),91);
    }
    TEST_CASE("remove elements"){
        MagicalContainer container= MagicalContainer();
        CHECK_EQ(container.size(),0);
        for (int i = 0; i < 90; i++)
        {
            container.addElement(i);
        }
        CHECK_EQ(container.size(),90);
        for (int i = 0; i < 90; i++)
        {
            container.removeElement(i);
        }
        CHECK_EQ(container.size(),0);
        SUBCASE("removing element when there are none"){
            CHECK_NOTHROW(container.removeElement(1));
        }
        SUBCASE("removing element when there are none"){
            container.addElement(17);
            CHECK_NOTHROW(container.removeElement(72));
        }
    
    }
}
TEST_SUITE("iterators"){
    TEST_CASE("build from empty iterator"){
        MagicalContainer container = MagicalContainer();
        SUBCASE("ascending "){
            MagicalContainer::AscendingIterator ascIter(container);
            CHECK_NOTHROW(ascIter.begin());
            CHECK_EQ(ascIter.begin(),ascIter.end());
        }
         SUBCASE("prime "){
            MagicalContainer::PrimeIterator primeIter(container);
            CHECK_NOTHROW(primeIter.begin());
            CHECK_EQ(primeIter.begin(),primeIter.end());
        }
         SUBCASE(" side cross"){
            MagicalContainer::SideCrossIterator crossIter(container);
            CHECK_NOTHROW(crossIter.begin());
            CHECK_EQ(crossIter.begin(),crossIter.end());
        }
    }
    TEST_CASE("iterate over all elements"){
        MagicalContainer container = MagicalContainer();
        container.addElement(1);
        container.addElement(2);
        container.addElement(7);
        container.addElement(4);
        container.addElement(3);
        container.addElement(15);
        SUBCASE("ascending "){
            int arr[] ={1,2,3,4,7,15};
            MagicalContainer::AscendingIterator ascIter(container);
            MagicalContainer::AscendingIterator it = ascIter.begin();
            for (int i = 0; i < 6; i++)
            {
                CHECK_EQ(*it,arr[i]);
                CHECK_NE(it,ascIter.end());
                ++it;
            }
            
            
        }
         SUBCASE("prime "){
            int arr[] ={2,3,7};
            MagicalContainer::PrimeIterator primeIter(container);
            MagicalContainer::PrimeIterator it = primeIter.begin();
            for (int i = 0; i <3; i++)
            {
                CHECK_EQ(*it,arr[i]);
                CHECK_NE(it,primeIter.end());
                ++it;
            }
            
        }
         SUBCASE(" side cross"){
            int arr[] ={1,15,2,7,3,4};
            MagicalContainer::SideCrossIterator crossIter(container);
            MagicalContainer::SideCrossIterator it = crossIter.begin();
            for (int i = 0; i < 6; i++)
            {
                
                CHECK_EQ(*it,arr[i]);
                CHECK_NE(it,crossIter.end());
                ++it;
            }
        }
    }
    TEST_CASE("throws past the last element"){
        MagicalContainer container = MagicalContainer();
        container.addElement(1);
        container.addElement(2);
        container.addElement(7);
        container.addElement(4);
        container.addElement(3);
        container.addElement(15);
        SUBCASE("ascending "){
            int arr[] ={1,2,3,4,7,15};
            MagicalContainer::AscendingIterator ascIter(container);
            MagicalContainer::AscendingIterator it = ascIter.begin();
            for (int i = 0; i < 6; i++)
            {
                ++it;
            }
            CHECK_EQ(it,ascIter.end());
            CHECK_THROWS(++it);
            
        }
         SUBCASE("prime "){
            int arr[] ={2,3,7};
            MagicalContainer::PrimeIterator primeIter(container);
            MagicalContainer::PrimeIterator it = primeIter.begin();
            for (int i = 0; i <3; i++)
            {
                ++it;
            }
            CHECK_EQ(it,primeIter.end());
            CHECK_THROWS(++it);
            
        }
         SUBCASE(" side cross"){
            int arr[] ={1,15,2,7,3,4};
            MagicalContainer::SideCrossIterator crossIter(container);
            MagicalContainer::SideCrossIterator it = crossIter.begin();
            for (int i = 0; i < 6; i++)
            {
                ++it;
            }
            CHECK_EQ(it,crossIter.end());
            CHECK_THROWS(++it);
        }
    }

}

TEST_SUITE("containers interaction"){
   TEST_CASE("iterate over everyone at once"){
    MagicalContainer container = MagicalContainer();
        container.addElement(1);
        container.addElement(2);
        container.addElement(7);
        container.addElement(4);
        container.addElement(3);
        container.addElement(15);
        int ascarr[] ={1,2,3,4,7,15};
        int crossarr[] ={1,15,2,7,3,4};
        int primearr[] ={2,3,7};
        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::AscendingIterator ascit = ascIter.begin();

        MagicalContainer::PrimeIterator primeIter(container);
        MagicalContainer::PrimeIterator primeit = primeIter.begin();

        MagicalContainer::SideCrossIterator  crossIter(container);
        MagicalContainer::SideCrossIterator crossit = crossIter.begin();
        for (int i = 0; i < 6; i++)
        {
            CHECK_EQ(*ascit,ascarr[i]);
            CHECK_EQ(*crossit,crossarr[i]);
            if (i<3)
            {
            CHECK_EQ(*primeit,primearr[i]);
            ++primeit;
            }
            ++ascit;
            ++crossit;
        }
   }

   TEST_CASE("add an element in the middle of iterating before its turn"){

    MagicalContainer container = MagicalContainer();
    container.addElement(1);
    container.addElement(2);
    container.addElement(7);
    container.addElement(4);
    container.addElement(3);
    container.addElement(15);
    SUBCASE("ascending "){
        int arr[] ={1,2,3,4,7,15};
        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::AscendingIterator it = ascIter.begin();
        for (int i = 0; i < 3; i++)
        {
            ++it;
        }
        container.addElement(5);
        CHECK_NE(*it,5);
        ++it;
        CHECK_EQ(*it,5);
        container.removeElement(5);
    }
        SUBCASE("prime "){
        int arr[] ={2,3,7};
        MagicalContainer::PrimeIterator primeIter(container);
        MagicalContainer::PrimeIterator it = primeIter.begin();
        for (int i = 0; i <1; i++)
        {
            ++it;
        }
        container.addElement(5);
        CHECK_NE(*it,5);
        ++it;
        CHECK_EQ(*it,5);
        container.removeElement(5);
        
    }
        SUBCASE(" side cross"){
        int arr[] ={1,15,2,7,3,4};
        MagicalContainer::SideCrossIterator crossIter(container);
        MagicalContainer::SideCrossIterator it = crossIter.begin();
        for (int i = 0; i < 2; i++)
        {
            ++it;
        }
        container.addElement(8);
        CHECK_NE(*it,8);
        ++it;
        CHECK_EQ(*it,8);
        container.removeElement(8);
    }
    }
    TEST_CASE("add an element after its time"){
    MagicalContainer container = MagicalContainer();
    container.addElement(1);
    container.addElement(2);
    container.addElement(7);
    container.addElement(4);
    container.addElement(3);
    container.addElement(15);
    SUBCASE("ascending "){
        int arr[] ={1,2,3,4,7,15};
        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::AscendingIterator it = ascIter.begin();
        for (int i = 0; i < 3; i++)
        {
            ++it;
        }
        container.addElement(0);
        ++it;
        CHECK_EQ(*it,7);
        container.removeElement(0);
    }
        SUBCASE("prime "){
        int arr[] ={2,3,7};
        MagicalContainer::PrimeIterator primeIter(container);
        MagicalContainer::PrimeIterator it = primeIter.begin();
        for (int i = 0; i <2; i++)
        {
            ++it;
        }
        container.addElement(5);
        ++it;
        CHECK_EQ(it,primeIter.end());
        container.removeElement(5);
        
    }
        SUBCASE(" side cross"){
        int arr[] ={1,15,2,7,3,4};
        MagicalContainer::SideCrossIterator crossIter(container);
        MagicalContainer::SideCrossIterator it = crossIter.begin();
        for (int i = 0; i < 2; i++)
        {
            ++it;
        }
        container.addElement(21);
        ++it;
        CHECK_EQ(*it,7);
        container.removeElement(21);
    }
    }
}