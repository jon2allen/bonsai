#include <iostream>
using namespace std;

class FenwickTree {
private:
    int* tree;
    int size;

public:
    FenwickTree(int size) {
        this->size = size;
        tree = new int[size + 1];
        for (int i = 0; i <= size; i++) {
            tree[i] = 0;
        }
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }

    void deleteElement(int index) {
        update(index, -1);
    }

    void printTree() {
        for (int i = 1; i <= size; i++)
            cout << tree[i] << " ";
        cout << endl;
    }
};

int main() {
    int size = 10;
    FenwickTree ft(size);

    ft.update(1, 1);
    ft.update(2, 2);
    ft.update(3, 3);
    ft.update(4, 4);
    ft.update(5, 5);
    ft.update(6, 6);
    ft.update(7, 7);
    ft.update(8, 8);
    ft.update(9, 9);
    ft.update(10, 10);

    cout << "Initial tree: ";
    ft.printTree();

    ft.deleteElement(5);
    cout << "After deleting element 5: ";
    ft.printTree();

    cout << "Sum from 1 to 5: " << ft.rangeQuery(1, 5) << endl;
    cout << "Sum from 6 to 10: " << ft.rangeQuery(6, 10) << endl;

    return 0;
}
