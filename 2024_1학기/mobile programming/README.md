# mobile programming Codes

**2024년 1학기 모바일프로그래밍** 수업의 실습 및 과제 소스코드 저장소입니다.
<br>

## 📂 Source Code Index

| 폴더 (주차) | 파일명 | 주제 | 설명 |
|:---:|:---|:---|:---|
| **week_04** | `Animal.java` | **추상 클래스** | abstract 키워드 기반의 요약 클래스 정의 |
| | `Automoile.java` | **클래스 상속** | super 키워드를 이용한 상속 및 생성자 처리 |
| | `Car.java` | **클래스 기초** | 필드, 생성자 및 static 변수/메소드 활용 실습 |
| | `MainActivity.java`| **객체 활용** | 안드로이드 로그(Log)를 통한 객체 생성 결과 확인 |
| | `Tiger.java` | **추상 구현** | 추상 클래스를 상속받아 미구현 메소드 구체화 |
| | `iAnimal.java` | **인터페이스** | interface 선언을 통한 다중 상속 기반 마련 |
| **week_05** | **[Calculator]** | **사칙연산기** | 형변환 및 터치 이벤트를 이용한 계산기 구현 |
| | `MainActivity.java`| **연산 로직** | OnTouchListener 기반 사칙연산 및 예외 처리 |
| | `activity_main.xml`| **UI 레이아웃** | LinearLayout 기반 버튼 및 입력창 수직 배치 |
| | **[Photoapp]** | **사진 보기 앱** | 체크박스 및 라디오버튼 기반 이미지 전환 실습 |
| | `MainActivity.java`| **선택 로직** | 상태 변경 리스너를 통한 실시간 사진 변경 |
| | `activity_main.xml`| **UI 레이아웃** | 위젯 가시성(visibility) 제어를 포함한 설계 |
| **week_06** | **[Only JAVA]** | **동적 UI 생성** | XML 없이 자바 코드로만 화면 레이아웃 구성 |
| | `MainActivity.java`| **레이아웃 코딩** | 코드를 이용한 위젯 생성 및 속성 정의 실습 |
| | **[TableLayout]** | **격자형 계산기** | TableLayout을 활용한 숫자 패드 계산기 구현 |
| | `MainActivity.java`| **버튼 배열 처리** | 배열과 반복문을 이용한 숫자 버튼 이벤트 바인딩 |
| | `activity_main.xml`| **표 형식 레이아웃** | TableRow를 이용한 숫자 및 연산 버튼 정렬 |
| **week_07** | **[TextView]** | **자동 완성 텍스트** | 데이터 연결을 통한 자동 완성 텍스트뷰 실습 | 
| | `MainActivity.java`| **어댑터 연결** | ArrayAdapter와 Tokenizer를 이용한 목록 제어 |
| | `activity_main.xml`| **자동 완성 UI** | AutoComplete 위젯 및 힌트 속성 정의 |
| | **[dpick,tpick]** | **예약 기능 앱** | 날짜 및 시간 선택 위젯 활용 실습 |
| | `MainActivity.java`| **시간 예약 로직** | Chronometer 제어 및 위젯 가시성 동적 전환 구현 |
| | `activity_main.xml`| **피커 UI 구성** | DatePicker와 TimePicker를 FrameLayout에 배치 |
| **week_09** | **[ActionBar, Fragment]** | **액션바 및 프래그먼트** | 탭 메뉴를 이용한 화면 전환 및 데이터 전달 실습 |
| | `MainActivity.java` | **액션바/탭** | 액션바 내비게이션 모드 설정 및 탭 리스너 구현 |
| | `MyTabFragment.java` | **프래그먼트** | Bundle을 통한 데이터 전달 및 배경색 동적 변경 |
| | **[WebView]** | **웹 브라우저** | WebView 위젯을 활용한 앱 내 웹 페이지 출력 |
| | `MainActivity.java`| **웹 제어 로직** | WebViewClient 설정 및 자바스크립트 활성화 실습 |
| | `activity_main.xml`| **브라우저 UI** | URL 입력창(EditText) 및 이동/이전 버튼 배치 |
| **week_10** | **[Journal app]** | **일기장 앱** | 내장 메모리 파일 입출력을 이용한 일기장 구현 |
| | `MainActivity.java` | **파일 입출력 로직** | FileInputStream/OutputStream 기반 일기 저장 및 읽기 |
| | `activity_main.xml` | **일기장 UI** | DatePicker(스피너 모드) 및 일기 입력창 배치 |
| | **[User Input App]** | **사용자 정보 입력** | 대화 상자와 커스텀 토스트를 이용한 데이터 입력 |
| | `MainActivity.java` | **대화 상자 로직** | AlertDialog를 통한 입력값 획득 및 뷰 업데이트 |
| | `activity_main.xml` | **메인 UI** | 사용자 정보를 표시할 TextView 및 버튼 배치 |
| | `dialog1.xml` | **커스텀 대화 상자** | 이름과 이메일 입력을 위한 레이아웃 설계 |
| | `toast1.xml` | **커스텀 토스트** | 이미지와 텍스트를 조합한 빨간색 토스트 UI |
| **week_11** | `LoginActivity.java` | **로그인 로직** | 이메일/비밀번호 인증 및 메인 화면 전환 처리 |
| | `MainActivity.java` | **회원정보 관리** | DB 데이터 조회(ValueEventListener) 및 정보 수정 |
| | `RegisterActivity.java`| **회원가입 로직** | 신규 계정 생성 및 사용자 프로필 DB 저장 구현 |
| | `UserAccount.java` | **데이터 모델** | 사용자 정보(UID, 이메일, 닉네임 등) VO 클래스 |
| | `activity_login.xml` | **로그인 UI** | 이메일/비밀번호 입력창 및 로그인 버튼 배치 |
| | `activity_main.xml` | **메인 UI** | 회원정보 출력, 수정 및 로그아웃 인터페이스 |
| | `activity_register.xml`| **회원가입 UI** | 상세 프로필 입력을 위한 회원가입 양식 설계 |
| **week_12** | `MainActivity.java` | **그래픽 구현 로직** | 터치 이벤트 기반 선 및 원 그리기 기능 구현 |
| | `activity_main.xml` | **메인 UI** | 기본 텍스트뷰를 포함한 메인 화면 레이아웃 |
| **week_13** | **[GoogleMap]** | **구글 지도 앱** | Google Maps API를 이용한 지도 제어 및 마킹 |
| | `MainActivity.java` | **지도 제어 로직** | 카메라 이동, 줌 제어 및 클릭 이벤트 오버레이 구현 |
| | `activity_main.xml` | **지도 뷰 UI** | MapFragment를 이용한 전체 화면 지도 배치 |
| | **[ListView]** | **리스트뷰 앱** | 데이터 동적 추가 및 삭제가 가능한 리스트 구현 |
| | `MainActivity.java` | **리스트 제어 로직** | ArrayAdapter를 이용한 아이템 추가 및 롱클릭 삭제 |
| | `activity_main.xml` | **리스트 UI** | EditText, Button 및 ListView 위젯 배치 |
| **week_14** | `MainActivity.java` | **상태 감지 로직** | BatteryManager를 통한 충전량 및 전원 연결 확인 |
| | `activity_main.xml` | **배터리 UI** | 상태별 배터리 이미지 및 정보 표시 EditText 배치 |
