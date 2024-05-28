import java.io.IOException;
import java.net.*;

public class MulticastReceiver {

    private final String multicastAddress;
    private final int port;

    public MulticastReceiver(String multicastAddress, int port) {
        this.multicastAddress = multicastAddress;
        this.port = port;
    }

    public void receiveData() throws IOException {
        InetAddress address = InetAddress.getByName(multicastAddress);
        MulticastSocket socket = new MulticastSocket(port);
        socket.joinGroup(address);

        byte[] data = new byte[1024];
        DatagramPacket packet = new DatagramPacket(data, data.length);
        socket.receive(packet);

        String message = new String(packet.getData(), 0, packet.getLength());
        System.out.println("Received message from multicast group: " + message);

        socket.leaveGroup(address);
        socket.close();
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 2) {
            System.out.println("Usage: java MulticastReceiver <multicast address> <port>");
            return;
        }

        String multicastAddress = args[0];
        int port = Integer.parseInt(args[1]);

        MulticastReceiver receiver = new MulticastReceiver(multicastAddress, port);
        receiver.receiveData();
    }
}

