#ifndef UTILITIES_H
#define UTILITIES_H

#include <random> // C++11

class Utilities
{
public:
	template <typename M, typename V>
	static void MapToVector(const M& m, V& v);

	template <typename V1, typename V2>
	static void MergeVectors(const V1& from, V2& to);

	template<typename Vec>
	static void EraseElementFromVector(int i, Vec& vector);

	static double GetRandomNumber(double min, double max);
	static int GetRandomNumber(int min, int max);

private:
	Utilities() {};
	Utilities(const Utilities&) {};
};

template<typename M, typename V>
inline void Utilities::MapToVector(const M & m, V & v)
{
	for (auto it = m.begin(); it != m.end(); ++it)
		v.push_back(it->second);
}

template<typename V1, typename V2>
inline void Utilities::MergeVectors(const V1 & from, V2 & to)
{
	to.reserve(to.size() + from.size());
	to.insert(to.end(), from.begin(), from.end());
}

template<typename Vec>
inline void Utilities::EraseElementFromVector(int i, Vec & vector)
{
	auto itr = vector.begin();
	for (int j = 0; j < i; j++)
		itr++;
	vector.erase(itr);
}

#endif // !UTILITIES_H