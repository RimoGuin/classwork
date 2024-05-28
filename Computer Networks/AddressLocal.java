import java.io.*;
import java.net.*;

public class AddressLocal {
    public static void main(String args[]) throws Exception {
        InetAddress ip = InetAddress.getLocalHost();
        System.out.println("Host name is: " + ip.getHostName());
        System.out.println("Host address is: "+ ip.getHostAddress());
    }
}

