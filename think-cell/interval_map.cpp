#include <map>
#include <iostream>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}
	const std::map<K, V> &get_map() { return this->m_map;}
	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		if (keyBegin < keyEnd) {
			auto end_val = this->m_valBegin;
			auto begin_val = this->m_valBegin;
			auto it = this->m_map.upper_bound(keyEnd);
			if (it != m_map.begin())
			{
				end_val = (--it)->second;
				if (!(keyBegin < it->first))
					begin_val = end_val;
			}
			while (it != m_map.begin() && keyBegin < it->first)
			{
				it = m_map.erase(it);
				--it;
			}
			if (it != m_map.end() && !(it->first < keyBegin) && !(keyEnd < it->first))
			{
				it = m_map.erase(it);
				if (it != m_map.begin()) {
					begin_val = (--it)->second;
					++it;
				}
				else
					begin_val = m_valBegin;
			}
			else if (it != m_map.end() && it->first < keyBegin)
			{
				begin_val = it->second;
				++it;
			}
			if (!(begin_val == val))
				this->m_map.insert_or_assign(it, keyBegin, val);
			if (!(val == end_val))
				this->m_map.insert_or_assign(it, keyEnd, end_val);
		}
		// if (keyBegin < keyEnd) {
		// 	auto it_l = this->m_map.lower_bound(keyBegin);
		// 	auto it_r = this->m_map.upper_bound(keyEnd);
		// 	auto end_val = (*this)[keyEnd];
		// 	auto hint_it = this->m_map.erase(it_l, it_r);
		// 	if ((*this)[keyBegin] != val)
		// 		this->m_map.emplace_hint(hint_it, keyBegin, val);
		// 	if ((*this)[keyEnd] != end_val)
		// 		this->m_map.emplace_hint(hint_it, keyEnd, end_val);
		// }
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

