import java.io.IOException;
import java.net.*;

public class MulticastSender {

    private final String multicastAddress;
    private final int port;
    private final String message;

    public MulticastSender(String multicastAddress, int port, String message) {
        this.multicastAddress = multicastAddress;
        this.port = port;
        this.message = message;
    }

    public void sendData() throws IOException {
        InetAddress address = InetAddress.getByName(multicastAddress);
        MulticastSocket socket = new MulticastSocket();

        byte[] data = message.getBytes();
        DatagramPacket packet = new DatagramPacket(data, data.length, address, port);
        socket.send(packet);

        System.out.println("Sent message to multicast group: " + message);

        socket.close();
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 3) {
            System.out.println("Usage: java MulticastSender <multicast address> <port> <message>");
            return;
        }

        String multicastAddress = args[0];
        int port = Integer.parseInt(args[1]);
        String message = args[2];

        MulticastSender sender = new MulticastSender(multicastAddress, port, message);
        sender.sendData();
    }
}

