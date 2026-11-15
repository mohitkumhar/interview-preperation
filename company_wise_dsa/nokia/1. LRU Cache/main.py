"""
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.

"""

# Brute Force


class LRUCache:

    def __init__(self, capacity: int):
        self.n = capacity
        self.cache = []

    def get(self, key: int) -> int:
        for i in range(len(self.cache)):
            value = self.cache[i]
            if value[0] == key:
                self.cache.pop(i)
                self.cache.append((key, value[1]))

                return value[1]
        return -1

    def put(self, key: int, value: int) -> None:
        for i in range(len(self.cache)):
            node = self.cache[i]

            if node[0] == key:
                self.cache.pop(i)
                self.cache.append((key, value))

                return

        if self.n == len(self.cache):
            self.cache.pop(0)
            self.cache.append((key, value))
        else:
            self.cache.append((key, value))


# Optimal [Expected] - Using Doubly LinkedList


class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.head = None
        self.tail = None


class LRUCache:

    def __init__(self, capacity: int):
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.n = capacity
        self.cache = {}

    def get(self, key: int) -> int:
        if key in self.cache:
            val = self.cache[key]
            self.cache.pop(key)
            self.cache[key] = val

            return val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.pop(key)
            self.cache[key] = value
            return

        if len(self.cache) == self.n:
            self.cache.pop(next(iter(self.cache)))
            self.cache[key] = value
        else:
            self.cache[key] = value
