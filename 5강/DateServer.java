import java.net.*;
import java.io.*;

public class DateServer {
    public static void main(String[] args) throws Exception {
        ServerSocket server = new ServerSocket(6013);

        while (true) {
            System.out.println("Waiting for connection...");
            Socket client = server.accept();
            PrintWriter pout = new PrintWriter(client.getOutputStream(),true);
            System.out.println("New Clinet connection...");
            pout.println(new java.util.Date().toString());
            client.close();
            }
        }
    }