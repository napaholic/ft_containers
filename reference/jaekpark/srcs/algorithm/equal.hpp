#ifndef _FT_EQUAL_HPP
#define _FT_EQUAL_HPP

#include "../config.hpp"

_BEGIN_NAMESPACE_FT

template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
  for (; first1 != last1; ++first1, ++first2) {
    if (!(*first1 == *first2)) {
      return false;
    }
  }
  return true;
}
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
           BinaryPredicate pred) {
  for (; first1 != last1; ++first1, ++first2) {
    if (!pred(*first1, *first2)) {
      return false;
    }
  }
  return true;
}

_END_NAMESPACE_FT

#endif