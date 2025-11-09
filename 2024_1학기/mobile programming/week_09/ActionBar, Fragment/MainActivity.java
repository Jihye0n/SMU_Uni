package com.example.myapplication9;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity implements ActionBar.TabListener {
    ActionBar.Tab tabSong, tabArtist, tabAlum;
    MyTabFragment myFrags[] = new MyTabFragment[3]; // 포인터 변수 3개를 만든것이다.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // setContentView(R.layout.activity_main); // 자바로만 하기 때문에 예외처리 (xml 안들고 온다.)

        ActionBar bar = getSupportActionBar(); // 기능이 없으면 에러난다.
        bar.setNavigationMode(ActionBar.NAVIGATION_MODE_TABS);

        tabSong = bar.newTab();
        tabSong.setText("음악별");
        tabSong.setTabListener(this);
        bar.addTab(tabSong);

        tabArtist = bar.newTab();
        tabArtist.setText("가수별");
        tabArtist.setTabListener(this);
        bar.addTab(tabArtist);

        tabAlum = bar.newTab();
        tabAlum.setText("앨범별");
        tabAlum.setTabListener(this);
        bar.addTab(tabAlum);
    }

    @Override
    public void onTabSelected(ActionBar.Tab tab, FragmentTransaction ft) { // 탭이 눌러질 때 
        MyTabFragment myTabFrag = null;
        
        if (myFrags[tab.getPosition()] == null) {

            myTabFrag = new MyTabFragment();
            Bundle data = new Bundle();
            data.putString("tabName", tab.getText().toString());
            
            myTabFrag.setArguments(data);
            myFrags[tab.getPosition()] = myTabFrag;
        }
        else
            myTabFrag = myFrags[tab.getPosition()];
        
        ft.replace(android.R.id.content, myTabFrag); // 새로고침
    }

    @Override
    public void onTabUnselected(ActionBar.Tab tab, FragmentTransaction ft) { // 탭이 눌러지지 않을 때 

    }

    @Override
    public void onTabReselected(ActionBar.Tab tab, FragmentTransaction ft) {

    }
}