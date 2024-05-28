import java.io.*;
import java.net.*;

public class EchoClient {

  public static void main(String[] args) throws IOException {
    // Server address (localhost for this example)
    String serverAddress = "localhost";

    // Port to connect to
    int port = 8080;

    try {
      // Create a socket connection
      Socket clientSocket = new Socket(serverAddress, port);

      // Create streams for reading and writing data
      DataInputStream inputStream = new DataInputStream(clientSocket.getInputStream());
      DataOutputStream outputStream = new DataOutputStream(clientSocket.getOutputStream());

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      String message;

      // Send and receive messages
      while ((message = br.readLine()) != null) {
        outputStream.writeUTF(message);
        outputStream.flush();

        String response = inputStream.readUTF();
        System.out.println("Server says: " + response);
        if(response.equals("exit")) break;
      }

      // Close the connection
      outputStream.close();
      inputStream.close();
      clientSocket.close();
    } catch (IOException e) {
      System.err.println("Client Exception: " + e.getMessage());
    }
  }
}

