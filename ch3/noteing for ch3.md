# 클래스



### 객체지향 프로그래밍

객체란 백수들과 그와 관련된 메서드들이 모여서 이룬 하나의 꾸러미다

그리고 그 객체라는 걸 구현할 문법이 클래스이다



객체를 더욱 안전하고 유연하게 만들기 위해 만들어진 문법이 클래스이다

이런저런 규약이나, 당장 받아들여지지 않을 문법이 많을 수도 있다

대부분의 문법이 다수의 사용자(클래스를 가져다 사용하는)를 배려하는 차원에서 만들어진다

사용자의 편의성을 극대화하고

사용자의 실수 가능성을 제작자가 차단해야 한다



기본적인 발단은 앞서 말했지만, 제작자와 사용자의 관점을 분리해서 생각한다는 것



이때, <u>인터페이스</u>라는 객체지향 사고에서 중요한 개념이 등장한다

출력을 위한 구체적인 방법을 사용자가 굳이 알아야 할 필요가 없다는 것이다

이를 보완하는 것을 인터페이스 함수라고 한다



### 클래스 기본 문법

정말 일차원적으로 생각하면 함수가 들어간 구조체라고 생각해도 된다

그리고 추가적으로 접근 제어 지시자라는 게 추가로 들어간다

```cpp
class Test
{
	public:
    
    int data;
    
    void Method(void)
    {
        cout<<data<<endl;
    }
}
```

이때 data는 메서드 안에 선언된 지역변수가 아닌 <u>멤버 변수</u>이다



보통 생성자를 통해 멤버 변수를 초기화한다

생성자는 사용자가 객체를 선언하면 자동으로 호출되고

별도로 초기화 코드를 기술하지 않더라도 생성자 함수에서 규정한 값으로 멤버가 자동으로 초기화된다

```cpp
class Test
{
	public:
    
    int data;
    
    Test()
    {
        data = 10;
    }
}
```

물론 그냥 멤버 변수를 선언하면서 초기화 해도 된다



아니면 생성자 초기화 목록을 활용 할 수 있다

```cpp
class Test
{
	public:
    
    int data;
    
    Test() : data(10)
    {
        cout<<data<<endl;
    }
}
```

참고로 멤버 변수가 참조자 형식이면 그냥 무조건 이 초기화 목록을 이용해야 한다고 한다



**접근 제어 지시자**

제작자 스스로 자신이 만든 클래스의 특정 요소에 사용자가 접근할 수 없게 하는 도구다

대충 아이폰이 분해 안되게 해놓은 것과 비슷한 논리이다

불필요한 클래스의 코드 사용을 인식하고 사용자가 이용할 수 있는 코드를 제한 하는 것이

클래스 제작자의 몫이기 때문

- public : 멤버에 관한 모든 외부 접근 허용
- protected : 파생 클래스 제외 멤버에 관한 모든 외부 접근 차단
- private : 멤버에 관한 모든 외부 접근 차단 (디폴트)



멤버 변수에 대한 직접 접근을 차단 하더라도,

해당 클래스의 멤버 함수에 경우 접근이 자유롭다

이때 등장하는 개념이 인터페이스 함수이다

이를 통해 데이터 흐름을 통해하는 것임



### 생성자와 소멸자

생성자와 소명자는 객체가 생성 및 소멸될 때 자동으로 호출되는 함수이다

반환 형식이 없고, 함수 이름이 클래스 이름과 같다는 게 특징

생성자는 같은 용도의 다중 정의가 가능 하지만,

소멸자는 불가능 하다(별도로 소멸되기 때문)



제작자가 생성자와 소멸자를 만들지 않아도

컴파일러가 알아서 만든다 이름 디폴스 생성자라고 한다

즉, 생성자와 소멸자가 없는 클래스는 없다



- main() 함수가 호출되기 전에 생성자가 호출될 수 있다(전역변수로 객체 선언)
- 생성자는 다중 정의 가능
- 소멸자는 다중 정의 불가능
- main() 함수가 끝난 후에 소멸자가 호출 될 수 있다
- 생성자와 소멸자는 생략할 경우 컴파일러가 알아서 만든다



