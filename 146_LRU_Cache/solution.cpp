#include <map>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) :
        m_capacity(capacity)
    {
    }

    int get(int key) {
        if (elements.find(key) == elements.end())
        {
            return -1;
        }

        if (nodes.find(key) != nodes.end())
        {
            visited_keys.erase(nodes[key]);
        }
        nodes[key] = visited_keys.insert(visited_keys.end(), key);
        return elements[key];
    }

    void put(int key, int value) {

        if (elements.size() < m_capacity)
        {
            if (nodes.find(key) != nodes.end())
            {
                visited_keys.erase(nodes[key]);
            }
            nodes[key] = visited_keys.insert(visited_keys.end(), key);
        }
        else
        {
            if (nodes.find(key) != nodes.end())
            {
                visited_keys.erase(nodes[key]);
            }
            else
            {
                int key_to_del = *(visited_keys.begin());
                visited_keys.pop_front();
                nodes.erase(key_to_del);
                elements.erase(key_to_del);
            }
            nodes[key] = visited_keys.insert(visited_keys.end(), key);
        }

        elements[key] = value;
    }

    int m_capacity;
    map<int, int> elements;
    map<int, list<int>::iterator> nodes;
    list<int> visited_keys;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */