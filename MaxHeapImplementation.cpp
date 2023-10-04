#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    vector<int> nodes;
    int capacity;
    int size;

    // These 3 will return the indexes, not the elements
    int getLeftCh(int index)
    {
        return (2 * index) + 1;
    }

    int getRightCh(int index)
    {
        return (2 * index) + 2;
    }

    int getParent(int index)
    {
        return (index - 1) / 2;
    }
    //

    void heapify(int index)
    {
        int cur = nodes[index];
        int li = getLeftCh(index);
        int ri = getRightCh(index);

        int temp = index;
        if (li < size && nodes[li] > cur)
            temp = li;
        if (ri < size && nodes[ri] > cur)
            temp = ri;
        if (temp != index)
        {
            swap(nodes[index], nodes[temp]);
            heapify(temp);
        }
    }

public:
    MaxHeap(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        nodes.resize(capacity);
    }

    int top()
    {
        if (size == 0)
        {
            cout << "Heap is Empty!";
            return -1;
        }
        else
            return nodes[0];
    }

    void push(int ele)
    {
        if (size == capacity)
        {
            cout << "Heap is Full!";
            return;
        }

        if (size == 0)
        {
            nodes[0] = ele;
            size++;
            return;
        }

        nodes[size] = ele;
        int index = size;
        size++;

        while (index > 0 && nodes[getParent(index)] < nodes[index])
        {
            swap(nodes[index], nodes[getParent(index)]);
            index = getParent(index);
        }
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "No Element exists in heap!";
            return;
        }

        int maxi = nodes[0];
        nodes[0] = nodes[size - 1];
        size--;

        heapify(0);
    }
};

int main()
{
    MaxHeap mx(30);
    mx.push(20);
    mx.push(28);
    mx.push(23);
    mx.push(10);
    mx.push(12);
    mx.pop();
    mx.pop();
    mx.pop();
    mx.pop();

    cout << mx.top();
    return 0;
}