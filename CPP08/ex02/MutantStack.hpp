#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:

        typedef typename std::stack<T>::container_type container_type;
        typedef typename container_type::iterator iterator;
        typedef typename container_type::reverse_iterator reverse_iterator;
        typedef typename container_type::const_iterator const_iterator;
        typedef typename container_type::const_reverse_iterator const_reverse_iterator;
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        iterator begin();
        reverse_iterator rbegin();
        iterator end();
        reverse_iterator rend();
        const_iterator begin() const;
        const_reverse_iterator rbegin() const;
        const_iterator end() const;
        const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"