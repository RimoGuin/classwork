/* Write a program in java to display the system defined information
 * regarding the main thread. Change the default name of the main thread 
 * to "MyThread" and define some activity for the thread.
 */

class CurrentThreadDemo {
    public static void main(String args[]) {
        Thread t = Thread.currentThread();
        System.out.println("Current thread: " + t);
        t.setName("My Thread");
        System.out.println("After name change: " + t);
        try {
            for(int n = 5; n > 0; n--) {
                System.out.println(n);
                Thread.sleep(1000);
            }
        }catch(InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }
    }
}