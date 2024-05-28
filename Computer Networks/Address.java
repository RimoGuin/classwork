import java.io.*;
import java.net.*;

public class Address {
    public static void main(String args[]) throws Exception {
        InetAddress ip = InetAddress.getByName("www.google.com");
        System.out.println("Host name is: " + ip.getHostName());
        System.out.println("Host address is: "+ ip.getHostAddress());
    }
}
