#include "header.h"
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) :
        m_capacity(capacity)
    {

    }

    int get(int key)
    {
        int value = -1;
        if (m_accelerator.find(key) != m_accelerator.end())
        {
            value = m_accelerator[key]->value;
            m_nodes.erase(m_accelerator[key]);
            m_nodes.emplace_front(key, value);
            m_accelerator[key] = m_nodes.begin();
        }
        return value;
    }

    void put(int key, int value)
    {
        if (m_accelerator.find(key) != m_accelerator.end())
        {
            m_nodes.erase(m_accelerator[key]);
            m_nodes.emplace_front(key, value);
            m_accelerator[key] = m_nodes.begin();
        }
        else
        {
            if (m_capacity == m_nodes.size())
            {
                m_accelerator.erase(m_nodes.back().key);
                m_nodes.pop_back();
            }
            m_nodes.emplace_front(key, value);
            m_accelerator[key] = m_nodes.begin();
        }
    }

private:
    struct LURNode
    {
        int key;
        int value;

        LURNode(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
    };
    int m_capacity;
    std::list<LURNode> m_nodes;
    std::unordered_map<int, std::list<LURNode>::iterator> m_accelerator;
};