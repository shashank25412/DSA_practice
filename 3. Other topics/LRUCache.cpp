#include <bits/stdc++.h>
using namespace std;

/*
    LRU (Least Recently Used) Cache
    ---------------------------------
    To implement LRU cache, we can use a doubly linked list and an unordered_map. The unordered_map will store the
    key and the pointer to the corresponding node in the linked list. The linked list will maintain the order of
    usage, with the most recently used node at the head and the least recently used node at the tail.

    Basic operations:
    ------------------
    1. get(key): If the key exists in the cache, return its value and move the corresponding node to the head of the linked list. 
                 If the key does not exist, return -1.

    2. put(key, value): If the key already exists in the cache, update its value and move the corresponding node to the head of
                        the linked list. If the key does not exist, add a new node to the head of the linked list. If the cache is full,
                        remove the least recently used node from the tail of the linked list.

    Time Complexity:
    ------------------
    Both get and put operations have a time complexity of O(1) due to the use of the unordered_map for constant time access and the
    linked list for constant time insertion and deletion.
*/

class Node{
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int key, int value){
        this->key = key;
        this->value = value; 
        prev = next = NULL;
    }
};

class LRUCache{
public:
    int capacity;
    unordered_map<int, Node*> m = {};

    Node* _head = new Node(-1, -1);
    Node* _tail = new Node(-1, -1);

    LRUCache(int capacity){
        this->capacity = capacity;
        _head->next = _tail;
        _tail->prev = _head;
    }

    void addNode(Node* nodeToAdd){
        Node* tmpNode = _head->next;
        _head->next = nodeToAdd;
        nodeToAdd->prev = _head;

        nodeToAdd->next = tmpNode;
        tmpNode->prev = nodeToAdd;
    }

    void deleteNode(Node* nodeToDelete){
        Node* oldPrevNode = nodeToDelete->prev;
        Node* oldNextNode = nodeToDelete->next;

        oldPrevNode->next = oldNextNode;
        oldNextNode->prev = oldPrevNode;
    }

    int get(int key){
        auto it = m.find(key);
        if(it == m.end()){
            return -1;
        }

        Node* ansNode = it->second;

        m.erase(key);
        deleteNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ansNode->value;
    }

    void put(int key, int value){
        // if key already existed in the map, remove the node.
        if(m.find(key) != m.end()){
            Node* tmpNode = m[key];
            deleteNode(tmpNode);
            m.erase(key);
            delete tmpNode;
        }

        // if cache is already full
        if(m.size() == capacity){
            Node* tmpNode = _tail->prev;
            deleteNode(tmpNode);
            m.erase(tmpNode->key);
            delete tmpNode;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};


int main(){

    LRUCache* _cache = new LRUCache(3);
    _cache->put(1, 1);
    _cache->put(2, 2);
    _cache->put(3, 3);
    cout << _cache->get(1) << endl; // returns 1
    _cache->put(4, 4); // evicts key 2
    cout << _cache->get(2) << endl; // returns -1 (not found)
    _cache->put(5, 5); // evicts key 3
    cout << _cache->get(3) << endl; // returns -1 (not found)
    cout << _cache->get(4) << endl; // returns 4
    cout << _cache->get(5) << endl; // returns 5

    return 0;
}