객체의 생성시기와 소멸시기를 정확히 파악 할 필요가 있다

생성시기는 당연히 객체를 선언한 시기다, 이때 main 함수 보다도 먼저 생성 될 수 있다

소멸시기는 해당 객체의 데이터 반환 시기이다 지역 변수의 경우 해당 블록 범위가 끝날 때라고 할 수 있다

그리고 물론, new로 생성하고 delete로 메모리를 해제하는 동적 객체의 생성과 소멸은 당연히 그 시기가 일치한다



**참조 형식 멤버 초기화**

앞서 멤버 변수가 참조자 형식이면 반드시 생성자 초기화 목록을 사용해야 한다고 했다

참조자 형식은 선언과 동시에 초기화를 해줘야 하는데

생성자 초기화 목록을 사용하면

객체 생성시기와 생성자에서 일어나는 멤버 변수 초기화가 직접적으로 연달아 일어나기 때문인 듯

```cpp
class CRefTest
{
    int &m_nData;
    
    public:
    CRefTest(int &rParam) : m_nData(rParam) { }
}
```

이때 생성자 함수의 매개 변수 (rParam) 또한 참조자 형식으로 선언 한 것을 볼 수 있는데

rParam은 함수가 반환 될 때 자동으로 소멸 되기 때문에

참조자 형식으로 선언해서 생성자 매개 변수를 통한 데이터 전달 과정에서 길을 잃지 않게 끔 해주기 위함이다

즉, 참조형식을 통해 주소를 전해준다면 생성자 매개 변수가 소멸 되어도 값을 사용 할 수 있기 때문이다

데이터 -> ~~&rParam~~ -> &m_nData



항상 참조자를 사용 할 때 대상을 반드시 규정해야 하고, 중간에 원본 대상을 바꿀 수 없다는 걸 기억하자



**생성자 다중 정의**

일반 함수 다중정의랑 별 다른건 없다

근데 이러면 번거로울 뿐만 아니라 골치 아픈 버그?를 만들어 낸다고 한다

그래서 등장한 문법이 생성자 위임이다

```cpp
class Test
{
    int data1 = 0;
    int data2 = 0;
    
    public:
    Test(int x)
    {
        if(x>100) x=100;
        data1 = x;
    }
    
    Test(int x, int y) : Test(x)
    {
        if(y>200) y = 200;
        data2 = y;
    }
}
```

생성자를 추가 호출 하는 방식이라고 하는데 뭔소린지는 모르겠다

어쨌든 대충 이미 정의된 코드를 복붙해와서 향후 유지 보수의 능률을 올려준단다



**명시적 디폴트 생성자**

```cpp
class Test
{
    CTest(void) = default;
}
```

말그대로 <u>디폴트 생성자가 존재 한다는 걸 명시</u>하는 문법이다

물론 굳이 명시하지 않아도 디폴트 생성자는 컴파일러가 알아서 생성해주지만

어쨌든 아직은 잘 모르지만 선언과 정의를 따로 할 필요 없이 명시해 줄 수 있다

명시한다는 거 자체에 의의가 있는 듯



```cpp
CTest(void) = delete
```

비슷한 맥락에서 이미 다른 생성자를 생성해서

디폴트 생성자가 없는 클래스에 경우

<u>디폴트 생성자가 없다고 명시</u>해 줄 수도 있다



### 메서드

클래스가 제공하는 기능을 실행하는 방법으로 주로 쓰인다

사용자와 클래스 제작자를 이어주는 역할을 한다

때문에 멤버함수 보다는 주로 메서드 또는 인터페이스 함수라고 불린다

``` cpp
static int CTest::GetParam(void) const
```

원형은 위와 같다 static과 const는 생략 가능하며 뒤에서 설명한다



**this 포인터**

작성 중인 클래스의 실제 인스턴스에 대한 주소를 가리키는 포인터이다

설명하기 까다롭지만 어려운 개념은 아니다

말 그대로 선언한 인스턴스에 대해 개별적으로 해당 클래스에 접근하는 걸 뜻한다



안써도 큰 문제는 되지 않지만 

