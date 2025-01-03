#include <iostream>
#include <algorithm> // STL sort 함수 사용을 위해 algorithm라이브러리 필요
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;        // template를 사용해 변수생성
    int m_size;     // 크기
    int m_capacity; // 용량

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
        delete[] data; /*new나와서 delete시켜줘야함*/
    }
    // push_back은 vector에 맨뒤에 수를 추가하는거
    void push_back(const T& element) {
        if (m_size >= m_capacity) {
            resize(m_capacity + 5); // 배열 크기를 5 증가
        }
        data[m_size++] = element;
    }
    // pop_back은 맨뒤에있는 수를 빼는거
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
    // 잘모르겠음 resize
    void resize(int new_capacity) {
        if (new_capacity <= m_capacity) {
            return;
        } /*해석필요*/

        T* new_data = new T[new_capacity];
        for (int i = 0; i < m_size; i++) {
            new_data[i] = data[i];
        }
        /*new나와서 delete시켜줘야함 메모리누수발생때문에*/
        delete[] data;
        data = new_data;
        m_capacity = new_capacity;
    }

    void sortData() {
        sort(data, data + m_size);
    } // ? 정렬한데

    // 디버깅용 데이터 출력
    void print() const {
        for (int i = 0; i < m_size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SimpleVector<int> vec;

    // 데이터 추가
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

    cout << "Vector안에 수들: ";
    vec.print();

    vec.sortData();
    cout << "정렬하기 : ";
    vec.print();

    // 데이터 크기 및 용량 확인
    cout << "입력된 수의 크기: " << vec.size() << ", 수가 들어올 수 있는 용량: " << vec.capacity() << endl;

    // 원소 제거
    vec.pop_back();
    cout << "정렬하고 가장 뒤에있는 수를 제거 :";
    vec.print();

    vec.resize(20);
    cout << "용량을 " << vec.capacity() << "으로 변경";

    return 0;
}
