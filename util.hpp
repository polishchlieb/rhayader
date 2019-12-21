#pragma once
#include <vector>

namespace soviet {
	namespace util {
		template<typename T, typename _v>
		T reduce(std::vector<_v>& vec, T (*callback)(T&, _v&), T initial = 0) {
			T accumulator = initial;
			for (_v& element : vec) {
				accumulator = callback(accumulator, element);
			}
			return accumulator;
		}

		template<typename T, typename t>
		void map(std::vector<t>& result, std::vector<T>& vec, t (*callback)(T&)) {
			for (T& element : vec) {
				result.push_back(callback(element));
			}
		}
	}
}