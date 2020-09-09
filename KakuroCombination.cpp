#include "pch.h"
#include "KakuroCombination.h"
#include <algorithm>
#include <numeric>


Logic::CKakuroCombination::CKakuroCombination()
{
	this->AllNumerals = new int[]{ 1,2,3,4,5,6,7,8,9 };

	const std::set<int> Logic::CKakuroCombination::AllNumeralsSet(
		std::begin(Logic::CKakuroCombination::AllNumerals),
		std::end(Logic::CKakuroCombination::AllNumerals));
};

void Logic::CKakuroCombination::GetPossibleCombinationSets(std::set<std::set<int>>& possibleCombinations, int numPositions, int sum, const std::set<int>& forbiddenNumerals)
{
	std::set<std::set<int>> resultingCombinations;
	std::set<int> allowedNumerals;
	InvertForbiddenSet(forbiddenNumerals, allowedNumerals);

	if(numPositions > 0 && numPositions < 10)
	for (auto& numeral : allowedNumerals)
	{
		std::set<int> newForbiddenNumerals(forbiddenNumerals);

		//avoid superfluous calculations; order does not matter
		for (int i = 1; i <= numeral; ++i)
		{
			newForbiddenNumerals.emplace(numeral);
		}
		std::set<std::set<int>> nextCombinations;
		GetPossibleCombinationSets(nextCombinations, numPositions - 1, sum - numeral, newForbiddenNumerals);
		for (const std::set<int>& next : nextCombinations)
		{
			if( (numeral + std::accumulate(next.begin(), next.end(), 0))  == sum)
			{ 
				std::set<int> copyNext(next);
				copyNext.emplace(numeral);
				resultingCombinations.emplace(copyNext);
			}
			
		}
	}

	possibleCombinations = resultingCombinations;
}

void Logic::CKakuroCombination::InvertForbiddenSet(const std::set<int>& forbiddenNumerals, std::set<int>& allowedNumerals)
{
	const int allNumerals[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	const std::set<int> allNumeralsSet(
		std::begin(allNumerals),
		std::end(allNumerals));

	allowedNumerals.clear();

	// Copy numeral if it cannot be found in forbiddenNumerals;
	std::copy_if(
		allNumeralsSet.begin(), allNumeralsSet.end(), allowedNumerals,
		[&](int n, auto forbiddenNumerals) {return forbiddenNumerals.std::find(n) == forbiddenNumerals.end()});

}
