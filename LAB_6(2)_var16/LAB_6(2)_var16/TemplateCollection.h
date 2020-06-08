#pragma once
#include <iostream>
template <class T>
class TemplateCollection{
private:
	T* elements; // ���� ��������
	int capacity; // ����� �� �������
	int _size; // ʳ������ ��������

public:
	TemplateCollection(); // ����������� �����
	void add(T); //params: ������� ��� ���������
	T& get(int); //params: ������
	void pop(); // ������� ������� ������� ��������
	int size(); // ������� ����� ��������
	void print(); // �������� ���� �������
	void clear(); // ����� ��������
	T& operator[](int); // ���������� ����������
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

