import java.io.*;
import java.net.*;

public class EchoServer {

  public static void main(String[] args) throws IOException {
    ServerSocket serverSocket = null;

    // Port to listen on
    int port = 8080;

    try {
      serverSocket = new ServerSocket(port);
      System.out.println("Server started on port " + port);

      while (true) {
        // Wait for a client connection
        Socket clientSocket = serverSocket.accept();

        // Create streams for reading and writing data
        DataInputStream inputStream = new DataInputStream(clientSocket.getInputStream());
        DataOutputStream outputStream = new DataOutputStream(clientSocket.getOutputStream());

        String message;

        // Read messages from the client and echo them back
        while ((message = inputStream.readUTF()) != null) {
          System.out.println("Client says: " + message);
          outputStream.writeUTF(message);
          outputStream.flush();
        }

        // Close the connection
        outputStream.close();
        inputStream.close();
        clientSocket.close();
      }
    } catch (IOException e) {
      System.err.println("Server Exception: " + e.getMessage());
    } finally {
      if (serverSocket != null) {
        serverSocket.close();
      }
    }
  }
}

