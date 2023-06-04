#pragma once
namespace ariel
{
    

    class MagicalContainer
    {
    private:
        /* data */
    public:
        MagicalContainer(/* args */);
        ~MagicalContainer();
        void addElement(int);
        int size();
        void removeElement(int);
        class AscendingIterator{
            private:
            /* data */
            public:
                AscendingIterator(MagicalContainer);
                ~AscendingIterator();
                AscendingIterator begin();
                AscendingIterator end();
                AscendingIterator& operator=(const AscendingIterator&);
                AscendingIterator& operator++();
                bool operator==(const AscendingIterator&)const;
                int  operator*()const;
        };
        class SideCrossIterator{
            private:
            /* data */
            public:
                SideCrossIterator(MagicalContainer);
                ~SideCrossIterator();
                SideCrossIterator begin();
                SideCrossIterator end();
                SideCrossIterator& operator=(const SideCrossIterator&);
                SideCrossIterator& operator++();
                bool operator==(const SideCrossIterator&)const;
                int  operator*()const;
        };
    
    
    class PrimeIterator{
            private:
            /* data */
            public:
                PrimeIterator(MagicalContainer);
                ~PrimeIterator();
                PrimeIterator begin();
                PrimeIterator end();
                PrimeIterator& operator=(const PrimeIterator&);
                PrimeIterator& operator++();
                bool operator==(const PrimeIterator&)const;
                int  operator*()const;
        };
    };
    
}
