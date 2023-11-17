#include <iostream>
#include <memory>
#include <list>
#include <utility>
#include <array>

#define BLOCK_SIZE 1024

using std::array;

namespace My_Allocator {
    template <class T>
    class Allocator {
    private:
        array<T, BLOCK_SIZE> _used_blocks;
        array<T*, BLOCK_SIZE> _free_blocks;
        size_t _free_count;

    public:
        static constexpr size_t max_count = BLOCK_SIZE;
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;

        Allocator() {
            // _used_blocks = (char *)malloc(sizeof(T) * max_count);
            // _free_blocks = (void **)malloc(sizeof(void *) * max_count);

            for (size_t i = 0; i < max_count; i++) {
                _free_blocks[i] = &_used_blocks[i];
            }
            _free_count = max_count;
#ifdef DEBUG
            std::cout << "allocator: memory init" << std::endl;
#endif
        }

        ~Allocator() {
#ifdef DEBUG
            if (_free_count < max_count)
                std::cout << "allocator: Memory leak?" << std::endl;
            else
                std::cout << "allocator: Memory freed" << std::endl;
#endif

            // delete _free_blocks;
            // delete _used_blocks; 

            // _free_blocks = nullptr;
            // _used_blocks = nullptr;
        }

        template <class U>
        struct rebind {
            using other = Allocator<U>;
        };

        // мы не используем параметр n - поэтому с std::vector данный аллокатор работать не будет
        T *allocate(size_t n) {
            T *result = nullptr;
            if (_free_count > 0) {
                result = (T *)_free_blocks[--_free_count];
#ifdef DEBUG
                std::cout << "allocator: Allocate " << (max_count - _free_count) << " of " << max_count << " Address:" << result << std::endl;
#endif
            }
            else {
                std::cout << "allocator: No memory exception :-)" << std::endl;
            }
            return result;
        }

        void deallocate(T *pointer, size_t) {
#ifdef DEBUG
            std::cout << "allocator: Deallocate block " << std::endl;
#endif
            _free_blocks[_free_count++] = pointer;
        }
        template <typename U, typename... Args>
        void construct(U *p, Args &&...args) {
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p) {
            p->~T();
        }
    };

    template <class T, class U>
    constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs) {
        return true;
    }

    template <typename T, typename U, size_t BLOCK_COUNT>
    constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs) {
        return false;
    }
}

