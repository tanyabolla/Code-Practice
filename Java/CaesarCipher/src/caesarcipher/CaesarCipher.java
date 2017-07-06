package caesarcipher;

import java.util.Scanner;
import java.io.*;
import java.io.FileWriter;
import java.io.IOException;

/**
 * @author Chaitanya Bolla
 * cb3172
 * HW01 Caesar Cipher
 */
public class CaesarCipher {

    public static String encrypt(String line, String key){
        String encrypted = "";
        char arrayLine[] = line.toCharArray();
        int keyCount = 0;
        for(int i = 0; i < arrayLine.length; i++){
            //Since the key needs to restart once it ends, using a modulus operator 
            //will make it restart as the index i increases
            int index = keyCount%(key.length());
            //int key = (int)(key.charAt(indexKey));
            char charAtIndex = key.charAt(index);
            int charKey = (int)charAtIndex;
            int num = (int)arrayLine[i];
            //Uppercase ASCII letters
            if(num > 64 && num < 91){ 
                int numOfLetter = ((num - 65) + (charKey - 65))%26;
                char newLetter = (char)(numOfLetter + 65);
                encrypted += newLetter;
            }
            //Lowercase ASCII letters
            else if(num > 96 && num < 123){
                int numOfLetter = ((num - 97) + (charKey - 97))%26;
                char newLetter = (char)(numOfLetter + 97);
                encrypted += newLetter;
            }
            else{
                char space = ' ';
                encrypted += space;
                //If it's a blank space, it'll add a blank space to the string
                //not working
            }
            ++keyCount;
        }
        return encrypted; 
    }
    
    public static String decrypt(String line, String key){
        String decrypted = "";
        char arrayLine[] = line.toCharArray();
        int keyCount = 0;
        for(int i = 0; i < arrayLine.length; i++){
            int index = keyCount%(key.length());
            //int key = (int)(key.charAt(indexKey));
            char charAtIndex = key.charAt(index);
            int charKey = (int)charAtIndex;
            int num = (int)arrayLine[i];
            //Uppercase ASCII letters
            if(num > 64 && num < 91){ 
                int numOfLetter = ((num - 65) - (charKey - 65))%26;
                char newLetter = (char)(numOfLetter + 90);
                decrypted += newLetter;
            }
            //Lowercase ASCII letters
            else if(num > 96 && num < 123){
                int numOfLetter = ((num + 97) - (charKey - 97))%26;
                char newLetter = (char)(numOfLetter + 122);
                decrypted += newLetter;
            }
            else{
                char space = ' ';
                decrypted += space; 
                //If it's a blank space, it'll add a blank space to the string
                //not working
            }
            ++keyCount;
        }
        return decrypted;
    }

    public static void main(String[] args) {
        Scanner choice = new Scanner(System.in);
        System.out.println("Encrypt or decrypt: ");
        String chosenOne = choice.next();
        chosenOne = chosenOne.toLowerCase();
        
        String key = "";
        String fileName = null;
        Scanner input = new Scanner(System.in);
        Scanner inputFile = new Scanner(System.in);
        if("encrypt".equals(chosenOne)){
            System.out.println("Enter a key to encrypt the file: ");
            key = input.next();
            System.out.println("Enter the name of the input file: ");
            fileName = inputFile.next();
        }
        else if("decrypt".equals(chosenOne)){
            System.out.println("Enter a key to decrypt the file: ");
            key += input.next();
            System.out.println("Enter the name of the input file: ");
            fileName = inputFile.next();
        }
        
        String outputFileName = null;
        Scanner output = new Scanner(System.in);
        System.out.println("Enter the name of the output file: ");
        outputFileName = output.next();
        String encrypted = "";
        String decrypted = "";
        File file = new File(fileName);
        try{
            String line = "";
            Scanner scan = new Scanner(file);
            while (scan.hasNextLine()){
                line += scan.next();
            }
            if("encrypt".equals(chosenOne)){
                encrypted = encrypt(line, key);
                //System.out.println(encrypted);
                //writeToFile(encrypted, outputFileName);
            }
            else if("decrypt".equals(chosenOne)){
                decrypted = decrypt(line, key);
                //System.out.println(decrypted);
                //writeToFile(encrypted, outputFileName);
            }
            scan.close();
        }
        catch(FileNotFoundException e){
            System.out.println("File not found");
        }
        
        if("encrypt".equals(chosenOne)){
            try{
                FileWriter data = new FileWriter(outputFileName);
                data.write(encrypted);
            }
            catch(IOException ex){
                ex.printStackTrace();
            }
        }
        else{
            try{
                FileWriter data = new FileWriter(outputFileName);
                data.write(decrypted);
            }
            catch(IOException ex){
                ex.printStackTrace();
            }
        }
    }
}
