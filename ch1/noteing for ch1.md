# 1. C와는 다른 C++

***

 ### 자료형

**변수 선언 및 정의**

``` cpp
int a(10);
int b(a);
```

이게 훨씬 c++답게 변수를 선언하는 방법이라는데 잘은 모르겠다



**auto** 

왠지 자주 쓸 것 같다

초깃 값에 형식에 맞춰서, 선언한느 해당 인스턴스의 형식이 자동으로 결정 된다

약간 템플릿? 같은 문법이다



### 동적 할당

new로 할당하고 delete로 해제 한다

주의 할만한 점은 배열은 delete[]로 해제해야 한다

아직 뭔소린지 자세히는 모르겠지만

new는 객체의 생성자를 호출하고, delete는 객체의 소멸자를 호출 한단다



### 참조자(Reference)

포인터와 구조적으로 비슷하며, 선언과 동시에 초기화해야 한다

즉, 참조 원본이 있어야 한다

```cpp
int &ref = nData;
```

상수에는 포인터 사용이 불가능 한 것처럼, 참조자 또한 사용 불가



주의 할 점으로, 겉으로 보기에 전혀 포인터로 보이지 않는 데다는 것이지만

포인터와 참조는 내부 구조상 같다는 것



**r- value 참조**

아직 뭔소린지 잘 모르겠다

상수형 참조라고도 하고

연산 <u>임시 결과</u>로 나타나는 상수를 참조 할 수 있다

```cpp
int &&rdata = nInput * 5;
```



### 범위 기반 for문

반복 횟수를 배열 요소 개수에 맞춰 자동으로 결정한다

```cpp
for(auto n : aList)
    cout<< n << endl;
```

auto연산자를 이용한 문법이다

근데 디테일한 반복이 요구되는 프로그래밍에서는 어울리지 않을듯

처음부터 배열을 만들 때 정형화를 시켜 놓으면 코드가 많이 깔끔해지긴 할 거 같다



***



## 5. Function

***

