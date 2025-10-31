package study_6강;

public class ThreadExample4 { //부모 쓰레드의 대기 wait? join!
    public static void main(String[] args) {
        Runnable task = () -> { //main thread가 기다림
            for (int i = 1; i <= 5; i++) {
                System.out.println("Hello Lambda " + i);
            }
        };
        Thread thread = new Thread(task);
        thread.start();
        try {
            thread.join(); // child thread가 끝날 때까지 main thread가 기다림
        } catch (InterruptedException ie) {
            System.out.println("Main thread interrupted");
            Thread.currentThread().interrupt();
        }
        System.out.println("Task completed");
    }
}