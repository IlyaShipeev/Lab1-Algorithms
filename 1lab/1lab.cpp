#include <iostream>
#include <iostream>
using namespace std;
template<typename T>
class List {
private:
    T* data;       // Указатель на динамический массив
    size_t size;   // Количество элементов в списке
    size_t capacity; // Вместимость массива
    void expand();
public:
    List();
    List(const T& t);
    List(const List& other);
    ~List();

    size_t return_size();
    void ClearList();
    bool is_empty();
    size_t is_it_here(const T& value);
    T findByIndex(size_t index);
    void changeByIndex(size_t index, const T& value);
    size_t findByNumber(const T& value);
    void add(const T& value);
    void addByIndex(size_t index, const T& value);
    void delByNumber(const T& value);
    void delById(size_t index);
    void fillWithRandomValues(size_t count, int minValue, int maxValue);
    T* find_begin();
    T* find_rbegin();
    T* find_end();
    T* find_rend();
    void printList();
    class Iterator {
    private:
        T* ptr;  // Указатель на текущий элемент
    public:
        Iterator(T* p) : ptr(p) {}

        // Доступ к значению (разыменование)
        T& operator*() { return *ptr; }

        // Инкремент ++ (переход к следующему элементу)
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        // Декремент -- (переход к предыдущему элементу)
        Iterator& operator--() {
            --ptr;
            return *this;
        }

        // Проверка на равенство
        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        // Проверка на неравенство
        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    // Методы для получения итераторов
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }
    class ReverseIterator {
    private:
        T* ptr;
    public:
        ReverseIterator(T* p) : ptr(p) {}

        // Доступ к значению
        T& operator*() { return *ptr; }

        // Инкремент ++ (но в обратном направлении)
        ReverseIterator& operator++() {
            --ptr;
            return *this;
        }

        // Декремент -- (но в обратном направлении)
        ReverseIterator& operator--() {
            ++ptr;
            return *this;
        }

        // Проверка равенства
        bool operator==(const ReverseIterator& other) const {
            return ptr == other.ptr;
        }

        // Проверка неравенства
        bool operator!=(const ReverseIterator& other) const {
            return ptr != other.ptr;
        }
    };

    // Методы для получения обратных итераторов
    ReverseIterator rbegin() { return ReverseIterator(data + size - 1); }
    ReverseIterator rend() { return ReverseIterator(data - 1); }
};

template<typename T>
List<T>::List() : data(nullptr), size(0), capacity(5) {
    data = new T[capacity]; // Начальная емкость 5
}

template<typename T>
List<T>::List(const T& t) : size(1), capacity(5) {
    data = new T[capacity];
    data[0] = t;
}

