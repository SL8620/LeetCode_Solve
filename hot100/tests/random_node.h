#ifndef TESTS_RANDOM_NODE_H
#define TESTS_RANDOM_NODE_H
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};
#endif
