package study_6강;

public class ThreadExample1 {

    public static void main(String[] args) {
        Thread thread = new MyThread1(); // f.MyThread1 객체(인스턴스) 생성
        thread.start(); // 스레드 시작 -> run() 메서드 호출
    }
}