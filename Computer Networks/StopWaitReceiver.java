import java.io.IOException;
import java.net.*;

public class Receiver {

    private final DatagramSocket socket;
    private final int expectedSeqNum;

    public Receiver(int port) throws Exception {
        this.socket = new DatagramSocket(port);
        this.expectedSeqNum = 0;
    }

    public void receiveData() throws Exception {
        while (true) {
            byte[] data = new byte[1 + 1024]; // Assuming data size is less than 1024
            DatagramPacket packet = new DatagramPacket(data, data.length);
            socket.receive(packet);

            int seqNum = data[0];
            if (seqNum == expectedSeqNum) {
                System.out.println("Received packet: " + new String(data, 1, packet.getLength() - 1));
                expectedSeqNum = (expectedSeqNum + 1) % 2; // Wrap around for two packets
            }

            // Send ACK for the expected packet (or received packet if in order)
            byte[] ackData = new byte[1];
            ackData[0] = (byte) expectedSeqNum;
            DatagramPacket ackPacket = new DatagramPacket(ackData, ackData.length, packet.getAddress(), packet.getPort());
            socket.send(ackPacket);
        }
    }

    public static void main(String[] args) throws Exception {
        int port = 9876;
        Receiver receiver = new Receiver(port);
        receiver.receiveData();
    }
}

