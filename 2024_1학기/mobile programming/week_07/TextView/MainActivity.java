package com.example.myapplication7_2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.MultiAutoCompleteTextView;


public class MainActivity extends AppCompatActivity {

    AutoCompleteTextView auto;
    MultiAutoCompleteTextView multi;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String[] itmes = {"CSI-뉴욕", "CSI-라스베가스", "CSI-마이애미", "Friedns", "Fringe", "Lost" };

        auto = (AutoCompleteTextView) findViewById(R.id.auto);

        //문자열만 처리
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_dropdown_item_1line, itmes);
        auto.setAdapter(adapter);

        multi = (MultiAutoCompleteTextView) findViewById(R.id.multi);
        MultiAutoCompleteTextView.CommaTokenizer token = new MultiAutoCompleteTextView.CommaTokenizer();

        // token 기능을 넣는다. (콤마 찍어주는 기능)
        // 등록되어있는 어댑터에 맞는 것이 있다면 넣어 준다.
        multi.setTokenizer(token);
        multi.setAdapter(adapter);
    }
}