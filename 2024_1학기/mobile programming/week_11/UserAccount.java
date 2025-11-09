package com.example.firebaseproject;

import java.util.HashMap;
import java.util.Map;

public class UserAccount {
    private String uID;
    private String emailId;
    private String password;
    private String userName;
    private String nickName;

    public UserAccount() {

    }
    public UserAccount(String uID, String emailId, String password, String userName, String nickName) {
        this.uID = uID;
        this.emailId = emailId;
        this.password = password;
        this.userName = userName;
        this.nickName = nickName;
    }
    public String getuID() {
        return uID;
    }

    public void setuID(String uID) {
        this.uID = uID;
    }

    public String getEmailId() {
        return emailId;
    }

    public void setEmailId(String emailId) {
        this.emailId = emailId;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getNickName() {
        return nickName;
    }

    public void setNickName(String nickName) {
        this.nickName = nickName;
    }

    public Map<String, Object> toMap() {
        HashMap<String, Object> result = new HashMap<>();
        result.put("uID", uID);
        result.put("emailId", emailId);
        result.put("password", password);
        result.put("userName", userName);
        result.put("nickName", nickName);

        return result;
    }
}
