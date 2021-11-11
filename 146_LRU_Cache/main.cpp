#include "header.h"
#include "revisit2.h"

int main(char* args[], int argc)
{
    //[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

    int value = -1;

    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    value = obj->get(1);
    obj->put(3, 3);
    obj->put(4, 4);
    value = obj->get(1);
    value = obj->get(3);
    value = obj->get(4);

    return 0;
}