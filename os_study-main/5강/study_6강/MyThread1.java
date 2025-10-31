package study_6강;

class MyThread1 extends Thread {
    public void run() {
        try {
            while (true) {
                System.out.println("f.MyThread1 is running");
                Thread.sleep(500); // 1초 대기
            }
        } catch (InterruptedException ie) {
            System.out.println("f.MyThread1 interrupted");
        }
    }
}


