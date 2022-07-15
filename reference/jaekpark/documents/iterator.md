# 반복자(Iterator)
## 목차(Contents)

### [1. `iterator`, 반복자란?](#iterator-반복자란)
### [2. `iterator` 클래스](#iterator-클래스)
+ [멤버 타입 (Member types)](#멤버-타입member-types)
### [3. 참고 자료 (Reference)](#reference)
---
# `iterator`, 반복자란?<sup>[[3]](#reference)
> 반복자(iterator)란 STL 컨테이너에 저장된 요소를 `반복적으로 순회`하여, 각각의 `요소에 대한 접근`을 제공하는 객체입니다. 즉, `컨테이너의` `구조`나 `요소의 타입`과는 상관없이 컨테이너에 저장된 데이터를 순회하는 과정을 일반화한 표현입니다.
> 
> 템플릿이 타입과 상관없이 알고리즘을 표현할 수 있게 해준다면, 반복자는 컨테이너와 상관없이 알고리즘을 표현할 수 있게 해주는 것입니다.
> 
> 반복자가 가져야 할 요구 사항과 정의되어야 할 연산자는 다음과 같습니다.
>	1. 가리키는 요소의 값에 접근할 수 있어야 합니다. 따라서 `참조 연산자(*)`가 정의되어야 합니다.
>	2. 반복자 사이의 `대입 연산, 비교 연산`이 가능해야 합니다. 따라서 `대입`, `관계` 연산자가 정의되어야합니다.
>	3. 가리키는 요소의 주변 요소로 이동할 수 있어야 합니다. 따라서 `증가 연산자(++)`가 정의되어야 합니다.
>
> <sub>[출처 : 반복자, TCP school](http://www.tcpschool.com/cpp/cpp_iterator_intro)

---
# `iterator` 클래스<sup>[[1][2]](#reference)

```c++
//iterator Synopsis
template <class Category,
	class T,
	class Distance = ptrdiff_t,
	class Pointer = T*,
	class Reference = T&>
struct iterator {
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};
```
## 멤버 타입(Member types)
+ `Category`

	반복자 종류

	| iterator tag               | Category of iterators  |
	| -------------------------- | ---------------------- |
	| input_iterator_tag         | Input Iterator         |
	| output_iterator_tag        | Output Iterator        |
	| forward_iterator_tag       | Forward Iterator       |
	| bidirectional_iterator_tag | Bidirectional Iterator |
	| random_access_iterator_tag | Random-access Iterator |


+ `T`

	반복자가 가리키는 요소의 데이터 `타입`
+ `Distance`

	두 반복자 간의 `차이`
+ `Pointer`

	반복자가 가리키는 요소의 `포인터`

+ `Reference`

	반복자가 가리키는 요소의 `참조자`

### OCF(Orthodox Canoical Form)

#### 생성자 (Constructor)

#### 소멸자 (Destructor)
  
```iterator(void)
```

#### 복사 대입 연산자 (Copy Assignment Operator)
---
### relation operators
---
## Reference
index|title | author | last modified | accessed | url status
-|-|-|-|-|-
[1](https://www.cplusplus.com/reference/iterator/iterator/?kw=iterator)|[std::iterator](https://www.cplusplus.com/reference/iterator/iterator/?kw=iterator)|cplusplus|unknown|May 09, 2022| ok
[2](https://en.cppreference.com/w/cpp/iterator/iterator)|[std::iterator](https://en.cppreference.com/w/cpp/iterator/iterator)|cppreference|6 Aug, 2021|May 09, 2022| ok
[3](http://www.tcpschool.com/cpp/cpp_iterator_intro)|[반복자](http://www.tcpschool.com/cpp/cpp_iterator_intro)|TCP school|unknown|May 09, 2022|ok