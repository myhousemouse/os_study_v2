package study_6강;

public class ThreadExample3 { // Runnable 람다 표현식 사용
    public static void main(String[] args) {
        Runnable task = () -> {
            try {
                while (true) {
                    System.out.println("Runnable 구현 - Thread 실행 중...");
                    Thread.sleep(1000); // 1초 대기
                }
            } catch (InterruptedException ie) {
                System.out.println("Runnable 구현 - Thread가 인터럽트되었습니다.");
            }
        };
        Thread thread = new Thread(task);
        thread.start();
    }
}