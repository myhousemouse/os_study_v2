package study_6강;

public class MyThread2 implements Runnable {
    public void run() {
        try{
            while (true){
                System.out.println("f.MyThread2 is running");
                Thread.sleep(500);
            }
        }
        catch (InterruptedException ie){
            System.out.println("f.MyThread2 interrupted");
        }
    }
}
