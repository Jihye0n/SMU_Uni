// 애완동물 사진 보기 앱 만들기
package com.example.myapplication5photoapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    TextView text1, text2;
    CheckBox chkAgree;
    RadioGroup Rgroup1;
    RadioButton rdoDog, rdoCat, rdoRabbit;
    Button btnOk;
    ImageView imgPet;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        text1 = (TextView) findViewById(R.id.text1);
        text2 = (TextView) findViewById(R.id.text2);
        chkAgree = (CheckBox) findViewById(R.id.chkAgree);
        Rgroup1 = (RadioGroup)  findViewById(R.id.Rgroup1);
        rdoDog = (RadioButton) findViewById(R.id.rdoDog);
        rdoCat = (RadioButton) findViewById(R.id.rdoCat);
        rdoRabbit = (RadioButton)  findViewById(R.id.rdoRabbit);
        btnOk = (Button) findViewById(R.id.btnOK);
        imgPet = (ImageView) findViewById(R.id.imgPet);

        chkAgree.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (chkAgree.isChecked()) {
                    text2.setVisibility(View.VISIBLE);
                    Rgroup1.setVisibility(View.VISIBLE);
                    btnOk.setVisibility(View.VISIBLE);
                    imgPet.setVisibility(View.VISIBLE);
                }
                else {
                    text2.setVisibility(View.INVISIBLE);
                    Rgroup1.setVisibility(View.INVISIBLE);
                    btnOk.setVisibility(View.INVISIBLE);
                    imgPet.setVisibility(View.INVISIBLE);
                }
            }
        });

        /*
        btnOk.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int checkedRadio = Rgroup1.getCheckedRadioButtonId();
                if (checkedRadio == R.id.rdoDog)
                    imgPet.setImageResource(R.drawable.dog);
                else if (checkedRadio == R.id.rdoCat)
                    imgPet.setImageResource(R.drawable.cat);
                else if (checkedRadio == R.id.rdoRabbit)
                    imgPet.setImageResource(R.drawable.rabbit);
                else Toast.makeText(getApplicationContext(), "동물 먼저 선택하세요", Toast.LENGTH_SHORT).show();
            }
        });
        */

        // 클릭하면 바로 사진이 뜬다. (선택 완료 버튼 클릭 없이)
        rdoDog.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked)
                    imgPet.setImageResource((R.drawable.dog));
            }
        });

        rdoCat.setOnCheckedChangeListener((new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked)
                    imgPet.setImageResource(R.drawable.cat);
            }
        }));

        rdoRabbit.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked)
                    imgPet.setImageResource(R.drawable.rabbit);
            }
        });
    }
}

// 사진 넣기 [res] - [drawable] - 사진 복사해서 붙어넣기(paste)