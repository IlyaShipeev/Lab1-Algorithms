//#include <iostream>
//using namespace std;
//template<typename T>
//class List {
//private:
//    T* data;       // ��������� �� ������������ ������
//    size_t size;   // ���������� ��������� � ������
//    size_t capacity; // ����������� �������
//    void expand();
//public:
//    List();
//    List(const T& t);
//    List(const List& other);
//    ~List();
//
//    size_t return_size();
//    void ClearList();
//    bool is_empty();
//    void is_it_here(const T& value);
//    T findByIndex(size_t index);
//    void changeByIndex(size_t index, const T& value);
//    size_t findByNumber(const T& value);
//    void add(const T& value);
//    void addByIndex(size_t index, const T& value);
//    void delByNumber(const T& value);
//    void delById(size_t index);
//
//    T* find_begin();
//    T* find_rbegin();
//    T* find_end();
//    T* find_rend();
//
//    void printList();
//    class Iterator {
//    private:
//        T* ptr;  // ��������� �� ������� �������
//    public:
//        Iterator(T* p) : ptr(p) {}
//
//        // ������ � �������� (�������������)
//        T& operator*() { return *ptr; }
//
//        // ��������� ++ (������� � ���������� ��������)
//        Iterator& operator++() {
//            ++ptr;
//            return *this;
//        }
//
//        // ��������� -- (������� � ����������� ��������)
//        Iterator& operator--() {
//            --ptr;
//            return *this;
//        }
//
//        // �������� �� ���������
//        bool operator==(const Iterator& other) const {
//            return ptr == other.ptr;
//        }
//
//        // �������� �� �����������
//        bool operator!=(const Iterator& other) const {
//            return ptr != other.ptr;
//        }
//    };
//
//    // ������ ��� ��������� ����������
//    Iterator begin() { return Iterator(data); }
//    Iterator end() { return Iterator(data + size); }
//    class ReverseIterator {
//    private:
//        T* ptr;
//    public:
//        ReverseIterator(T* p) : ptr(p) {}
//
//        // ������ � ��������
//        T& operator*() { return *ptr; }
//
//        // ��������� ++ (�� � �������� �����������)
//        ReverseIterator& operator++() {
//            --ptr;
//            return *this;
//        }
//
//        // ��������� -- (�� � �������� �����������)
//        ReverseIterator& operator--() {
//            ++ptr;
//            return *this;
//        }
//
//        // �������� ���������
//        bool operator==(const ReverseIterator& other) const {
//            return ptr == other.ptr;
//        }
//
//        // �������� �����������
//        bool operator!=(const ReverseIterator& other) const {
//            return ptr != other.ptr;
//        }
//    };
//
//    // ������ ��� ��������� �������� ����������
//    ReverseIterator rbegin() { return ReverseIterator(data + size - 1); }
//    ReverseIterator rend() { return ReverseIterator(data - 1); }
//};
//
//template<typename T>
//List<T>::List() : data(nullptr), size(0), capacity(5) {
//    data = new T[capacity]; // ��������� ������� 5
//}
//
//template<typename T>
//List<T>::List(const T& t) : size(1), capacity(5) {
//    data = new T[capacity];
//    data[0] = t;
//}
//
//template<typename T>
//List<T>::List(const List& other) : size(other.size), capacity(other.capacity) {
//    data = new T[capacity];
//    for (size_t i = 0; i < size; i++) {
//        data[i] = other.data[i];
//    }
//}
//
//template<typename T>
//List<T>::~List() {
//    delete[] data;
//}
//
//template<typename T>
//size_t List<T>::return_size() {
//    return size;
//}
//
//template<typename T>
//void List<T>::add(const T& value) {
//    if (size == capacity) {
//        expand();
//    }
//    data[size] = value;
//    size++;
//}
//
//template<typename T>
//void List<T>::expand() {
//    size_t n0 = 5;
//    capacity += n0;
//    T* newData = new T[capacity];
//    for (size_t i = 0; i < size; i++) {
//        newData[i] = data[i];
//    }
//    delete[] data;
//    data = newData;
//}
//template<typename T>
//void List<T>::ClearList() {
//    size_t n0 = 5;
//    T* newData = new T[n0];
//    delete[] data;
//    data = newData; //cam delall
//}
//template<typename T>
//bool List<T>::is_empty() {
//    if (size == 0) {
//        cout << "������ ������.\n";
//        return true;
//    }
//    else {
//        cout << "������ �� ������.\n";
//        return false;
//    }
//}
//
//template<typename T>
//void List<T>::is_it_here(const T& value) {
//    for (size_t i = 0; i < size; i++) {
//        if (data[i] == value) {
//            cout << "��� ������� ������\n";
//        }
//    }
//    cout << "����� ������� � ������ �����������\n";
//}
//template<typename T>
//T findByIndex(size_t index) {
//    if (index >= size) {
//        cout << "������ ������� �� ������� ������!\n";
//        return;
//    }
//    else return data[index];
//
//}
//template<typename T>
//void changeByIndex(size_t index, const T& value)
//{
//    if (index >= size) { // ������ ���� ����
//        cout << "������ ������� �� ������� ������!\n";
//        return;
//    }
//    data[index] = value;
//}
//
//template<typename T>
//size_t findByNumber(const T& value) {
//    for (size_t i = 0; i < size; i++) {
//        if (data[i] == value) {
//            return i;
//        }
//    }
//    cout << "�������" << value << " � ������ �����������\n";
//    return -1;  // ���� ������� �� ������
//}
//template<typename T>
//void addByIndex(size_t index, const T& value) {
//    if (index > size) { //���� ����� �� ������� ����� ��������� � ������
//        cout << "������ ������� �� ������� ������!\n";
//        return;
//    }
//    if (size == capacity) {
//        expand();
//    }
//    T* newData = new T[capacity];
//    for (size_t i = 0; i < size + 1; i++) {
//        if (i < index) {
//            newData[i] = data[i];  // �������� �������� �� index
//        }
//        else if (i == index) {
//            newData[i] = value;  // ��������� ����� �������
//        }
//        else {
//            newData[i] = data[i - 1];  // �������� ���������� ��������
//        }
//    }
//    size++;
//}
//template<typename T>
//void delByNumber(const T& value) {
//    size_t index = -1;
//
//    for (size_t i = 0; i < size; i++) {
//        if (data[i] == value) {
//            index = i;
//            break;
//        }
//    }
//    if (index == -1) {
//        cout << "������� �� ������!\n";
//        return;
//    }
//
//
//    for (size_t i = index; i < size; i++) {//////SIZE -1????????????????????????????????????
//        data[i] = data[i + 1];
//    }
//    size--;
//}
//template<typename T>
//void List<T>::delById(size_t index) {
//    if (index >= size) {
//        cout << "������ ������� �� �������!\n";
//        return;
//    }
//
//    // �������� ���������� �������� �����
//    for (size_t i = index; i < size - 1; i++) {
//        data[i] = data[i + 1];
//    }
//
//    size--;  // ��������� ���������� ���������
//}
////���������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ��������� ��� ��� ���� ����� � ���������
//template<typename T>
//T* List<T>::find_begin() {
//    return (size != 0) ? (data) : find_end();  // ������ ������� �������
//}
//template<typename T>
//T* List<T>::find_rbegin() {
//    return (size != 0) ? (data + size - 1) : find_end();
//}
//template<typename T>
//T* List<T>::find_end() {
//    return data + size;  // ��������� ��(������ ����� ����) �������������� ������� �� �������� �������
//}
//
//template<typename T>
//T* List<T>::find_rend() {
//    return (size > 0) ? (data - 1) : find_end();
//}
//
//
//
//
//void menu() {
//    List<int> myList;
//    int choice, value, index;
//
//    while (true) {
//        cout << "\n--- ���� ---\n";
//        cout << "1. �������� �������\n";
//        cout << "2. �������� �� �������\n";
//        cout << "3. ������� ������� �� ��������\n";
//        cout << "4. ������� ������� �� �������\n";
//        cout << "5. ��������� ������� ��������\n";
//        cout << "6. ������� ������\n";
//        cout << "0. �����\n";
//        cout << "�������� ��������: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "������� �����: ";
//            cin >> value;
//            myList.add(value);
//            break;
//        case 2:
//            cout << "������� ������ � �����: ";
//            cin >> index >> value;
//            myList.addByIndex(index, value);
//            break;
//        case 3:
//            cout << "������� ����� ��� ��������: ";
//            cin >> value;
//            myList.delByNumber(value);
//            break;
//        case 4:
//            cout << "������� ������ ��� ��������: ";
//            cin >> index;
//            myList.delById(index);
//            break;
//        case 5:
//            cout << "������� ����� ��� ������: ";
//            cin >> value;
//            myList.is_it_here(value);
//            break;
//        case 6:
//            cout << "������� ������: ";
//            myList.printList();
//            break;
//        case 0:
//            return;
//        default:
//            cout << "������������ ����! ���������� �����.\n";
//        }
//    }
//}
//template<typename T>
//void List<T>::printList() {
//    for (size_t i = 0; i < size; i++) {
//        std::cout << data[i] << " ";
//    }
//    cout << "\n";
//}
//
