import java.io.*;
import java.net.*;

public class DateServer {

    private final int port;

    public DateServer(int port) {
        this.port = port;
    }

    public void start() throws IOException {
        ServerSocket serverSocket = new ServerSocket(port);
        System.out.println("Server started on port " + port);

        while (true) {
            // Wait for a client connection
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected from " + clientSocket.getInetAddress().getHostAddress());

            // Process the request (assuming the request is empty)
            processRequest(clientSocket);

            // Close the client connection
            clientSocket.close();
        }
    }

    private void processRequest(Socket clientSocket) throws IOException {
        // Get the output stream to send the response
        OutputStream outputStream = clientSocket.getOutputStream();
        PrintWriter writer = new PrintWriter(outputStream, true);

        // Get the current date and time
        String currentDate = new java.util.Date().toString();

        // Send the response (current date and time)
        writer.println(currentDate);
    }

    public static void main(String[] args) throws Exception {
        int port = 8080; // You can change the port number here
        DateServer server = new DateServer(port);
        server.start();
    }
}

