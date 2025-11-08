package com.example.myapplication4;

public class Automoile extends Car{ // 자동차꺼 그대로 끌어와서 쓴다.
    private int seat;

    public Automoile(int spead, String color, int seat) {
        super(spead, color); // super : 상위클래스에 있는 생성자를 처리
        this.seat = seat;
    }
    public Automoile(int seat) {
        this.seat = seat; // 내꺼만 초기화
    }
    public void setSpead(int spead) { // Car에서 확장해서 가져오면 내꺼가 된다.
        super.setSpead(spead);
    }
    public int getSeat() {
        return seat;
    }
}
