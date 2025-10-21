import javax.crypto.KeyGenerator;
import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import java.util.Base64;
import java.util.Scanner;

class DES{
	public static void main(String[] args){
		try{
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter plaintext:");
			String plaintext=sc.nextLine();
			
			KeyGenerator gen=KeyGenerator.getInstance("DES");
			SecretKey secret=gen.generateKey();
			
			Cipher cipher=Cipher.getInstance("DES");
			cipher.init(Cipher.ENCRYPT_MODE,secret);
			
			byte[] textBytes=plaintext.getBytes();
			byte[] encBytes=cipher.doFinal(textBytes);
			
			String encString=Base64.getEncoder().encodeToString(encBytes);
			System.out.println("Encrypted string: "+encString);
			
			cipher.init(Cipher.DECRYPT_MODE,secret);
			byte[] decBytes=cipher.doFinal(encBytes);
			
			String decString=new String(decBytes);
			System.out.println("Decrypted string: "+decString);
			
			sc.close();
		}
		catch (Exception e){
			e.printStackTrace();
		}
	}
}
