import java.io.*;
import java.net.*;

public class DateClient {

    private final String hostname;
    private final int port;

    public DateClient(String hostname, int port) {
        this.hostname = hostname;
        this.port = port;
    }

    public void connect() throws IOException {
        Socket clientSocket = new Socket(hostname, port);
        System.out.println("Connected to server: " + hostname + ":" + port);

        // Send an empty request (optional for this example)
        // You can modify this to send different requests based on your needs
        // PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true);
        // writer.println();

        // Receive the response (current date and time)
        BufferedReader reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        String response = reader.readLine();
        System.out.println("Server response: " + response);

        // Close the connection
        clientSocket.close();
    }

    public static void main(String[] args) throws Exception {
        String hostname = "localhost"; // Replace with server hostname if running on different machine
        int port = 8080;
        DateClient client = new DateClient(hostname, port);
        client.connect();
    }
}

