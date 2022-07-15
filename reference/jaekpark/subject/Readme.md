# ft_containers
	C++ containers, easy mode

Summary: 

>The standard C++ containers have all a specific usage.
>To make sure you understand them, let’s re-implement them!

	C++ 컨테이너는 종류에 따라 각기 다른 특징을 가지고 있고, 컨테이너를 잘 이해하고 있는 프로그래머는 상황에 따라 적합한 컨테이너를 사용해 문제를 효과적으로 해결 할 수 있습니다.

	따라서 C++ STL(Standard Template Library)에서 제공하는 컨테이너들의 올바른 이해를 위해 이를 재구현해봅시다.

## Contents

- [ft_containers](#ft_containers)
	- [Contents](#contents)
	- [1. Objectives](#1-objectives)
	- [2. 기본 규칙 (Geneal rules)](#2-기본-규칙-geneal-rules)
	- [3. 필수 구현 파트 (Mandatory part)](#3-필수-구현-파트-mandatory-part)
		- [3.1 요구 사항 (Requirements)](#31-요구-사항-requirements)
		- [3.2 테스트 (Testing)](#32-테스트-testing)
	- [4. 보너스 파트 (Bonus part)](#4-보너스-파트-bonus-part)
	- [5. 제출 및 동료 평가 (Submission and peer-evaluation)](#5-제출-및-동료-평가-submission-and-peer-evaluation)

## 1. Objectives

> In this project, you will implement a few container types of the C++ standard template library. 
> You have to take the structure of each standard container as reference. If a part of the Orthodox Canonical form is missing in it, do not implement it.
> As a reminder, you have to comply with the C++98 standard, so any later feature of the containers MUST NOT be implemented, but every C++98 feature(even deprecated ones) is expected.

이번 프로젝트의 목표는 C++ STL에 포함된 몇가지 컨테이너를 직접 구현하는 것입니다. 각 컨테이너는 C++ 표준 컨테이너와 같은 구조로 구현해야 합니다. 만약 해당 컨테이너가`OCF(Orthodox Canonical Form)`를 따르지 않는다면, 우리 역시 마찬가지로 구현해야 합니다. 재차 강조하지만 기준이 되는 C++ 표준 버전은 `C++98` 표준입니다. 따라서 `C++98`이 아닌 최근 버전에서 제공되는 기능들은 포함되어선 안됩니다. 하지만 `C++98`에 포함되는 모든 기능들은 최근 표준에서는 `사용되지 않는(Deprecated)` 것일지라도 반드시 구현해야합니다.

## 2. 기본 규칙 (Geneal rules)

> **Compiling**
> + Compile your code with `c++` and the flags `-Wall -Wextra -Werror`
> + Your code should still compile if you add the flag `-std=c++98`


> **Formatting and naming conventions**
> + For each container, turn in the appropriately named class files.
> + Goodbye `Norminette`! No coding style is enforced. You can follow your favorite one.
> But keep in mind that a code your peer-evaluators can’t understand is a code they can’t grade. Do your best to write a clean and readable code.

**컴파일**
+ 컴파일러는 `c++` 를 사용해야하고 컴파일 플래그로 `-Wall -Wextra -Werror`를 사용해야합니다.
+ `-std=c++98` 플래그를 사용해 컴파일 했을 때도 문제가 없어야합니다.
  
**포맷팅과 네이밍 컨벤션**
+ 각 컨테이너에 대해 적절한 이름으로 명명된 클래스 파일들을 제출해야 합니다. 
  + `예 : header file for class Vector -> Vector.hpp`
+ `norminette`은 더 이상 사용하지 않습니다. 특별히 강제되는 코딩 스탠다드는 없기 때문에 원하는 표준에 따라 코드를 작성해도 좋습니다. 하지만 동료 평가시 평가자가 평가를 진행하기 힘들 정도로 이해하기 어려운 난잡한 코드는 평가 받을 수 없습니다. 최선을 다해 가독성이 좋은 클린 코드를 작성하도록 해봅시다.

> **Allowed/Forbidden**
> 
> You are not coding in C anymore. Time to C++! Therefore:
> + You are allowed to use everything from the `standard library`. Thus, instead of sticking to what you already know, it would be smart to use as much as possible the `C -ish versions` of the C functions you are used to.
> + However, you can’t use any other external library. It means `C++11` (and derived forms) and `Boost libraries` are **forbidden**. The following functions are forbidden too:` *printf()`, `*alloc()` and `free()`. If you use them, your grade will be 0 and that’s it.

**허용/금지**
+ C++ `표준 라이브러리`에 포함되어있는 함수는 모두 사용 할 수 있습니다. 따라서 우리가 기존 `C`에서 사용했던 함수들을 사용하기 보다는 같은 기능을 하는 `C++ 버전`의 함수를 사용하는 것이 좋습니다.
+ 그러나 `C++11` 에서 새롭게 제공하는 함수들이나 `Boost 라이브러리`와 같은 외부 라이브러리는 **사용할 수 없습니다**. 또한 `C`에서 사용되는 `*printf()`, `*alloc()`, `free()` 함수도 사용을 금지합니다. 만약 이 규칙을 어길 경우 평가 점수는 0점입니다.


> **A few design requirements**
> + `Memory leakage` occurs in C++ too. When you allocate memory, you must avoid memory leaks.
> + Any function implementation put in a header file (except for `function templates`) means 0 to the exercise.
> + You should be able to use each of your headers independently from others. Thus, they must include all the dependencies they need. However, you must avoid the problem of `double inclusion` by adding `include guards`. Otherwise, your grade will be 0.

**설계 요구사항**
+ C++ 에서도 `메모리 누수`는 발생 할 수 있습니다. 만약 동적 메모리 할당을 사용한 경우 메모리 누수가 발생하지 않도록 구현해야합니다.
+ `함수 템플릿`을 제외한 일반 함수는 헤더 파일에 구현 할 수 없습니다. 헤더 파일에 일반 함수의 구현이 포함된 경우 평가 점수는 0점입니다.
+ 각 헤더 파일은 독립적으로 사용 가능하도록 구성해야합니다. 따라서 헤더 파일은 파일에 포함된 기능들이 동작하도록 하는 모든 의존성을 포함해야 합니다. 다만 `헤더파일 중복선언(double inclusion)` 문제를 피하기 위해 각 헤더 파일에 `include guards`를 추가해야 합니다. 그렇지 않을 경우 평가점수는 0점입니다.
  + `include guard macro`<sub> 역자 주
	```c
	// File name : foo.h
	#ifndef FOO_H // include guard
	#define FOO_H
		// something ...
	#endif
	```

> **Read me**
> + You can add some additional files if you need to (i.e., to `split your code`) and organize your work as you wish as long as you turn in the mandatory files.
> + By Odin, by Thor! Use your brain!!!

**Read me**
+ 필요한 경우 추가적인 파일을 포함(즉, `코드 분할`을 위한 파일)해 제출 할 수 있습니다. `Mandatory`에서 요구하는 필수 파일만 제출 한다면 추가적인 구성은 자유롭게 할 수 있습니다.
+ 자, 머리 한번 써봅시다.


	> Since your task here is to recode the STL containers, you of course cannot use them in order to implement yours.

	> 당연한 일이겠지만, 이번 과제는 STL 컨테이너를 직접 구현해보는 것이기 때문에 C++ STL Container는 사용 할 수 없습니다.

## 3. 필수 구현 파트 (Mandatory part)

> Implement the following containers and turn in the necessary `<container>.hpp` files:

아래에 기재된 컨테이너를 구현하고 `<컨테이너 이름>.hpp`의 형식으로 파일을 작성합니다.

+ `벡터 (vector)`
	
	>	You don’t have to do the `vector<bool>` specialization.
	
	`vector<bool>` 타입에 대한 템플릿 특수화를 구현할 필요는 없습니다.
	
+ `맵 (map)`

+ `스택 (stack)`

  	> It will use your vector class as default underlying container. But it must still be compatible with other containers, the STL ones included.
	
	`vector` 클래스를 기반으로 작성해야 합니다. 하지만 다른 컨테이너와 호환 가능하도록 작성해야 합니다.

	> You can pass this assignment without the stack (80/100). But if you want to do the bonus part, you have to implement the 3 mandatory containers: vector, map and stack.

	> 이번 과제는 스택을 구현하지 않아도 벡터와 맵이 문제 없을 경우 80/100점으로 통과가 가능합니다. 하지만 보너스 파트를 평가받으려면 vector, map, stack 이 세 종류의 컨테이너는 반드시 구현해야합니다.

> You also have to implement:

아래의 항목 또한 구현해야합니다.

+ `iterators_traits`
+ `reverse_iterator`
+ `enable_if`

	> Yes, it is `C++11` but you will be able to implement it in a `C++98` manner.
	> This is asked so you can discover `SFINAE`.

	네 이는 `C++11` 표준 부터 제공되는 기능이지만, `C++98` 표준으로도 구현이 가능합니다.

	`SFINAE`가 무엇인지 알아보도록 합시다.

+ `is_integral`
+ `equal and/or lexicographical_compare`
+ `std::pair`
+ `std::make_pair`

### 3.1 요구 사항 (Requirements)
> + The namespace must be `ft`.
+ `namespace`는 `ft`로 정의합니다.
> + Each inner data structure used in your containers must be logical and justified (this means using a `simple array` for `map` is not ok).
+ 컨테이너 구현에 사용되는 내부 자료구조는 논리적이고 타당해야합니다. 이 말은 `map` 구현을 위해 `단순 배열`을 사용 할 수 없음을 의미합니다.
> + You **cannot** implement `more public functions` than the ones offered in the standard containers. Everything else must be `private` or `protected`. Each public function or variable must be justified.
+ C++ 표준 컨테이너에 정의된 것 외의 추가 `public` 멤버 함수는 구현할 수 없습니다. 표준의 퍼블릭 멤버 함수를 제외한 모든 구성 요소는 `private` 혹은 `protected` 접근 제한자로 보호해야 합니다. 각 `public` 멤버 함수나 변수는 선언하는데 타당한 이유가 있어야 합니다.
> + All the member functions, non-member functions and `overloads` of the standard containers are expected.
+ 모든 멤버 함수 혹은 비-멤버 함수는 표준에서 구현 된것과 동일하게 `오버로드` 해야합니다.
> + You must follow the `original naming`. Take care of details.
+ 위 요소들의 명명 규칙은 표준과 동일하게 구성해야합니다. 세부 사항을 잘 확인합니다.
> + If the container has an `iterator` system, you must implement it.
+ 컨테이너에 `반복자(iterator)`가 구현된 경우 동일하게 구현합니다.
> + You must use `std::allocator`.
+ 메모리 할당은 `std::allocator`를 사용해야합니다.
> + For non-member `overloads`, the keyword `friend` is allowed. Each use of friend must be justified and will be checked during evaluation.
+ `비-멤버 함수의 오버로딩`에 `friend` 키워드를 사용할 수 있습니다. 이 때 사용 이유가 타당해야하며 이는 동료 평가시 검증할 수 있어야 합니다.
> + Of course, for the implementation of `map::value_compare`, the keyword `friend` is allowed.
+ 물론 `map::value_compare`를 구현할때 `friend` 키워드를 사용 가능합니다.


	> You can use https://www.cplusplus.com/ and https://cppreference.com/ as references.
	
	> https://www.cplusplus.com/ 과 https://cppreference.com/ 을 참고할 수 있습니다.

### 3.2 테스트 (Testing)
> + You must also provide tests, at least a main.cpp, for your defense. You have to go further than the main given as example!
+ 동료 평가 디펜스를 위해 기본으로 주어지는 `main.cpp` 외의 추가적으로 작성된 파일을 반드시 제출해야 합니다.
> + You must produce two binaries that run the same tests: one with your containers only, and the other one with the STL containers.
+ 기존 C++ 표준 컨테이너와 비교하기 위해 표준 컨테이너로 컴파일 한 실행파일과 직접 구현한 컨테이너로 컴파일 한 실행파일을 만들 수 있도록 구성해야합니다.
> + Compare outputs and performance / timing (your containers can be up to 20 times slower).
+ 출력 결과와 성능(20배 정도 차이 내)을 비교해봅시다.
> + Test your containers with: `ft::<container>`.
+ 위 규칙에 따라 직접 구현한 컨테이너는 `ft::<container>` 형식으로 테스트 할 수 있어야 합니다.

	> A main.cpp file is available to download on the intranet project page.

	> main.cpp 파일은 인트라넷의 프로젝트 페이지에서 다운로드 할 수 있습니다.

## 4. 보너스 파트 (Bonus part)

> You will get extra points if you implement one last container:

`set` 컨테이너를 구현해 추가 점수를 받을 수 있습니다.

+ set
	
	> But this time, a `Red-Black tree` is mandatory.

	`레드-블랙 트리`를 기본으로 구현하도록 합니다.

> The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

> 보너스 파트는 기본 파트의 구현이 완벽한 경우에만 평가를 진행 할 수 있습니다. 완벽의 의미는 필수 구현 파트의 모든 부분 (stack을 포함한)이 제출 되었고, 오작동 없이 잘 동작한 경우를 말합니다. 만약 필수 구현 파트에서 요구하는 부분에서 통과하지 못한 경우, 보너스 파트는 평가를 진행 할 수 없습니다.

## 5. 제출 및 동료 평가 (Submission and peer-evaluation)

> Turn in your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don’t hesitate to double check the names of your files to ensure they are correct.

항상 그랬듯이 프로젝트 깃 리포지토리에 과제를 제출합시다. 평가는 해당 깃 리포지토리 안에서만 진행됩니다. 올바른 파일이름으로 제출했는지 꼭 다시 한번 확인 해야합니다.