package com.example.firebaseproject;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class RegisterActivity extends AppCompatActivity {

    FirebaseAuth mFirebaseAuth;
    DatabaseReference mDatabaseRef;
    EditText etEmail, etPwd, etUsername, etNick;
    Button btnReg;
    TextView tvLogin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);
        setTitle("회원가입 화면");

        mFirebaseAuth = FirebaseAuth.getInstance();
        mDatabaseRef = FirebaseDatabase.getInstance().getReference("firebaseauth");

        UserAccount userAccount = new UserAccount();

        etEmail = (EditText) findViewById(R.id.etEmail);
        etPwd = (EditText) findViewById(R.id.etPwd);
        etUsername = (EditText) findViewById(R.id.etUsername);
        etNick = (EditText) findViewById(R.id.etNickname);
        btnReg = (Button) findViewById(R.id.btnRegister);
        tvLogin = (TextView) findViewById(R.id.textViewSignin);

        tvLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent mIntent = new Intent(RegisterActivity.this,LoginActivity.class);
                startActivity(mIntent);
                finish();
            }
        });

        btnReg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String strEmail = etEmail.getText().toString().trim();
                String strPwd = etPwd.getText().toString().trim();
                Log.d("TEST1", "email="+strEmail+", pwd="+strPwd);

                mFirebaseAuth.createUserWithEmailAndPassword(strEmail, strPwd).addOnCompleteListener(RegisterActivity.this, new OnCompleteListener<AuthResult>() {
                    @Override
                    public void onComplete(@NonNull Task<AuthResult> task) {
                        Log.d("Test1", "task = "+task.isSuccessful());

                        if(task.isSuccessful())
                        {
                            FirebaseUser firebaseUser = mFirebaseAuth.getCurrentUser();
                            // 회원가입 성공, 회원 정보 DB 입력
                            userAccount.setuID(mFirebaseAuth.getUid());
                            userAccount.setEmailId(etEmail.getText().toString());
                            userAccount.setPassword(etPwd.getText().toString());
                            userAccount.setUserName(etUsername.getText().toString());
                            userAccount.setNickName(etNick.getText().toString());

                            mDatabaseRef.child("UserAccount").child(firebaseUser.getUid()).setValue(userAccount);

                            Toast.makeText(RegisterActivity.this, "회원가입에 성공하였습니다.", Toast.LENGTH_SHORT).show();

                            Intent mIntent = new Intent(RegisterActivity.this, MainActivity.class);
                            startActivity(mIntent);
                            finish();
                        }
                        else
                        {
                            Toast.makeText(RegisterActivity.this, "회원가입에 실패하였습니다.",Toast.LENGTH_SHORT).show();
                        }
                    }
                });
            }
        });
    }
}