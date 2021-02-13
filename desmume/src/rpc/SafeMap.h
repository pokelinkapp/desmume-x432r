#ifndef SAFE_MAP_H
#define SAFE_MAP_H

#include <mutex>
#include <condition_variable>
#include <map>

template<class Key, class Value>
class ThreadSafeMap {
    std::mutex m_;
    std::map<Key, Value> c_;

public:
    Value Get(Key const& k) {
        std::unique_lock<decltype(m_)> lock(m_);
        return c_[k]; // Return a copy.
    }

    void Remove(Key const& k) {
        std::unique_lock<decltype(m_)> lock(m_);

        if (c_.find(k) != c_.end()) {
            c_.erase(k);
        } 
    }

    bool Contains(Key const& k) {
        std::unique_lock<decltype(m_)> lock(m_);

        return c_.find(k) != c_.end();
    }
    
    void Set(Key const& k, Value& v) {
        std::unique_lock<decltype(m_)> lock(m_);
        c_[k] = std::forward<Value>(v);
    }
};

#endif