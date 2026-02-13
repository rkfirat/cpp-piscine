#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <sstream>
#include <iomanip>


class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &rhs);

		void run(int argc, char **argv);

	private:
		void fordJohnsonVector(std::vector<int> &arr);
		void fordJohnsonDeque(std::deque<int> &arr);

		double getTime(struct timeval &start, struct timeval &end);

		template <typename Container>
		void printContainer(const Container &c, const std::string &label);
};

#endif
