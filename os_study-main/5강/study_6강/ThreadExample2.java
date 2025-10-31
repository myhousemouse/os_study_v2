package study_6강;

public class ThreadExample2 {
    public static void main(String[] args) {
        Thread thread = new Thread(new MyThread2()); // Thread 호출 -> f.MyThread2 객체 생성
        thread.start(); // f.MyThread1 실행과 같음
    }
}
