#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }
PmergeMe::~PmergeMe() {}
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	(void)rhs;
	return *this;
}

double PmergeMe::getTime(struct timeval &start, struct timeval &end)
{
	return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

static void buildJacobsthalOrder(size_t pendSize, std::vector<size_t> &order)
{
	if (pendSize <= 1)
		return;
	order.reserve(pendSize - 1);

	std::vector<size_t> jn;
	jn.push_back(0);
	jn.push_back(1);
	while (jn.back() < pendSize)
	{
		size_t next = jn[jn.size() - 1] + 2 * jn[jn.size() - 2];
		jn.push_back(next);
	}

	std::vector<bool> used(pendSize, false);
	used[0] = true;

	for (size_t k = 2; k < jn.size(); k++)
	{
		size_t hi = jn[k];
		if (hi > pendSize)
			hi = pendSize;
		for (size_t i = hi; i > jn[k - 1]; i--)
		{
			size_t idx = i - 1;
			if (idx < pendSize && !used[idx])
			{
				order.push_back(idx);
				used[idx] = true;
			}
		}
		if (hi >= pendSize)
			break;
	}
	for (size_t i = 1; i < pendSize; i++)
	{
		if (!used[i])
			order.push_back(i);
	}
}

static void swapGroups(std::vector<int> &arr, size_t a, size_t b, size_t groupSize)
{
	for (size_t i = 0; i < groupSize; i++)
		std::swap(arr[a + i], arr[b + i]);
}

static size_t binarySearchGroup(const std::vector<int> &arr, size_t startIdx,
								size_t groupSize, size_t count, int val)
{
	size_t lo = 0, hi = count;
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		int rep = arr[startIdx + (mid + 1) * groupSize - 1];
		if (rep < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

static void insertGroup(std::vector<int> &arr, size_t startIdx, size_t groupSize, size_t count, size_t pos, std::vector<int> &tmp)
{
	size_t insertAt = startIdx + pos * groupSize;
	size_t endAt = startIdx + count * groupSize;
	std::copy_backward(arr.begin() + insertAt, arr.begin() + endAt,
					   arr.begin() + endAt + groupSize);
	std::copy(tmp.begin(), tmp.end(), arr.begin() + insertAt);
}

void PmergeMe::fordJohnsonVector(std::vector<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1)
		return;

	size_t maxGroupSize = 1;
	while (maxGroupSize * 2 <= n)
		maxGroupSize *= 2;

	for (size_t gs = 1; gs < n; gs *= 2)
	{
		size_t pairSize = gs * 2;
		for (size_t i = 0; i + pairSize <= n; i += pairSize)
		{
			if (arr[i + gs - 1] > arr[i + pairSize - 1])
				swapGroups(arr, i, i + gs, gs);
		}
	}

	for (size_t gs = maxGroupSize / 2; gs >= 1; gs /= 2)
	{
		size_t pairSize = gs * 2;
		size_t numFullPairs = n / pairSize;
		bool hasStraggler = ((n / gs) % 2 == 1);

		if (numFullPairs == 0)
			continue;

		std::vector<int> mainGroups;
		std::vector<int> pendGroups;
		std::vector<int> pendReps;
		std::vector<int> pendPairReps;

		mainGroups.reserve(numFullPairs * gs);
		pendGroups.reserve(numFullPairs * gs);

		for (size_t i = 0; i < numFullPairs; i++)
		{
			size_t base = i * pairSize;
			for (size_t j = 0; j < gs; j++)
				pendGroups.push_back(arr[base + j]);
			pendReps.push_back(arr[base + gs - 1]);
			for (size_t j = 0; j < gs; j++)
				mainGroups.push_back(arr[base + gs + j]);
			pendPairReps.push_back(arr[base + pairSize - 1]);
		}

		std::vector<int> stragglerGroup;
		bool hasStragglerGroup = false;
		if (hasStraggler)
		{
			hasStragglerGroup = true;
			size_t base = numFullPairs * pairSize;
			for (size_t j = 0; j < gs && base + j < n; j++)
				stragglerGroup.push_back(arr[base + j]);
		}

		for (size_t i = 0; i < mainGroups.size(); i++)
			arr[i] = mainGroups[i];

		size_t mainCount = numFullPairs;

		if (numFullPairs > 0)
		{
			std::vector<int> tmp(pendGroups.begin(), pendGroups.begin() + gs);
			insertGroup(arr, 0, gs, mainCount, 0, tmp);
			mainCount++;
		}

		std::vector<size_t> insertionOrder;
		buildJacobsthalOrder(numFullPairs, insertionOrder);

		for (size_t o = 0; o < insertionOrder.size(); o++)
		{
			size_t pendIdx = insertionOrder[o];
			int val = pendReps[pendIdx];
			int pairVal = pendPairReps[pendIdx];

			size_t searchLimit = binarySearchGroup(arr, 0, gs, mainCount, pairVal + 1);
			size_t pos = binarySearchGroup(arr, 0, gs, searchLimit, val);

			std::vector<int> tmp(pendGroups.begin() + pendIdx * gs,
								 pendGroups.begin() + (pendIdx + 1) * gs);
			insertGroup(arr, 0, gs, mainCount, pos, tmp);
			mainCount++;
		}

		if (hasStragglerGroup && !stragglerGroup.empty())
		{
			int val = stragglerGroup[gs - 1 < stragglerGroup.size() ? gs - 1 : stragglerGroup.size() - 1];
			size_t pos = binarySearchGroup(arr, 0, gs, mainCount, val);
			insertGroup(arr, 0, gs, mainCount, pos, stragglerGroup);
			mainCount++;
		}
	}
}

static void swapGroupsDeque(std::deque<int> &arr, size_t a, size_t b, size_t gs)
{
	for (size_t i = 0; i < gs; i++)
		std::swap(arr[a + i], arr[b + i]);
}

static size_t binarySearchGroupDeque(const std::deque<int> &arr, size_t startIdx, size_t gs, size_t count, int val)
{
	size_t lo = 0, hi = count;
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		int rep = arr[startIdx + (mid + 1) * gs - 1];
		if (rep < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

static void insertGroupDeque(std::deque<int> &arr, size_t startIdx, size_t gs, size_t count, size_t pos, std::vector<int> &tmp)
{
	(void)count;
	size_t insertAt = startIdx + pos * gs;
	arr.insert(arr.begin() + insertAt, tmp.begin(), tmp.end());
	for (size_t i = 0; i < gs; i++)
		arr.pop_back();
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1)
		return;

	size_t maxGroupSize = 1;
	while (maxGroupSize * 2 <= n)
		maxGroupSize *= 2;

	for (size_t gs = 1; gs < n; gs *= 2)
	{
		size_t pairSize = gs * 2;
		for (size_t i = 0; i + pairSize <= n; i += pairSize)
		{
			if (arr[i + gs - 1] > arr[i + pairSize - 1])
				swapGroupsDeque(arr, i, i + gs, gs);
		}
	}

	for (size_t gs = maxGroupSize / 2; gs >= 1; gs /= 2)
	{
		size_t pairSize = gs * 2;
		size_t numFullPairs = n / pairSize;
		bool hasStraggler = ((n / gs) % 2 == 1);

		if (numFullPairs == 0)
			continue;

		std::vector<int> mainGroups, pendGroups;
		std::vector<int> pendReps, pendPairReps;
		mainGroups.reserve(numFullPairs * gs);
		pendGroups.reserve(numFullPairs * gs);

		for (size_t i = 0; i < numFullPairs; i++)
		{
			size_t base = i * pairSize;
			for (size_t j = 0; j < gs; j++)
				pendGroups.push_back(arr[base + j]);
			pendReps.push_back(arr[base + gs - 1]);
			for (size_t j = 0; j < gs; j++)
				mainGroups.push_back(arr[base + gs + j]);
			pendPairReps.push_back(arr[base + pairSize - 1]);
		}

		std::vector<int> stragglerGroup;
		bool hasStragglerGroup = false;
		if (hasStraggler)
		{
			hasStragglerGroup = true;
			size_t base = numFullPairs * pairSize;
			for (size_t j = 0; j < gs && base + j < n; j++)
				stragglerGroup.push_back(arr[base + j]);
		}

		for (size_t i = 0; i < mainGroups.size(); i++)
			arr[i] = mainGroups[i];

		size_t mainCount = numFullPairs;

		if (numFullPairs > 0)
		{
			std::vector<int> tmp(pendGroups.begin(), pendGroups.begin() + gs);
			insertGroupDeque(arr, 0, gs, mainCount, 0, tmp);
			mainCount++;
		}

		std::vector<size_t> insertionOrder;
		buildJacobsthalOrder(numFullPairs, insertionOrder);

		for (size_t o = 0; o < insertionOrder.size(); o++)
		{
			size_t pendIdx = insertionOrder[o];
			int val = pendReps[pendIdx];
			int pairVal = pendPairReps[pendIdx];

			size_t searchLimit = binarySearchGroupDeque(arr, 0, gs, mainCount, pairVal + 1);
			size_t pos = binarySearchGroupDeque(arr, 0, gs, searchLimit, val);
			std::vector<int> tmp(pendGroups.begin() + pendIdx * gs,
								 pendGroups.begin() + (pendIdx + 1) * gs);
			insertGroupDeque(arr, 0, gs, mainCount, pos, tmp);
			mainCount++;
		}

		if (hasStragglerGroup && !stragglerGroup.empty())
		{
			int val = stragglerGroup[gs - 1 < stragglerGroup.size() ? gs - 1 : stragglerGroup.size() - 1];
			size_t pos = binarySearchGroupDeque(arr, 0, gs, mainCount, val);
			insertGroupDeque(arr, 0, gs, mainCount, pos, stragglerGroup);
			mainCount++;
		}
	}
}

void PmergeMe::run(int argc, char **argv)
{
	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		std::stringstream ss(arg);
		long num;
		while (ss >> num)
		{
			if (ss.fail() || num < 0 || num > 2147483647)
				throw std::runtime_error("Error");
			vec.push_back(static_cast<int>(num));
			deq.push_back(static_cast<int>(num));
		}
		if (!ss.eof())
			throw std::runtime_error("Error");
	}

	if (vec.empty())
		return;

	printContainer(vec, "Before");

	struct timeval start, end;

	gettimeofday(&start, NULL);
	fordJohnsonVector(vec);
	gettimeofday(&end, NULL);
	double vecTime = getTime(start, end);

	gettimeofday(&start, NULL);
	fordJohnsonDeque(deq);
	gettimeofday(&end, NULL);
	double deqTime = getTime(start, end);

	printContainer(vec, "After");

	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : "
			  << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;

	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::deque  : "
			  << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}

template <typename Container>
void PmergeMe::printContainer(const Container &c, const std::string &label)
{
	std::cout << label << ":\t";
	for (size_t i = 0; i < c.size(); i++)
	{
		if (c.size() > 5 && i == 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;
}
