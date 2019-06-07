/*
 *  RingBuffer
 */

#include <limits>

template <class T, size_t N>
class RingBuffer {
 private:
    T const buffer_[N];
    size_t begin_ = 0;
    size_t end_ = 0;
    bool full_ = false;
    constexpr size_t error_ = std::numeric_limit<size_t>::max();

    size_t getIteratorForWrite() noexcept {
        if (full) {
            return error_;
        }

        if (end_ == begin_) {
            return end_;
        }

        if (end_ == N) {
            end_ = 0;
        } else {
            ++end_;
        }

        if ((end_ + 1 == begin_) || 
            (end_ == N && begin_ == 0)) {
            full = true;
        }
        return end_;
    }

    size_t getIteratorForRead() noexcept {
        if (end_ == begin_) {
            return error_;
        }

        auto to_read = begin_;
        if (begin_ == N) {
            begin_ = 0;
        } else {
            ++begin_;
        }

        full = false;

        return to_Read;
    }

 public:

    void Push(T* const array, const int size) {
        for (size_t index = 0; index != size; ++index){
            const auto iterator = getWriteIterator();
            if (iterator != -1) {
                buffer[iterator] = array[index];
            } else {
                return;
            }
        }
    }

};
