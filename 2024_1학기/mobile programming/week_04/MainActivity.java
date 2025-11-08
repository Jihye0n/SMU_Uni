package com.example.myapplication4;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button; // xml에 하드코딩 되어 있는 값을 메인에 버튼이라는 위젯을 연동

public class MainActivity extends AppCompatActivity {
    Button naverpage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        naverpage = (Button) findViewById(R.id.naverpage);

        naverpage.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Car myCar1 = new Car();
                Car myCar2 = new Car();
                Car myCar3 = new Car();
                Automoile myAuto1 = new Automoile(4);
                Automoile myAuto2 = new Automoile(100, "흰색", 4);

                String str = " 안녕하세요   ";
                Log.d("test1","carCount = " +str);
                str = str+" 반갑습니다~! "; // set 기능이 없다. 그 이유는 연산자 오버로딩이 되어 있기 때문이다.
                Log.d("test1","carCount = " +str);
                str = str.trim(); // 공백 제거
                Log.d("test1","carCount = " +str);

                Log.d("test1","carCount = " +Car.carCount);

            }
        });

    }
}