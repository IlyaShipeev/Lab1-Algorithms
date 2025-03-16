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
    bool is_it_here(const T& value);
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
            return true;
        }
        else {
            return false;
        }
    }

template<typename T>
bool List<T>::is_it_here(const T& value) {
    for (size_t i = 0; i < size; i++) {
        if (data[i] == value) 
            return true;
        }
    
    return false;
}
template<typename T>
T List<T>::findByIndex(size_t index) {
    if (index >= size || index < 0) {
        throw out_of_range ("Индекс выходит за границы списка!\n");
    }
    return data[index];
};

template<typename T>
void List<T>::changeByIndex(size_t index, const T& value)
{
    if (index >= size || index < 0) { // меняем если есть
        throw out_of_range("Индекс выходит за границы списка!\n");
    }
    data[index] = value;
}

template<typename T>
size_t List<T>::findByNumber(const T& value) {
    for (size_t i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    throw runtime_error ("Элемент в списке отсутствует!\n");
};

template<typename T>
void List<T>:: addByIndex(size_t index, const T& value) {
    if (index > size || index < 0) { //если равен то будет самым последним в списке
        throw out_of_range("Индекс выходит за границы списка!\n");
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
    if (index >= size || index < 0) {
        throw out_of_range("Индекс выходит за границы списка!\n");
    }

    // Сдвигаем оставшиеся элементы влево
    for (size_t i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    size--;  // Уменьшаем количество элементов
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
void runMenu() {
    int choice;
    List<int> myList;
    T value;
    size_t index;
    auto directIt = myList.find_begin();
    auto reverseIt = myList.find_rbegin();
    while (true) {
        cout << "\n--- ГЛАВНОЕ МЕНЮ ---\n";
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
        cout << "11. Изменение элемента по индексу\n";
        cout << "12. Опрос размера списка\n";

        cout << "------------------------\n";
        cout << "13. Прямой итератор: В начало\n";
        cout << "14. Прямой итератор: Шаг вперед\n";
        cout << "15. Прямой итератор: Запись в текущую позицию\n";
        cout << "16. Прямой итератор: Печать текущего элемента\n";
        cout << "17. Прямой итератор: Текущий статус\n";

        cout << "------------------------\n";
        cout << "18. Обратный итератор: В конец\n";
        cout << "19. Обратный итератор: Шаг назад\n";
        cout << "20. Обратный итератор: Запись в текущую позицию\n";
        cout << "21. Обратный итератор: Печать текущего элемента\n";
        cout << "22. Обратный итератор: Текущий статус\n";

        cout << "------------------------\n";
        cout << "23. Отладка: Наполнить список случайными элементами\n";
        cout << "24. Проверка равенства прямых итераторов (==)\n";
        cout << "25. Проверка неравенства прямых итераторов (!=)\n";
        cout << "26. Проверка равенства обратных итераторов (==)\n";
        cout << "27. Проверка неравенства обратных итераторов (!=)\n";
        cout << "0. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение: ";
            cin >> value;
            myList.add(value);
            break;
        case 2:
            cout << "Введите индекс и значение: ";
            cin >> index >> value;
            try {
                myList.addByIndex(index, value);
                cout << "Элемент добавлен!" << endl;
            }
            catch (const out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        case 3:
            cout << "Введите значение для удаления: ";
            cin >> value;
            myList.delByNumber(value);
            break;
        case 4:
            cout << "Введите индекс для удаления: ";
            cin >> index;
            try {
                myList.delById(index);
                cout << "Элемент удален!" << endl;
            }
            catch (const out_of_range& e) {
                cerr << e.what();
            }
            break;
        case 5:
            cout << "Введите значение для проверки: ";
            cin >> value;
            myList.is_it_here(value) ? cout << "Ваш элемент найден в списке!" << endl : cout << "Такой элемент в списке отсутствует!\n";
            break;
        case 6:
            cout << "Текущий список: ";
            myList.printList();
            break;
        case 7:
            myList.ClearList();
            break;
        case 8:
            
            myList.is_empty() ? cout << "Список пустой.\n" : cout << "Список не пустой.\n";
            break;
        case 9:
            cout << "Введите индекс элемента: ";
            cin >> index;
            try {
                cout << "Результат поиска: " << myList.findByIndex(index) << endl;
            }
            catch (const out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        case 10:
            cout << "Введите элемент для поиска: ";
            cin >> value;
            try {
                cout << "Элемент найден под индексом: " << myList.findByNumber(value);
            }
            catch (const runtime_error& e) {
                cerr << e.what() << endl;
            }
            break;
        case 11:
            cout << "Введите индекс и новое значение: ";
            cin >> index >> value;

            try {
                myList.changeByIndex(index, value);
                cout << "Элемент изменен успешно!\n";
            }
            catch (const out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        case 12:
            cout << "Размер списка: " << myList.return_size() << endl;
            break;

            // Прямой итератор
        case 13:
            directIt = myList.find_begin();
            cout << "Прямой итератор установлен в начало.\n";
            break;
        case 14:
            if (directIt != myList.find_end()) {
                ++directIt;
                cout << "Шаг вперед выполнен.\n";
            }
            else {
                cout << "Итератор уже в конце списка!\n";
            }
            break;
        case 15:
            cout << "Введите новое значение: ";
            cin >> value;
            *directIt = value;
            cout << "Запись выполнена.\n";
            break;
        case 16:
            if (directIt != myList.find_end()) {
                cout << "Текущий элемент: " << *directIt << endl;
            }
            else {
                cout << "Итератор вне границ списка.\n";
            }
            break;
        case 17:
            cout << "Адрес итератора: " << &directIt << endl;
            break;

            // Обратный итератор
        case 18:
            reverseIt = myList.find_rbegin();
            cout << "Обратный итератор установлен в конец.\n";
            break;
        case 19:
            if (reverseIt != myList.find_rend()) {
                --reverseIt;
                cout << "Шаг назад выполнен.\n";
            }
            else {
                cout << "Итератор уже в начале списка!\n";
            }
            break;
        case 20:
            cout << "Введите новое значение: ";
            cin >> value;
            *reverseIt = value;
            cout << "Запись выполнена.\n";
            break;
        case 21:
            if (reverseIt != myList.find_rend()) {
                cout << "Текущий элемент: " << *reverseIt << endl;
            }
            else {
                cout << "Итератор вне границ списка.\n";
            }
            break;
        case 22:
            cout << "Адрес итератора: " << &reverseIt << endl;
            break;

            // Отладка
        case 23:
            myList.fillWithRandomValues(30, 10, 100);
            break;
        case 24:
            if (directIt == myList.find_begin()) {
                cout << "Прямой итератор находится в начале (равны).\n";
            }
            else {
                cout << "Прямой итератор не в начале (не равны).\n";
            }
            break;

        case 25:
            if (directIt != myList.find_end()) {
                cout << "Прямой итератор не указывает на конец (не равны).\n";
            }
            else {
                cout << "Прямой итератор указывает на конец (равны).\n";
            }
            break;

        case 26:
            if (reverseIt == myList.find_rbegin()) {
                cout << "Обратный итератор находится в конце (равны).\n";
            }
            else {
                cout << "Обратный итератор не в конце (не равны).\n";
            }
            break;

        case 27:
            if (reverseIt != myList.find_rend()) {
                cout << "Обратный итератор не указывает на начало (не равны).\n";
            }
            else {
                cout << "Обратный итератор указывает на начало (равны).\n";
            }
            break;
        case 0:
            return;

        default:
            cout << "Некорректный ввод! Попробуйте снова.\n";
        }
    }
}

template<typename T>
void List<T>:: printList() {
    for (size_t i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    runMenu<int>();
}
