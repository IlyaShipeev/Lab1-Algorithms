//#include <iostream>
//using namespace std;
//template<typename T>
//class List {
//private:
//    T* data;       // Указатель на динамический массив
//    size_t size;   // Количество элементов в списке
//    size_t capacity; // Вместимость массива
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
//        T* ptr;  // Указатель на текущий элемент
//    public:
//        Iterator(T* p) : ptr(p) {}
//
//        // Доступ к значению (разыменование)
//        T& operator*() { return *ptr; }
//
//        // Инкремент ++ (переход к следующему элементу)
//        Iterator& operator++() {
//            ++ptr;
//            return *this;
//        }
//
//        // Декремент -- (переход к предыдущему элементу)
//        Iterator& operator--() {
//            --ptr;
//            return *this;
//        }
//
//        // Проверка на равенство
//        bool operator==(const Iterator& other) const {
//            return ptr == other.ptr;
//        }
//
//        // Проверка на неравенство
//        bool operator!=(const Iterator& other) const {
//            return ptr != other.ptr;
//        }
//    };
//
//    // Методы для получения итераторов
//    Iterator begin() { return Iterator(data); }
//    Iterator end() { return Iterator(data + size); }
//    class ReverseIterator {
//    private:
//        T* ptr;
//    public:
//        ReverseIterator(T* p) : ptr(p) {}
//
//        // Доступ к значению
//        T& operator*() { return *ptr; }
//
//        // Инкремент ++ (но в обратном направлении)
//        ReverseIterator& operator++() {
//            --ptr;
//            return *this;
//        }
//
//        // Декремент -- (но в обратном направлении)
//        ReverseIterator& operator--() {
//            ++ptr;
//            return *this;
//        }
//
//        // Проверка равенства
//        bool operator==(const ReverseIterator& other) const {
//            return ptr == other.ptr;
//        }
//
//        // Проверка неравенства
//        bool operator!=(const ReverseIterator& other) const {
//            return ptr != other.ptr;
//        }
//    };
//
//    // Методы для получения обратных итераторов
//    ReverseIterator rbegin() { return ReverseIterator(data + size - 1); }
//    ReverseIterator rend() { return ReverseIterator(data - 1); }
//};
//
//template<typename T>
//List<T>::List() : data(nullptr), size(0), capacity(5) {
//    data = new T[capacity]; // Начальная емкость 5
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
//        cout << "Список пустой.\n";
//        return true;
//    }
//    else {
//        cout << "Список не пустой.\n";
//        return false;
//    }
//}
//
//template<typename T>
//void List<T>::is_it_here(const T& value) {
//    for (size_t i = 0; i < size; i++) {
//        if (data[i] == value) {
//            cout << "Ваш элемент найден\n";
//        }
//    }
//    cout << "Такой элемент в списке отсутствует\n";
//}
//template<typename T>
//T findByIndex(size_t index) {
//    if (index >= size) {
//        cout << "Индекс выходит за границы списка!\n";
//        return;
//    }
//    else return data[index];
//
//}
//template<typename T>
//void changeByIndex(size_t index, const T& value)
//{
//    if (index >= size) { // меняем если есть
//        cout << "Индекс выходит за границы списка!\n";
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
//    cout << "Элемент" << value << " в списке отсутствует\n";
//    return -1;  // Если элемент не найден
//}
//template<typename T>
//void addByIndex(size_t index, const T& value) {
//    if (index > size) { //если равен то элемент будет последним в списке
//        cout << "Индекс выходит за границы списка!\n";
//        return;
//    }
//    if (size == capacity) {
//        expand();
//    }
//    T* newData = new T[capacity];
//    for (size_t i = 0; i < size + 1; i++) {
//        if (i < index) {
//            newData[i] = data[i];  // Копируем элементы до index
//        }
//        else if (i == index) {
//            newData[i] = value;  // Вставляем новый элемент
//        }
//        else {
//            newData[i] = data[i - 1];  // Копируем оставшиеся элементы
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
//        cout << "Элемент не найден!\n";
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
//        cout << "Индекс выходит за границы!\n";
//        return;
//    }
//
//    // Сдвигаем оставшиеся элементы влево
//    for (size_t i = index; i < size - 1; i++) {
//        data[i] = data[i + 1];
//    }
//
//    size--;  // Уменьшаем количество элементов
//}
////ИТЕРАТОРЫ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ПРОВЕРИТЬ ЧТО ТАМ ВХОД ВЫХОД В МЕТОДИЧКЕ
//template<typename T>
//T* List<T>::find_begin() {
//    return (size != 0) ? (data) : find_end();  // Первый элемент массива
//}
//template<typename T>
//T* List<T>::find_rbegin() {
//    return (size != 0) ? (data + size - 1) : find_end();
//}
//template<typename T>
//T* List<T>::find_end() {
//    return data + size;  // Указатель на(следущ после ласт) несуществующий элемент за границей массива
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
//        cout << "\n--- МЕНЮ ---\n";
//        cout << "1. Добавить элемент\n";
//        cout << "2. Добавить по индексу\n";
//        cout << "3. Удалить элемент по значению\n";
//        cout << "4. Удалить элемент по индексу\n";
//        cout << "5. Проверить наличие элемента\n";
//        cout << "6. Вывести список\n";
//        cout << "0. Выйти\n";
//        cout << "Выберите действие: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Введите число: ";
//            cin >> value;
//            myList.add(value);
//            break;
//        case 2:
//            cout << "Введите индекс и число: ";
//            cin >> index >> value;
//            myList.addByIndex(index, value);
//            break;
//        case 3:
//            cout << "Введите число для удаления: ";
//            cin >> value;
//            myList.delByNumber(value);
//            break;
//        case 4:
//            cout << "Введите индекс для удаления: ";
//            cin >> index;
//            myList.delById(index);
//            break;
//        case 5:
//            cout << "Введите число для поиска: ";
//            cin >> value;
//            myList.is_it_here(value);
//            break;
//        case 6:
//            cout << "Текущий список: ";
//            myList.printList();
//            break;
//        case 0:
//            return;
//        default:
//            cout << "Некорректный ввод! Попробуйте снова.\n";
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
