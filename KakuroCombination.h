#pragma once
#include "pch.h"
#include <set>

namespace Logic {
	class CKakuroCombination {
	public:
		static void GetPossibleCombinationSets(std::set<std::set<int>>& possibleCombinations, int numPositions, int sum, const std::set<int>& forbiddenNumerals);
	private:
		static void InvertForbiddenSet(const std::set<int>& forbiddenNumerals, std::set<int>& allowedNumerals);

	};
};