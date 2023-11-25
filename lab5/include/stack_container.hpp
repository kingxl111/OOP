#pragma once

#include <iostream>

template<class T, class ALLOCATOR>
class Stack {
private:
	struct Stack_item;

	using allocator_type = typename ALLOCATOR::template rebind<Stack_item>::other;

	struct eraser {
		allocator_type stack_item_eraser;

		eraser() : stack_item_eraser() {};
		eraser(allocator_type* another_eraser) : stack_item_eraser(another_eraser) {}

		void operator() (void* ptr) {
			stack_item_eraser.deallocate((Stack_item*)ptr, 1);
		}
	};

	struct Stack_item {
		T data;
		Stack_item* next;

		Stack_item() noexcept : data(), next(nullptr) {};
		explicit Stack_item(const T & elem) noexcept : data(elem), next(nullptr) {}

		friend bool operator != (const Stack_item & lhs, const Stack_item & rhs) {
			return &lhs.data != &rhs.data;
		}

		friend bool operator == (const Stack_item & lhs, const Stack_item & rhs) {
			return &lhs.data == &rhs.data;
		}

		friend std::ostream & operator << (std::ostream & out, const Stack_item & node) {
			out << node.data;
			return out;
		}
	};

public:
	class Iterator {
	private:
		Stack_item* ptr;
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		using const_reference = const T&;

		Iterator() : ptr(nullptr) {}
		Iterator(Stack_item* another_ptr) : ptr(another_ptr) {}

		bool is_null() {
			return ptr == nullptr;
		}

		void unvalidate() {
			ptr = nullptr;
		}

		Iterator & operator ++ () {
			if (this->ptr != nullptr) {
				this->ptr = this->ptr->next;
				return *this;
			} 
            else {
				throw std::logic_error("Iterator points to nullptr");
			}
		}

		bool operator != (const Iterator & other_iterator) {
			return &other_iterator.ptr->data != &this->ptr->data;
		}

		bool operator == (const Iterator & other_iterator) {
			return &other_iterator.ptr->data == &this->ptr->data;
		}

		friend std::ostream & operator << (std::ostream & out, const Iterator & it) {
			out << *(it.ptr);
			return out;
		}

		Stack_item & operator * () {
			return *ptr;
		}
	};

private:
	Stack_item* top_item;
	eraser stack_eraser;

public:
	Stack() noexcept : top_item() {};

	Iterator begin() {
		return Iterator(top_item);
	}

	Iterator end() {
		return Iterator(nullptr);
	}

	void pop() {
		if (top_item) {
            Stack_item* next = top_item->next;
            stack_eraser.stack_item_eraser.deallocate(top_item, 1);
            top_item = next;
		} 
        else {
			throw std::logic_error("Empty stack!");
		}
	}

	void push(const T & elem) {
		Stack_item* new_item = stack_eraser.stack_item_eraser.allocate(sizeof(Stack_item));
		stack_eraser.stack_item_eraser.construct(new_item, elem);
		Stack_item* new_node(new_item);
		new_node->next = top_item;
		top_item = new_node;
	}

	T top() {
		if (top_item) {
			return top_item->data;
		} 
        else {
			throw std::logic_error("Stack is empty!");
		}
	}

	void erase(Iterator it) {
		if (it.is_null()) {
			throw std::logic_error("Iterator points to nullptr!");
		}
        else {
			if (*it == *top_item) {
				top_item = top_item->next;
			} else {
				Stack_item* prev_item = top_item;
				while (*prev_item->next != *it) {
					prev_item = prev_item->next;
				}
				prev_item->next = prev_item->next->next;
				(*it).next = nullptr;
			}
		}
	}
};