#include <iostream>
#include <memory>

auto allocated = size_t{0};
// Overload operator new and delete to track allocations 
void* operator new(size_t size) {
  void* p = std::malloc(size);
  allocated += size;
  return p;
}
void operator delete(void* p) noexcept {
  return std::free(p);
}
int main() {
  allocated = 0;
  auto s = std::string{""}; // Elaborate with different string sizes
  std::cout << "stack space = " << sizeof(s)
    << ", heap space = " << allocated
    << ", capacity = " << s.capacity() << '\n';
}