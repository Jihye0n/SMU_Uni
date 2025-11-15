// 비밀번호 생성하기

import java.util.Scanner;

public class LAB_4 {
    static boolean checkPassword(String pwd) {
        if (pwd.length() < 8)
            return false;
        for (int i=0; i < pwd.length(); i++) {
            char ch = pwd.charAt(i);
            if (!Character.isAlphabetic(ch))
                return false;
        }
        return true;
    }

    public static void main (String[] args) {
        Scanner s = new Scanner(System.in);
        String password;

        System.out.print("새로운 비밀번호를 입력하세요 : ");
        password = s.next();

        if (checkPassword(password))
            System.out.println("Good~ 비밀번호가 올바르게 생성되었어요.");
        else
            System.out.println("오류! 비밀번호가 규칙에 맞지 않습니다.");

        s.close();
    }
}
