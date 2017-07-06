/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package networking;

/**
 *
 * @author Tanya
 */
import java.io.*;
import java.net.*;
import java.util.*;

public class Networking {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        Socket client = new Socket("172.16.10.87", 1234);
        if(client.isConnected()){
           Scanner sin = new Scanner(client.getInputStream());
           int num = sin.nextInt();
           PrintStream sout = new PrintStream(client.getOutputStream());
           sout.print("GET / HTTP/1.0\r\n\r\n");
           int total = num + 127 - 14 + 7 * 622 - 100;
           while (sin.hasNext()){
               System.out.println(sin.nextLine());
           }
           client.close();
        }
        else{
            System.out.println("Oops, could't connect!");
        }
    }
}
