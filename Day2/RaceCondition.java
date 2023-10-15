import java.util.Random;

public class RaceCondition {
    private static int a = 0;
    private static int b = 0;

    private static Object lock = new Object();

    public static void main(String[] args) {
        Random random = new Random();

        //race condition
        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 3; i++) {
                System.out.printf("T1: a=%d b=%d\n", a, b);
                a++;
                try {
                    Thread.sleep(random.nextInt(2000));
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                b++;
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 3; i++) {
                System.out.printf("T2: a=%d b=%d\n", a, b);
                a++;
                try {
                    Thread.sleep(random.nextInt(1000));
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                b++;
            }
        });

        t1.start();
        t2.start();
        try {
            t2.join();
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        //fixed using a lock
        a = 0;
        b = 0;
        System.out.println();
        Thread t3 = new Thread(() -> {
            for (int i = 0; i < 3; i++) {
                synchronized (lock) {
                    System.out.printf("T3: a=%d b=%d\n", a, b);
                    a++;
                    try {
                        Thread.sleep(random.nextInt(2000));
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    b++;
                }
            }
        });

        Thread t4 = new Thread(() -> {
            synchronized (lock) {
                for (int i = 0; i < 3; i++) {
                    System.out.printf("T4: a=%d b=%d\n", a, b);
                    a++;
                    try {
                        Thread.sleep(random.nextInt(1000));
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    b++;
                }
            }
        });

        t3.start();
        t4.start();
        try {
            t4.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