template<typename T>
List<T>::List(const List& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
List<T>::~List() {
    delete[] data;
}

template<typename T>
size_t List<T>::return_size() {
    return size;
}

template<typename T>
void List<T>::add(const T& value) {
    if (size == capacity) {
        expand();
    }
    data[size] = value;
    size++;
    cout << "Элемент добавлен успешно! \n";
}

template<typename T>
void List<T>::expand() {
    size_t n0 = 5;
    capacity += n0;
    T* newData = new T[capacity];
    for (size_t i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}
template<typename T>
void List<T>::ClearList() {
    size_t n0 = 5;
    T* newData = new T[n0];
    delete[] data;
    data = newData;
    size = 0;
    capacity = n0;
    cout << "Список очищен успешно! \n";
}
template<typename T>
bool List<T>::is_empty() {
        if (size == 0) {
            cout << "Список пустой.\n";
            return true;
        }
        else {
            cout << "Список не пустой.\n";
            return false;
        }
    }

template<typename T>
size_t List<T>::is_it_here(const T& value) {
    for (size_t i = 0; i < size; i++) {
        if (data[i] == value) {
            cout << "Ваш элемент найден в списке!" << endl;
            return 1;
        }
    }
    cout << "Такой элемент в списке отсутствует!\n";
    return 0;
}
template<typename T>
T List<T>::findByIndex(size_t index) {
    if (index >= size) {
        throw out_of_range ("Индекс выходит за границы списка!\n");
    }
    cout << "Элемент найден успешно! \n";
    return data[index];
};

template<typename T>
void List<T>::changeByIndex(size_t index, const T& value)
{
    if (index >= size) { // меняем если есть
        cout << "Индекс выходит за границы списка!\n";
        return;
    }
    data[index] = value;
    cout << "Элемент изменен успешно! \n";
}

template<typename T>
size_t List<T>::findByNumber(const T& value) {
    for (size_t i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    throw runtime_error ("Элемент в списке отсутствует\n");
    
};

template<typename T>
void List<T>:: addByIndex(size_t index, const T& value) {
    if (index > size) { //если равен то элемент будет последним в списке
        cout << "Индекс выходит за границы списка!\n";
        return;
    }
    if (size == capacity) {
        expand();
    }
    T* newData = new T[capacity];
    for (size_t i = 0; i < size + 1; i++) {
        if (i < index) {
            newData[i] = data[i];  // Копируем элементы до index
        }
        else if (i == index) {
            newData[i] = value;  // Вставляем новый элемент
        }
        else {
            newData[i] = data[i - 1];  // Копируем оставшиеся элементы
        }
    }
    delete[] data;
    data = newData;
    size++;
    cout << "Элемент добавлен успешно! \n";
}
template<typename T>
void List<T>::delByNumber(const T& value) {
    int index = -1;

    for (size_t i = 0; i < size; i++) {
        if (data[i] == value) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Элемент не найден!\n";
        return;
    }
    for (size_t i = index; i < size-1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    cout << "Элемент удален успешно!\n";
}
template<typename T>
void List<T>::delById(size_t index) {
    if (index >= size) {
        cout << "Индекс выходит за границы!\n";
        return;
    }

    // Сдвигаем оставшиеся элементы влево
    for (size_t i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    size--;  // Уменьшаем количество элементов
    cout << "Элемент удален успешно!\n";
}
//ИТЕРАТОРЫ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ПРОВЕРИТЬ ЧТО ТАМ ВХОД ВЫХОД В МЕТОДИЧКЕ
template<typename T>
T* List<T>::find_begin() {
    return (size!=0)? (data) : find_end();  // Первый элемент массива
}
template<typename T>
T* List<T>::find_rbegin() {
    return (size != 0) ? (data + size - 1) : find_rend();
}
template<typename T>
T* List<T>::find_end() {
    return data + size;  // Указатель на(следущ после ласт) несуществующий элемент за границей массива
}

template<typename T>
T* List<T>::find_rend() {
    return (size > 0) ? (data - 1) : find_end();
}
template<typename T>
void List<T>::fillWithRandomValues(size_t count, int minValue, int maxValue) {
    srand(time(0));  // Устанавливаем случайное зерно
    for (size_t i = 0; i < count; i++) {
        T value = minValue + rand() % (maxValue - minValue + 1);
        add(value);
    }
}





template<typename T>
void runMenu(List<T>& myList) {
    int choice;
    T value;
    size_t index;

    while (true) {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Добавить по индексу\n";
        cout << "3. Удалить элемент по значению\n";
        cout << "4. Удалить элемент по индексу\n";
        cout << "5. Проверить наличие элемента\n";
        cout << "6. Вывести список\n";
        cout << "7. Очистить список\n";
        cout << "8. Проверка списка на пустоту\n";
        cout << "9. Чтение элемента по индексу\n";
        cout << "10. Получение позиции элемента\n";
        cout << "11. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите элемент: ";
            cin >> value;
            myList.add(value);
            break;
        case 2:
            cout << "Введите индекс и элемент: ";
            cin >> index >> value;
            myList.addByIndex(index, value);
            break;
        case 3:
            cout << "Введите элемент для удаления: ";
            cin >> value;
            myList.delByNumber(value);
            break;
        case 4:
            cout << "Введите индекс для удаления: ";
            cin >> index;
            myList.delById(index);
            break;
        case 5:
            cout << "Введите элемент для поиска: ";
            cin >> value;
            cout << (myList.is_it_here(value) ? "Элемент найден!\n" : "Элемент не найден!\n");
            break;
        case 6:
            cout << "Текущий список: ";
            myList.printList();
            break;
        case 7:
            myList.ClearList();
            cout << "Список очищен!\n";
            break;
        case 8:
            cout << (myList.is_empty() ? "Список пуст.\n" : "Список не пуст.\n");
            break;
        case 9:
            cout << "Введите индекс элемента: ";
            cin >> index;
            try {
                cout << "Результат поиска: " << myList.findByIndex(index) << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
            break;
        case 10:
            cout << "Введите элемент для поиска: ";
            cin >> value;
            try {
                cout << "Элемент найден на позиции: " << myList.findByNumber(value) << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
            break;
        case 11:
            return;
        default:
            cout << "Некорректный ввод! Попробуйте снова.\n";
        }
    }
}
void menu() {
    int typeChoice;
    cout << "Выберите тип данных для списка:\n";
    cout << "1. int\n";
    cout << "2. float\n";
    cout << "3. string\n";
    cout << "Ваш выбор: ";
    cin >> typeChoice;

    if (typeChoice == 1) {
        List<int> myList;
        runMenu(myList);
    }
    else if (typeChoice == 2) {
        List<float> myList;
        runMenu(myList);
    }
    else if (typeChoice == 3) {
        List<string> myList;
        runMenu(myList);
    }
    else {
        cout << "Некорректный ввод! Попробуйте снова.\n";
        menu();
    }
}
template<typename T>
void List<T>:: printList() {
    for (size_t i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    cout << "\n";
}
int main()
{
    setlocale(LC_ALL, "Rus");
    menu();
}
