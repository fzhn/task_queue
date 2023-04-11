#include <functional>
#include <iostream>
#include <stdexcept>
#include <array>

extern "C" {
  #include "task_queue.h"
}

template<typename T, uint64_t SIZE>
class TaskQueue {
private:
    static constexpr unsigned getMsbPos(unsigned n) {
        unsigned p = 0;
        while (n >>= 1) {p++;}
        return p;
    }
    static constexpr uint64_t sizePowerOf2() {
        return 1UL << (uint64_t) getMsbPos(SIZE);
    }
    static constexpr uint64_t mSize = sizePowerOf2();
    static constexpr uint64_t mWrapMask = mSize - 1;
    static const T mEmpty;

    std::array<T, mSize> mQueue;
    std::atomic_uint64_t mReadPtr = 0;
    std::atomic_uint64_t mWritePtr = 0;

     uint64_t getSize() const {
        return mWritePtr.load() - mReadPtr.load();
    }

public:
    T pop() {
        if (!getSize()) {
            return mEmpty;
        }

        T task = std::move(mQueue[mReadPtr & mWrapMask]);
        mReadPtr++;
        return std::move(task);
    }

    void push(T task) {
        if (getSize() >= mSize) {
            throw std::runtime_error("Task queue is full. This should not happen.");
        }

        mQueue[mWritePtr & mWrapMask] = std::move(task);
        mWritePtr++;
    }

    bool isLockFree(){
        //std::cout << "Using atomic_uint64_t is lock free: " << mReadPtr.is_lock_free() << std::endl;
        return mReadPtr.is_lock_free();
    }

};
template<typename T, uint64_t SIZE> const T TaskQueue<T, SIZE>::mEmpty = T{ };

struct task_queue{
    TaskQueue<queue_data, QUEUE_SIZE> queue;
};

void push_task(struct task_queue** q, struct queue_data& data){
    (*q)->queue.push(data);
}
struct queue_data pop_task(struct task_queue** q){
    return (*q)->queue.pop();
}
