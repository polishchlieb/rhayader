#pragma once
#include <vector>

namespace soviet {
	namespace util {
		template<typename T, typename _v>
		T reduce(std::vector<_v>& arr, T (*callback)(T&, _v&), T initial = 0) {
			T accumulator = initial;
			for (_v& element : arr) {
				accumulator = callback(accumulator, element);
			}
			return accumulator;
		}
	}
}