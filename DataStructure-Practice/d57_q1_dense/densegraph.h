#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        // Your code here
        for(int i=0;i<3;i++) mData.push_back({});
    }

    DenseGraph(int n_in) {
        // Your code here
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
    }

    void AddEdge(int a, int b) {
        // Your code here
    }

    void RemoveEdge(int a, int b) {
        // Your code here
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
    }

    DenseGraph Transpose() const {
        // Your code here
    }

protected:
    int n;
    // Your code here
    std::vector<std::vector<size_t>> mData; 
};
#endif // __DENSE_GRAPH_H__
