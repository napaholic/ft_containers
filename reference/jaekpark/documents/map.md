# 맵(map)

## 목차(Contents)

### [1. `std::map`, 맵 컨테이너란?]
### [2. `std::map` 클래스]
+ [개요(Synopsis)](#개요synopsis)
+ [멤버 타입 (Member types)](#멤버-타입member-types12)
+ [멤버 함수 (Member functions)](#멤버-함수member-function)
    + [OCF (Orthodox Canonical Form)](#ocforthodox-canoical-form)
    + [Iterator](#iterators)
    + [capacity](#capacity)
    + [Modifiers](#modifiers)
    + [Element access](#element-access)
    + [Observers](#observers)
    + [Operations](#operations)
    + [Allocator](#allocator)
+ [비-멤버 함수 (Non-menber Function)](#비-멤버-함수-non-menber-function)
### [3. 참고 자료 (Reference)](#reference)
---
# `std::map`, 맵 컨테이너란?

> Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.<sup>[1]

**맵(map)** 이란 `키(key)`와 `값(value)`의 조합으로 이루어진 한 쌍의 데이터 묶음을 특정 순서로 저장하는 `연관 컨테이너(associate container)` 입니다. 

> key, value로 이루어진 한 쌍의 데이터 묶음을 `Node(노드)`라고 표현합니다.

<p align="center">
<img src="https://github.com/Jaekpark/ft_containers/blob/master/images/map_node.png?raw=true">
</p>

이 때 `키`는 각 원소를 비교하거나 정렬하는데 사용됩니다. 이 때 키는 중복이 허용되지 않기 때문에 하나의 키에 매핑된 하나의 값만 존재합니다. 맵에 삽입되는 원소들은 컨테이너 내부의 원소 비교 객체에 의해 순서대로 정렬됩니다.

> C++에서 하나의 `키`에 여러 `값`이 존재할 수 있는 컨테이너는 `멀티맵(multi-map)`이 있습니다.

맵은 일반적으로 `이진 탐색 트리(binary search tree)`로 구현됩니다.

> `트리(tree)`구조나 `이진 탐색 트리(binary search tree)`에 대해 잘 모르시는 경우 [이 문서](tree.md)를 참고하시기 바랍니다.


# `std::map` 클래스

 `맵(map)` 클래스는 다음과 같은 클래스 템플릿으로 정의되어 있습니다.

 ```c++
 template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
 class map
 ```
+ `Key`

	`key`의 자료형을 나타내는 템플릿 매개변수 입니다.

+ `T`

	`value`의 자료형을 나타내는 템플릿 매개변수 입니다.

+ `Compare`
	
	노드간 비교를 하기 위한 객체입니다. 별도의 처리가 없을 경우 기본적으로 `std::less`가 사용됩니다.

+ `Allocator`

	메모리 할당 객체입니다. 기본적으로 `std::allocator`가 사용됩니다. 맵 컨테이너는 `std::pair<const Key, T>` 타입의 객체를 원소로 사용하므로 해당 타입이 메모리 할당 객체의 템플릿 매개변수로 전달됩니다.
---
## 개요(Synopsis)

```c++
//Map synopsis
template <class Key, class T,class Compare = std::less<T>,
	class Allocator = std::allocator<std::pair<const Key, T> > >
class map {
public:
	// type alias
	typedef Key 						key_type;
	typedef T 						mapped_type;
	typedef std::pair<key_type, mapped_type>		value_type;
	typedef Compare 					key_compare;
	typedef Allocator					allocator_type;
	typedef typename allocator_type::reference		reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer		pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef typename allocator_type::size_type		size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef implementation					iterator;
	typedef implementation					const_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

	// value_compare
	class value_compare {
		friend class map;
	protected:
		key_compare		comp;
		value_compare(key_compare c);
	public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;

		// operator()
		bool operator()(const value_type& x, const value_type& y) const;
	};

	// constructor
	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	map(const map& x);
	// destructor
	~map();
	// operator=
	map& operator=(const map& x);
	
	// member functions

	// iterators
	iterator		begin();
	const_iterator		begin() const;
	iterator		end();
	const_iterator		end() const;
	reverse_iterator	rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator	rend();
	reverse_const_iterator	rend() const;

	// capacity
	bool			empty() const;
	size_type		size() const;
	size_type		max_size() const;

	// element access
	mapped_type& operator[](const key_type& key);

	// modifiers
	pair<iterator, bool>	insert(const key_type& key);
	iterator		insert(iterator position, const key_type& key);
	template <class InputIterator>
	void			insert(InputIterator first, InputIterator last);
	void			erase(iterator position);
	size_type		erase(const key_type& key);
	void			erase(iterator first, iterator last);
	void			swap(map& x);
	void			clear();

	// observers
	key_compare		key_comp() const;
	value_compare		value_comp() const;

	// operations
	iterator				find(const key_type& key);
	const_iterator				find(const key_type& key) const;
	size_type				count(const key_type& key) const;
	iterator				lower_bound(const key_type& key);
	const_iterator				lower_bound(const key_type& key) const;
	iterator				upper_bound(const key_type& key);
	const_iterator				upper_bound(const key_type& key) const;
	pair<iterator, iterator>		equal_range(const key_type& key);
	pair<const_iterator, const_iterator>	equal_range(const key_type& key) const;

	// allocator
	allocator_type&		get_allocator();
};
// non-member functions

// relation operators overloading
template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator<(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator>(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);

// specializes the std::swap
template <class Key, class T, class Compare, class Allocator>
void swap(map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs);
```
---
## 멤버 타입(Member types)<sup>[1][2]

| member type            | definition                                       | note                                                                                       |
| ---------------------- | ------------------------------------------------ | ------------------------------------------------------------------------------------------ |
| key_type               | 첫 번째 템플릿 매개변수 `Key`                    | 노드의 `key` 자료 타입을 말합니다.                                                         |
| mapped_type            | 두 번째 템플릿 매개변수 `T`                      | `key`와 쌍을 이루는 노드의 `value` 자료 타입을 말합니다.                                   |
| value_type             | `key`와 `value` 쌍으로 구성된 데이터 묶음입니다. | `std::pair<Key, T>`를 말합니다.                                                            |
| key_compare            | 세 번째 템플릿 매개변수 `Compare`                | 노드간 비교를 위한 객체로 기본적으로는 `std::less<Key>` 객체를 의미합니다.                 |
| value_compare          | 노드간 비교를 위한 `중첩 함수 클래스` 입니다.    | [value_compare]()                                                                          |
| allocator_type         | 네 번째 템플릿 매개변수 `Allocator`              | 메모리 할당 객체, 기본적으로 `std::allocator<value_type>` 을 말합니다.                     |
| reference              | `allocator_type::reference`                      | 참조자 타입 정의입니다. `value_type&`, `std::pair<Key, T>&`를 의미합니다.                  |
| const_reference        | `allocator_type::const_reference`                | 상수 참조자 타입 정의입니다. `const value_type&`, `const std::pair<Key, T>&`를 의미합니다. |
| pointer                | `allocator_type::pointer`                        | 포인터 타입 정의입니다. `value_type *`, `std::pair<Key, T> *`를 의미합니다.                |
| const_pointer          | `allocator_type::const_pointer`                  | 상수 포인터 타입입니다. `const value_type *`, `const std::pair<Key, T> *`를 의미합니다.    |
| iterator               | 맵 원소에 접근 가능한 반복자 입니다.             | `value_type`에 접근 가능한 `양방향 반복자(bidirectional iterator)`입니다.                  |
| const_iterator         | 맵 원소에 접근 가능한 상수 반복자입니다.         | `iterator`와 마찬가지로 `양방향 반복자`의 성질을 갖습니다.                                 |
| reverse_iterator       | `std::reverse_iterator<iterator>`                | `역방향 반복자` 입니다.                                                                    |
| const_reverse_iterator | `std::reverse_iterator<const_iterator>`          | 상수 역방향 반복자입니다.                                                                  |
| difference_type        | 부호 있는 정수 타입                              | 일반적으로 `std::ptrdiff_t`를 의미합니다.                                                  |
| size_type              | 부호 없는 정수 타입                              | 일반적으로 `std::size_t`를 의미합니다.                                                     |
---
## 멤버 함수(Member Function)

### OCF(Orthodox Canoical Form)
#### 생성자 (Constructor)
```c++
// default
map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
// range
template <class InputIterator>
map(InputIterator first, InputIterator last,
	const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
// copy
map(const map& x);
```

#### 소멸자 (Destructor)
  
```c++
~map(void)
```

#### 복사 대입 연산자 (Copy Assignment Operator)

```c++
map& operator=(const map& x);
```
---
### Iterators

#### begin & end

![iterator](https://upload.cppreference.com/mwiki/images/1/1b/range-begin-end.svg)

`begin` : 컨테이너의 첫 번째 원소를 참조하는 반복자를 반환.

**prototype**
```c++
iterator		begin();
const_iterator	begin() const;
```

맵 컨테이너의 첫 번째 원소를 참조하는 `양방향 반복자(bidirectional iterator)`를 반환합니다. 맵 컨테이너의 원소들은 컨테이너의 템플릿 매개변수로 전달되는 `Compare` 객체에 의해 정렬되기 때문에 별도의 객체 전달이 없는 경우 `std::less`에 의해 최소값을 갖는 `key` 노드가 첫 번째 원소입니다. 만약 `std::greater` 객체를 템플릿 매개변수로 전달한 경우에는 최대값 `key` 노드가 첫 번째 원소입니다. 컨테이너가 비어있는 경우에는 컨테이너의 종료위치를 표시하는 `end()`와 같은 값을 반환합니다.

`end` : 컨테이너의 마지막 위치를 참조하는 반복자를 반환. 	

**prototype**
```c++
iterator		end();
const_iterator	end() const;
```
컨테이너의 종료위치를 참조하는 `양방향 반복자`를 반환합니다. 이 때 컨테이너의 종료위치란 마지막 원소의 바로 다음 위치를 의미합니다. 맵 컨테이너의 `Compare` 객체가 `std::less`인 경우 `end() - 1` 위치의 원소는 컨테이너의 최대값 `key` 노드입니다.

![reverse_iterator](https://upload.cppreference.com/mwiki/images/3/39/range-rbegin-rend.svg)

`rbegin` : 컨테이너의 역방향 반복자 시작 지점 반환.

**prototype**
```c++
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
```

컨테이너의 역방향 반복자를 반환합니다. `rbegin()`은 컨테이너의 마지막 원소를 참조하는 역방향 반복자를 반환합니다. 마지막 원소는 `end()`가 참조하는 `past-the-last`의 전 위치(-1)와 같습니다. 

`rend` : 컨테이너의 역방향 반복자 종료 지점 반환.

**prototype**
```c++
reverse_iterator rend();
const_reverse_iterator rend() const;
```

컨테이너의 역방향 반복자를 반환합니다. `rend()`는 `begin()`이 참조하는 컨테이너의 첫 번째 원소를 마지막 원소로 참조하고 마지막 원소 다음 위치의 빈 공간을 참조하는 `past-the-last` 반복자를 반환합니다.

---
### Capacity
#### `empty` : 컨테이너가 비어있는지 확인.

**prototype**

```c++
bool empty() const;
```

컨테이너가 비어있는지 확인하는 함수 입니다. `begin() == end()`이고 `size() == 0` 연산 결과와 같습니다.

#### `size` : 컨테이너의 원소 개수를 반환.

**prototype**

```c++
size_type size() const;
```

컨테이너에 존재하는 원소의 개수를 반환합니다. 이 때 `size_type` 은 `부호 없는(unsigned)` 정수 타입입니다.

#### `max_size` : 컨테이너가 담을 수 있는 최대 원소개수 반환.

**prototype**

```c++
size_type max_size() const;
```

컨테이너가 도달 할 수 있는 최대 크기를 반환합니다. 하지만 컨테이너가 반드시 해당 사이즈만큼 원소를 담을 수 있음을 보장 하지는 않습니다.

---
### Element access

####  `operator[]` : `[]` 연산자 오버로딩, 해당 키 노드 생성, 접근 및 수정.

```c++
mapped_type& operator[](const key_type& key);
```

매개변수로 입력되는 `key`와 일치하는 노드에 접근, 생성, 수정 할 수 있도록 하는 연산자 오버로딩입니다. `key`가 일치하는 노드를 찾을 경우 해당 키값과 `매핑(mapped)`된 `value`의 참조자를 반환합니다. 만약 `key`와 일치하는 노드가 없는 경우 새롭게 노드를 생성한 후 `value`의 참조자를 반환합니다.

> c++11 이후 부터 사용 가능한 `at` 함수와 동작과 비슷합니다. 다만 `at` 함수는 `[]` 연산자와 다르게 존재하지 않는 `key` 값이 들어오는 경우 예외를 발생시킵니다.

---
### Modifiers

#### `insert` : 새로운 원소를 삽입.

**prototype**
```c++
// 1. insert single element
pair<iterator, bool> insert(const value_type& val);
// 2. insert with hint
iterator insert(iterator position, const value_type& val);
// 3. insert with range
template <class InputIterator>
void insert(InputIterator first, InputIterator last);
```

새로운 원소를 삽입하는 함수입니다. `c++ 컨테이너`에서 `맵`은 원소의 키값이 고유한 성질을 같기 때문에 동일한 키를 가지고 있는 원소가 존재하는지 확인하고, 존재하지 않는 경우 새롭게 추가합니다.
1. 단일 원소 삽입

	매개 변수로 들어오는 `val`을 새롭게 추가합니다. 이미 동일한 키값을 같는 노드가 이미 존재하는 경우 해당 노드를 참조하는 반복자를 `key`로 갖고, `value`는 `false`값을 갖는 `pair<iterator, false>` 형태의 값을 반환합니다. 반대인 경우 새롭게 노드를 생성해 삽입하고 해당 노드를 참조하는 반복자와, true값을 `pair<iterator, true>`형태로 반환합니다.

2. 위치 기반 삽입

	매개변수로 주어지는 `position`을 `힌트(hint)`로 `val`을 삽입하는 함수입니다. 이 때 `position`은 삽입 위치 탐색의 힌트 역할로 참고 할 수 있는 요소일뿐 `반드시 해당 위치의 전, 후에 삽입하는 것을 의미하지 않습니다.` 동일한 키를 갖는 노드가 존재하는 경우 해당 노드를 참조하는 반복자를 반환하고, 반대인 경우에는 새롭게 생성한 뒤 삽입한 노드를 참조하는 반복자를 반환합니다.

3. 범위 지정 삽입

	참조 가능한 객체의 특정 범위의 원소를 삽입하는 함수 입니다. 매개변수로 들어오는 `first` 부터 `last` 까지의 범위내에 있는 원소들을 새롭게 삽입합니다. 동일한 키의 노드가 이미 존재하지 않는 경우에만 새롭게 노드를 추가합니다.

#### `erase` : 원소 삭제.

**prototype**
```c++
// 1. erase with iterator
void erase(iterator position);
// 2. erase with key
size_type erase(const key_type& key);
// 3. erase with range
void erase(iterator first, iterator last);
```

컨테이너의 원소를 삭제하는 함수입니다.

1. `반복자`로 삭제

	매개변수로 입력되는 `position` 반복자가 참조하고 있는 노드를 삭제합니다. 이 때 `position`은 컨테이너에 존재하는 원소를 참조하는 반복자이어야 합니다. `end()`와 같이 역참조가 불가능한 값이 들어오는 경우 `undefined behavior`가 발생합니다.

2. `key`로 삭제

	매개변수 `key`와 동일한 값을 같는 원소를 삭제하는 함수 입니다. 반환 값은 삭제한 원소의 개수입니다. `맵 컨테이너`는 동일한 키를 갖는 원소가 1개이기 때문에 `1(삭제) 혹은 0(존재하지 않음)`을 반환합니다.

3. `범위 지정` 삭제

	매개변수 `first` 부터 `last`까지를 범위로 해당 범위 내의 원소를 삭제합니다. 해당 반복자들이 역참조가 불가능할 경우 `undefined behavior`가 발생합니다.

#### `swap` : 컨테이너의 콘텐츠 교환.

**prototype**
```c++
void swap(map& x);
```

동일한 타입을 갖는 두 컨테이너의 `구성 요소(contents)`를 서로 바꿔주는 함수 입니다.

#### `clear` : 컨테이너 원소 전체 삭제.

**prototype**
```c++
void clear();
```

컨테이너의 모든 원소를 삭제하는 함수 입니다.

---
### Observers

#### `key_comp` : 키(key) 비교 객체 반환.

**prototype**

```c++
key_compare key_comp() const;
```

맵 컨테이너가 `key`를 비교하는 데 사용하는 객체를 반환합니다. 해당 비교 객체는 컨테이너 생성시 템플릿 매개변수로 지정하는 `Compare`와 같습니다. 별다른 객체 지정이 없을 경우 기본적으로는 `std::less`입니다.

#### `value_comp` : 노드 비교 객체 반환

**prototype**

```c++
value_compare value_comp() const;
```

컨테이너의 원소 비교에 사용되는 비교 객체를 반환합니다. `key_comp`로 `key`를 비교하는 맵 컨테이너의 내부에 정의된 `중첩 클래스` `value_compare`를 반환합니다.

---
### Operations

#### `find` : 원소 탐색.

**prototype**

```c++
iterator find(const key_type& key);
const_iterator find(const key_type& key);
```

매개변수로 들어오는 `key`와 동일한 값을 갖는 원소가 존재하는지 찾는 함수입니다. 해당 원소가 존재하는 경우에는 맵 컨테이너의 타입에 따라 해당 원소를 참조하는 `반복자(iterator)` 혹은 `상수 반복자(const iterator)`를 반환합니다. 만약 원소가 존재하지 않는 경우에는 `end()`를 반환합니다.

#### `count` : 특정 키를 갖는 원소 개수 반환.

**prototype**
```c++
size_type count(const key_type& key) const;
```

매개변수로 들어오는 `key` 값을 갖는 원소들을 찾아 그 개수를 반환합니다. 맵 컨테이너의 원소는 고유한 `key`를 갖기 때문에 `1 혹은 0`이 반환됩니다.

#### `lower_bound` : 탐색 대상 값 이상의 값이 처음 나오는 위치 반환.

**prototype**
```c++
iterator lower_bound(const key_type& key);
const_iterator lower_bound(const key_type& key);
```

기본적으로 `(key_compare 객체가 std::less인 경우)` 매개변수로 들어오는 `key` 이상의 값이 처음 나오는 위치를 참조하는 반복자를 반환합니다. 동일한 키의 원소가 존재하는 경우 해당 위치의 반복자를 반환하고, 존재하지 않는 경우 `key` 보다 큰 값을 갖는 가장 처음의 원소 반복자를 반환합니다. 조건에 부합하는 원소가 없는 경우에는 `end()`를 반환합니다.

> `std::less` 를 비교 객체로 사용하는 경우, 해당 객체로 비교한 결과값이 (`std::less`는 `a < b`인 경우에 true, `a >= b`인 경우 `false`를 반환하기 때문에) `false`가 되는 첫 원소를 반환합니다.

#### `upper_bound` : 탐색 대상 값을 초과하는 값이 처음 나오는 위치 반환.

**prototype**
```c++
iterator upper_bound(const key_type& key);
const_iterator upper_bound(const key_type& key);
```

기본적으로 매개변수로 들어오는 `key`를 초과하는 값이 처음 나오는 위치를 참조하는 반복자를 반환합니다. 조건에 부합하는 원소가 없는 경우에는 `end()`를 반환합니다.

#### `equal_range` : 특정 `key` 조건을 만족하는 범위를 반환.

**prototype**
```c++
std::pair<iterator, iterator> equal_range(const key_type& key);
std::pair<const_iterator, const_iterator> equal_range(const key_type& key);
```

매개변수로 들어오는 `key` 값을 대상으로 컨테이너의 원소를 탐색 한 후, `lower_bound`와 `upper_bound`의 쌍으로 이루어진 데이터를 반환합니다.

반환 값 `pair`의 `first`는 `lower_bound` 원소를 참조하는 반복자, `second`는 `upper_bound` 원소를 참조하는 반복자입니다.

---
### Allocator

#### `get_allocator` : 메모리 할당 객체 반환.

**prototype**
```c++
allocator_type get_allocator() const;
```

맵 컨테이너가 사용하는 메모리 할당 객체를 반환합니다. 기본적으로 `std::allocator<value_type>`와 같은 객체가 반환됩니다.

---
## 비-멤버 함수 (Non-menber Function)
---
### relation operators

**prototype**
```c++
// operator ==
template <class Key, class T, class Compare, class Alloc>
bool operator==(const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs);
// operator !=
template <class Key, class T, class Compare, class Alloc>
bool operator!=(const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs);
// operator <
template <class Key, class T, class Compare, class Alloc>
bool operator<(const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs);
// operator >
template <class Key, class T, class Compare, class Alloc>
bool operator>(const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs);
// operator <=
template <class Key, class T, class Compare, class Alloc>
bool operator<=(const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs);
// operator >=
template <class Key, class T, class Compare, class Alloc>
bool operator>=(const std::map<Key, T, Compare, Alloc>& lhs, const std::map<Key, T, Compare, Alloc>& rhs);
```

1. `operator==`, `operator!=`

	매개변수로 들어오는 두 맵 컨테이너가 같은지 확인합니다. 맵 컨테이너가 같은 조건은 `원소의 개수(size)`가 같고, `모든 원소의 값이 동일`한 경우 동일한 경우 입니다.

2. `operator<`, `operator>`, `operator>=`, `operator<=`

	두 컨테이너의 대소를 비교합니다. `std::lexicopraphical_compare` 객체를 사용해 두 컨테이너의 원소들을 비교합니다.

---
### std::swap

`std::swap` 맵 컨테이너 템플릿 특수화

**prototype**
```c++
template <class Key, class T, class Compare, class Alloc>
void swap(std::map<Key, T Compare, Alloc>& lhs, std::map<Key, T, Compare, Alloc>& rhs);
```

`std::swap`의 맵 컨테이너용 템플릿 특수화입니다. 두 컨테이너의 모든 구성요소를 바꾸는 함수입니다.

---

## Reference

| index                                                | title                                                       | author       | last modified | accessed      | url status |
| ---------------------------------------------------- | ----------------------------------------------------------- | ------------ | ------------- | ------------- | ---------- |
| [1](https://en.cppreference.com/w/cpp/container/map) | [std::map](https://en.cppreference.com/w/cpp/container/map) | cppreference | 26 Jan, 2022  | 22 June, 2022 | ok         |
| [2](https://www.cplusplus.com/reference/map/map/)    | [std::map](https://www.cplusplus.com/reference/map/map/)    | cplusplus    | unknown       | 22 June, 2022 | ok         |