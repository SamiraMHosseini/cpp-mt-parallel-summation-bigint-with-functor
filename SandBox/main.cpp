#include <vector>
#include <thread>
#include <iostream>
#include <algorithm>

typedef unsigned long long ULLONG;

struct Sum_Num
{
	Sum_Num() : sum(0) {};
	Sum_Num(const Sum_Num&) = default;
	Sum_Num& operator=(const Sum_Num&) = default;
	~Sum_Num() = default;

	void operator()(ULLONG  start, ULLONG  end)
	{
		this->sum = 0;
		for (ULLONG i = start; i <= end; ++i)
		{
			this->sum += i;
		}
	}

	ULLONG sum{};
};

ULLONG vectAccumulate(std::vector<Sum_Num>& vect)
{
	ULLONG total{ 0 };

	for (const auto& item : vect)
	{

		total += item.sum;

	}
	return total;
}
class A
{
	int t{};

};
int main()
{
	constexpr int number_of_threads = 10000;                //1, 5,  3 , 6 , 8 , 9 , 5 , 10000
	constexpr ULLONG  number_of_items = 1000 * 1000 * 1000; //5, 1, ,7 , 21 ,21 ,26, 10 ,1000 * 1000 * 1000
	constexpr ULLONG  step = number_of_items / number_of_threads;

	ULLONG  NUM = number_of_threads;

	if (number_of_items % number_of_threads != 0)
	{
		NUM = number_of_threads - 1;
	}

	ULLONG  counter = 1;
	size_t  index = 0;
	ULLONG  start = 0;
	ULLONG  end = 0;
	std::vector<std::thread> workers;
	std::vector<Sum_Num> vectSum(number_of_threads);
	//Assigning a task to a specific thread
	for (; index < NUM; ++index, counter += step)
	{
		start = counter;
		end = counter + step - 1;
		std::cout << start << "  , " << end << " , " << index << '\n';
		workers.push_back(std::thread(std::ref(vectSum.at(index)), start, end));

	}
	if (number_of_items % number_of_threads != 0)
	{
		std::cout << counter << "  , " << number_of_items << " , " << index << '\n';

		workers.push_back(std::thread(std::ref(vectSum.at(index)), counter, number_of_items));

	}

	//Waiting for the threads to join
	std::for_each(workers.begin(), workers.end(),

		[](std::thread& th) -> void
		{th.join(); }

	);

	const ULLONG  total = vectAccumulate(vectSum);
	std::cout << "total: " << total << "\n";

}