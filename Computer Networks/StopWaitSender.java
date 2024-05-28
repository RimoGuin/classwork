import java.io.IOException;
import java.net.*;

public class StopWaitSender {

    private final DatagramSocket socket;
    private final InetAddress receiverAddress;
    private final int receiverPort;
    private final byte[] data;

    public Sender(String receiverHostname, int receiverPort, byte[] data) throws Exception {
        this.socket = new DatagramSocket();
        this.receiverAddress = InetAddress.getByName(receiverHostname);
        this.receiverPort = receiverPort;
        this.data = data;
    }

    public void sendData() throws Exception {
        int sequenceNumber = 0;
        boolean timedOut = false;

        while (!timedOut) {
            byte[] packetData = new byte[1 + data.length];
            packetData[0] = (byte) sequenceNumber;
            System.arraycopy(data, 0, packetData, 1, data.length);
            DatagramPacket packet = new DatagramPacket(packetData, packetData.length, receiverAddress, receiverPort);

            socket.send(packet);
            System.out.println("Sent packet with sequence number: " + sequenceNumber);

            // Set timeout (replace with actual timeout logic)
            long startTime = System.currentTimeMillis();
            long timeout = 1000; // 1 second timeout (adjust as needed)

            while (true) {
                if (System.currentTimeMillis() - startTime >= timeout) {
                    timedOut = true;
                    break;
                }

                byte[] ackData = new byte[1];
                DatagramPacket ackPacket = new DatagramPacket(ackData, ackData.length);
                try {
                    socket.receive(ackPacket);
                    if (ackData[0] == sequenceNumber) {
                        System.out.println("Received ACK for sequence number: " + sequenceNumber);
                        break;
                    }
                } catch (SocketTimeoutException e) {
                    // Handle timeout
                }
            }

            if (!timedOut) {
                sequenceNumber = (sequenceNumber + 1) % 2; // Wrap around for two packets
            }
        }

        System.out.println("Retransmission timed out.");
        socket.close();
    }

    public static void main(String[] args) throws Exception {
        String receiverHostname = "localhost";
        int receiverPort = 9876;
        byte[] data = "Hello, Stop and Wait!".getBytes();

        Sender sender = new Sender(receiverHostname, receiverPort, data);
        sender.sendData();
    }
}

