#pragma once

#include <cstddef>   // std::size_t
#include <stdexcept> // std::invalid_argument
#include <vector>    // std::vector
#include <utility>   // std::move

namespace kvstore {

template <typename Key, typename Value>
class Node final {
public:
    Node(Key key, Value value, std::size_t height) 
        : key_(std::move(key)), value_(std::move(value)), next_nodes_(height, nullptr) {
        if (height == 0) {
            throw std::invalid_argument("Height must be greater than 0");
        }
    }


    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

    const Key& key() const noexcept {
        return key_;
    }


    Value& value() noexcept {
        return value_;
    }

    const Value& value() const noexcept {
        return value_;
    }

    std::size_t height() const noexcept {
        return next_nodes_.size();
    }

    Node* next(std::size_t level) const {
        return next_nodes_[level];
    }

    void set_next(std::size_t level, Node* node) {
        next_nodes_[level] = node;
    }

private:
    // 由你设计
    
    Key key_;
    Value value_;
    std::vector<Node*> next_nodes_;
};

}  // namespace kvstore