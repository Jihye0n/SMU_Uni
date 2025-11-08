// 자바 클래스 생성
package com.example.myapplication4;

public class Car {
    private int spead; // 변수 생성
    private String color; // 변수 생성
    static int carCount = 0; // ! 클래스가 생성될 때 한 번만 실행 !

    public static int getCarCount() { // 9번줄 static 을 지우면 에러가 난다. !!중간고사 나옴 !!
        return carCount;              // 에러나오는 이유 - 변수를 조작하는 함수는 static으로 하면 안된다.
    }                                 // static으로 만들어져있는 펑션은 static의 관련된 펑션만 쓴다.

    // 클래스 변수 초기화
    public Car() {  carCount++; }

    public Car(int spead) { this.spead = spead; } // spead int 초기화 (this가 없으면 지역변수이다.)
    public Car(String color) { this.color = color; } // String color 초기화

    public Car(int spead, String color) {
        this.spead = spead;
        this.color = color;
        carCount++;
    }

    public int setUpSpead() {
        return spead;
    }
    public int setDownSpead() {
        return spead;
    }
    public String getColor() {
        return color;
    }

    public void setSpead(int spead) {
        this.spead = spead;
    }
}
