#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <vector>

using namespace std;
class Node {
    friend class Tree;

    protected:
        int data;
        vector<Node*> children;

    public:
        // Constructor
        Node(void);
        Node(int);
        Node (const vector<Node*>&);
        Node(int,const vector<Node*>&);

        // Operators
        bool operator!= (Node* n) {
            return (this->data != n->data);
        }
        bool operator== (Node* n) {
            return (this->data == n->data);
        }

        // Getters
        int getData(void)
        { return data; }

        const vector<Node*>& getChildren(void)
        { return children; }

        // Setters
        void setData(int val)
        { data = val; }

        void setChildren(const vector<Node*>& nodes)
        { children = nodes; }

        void addChild(Node*,int);

        bool isLeave(void);
};

#endif
