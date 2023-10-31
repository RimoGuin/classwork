/* Write a program in Java to create two child threads apart from the
 * main thread. Define suitable activities for the child threads and allow
 * the main thread to be passed while the children carry out their activities 
 * and then resume the main thread in a suitable manner such that all the threads
 * run in an intermixed manner.
 */

 class NewThread implements Runnable{
    Thread t;
    NewThread() {
        t = new Thread(this, "Demo Thread");
        System.out.println("Child thread: " + t);
        t.start();
    }

    public void run() {
        try {
            for(int i = 5; i > 0; i--) {
                System.out.println("child thread: " + i);
                Thread.sleep(500);
            }
        }catch(InterruptedException e) {
            System.out.println("Child interrupted.");
        }
        System.out.println("Exiting child thread");
    }
 }

 class ThreadDemo{
    public static void main(String args[]){
        new NewThread();
        try {
            for(int i = 5; i > 0; i--) {
                System.out.println("Main thread: " + i);
                Thread.sleep(1000);
            } 
        }catch(InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }
        System.out.println("Main thread exiting.");
    }
 }