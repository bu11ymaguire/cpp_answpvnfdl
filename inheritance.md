# C++ 다중 상속: 생성자 호출 순서와 접근 제어

## 1\. 생성자 호출 순서 📝

다중 상속에서 부모 클래스 생성자의 실제 호출 순서는 **생성자 초기화 리스트(Initializer List)의 작성 순서가 아닌, 자식 클래스 선언 시의 상속 순서**에 따라 결정됩니다.

### 규칙

객체는 다음과 같은 순서로 생성됩니다.

1.  **부모 클래스 생성**: 클래스 선언부에 나열된 부모 클래스의 순서대로 (`class Child : public ParentA, public ParentB` 라면 `A` -\> `B` 순).
2.  **멤버 변수 생성**: 클래스 내부에 선언된 멤버 변수의 순서대로.
3.  **자식 클래스 생성**: 마지막으로 자식 클래스 자신의 생성자 본문 실행.

**소멸자**는 이와 **정반대의 순서**로 호출됩니다.

### 예시 코드

```cpp
#include <iostream>

class ParentA {
public:
    ParentA() { std::cout << "1. ParentA constructor" << std::endl; }
};

class ParentB {
public:
    ParentB() { std::cout << "2. ParentB constructor" << std::endl; }
};

// ParentA를 먼저 상속, ParentB를 나중에 상속
class Child : public ParentA, public ParentB {
public:
    // 초기화 리스트 순서를 바꿔도(B, A), 실제 호출은 선언 순서(A, B)를 따름
    Child() : ParentB(), ParentA() {
        std::cout << "3. Child constructor" << std::endl;
    }
};

int main() {
    Child c;
}
```

**실행 결과:**

```
1. ParentA constructor
2. ParentB constructor
3. Child constructor
```

-----

## 2\. 부모 생성자의 Private 멤버 접근 🔐

**결론: 가능합니다.** ✅

자식 객체를 생성하는 과정에서 부모 생성자가 호출될 때, 그 생성자는 **부모 클래스의 멤버 함수**로 실행됩니다. 따라서 자신의 `private` 멤버 변수에 자유롭게 접근하여 초기화할 수 있습니다.

### 핵심 원리

  - 생성자는 클래스의 특별한 **멤버 함수**입니다.
  - 클래스의 멤버 함수는 해당 클래스의 `private` 멤버에 접근할 권한을 가집니다.
  - 자식 클래스에서 부모 생성자를 호출하는 것은, 부모의 초기화 책임을 부모에게 위임하는 것입니다.

### 예시 코드

```cpp
#include <iostream>

class Parent {
private:
    int private_value; // Parent만 접근 가능한 private 멤버

public:
    // 생성자는 Parent의 멤버 함수이므로 private_value에 접근 가능
    Parent(int val) : private_value(val) {
        std::cout << "Parent's private_value initialized to: " << private_value << std::endl;
    }
};

class Child : public Parent {
public:
    Child(int val) : Parent(val) { // 부모 생성자 호출
        // std::cout << private_value; // 컴파일 에러! 자식은 부모의 private에 접근 불가
    }
};

int main() {
    Child c(42);
}
```

**실행 결과:**

```
Parent's private_value initialized to: 42
```
