#pragma once


template <typename type1, typename type2> const std::unordered_map<type1, type2> traverse_unordered_map(const std::unordered_map<type2, type1>& src)
{
	std::unordered_map<type1, type2> dest;
	for (typename std::unordered_map<type2, type1>::const_iterator i = src.begin(); i != src.end(); i++)
	{
		dest.insert({ i->second, i->first });
	}
	return(dest);
}

template <typename type1, typename type2> std::unordered_map<type1, type2> traverse_unordered_map(std::unordered_map<type2, type1>& src)
{
	std::unordered_map<type1, type2> dest;
	for (typename std::unordered_map<type2, type1>::const_iterator i = src.begin(); i != src.end(); i++)
	{
		dest.insert({ i->second, i->first });
	}
	return(dest);
}