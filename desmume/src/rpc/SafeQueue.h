#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <class T>
class SafeQueue {
public:
    SafeQueue()
        : q() {
    }

    ~SafeQueue() {
    }
    
    void Enqueue(T t) {
        std::lock_guard<std::mutex> lock(m);
        q.push(t);
        c.notify_one();
    }

    T Dequeue() {
        std::unique_lock<std::mutex> lock(m);
        if (q.empty()) {
            return T();
        }
        T val = q.front();
        q.pop();
        return val;
    }

private:
    std::queue<T> q;
    mutable std::mutex m;
    std::condition_variable c;
};
#endif