범위 지정 연산자를 통해 소속을 정확히 명시 할 수 있다

되도록이면 그냥 쓰자

``` cpp
class CTest
{
    int m_nData;
public:
    CTest(int nParam) : m_nData(nParam){};
    void PrintData()
    {
        cout << this->m_nData << endl;
    }
}
```



**상수형 메서드**

```cpp
int GetData() const {};
```

대충 이렇게 뒤에 const가 붙은 걸 상수형 메서드라고 한다

일반적인 상수의 개념과 다르지 않다

저렇게 뒤에 const가 붙으면 **수정은 불가하고 읽기만 가능하다** 

그리고 상수형 메서드가 아닌 메서드를 호출 할 수 없다

당연히 const를 붙일 수 있는 메서드라면 무조건 붙여주는게 좋다



mutable, const_cast<>를 통해 상수형 메서드의 예외 처리를 할 수 있다

```cpp
class Test
{
    mutable int data = 0;
public:
    int GetData() const
    {
        data = 20;
        return data;
    }
}
```

```cpp
void TestFunc(const int &nParam)
{
    int &nNewParam = const_cast<int &>(nParam);
    nNewParam = 20;
}
```





**상수지시포인터, 상수포인터, 상수지시상수포인터, 포인터상수**

``` cpp
const char* test = "abc"; //상수지시포인터
char* test const = "abc"; //상수포인터
const char* test const = "abc"; //상수지시포인터상수
char ary[] = "abc"; //포인터상수
```

상수형 메서드 개념을 공부하다가 헷갈려서 상수 관련 개념을 다시 공부해봤다

이 위에 4개가 다 다르다고 한다.....



4번째 포인터상수는 그냥 배열이라고 생각하면 된다 <u>주소는 바뀔 수 없고, 대상체는 바뀐다</u>



1번째 상수지시포인터는 말 그대로 상수를 지시 할 수 있는 포인터다

<u>주소, 대상체 모두 바뀔 수 있고, 상수를 지시 할 수 있다</u>

최신 컴파일러에서 일반포인터로 상수를 지시하면 경고가 뜬다



2번째 상수포인터는 일반 상수 개념과 다르지 않다 선언과 동시에 지시해야하며

<u>주소, 대상체 모두 바뀔 수 없다</u>

이 또한 상수를 가리키면 경고가 뜬다



3번째 상수지시포인터상수 1번과 2번 제약의 짬뽕이다

<u>주소, 대상체 모두 바뀔 수 없다. 상수를 지시 할 수 있다</u>



**멤버 함수의 다중 정의**

함수 다중 정의랑 방법은 똑같다 

이 챕터에서 주로 다루는 내용은 다중 정의로 예외처리를 하는 부분이다

정수형만 받기 위해 실수형은 0으로 받는 방법과

delete 예약어로 자의적으로 에러를 발생시키는 것이다

``` cpp 
//실수형은 0으로 할당
void SetData(double dParam){m_nData = 0;}

//delete 예약어 사용
void SetData(double dParam) = delete;
```

어설프게 살아서 작동하는 코드가 더 심각한 문제를 만든다는 점에서

첫 번째 방법보다 두 번째



### 정적 멤버

전역 변수나 전역 함수랑 기능은 같다

근데 어쨌든 전역 변수나 전역 함수를 남발하면 굉장히 프로그래밍 과정이 불리해지기 때문에

클래스 안에 종속시켜 놓는 것이다



클래스 안에 좋속되어 있긴 하지만 

클래스만 명시한다면 인스턴스를 선언하지 않고 직접 호출 할 수 있다

this 포인터를 사용할 수 없고 반드시 선언과 정의를 분리해야 한다

```cpp
class Test
{
    int m_nData;
    static int m_nCount;
public:
    CTest(int nParam) : m_nData(nParam) {m_nCount++;}
    int GetData() {return m_nData;};
    void ResetCount() {m_nCount=0;};
    
    static int GetCount()
    {
        return m_nCount;
    };
};

int Test::m_nCount = 0;

int main()
{
    Test a(5), b(10);
    cout<<Test::GetCount()<<endl;
}
```

