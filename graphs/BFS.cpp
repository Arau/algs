#include <map>

using namespace std;

int numJumps(Node* init, Node* toFound) {
    map<Node*, bool> visited;
    Queue q<Node*>;
    init.numHops = 0;
    q.enqueue(init);
    while (!Q.isEmpty()) {
        Node* n = Q.dequeue();
        int numHops = n->numHops();
        if (n == toFound) { return numHops; }
        if ( visited[ n ] == visided.end() )  {
            visited[ n ] = true;
            if (n == toFound) { return numHops(); }
            for (int i = 0; i < n->numEdges(); ++i) {
                n->edge[i].setHops(numHops++);
                q.enqueue(n->edge[i]);
            }
        }
    }
}

