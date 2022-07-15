# 스택(Stack)

## 목차(Contents)

### [1. 스택(Stack)이란?](#스택stack이란)
### [2. `std::stack` 클래스]
+ [멤버 타입 (Member types)]
+ [멤버 함수 (Member functions)]
  + [OCF (Orthodox Canonical Form)]
  + [Iterator]
  + [Element access]
  + [Modifiers]
+ [비-멤버 함수 (Non-menber Function)]
### [3. 참고 자료 (Reference)](#reference)

---
# `std::stack`, 스택 컨테이너란?

**스택(stack)** 이란 `후입선출(last-in-first-out)` 구조로 동작하는 `컨테이너 어댑터(container adaptor)`의 한 종류입니다.

> `후입선출` 구조는 데이터가 마치 박스가 쌓이는(stack) 것처럼 데이터가 저장되고, 가장 나중에 입력된 데이터(top)부터 액세스가 가능한 구조를 말합니다.

> c++에서 `컨테이너 어댑터`란 특정 컨테이너 클래스를 자료를 담을 수 있는 기본 컨테이너로 사용하고, 필요에 따라 해당 컨테이너의 멤버 함수를 사용하거나 사용을 제한해 목적에 맞게 구성한 컨테이너를 말합니다.

`C++ STL`에서 스택은 기본적으로 `std::deque`를 기본 컨테이너 사용하고 있습니다.

> 하지만 우리가 구현해야하는 스택은 직접 구현한 벡터 컨테이너를 기본 컨테이너로 사용해야합니다.

# `std::stack` 클래스

`스택(stack)` 클래스는 다음과 같은 클래스 템플릿으로 정의되어 있습니다

```c++
template <class T, class Container = std::deque<T> >
class stack
```
+ `T`

	원소의 데이터 타입입니다.

+ `Container`

	원소를 저장하는데 사용 할 기본 컨테이너입니다. C++ 표준에서는 `deque`를 사용하고 있습니다.

## 개요(Synopsis)

```c++
// Stack Synopsis
template <class T, class Container = std::deque<T> >
class stack {
public:
	typedef Container container_type;
	typedef typename Container::value_type value_type;
	typedef typename Container::size_type size_type;
	typedef typename Container::reference reference;
	typedef typename Container::const_reference const_reference;

	// default constructor
	stack(const container_type& container = container_type());

	// copy constructor
	stack(const stack& other);

	// assignment operator
	stack& operator=(const stack& other);

	// destructor
	~stack();

	// member functions
	bool empty() const;
	size_type size() const;
	value_type& top();
	const value_type& top() const;
	void push(const value_type& val);
	void pop();

	// non-member functions
	// relation operator
	template <class T1, class C1>
  friend bool operator==(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
  template <class T1, class C1>
  friend bool operator!=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
  template <class T1, class C1>
  friend bool operator<(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
  template <class T1, class C1>
  friend bool operator<=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
  template <class T1, class C1>
  friend bool operator>(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
  template <class T1, class C1>
  friend bool operator>=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
}
```

---
## 멤버 타입(Member types)

| member type     | definition                                              | note                                                                                 |
| --------------- | ------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| container_type  | 두 번째 템플릿 매개변수 `Container`                     | 스택이 사용하는 컨테이너 타입                                                        |
| value_type      | 첫 번째 템플릿 매개변수 `T(container_type::value_type)` | 스택에 담기는 원소의 데이터 타입                                                     |
| size_type       | 부호 없는 정수 타입                                     | 일반적으로 `size_t`를 의미합니다.                                                    |
| reference       | `container_type::reference`                             | 참조자 타입 정의입니다. 스택이 사용하는 기본 컨테이너의 참조 타입니다.               |
| const_reference | `container_type::const_reference`                       | 상수 참조자 타입 정의입니다. 스택이 사용하는 기본 컨테이너의 상수 참조자 타입입니다. |

---
## 멤버 함수(Member Function)

### OCF(Orthodox Canoical Form)

#### 생성자 (Constructor)

```c++
// default
stack(const container_type& container = container_type());
// copy
stack (const stack& other);
```

#### 소멸자 (Destructor)
  
```c++
~stack(void)
```

#### 복사 대입 연산자 (Copy Assignment Operator)

```c++
stack& operator=(const stack& other);
```
---
### Capacity

#### `empty` : 컨테이너가 비어 있는지 확인.

**prototype**
```c++
bool empty() const;
```

스택이 비어있는지 확인하는 함수 입니다. 사용하는 `Container`의 멤버 함수에 `empty()`가 존재하는 경우 해당 함수를 사용 할 수 있습니다.

#### `size` : 컨테이너 원소 개수 반환.

**prototype**
```c++
size_type size() const;
```

스택 컨테이너에 담긴 원소 개수를 반환합니다. `Container`의 멤버 함수에 `size()`가 존재하는 경우 해당 함수를 사용 할 수 있습니다.

---
### Element access

#### `top` : 스택의 최상단 원소에 접근

**prototype**
```c++
value_type& top();
const value_type& top() const;
```

스택의 최상단 원소에 접근합니다. 스택의 최상단은 선형적 자료구조에서는 구현에 따라 다를 수 있지만 일반적으로 가장 마지막 원소와 동일합니다. 따라서 표준에서 `Container`는 `deque`이므로 `deque`의 `back()` 멤버 함수를 사용할 수 있습니다.

> `vector`도 마찬가지로 `back()` 멤버 함수를 활용 할 수 있습니다.

---
### Modifiers

#### `push` : 스택의 상단에 원소를 추가.

**prototype**
```c++
void push(const value_type& val);
```

스택의 최상단에 원소를 추가합니다. 표준 라이브러리에서 `deque`의 `push_back()` 멤버 함수를 사용할 수 있습니다.

> `vector`인 경우 역시 `push_back()` 함수를 사용 할 수 있습니다.

#### `pop` : 스택 최상단 데이터를 삭제.

**prototype**
```c++
void pop();
```

스택 최상단 원소를 삭제합니다. 표준 라이브러리에서 `deque`의 `pop_back()` 멤버 함수를 사용 할 수 있습니다.

> `vector` 역시 `pop_back()`을 사용 할 수 있습니다.

---
## 비-멤버 함수 (Non-menber Function)
---

#### `relation operator` : 스택 컨테이너 관계 연산자 오버로딩

**prototype**
```c++
template <class T1, class C1>
bool operator==(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
template <class T1, class C1>
bool operator!=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
template <class T1, class C1>
bool operator<(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
template <class T1, class C1>
bool operator<=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
template <class T1, class C1>
bool operator>(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
template <class T1, class C1>
bool operator>=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
```

스택 컨테이너의 관계 연산자 오버로딩 입니다. 내재된 `Container`의 연산자 오버로딩을 사용합니다.

## Reference

| index                                                  | title                                                           | author       | last modified | accessed      | url status |
| ------------------------------------------------------ | --------------------------------------------------------------- | ------------ | ------------- | ------------- | ---------- |
| [1](https://en.cppreference.com/w/cpp/container/stack) | [std::stack](https://en.cppreference.com/w/cpp/container/stack) | cppreference | 20 Dec, 2021  | 22 June, 2022 | ok         |
| [2](https://www.cplusplus.com/reference/stack/stack/)  | [std::stack](https://www.cplusplus.com/reference/stack/stack/)  | cplusplus    | unknown       | 22 June, 2022 | ok         |



