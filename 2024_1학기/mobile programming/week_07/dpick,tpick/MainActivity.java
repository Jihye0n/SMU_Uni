package com.example.myapplication7;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.os.SystemClock;
import android.view.View;
import android.widget.Button;
import android.widget.CalendarView;
import android.widget.Chronometer;
import android.widget.DatePicker;
import android.widget.RadioButton;
import android.widget.TextClock;
import android.widget.TimePicker;

// @SuppressWarnings("deprecation") -> 지원 종료된 클래스를  쓸 때

public class MainActivity extends AppCompatActivity {

    /*
    AnalogClock aclock; -> 지원 종료되어 못 쓴다.
    DigitalClock dclock; -> 지원 종료되어 못 쓴다.
    TextClock tclock;
    CalendarView cpick;
    */

    Chronometer cho1;
    Button btn;
    RadioButton rdodata, rdotime;
    DatePicker dpick;
    TimePicker tpick;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // tclock = (TextClock) findViewById(R.id.tclock);
        cho1 = (Chronometer) findViewById(R.id.cho1);
        btn = (Button) findViewById(R.id.btn);
        rdodata = (RadioButton) findViewById(R.id.rdodata);
        rdotime = (RadioButton) findViewById(R.id.rdotime);
        dpick = (DatePicker) findViewById(R.id.dpick);
        tpick = (TimePicker) findViewById(R.id.tpick);

        dpick.setVisibility(View.INVISIBLE);
        tpick.setVisibility(View.INVISIBLE);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                cho1.setBase(SystemClock.elapsedRealtime()); // 실제 시계하고 같은 스피드로 0으로 초기화
                cho1.start();
                cho1.setTextColor(Color. RED);
            }
        });

        rdodata.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dpick.setVisibility(View.VISIBLE);
            }
        });

        rdotime.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tpick.setVisibility(View.VISIBLE);
            }
        });
    }
}