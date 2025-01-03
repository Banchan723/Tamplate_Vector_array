#include <iostream>
#include <algorithm> // STL sort �Լ� ����� ���� algorithm���̺귯�� �ʿ�
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;        // template�� ����� ��������
    int m_size;     // ũ��
    int m_capacity; // �뷮

public:
    SimpleVector(int capacity = 10) : m_size(0), m_capacity(capacity) {
        data = new T[m_capacity];
    }

    SimpleVector(const SimpleVector& other)
        : m_size(other.m_size), m_capacity(other.m_capacity) {
        data = new T[m_capacity];
        for (int i = 0; i < m_size; i++) {
            data[i] = other.data[i];
        }
    }
    ~SimpleVector() {
        delete[] data; /*new���ͼ� delete���������*/
    }
    // push_back�� vector�� �ǵڿ� ���� �߰��ϴ°�
    void push_back(const T& element) {
        if (m_size >= m_capacity) {
            resize(m_capacity + 5); // �迭 ũ�⸦ 5 ����
        }
        data[m_size++] = element;
    }
    // pop_back�� �ǵڿ��ִ� ���� ���°�
    void pop_back() {
        if (m_size > 0) {
            m_size--;
        }
    }

    int size() const {
        return m_size;
    }
    int capacity() const {
        return m_capacity;
    }
    // �߸𸣰��� resize
    void resize(int new_capacity) {
        if (new_capacity <= m_capacity) {
            return;
        } /*�ؼ��ʿ�*/

        T* new_data = new T[new_capacity];
        for (int i = 0; i < m_size; i++) {
            new_data[i] = data[i];
        }
        /*new���ͼ� delete��������� �޸𸮴����߻�������*/
        delete[] data;
        data = new_data;
        m_capacity = new_capacity;
    }

    void sortData() {
        sort(data, data + m_size);
    } // ? �����ѵ�

    // ������ ������ ���
    void print() const {
        for (int i = 0; i < m_size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SimpleVector<int> vec;

    // ������ �߰�
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(1);
    vec.push_back(2);

    cout << "Vector�ȿ� ����: ";
    vec.print();

    vec.sortData();
    cout << "�����ϱ� : ";
    vec.print();

    // ������ ũ�� �� �뷮 Ȯ��
    cout << "�Էµ� ���� ũ��: " << vec.size() << ", ���� ���� �� �ִ� �뷮: " << vec.capacity() << endl;

    // ���� ����
    vec.pop_back();
    cout << "�����ϰ� ���� �ڿ��ִ� ���� ���� :";
    vec.print();

    vec.resize(20);
    cout << "�뷮�� " << vec.capacity() << "���� ����";

    return 0;
}
