/** Sort input as if by doing binary search.
 * ... a ... => a comes first,
 * .b.   .c. => b, c next, and so on.
 */

#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <string>

static size_t binary_distance(size_t size, size_t index)
{
	size_t first = 0;
	size_t distance = 0;
	while (true)
	{
		size_t step = size >> 1;
		size_t next = first + step;
		if (index == next)
		{
			return distance;
		}
		else if (index > next)
		{
			first = next + 1;
			size -= step + 1;
		}
		else if (index < next)
		{
			size = step;
		}
		++distance;
	};
}

static std::vector<size_t> binary_indices(size_t size)
{
	std::vector<size_t> indices(size);
	std::iota(begin(indices), end(indices), size_t{0});
	auto fn = [&](size_t x, size_t y) {
		return binary_distance(size, x) < binary_distance(size, y);
	};
	std::sort(begin(indices), end(indices), fn);
	return indices;
}

int main()
{
	auto str = std::string{};
	str.reserve(0x8000);
	std::copy(
		std::istreambuf_iterator<char>(std::cin),
		std::istreambuf_iterator<char>(),
		std::back_inserter(str));
	auto lines = std::vector<const char*>{ str.data() };
	for (
		auto end = std::end(str), it = std::find(std::begin(str) + 1, end, '\n');
		it != end;
		it = std::find(it+1, end, '\n'))
	{
		*it = '\0';
		if (it[1] != 0)
		{
			lines.push_back(&it[1]);
		}
	}
	auto indices = binary_indices(lines.size());
	for (auto index : indices)
	{
		std::cout << lines[index] << '\n';
	}
}
