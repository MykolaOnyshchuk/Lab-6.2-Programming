#pragma once
#include <iostream>
template <class T>
class TemplateCollection{
private:
	T* elements; // Вміст колекції
	int capacity; // Розмір із запасом
	int _size; // Кількість елементів

public:
	TemplateCollection(); // конструктор класу
	void add(T); //params: елемент для додавання
	T& get(int); //params: індекс
	void pop(); // видаляє останній елемент колекції
	int size(); // повертає розмір колекції
	void print(); // виводить вміст колекці
	void clear(); // очищує колекцію
	T& operator[](int); // перегрузка індексації
};

template<class T>
inline TemplateCollection<T>::TemplateCollection(){
	capacity = 1;
	_size = 0;
	elements = new T[capacity];
}

template<class T>
inline void TemplateCollection<T>::add(T item){
	if (_size == capacity) {
		T* temp = new T[capacity * 2];
		for (auto i = 0; i < _size; ++i) {
			temp[i] = elements[i];
		}
		capacity *= 2;
		delete[] elements;
		elements = temp;
	}
	elements[_size++] = item;
}

template<class T>
inline T& TemplateCollection<T>::get(int index){
	return elements[index];
}

template<class T>
inline void TemplateCollection<T>::pop(){
	--_size;
}

template<class T>
inline int TemplateCollection<T>::size(){
	return _size;
}

template<class T>
inline void TemplateCollection<T>::print(){
	for (auto& element : elements) {
		std::cout << element << std::endl;
	}
}

template<class T>
inline void TemplateCollection<T>::clear(){
	capacity = 0;
	_size = 0;
	delete[] elements;
}

template<class T>
inline T& TemplateCollection<T>::operator[](int index){
	return elements[index];
}

