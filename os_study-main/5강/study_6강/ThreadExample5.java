package study_6강;

public class ThreadExample5 { //쓰레드의 종료 - interrupt
public static void main(String[] args) throws InterruptedException {
    Runnable task = () -> { //main thread가 기다림
        try {
            while (true) {
                System.out.println("Hello Runnable");
                Thread.sleep(100); // 0.1초 대기
            }
        } catch (InterruptedException ie) {
            System.out.println("Runnable interrupted");
        }
    };
    Thread thread = new Thread(task);
    thread.start();
    Thread.sleep(500); // main thread 0.5초 대기
    thread.interrupt(); // child thread에 interrupt 신호 보냄
    System.out.println("Sent interrupt signal to Runnable");
    }
}