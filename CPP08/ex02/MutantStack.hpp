#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:

        typedef typename std::stack<T>::container_type container_type;
        typedef typename container_type::iterator iterator;
        typedef typename container_type::const_iterator const_iterator;
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
};

#include "MutantStackt.tpp"