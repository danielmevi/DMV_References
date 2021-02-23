/*
 *
 */
#include <array>
#include <cstddef>
#include <iostream>
#include <memory>

template <typename T, std::size_t _size = 127>
class RingBuffer {
 public:
    bool push(const T new_value) {
        const auto tmp_end = end + 1 == _size ? 0 : end + 1;
        if (not _buffer[tmp_end]) {
            _buffer[end] = std::make_unique<T>(new_value);
            return ++end, true;
        } else {
            return false;
        }
    }

    T pop() {
        const auto tmp_begin = begin + 1 == _size ? 0 : begin + 1;
        if (_buffer[tmp_begin]) {
            auto* tmp = _buffer[++begin]->release;
            return *tmp;
        } else {
            return T(0);
        }
    }

 private:
    std::array<std::unique_ptr<T>, _size> _buffer;
    size_t begin = 0;
    size_t end = 0;
};

int main(const int, const char* const[]) {
    RingBuffer<int, 2> RB;
    std::cout << RB.push(1) << ' ' << RB.push(2) << ' ' << RB.push(3) << '\n';

    return 1;
}
