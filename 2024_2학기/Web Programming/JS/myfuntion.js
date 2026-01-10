    // 함수 정의
    // 함수 앞에는 Funtion을 붙어줘야 한다.
    let adder = function (a, b) { // 변수에 함수 넣는것도 가능 [함수이름은 안씀]
        // a = 10 --> 쓰면 안된다!! [내부에서 숫자를 대입하는 것은 안됨 - 원본 유지!] 
        return a + b;
    } // 익명함수 [이름이 없는 함수 : 변수에 저장 가능 - 사용방법 : 일반함수와 같다. (호출 adder(10, 20)] --> 콜백함수

    function subtractor(a, b) {
        return a - b;
    }

    function multiplier(a, b) {
        return a * b;
    }

    function divider(a, b) {
        return a / b;
    }


    // 구구단 함수
    function gugudan(dan) {
        let d = parseInt(dan);
        if (d < 2 || d > 9 || isNaN(d)) { // isNaN : 숫자가 아닌지 확인하는 함수 [숫자가 아니라면 : True , 숫자 라면 :False]
            document.write("잘못 입력하셨습니다. <br>");
            return; // 함수 끝 [리턴 뒤에 아무것도 없으면 함수 끝이라는 의미]
        }

        for (i = 1; i <=9; i++) {
            document.write(d + " X " + i + " = " + d * i + "<br>");
        }
    }