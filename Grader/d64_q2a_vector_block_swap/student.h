#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if (a > b) std::swap(a, b);                      // no need for T* temp
  if (m == 0) return false;
  if (a < begin() || b >= end()) return false;     // a <= b, so this covers both
  if (m > (size_t)(end() - b)) return false;       // b's block fits
  if (m > (size_t)(b - a)) return false;           // no overlap
  for (size_t i = 0; i < m; i++) std::swap(*(a + i), *(b + i));
  return true;
}

#endif
