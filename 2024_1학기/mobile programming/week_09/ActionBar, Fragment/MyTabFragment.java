package com.example.myapplication9;

import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class MyTabFragment extends Fragment {
    String tabName; // 뿌려주는 기능 필요

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) { // OS에서 정보를 받아온다.
        super.onCreate(savedInstanceState);
        Bundle data = getArguments();
        tabName = data.getString("tabName"); // tabName로 되어있는 걸 읽어와서 tabName에 넣는다.
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        // 화면에 기능을 뿌려줄 때
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.MATCH_PARENT);

        LinearLayout baseLayout = new LinearLayout(super.getActivity());
        baseLayout.setOrientation(LinearLayout.VERTICAL);
        baseLayout.setLayoutParams(params);

        if (tabName == "음악별")
            baseLayout.setBackgroundColor(Color.RED);
        if (tabName == "가수별")
            baseLayout.setBackgroundColor(Color.GREEN);
        if (tabName == "앨범별")
            baseLayout.setBackgroundColor(Color.BLUE);
        return baseLayout;

    }
}
