#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);

template <typename T>
class MinHeap {
private:
    vector<T> array;  
    int size;         
    int capacity;     

public:
    // Constructor to set the heap's initial capacity
    MinHeap(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->array.resize(capacity);
    }
    
    // Function to restore heap order at index i
    void heapify(int i) {
        // Initialize smallest as root
        int smallest = i;    
        //  Find the Left child index
        int left = 2 * i + 1;    
         // Find the Right child index
        int right = 2 * i + 2;   
        
        // If left child is smaller than root
        if (left < size && array[left] < array[smallest])
            smallest = left;

        // If right child is smaller than the smallest so far
        if (right < size && array[right] < array[smallest])
            smallest = right;

        // If smallest is not root
        if (smallest != i) {
            swap(array[i], array[smallest]);  
            heapify(smallest);                
        }
    }

    // Function to create a min heap from a given array
    void buildHeap(const vector<T>& arr) {
        capacity = arr.size();
        size = capacity;
        array = arr;
        
        // Heapify the (n-1)/2 nodes
        for (int i = (size - 1) / 2; i >= 0; i--) {
            heapify(i);
        }
    }

    // Function to insert a new node into the min heap
    void insertNode(T value) {
        if (size == capacity) {
            // Resize the heap if necessary
            capacity *= 2;
            array.resize(capacity);
        }

        size++;
        int i = size - 1;
        array[i] = value;

        while (i != 0 && array[(i - 1) / 2] > array[i]) {
            swap(array[i], array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Function to get the topmost value from the min heap
    T peek() {
        if (size <= 0)
            return -1;  // Indicates that the heap is empty

        return array[0];
    }

    // Function to remove and return the minimum value from the heap
    T extractMin() {
        if (size <= 0)
            return -1;  // Indicates that the heap is empty
        if (size == 1) {
            size--;
            return array[0];
        }

        // Store the minimum value, and remove it
        T root = array[0];
        array[0] = array[size - 1];
        size--;
        // Heapify the root node after deletion
        heapify(0);  
        return root;
    }

    // Function to delete a specific node from the heap
    void DeleteNode(T key) {
        // Find the index of the key
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (array[i] == key) {
                index = i;
                break;
            }
        }
        // If key is not found, return
        if (index == -1) {
            cout << "Key not found" << endl;
            return;
        }

        if (index == size - 1) {
            size--;
            return;
        }

        // Move the last element to the index of the key to be deleted
        array[index] = array[size - 1];
        size--;

        // Heapify down to heapify the rest of the min heap
        heapify(index);
    }

    // Function to print the values of  the  min heap
    void printHeap() const {
        for (int i = 0; i < size; ++i)
            cout << array[i] << " ";
        cout << endl;
    }
};



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);


    int n,m,k;
    int r=0;

    cin >> n >> m >> k;

    vector <int> lista1(n);
    vector <int> lista2(m);
    vector <int> lista3(k);

    
    for(int i=0;i<n;i++){
        cin >> lista1[i];
    }

    for(int i=0;i<m;i++){
        cin >> lista2[i];
    }

    for(int i=0;i<k;i++){
        cin >> lista3[i];
    }

    
    MinHeap<int> minheap1(n);
    minheap1.buildHeap(lista1); // O(n)

    MinHeap<int> minheap2(m);
    minheap2.buildHeap(lista2); // O(n)

    MinHeap<int> minheap3(k);
    minheap3.buildHeap(lista3); // O(n)

    
    while(true){
        if (minheap1.peek()==-1){
            break;
        }else{
            if (minheap1.peek()>minheap2.peek() && minheap2.peek()!=-1){
                minheap1.extractMin();
                minheap2.extractMin();
                r++;
            } else if (minheap1.peek()*sqrt(2) > (minheap3.peek()) && minheap3.peek()!=-1){
                minheap1.extractMin();
                minheap3.extractMin();
                r++;
            }
            else{
                minheap1.extractMin();
            }
        }
    }

    cout << r << endl;
    return 0;
}

