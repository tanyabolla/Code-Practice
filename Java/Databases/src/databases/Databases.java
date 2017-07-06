/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package databases;
import java.io.*;
import java.sql.*;
/**
 *
 * @author Tanya
 */
public class Databases {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Connection conn=null; //SQL connection
        try{
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            String url = "jdbc:mysql://172.16.12.135/cs3913";
            String dbuser = "cs3913";
            String dbpass = "abc123";
            conn = DriverManager.getConnection(url,dbuser,dbpass);
            Statement s = conn.createStatement();
            s.executeQuery("select * from studentmottos;");
            ResultSet rs = s.getResultSet();
            while(rs.next()){
                int id=rs.getInt("id"); //tell it the column name
                String name = rs.getString("name");
                String motto = rs.getString("motto");
                //Date bday = rs.getDate("bday");
                System.out.println(id+","+name+","+motto);
            }
            rs.close();
            s.close();
            s=conn.createStatement();
            boolean sqlfail = false;
            try{
                boolean result = s.execute("INSERT INTO studentmottos(id, name, motto) VALUES('10208936', 'Chaitanya Bolla', 'My Motto');");
            }
            catch(SQLException e){
                System.out.println("FAILED TO ADD");
                sqlfail = true;
            }
            if (!sqlfail)
                System.out.println("Added to the DB");
                
        }catch(Exception e){
            System.out.println("Connection Error: "+e.toString());
        }
    }
}

