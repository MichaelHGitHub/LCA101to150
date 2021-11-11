#include "header.h"
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) :
        m_capacity(capacity)
    {

    }

    int get(int key)
    {
        int value = -1;
        for (std::list<LURNode>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++)
        {
            if (it->key == key)
            {
                value = it->value;
                LURNode node = *it;
                m_nodes.erase(it);
                m_nodes.emplace_back(node);
                break;
            }
        }
        return value;
    }

    void put(int key, int value)
    {
        bool added = false;
        for (std::list<LURNode>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++)
        {
            if (it->key == key)
            {
                it->value = value;
                LURNode node = *it;
                m_nodes.erase(it);
                m_nodes.emplace_back(node);
                added = true;
                break;
            }
        }

        if (!added)
        {
            if (m_capacity == m_nodes.size())
            {
                m_nodes.erase(m_nodes.begin());
            }
            m_nodes.emplace_back(LURNode(key, value));
        }
    }

private:
    struct LURNode
    {
        int key;
        int value;

        LURNode()
        {
        }

        LURNode(int key, int value)
        {
            this->key = key;
            this->value = value;
        }

        LURNode(const LURNode& node)
        {
            this->key = node.key;
            this->value = node.value;
        }
    };
    std::list<LURNode> m_nodes;
    int m_capacity;
};