import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Problem1 {
    
    private static int findPattern(String string, int offset, String pattern) {
        for (int i=offset; i < string.length() - pattern.length() + 1; i++) {
            //System.out.println(string.substring(i, i + pattern.length()));
            if (pattern.equals(string.substring(i, i + pattern.length())))
               return i; 
        }
        return -1;
    }

    public static void main(String[] args) {
        String data = "";
        File file;
        Scanner reader;
        try {
            file = new File("input");
            reader = new Scanner(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace(); 
            return;
        }
    
        while (reader.hasNextLine())
            data += reader.nextLine();
        
        reader.close();
        
        int index = 0;
        int end;
        String pattern = "mul(";
        String substr;
        String[] numbers;
        int sum = 0;

        while (((index = findPattern(data, index, pattern)) != -1) && (index < data.length())) {
            end = findPattern(data, index, ")");
            if (end == -1) {
                System.out.println("')' was not found. " + String.valueOf(index));
                break;
            }

            substr = data.substring(index + pattern.length(), end);
            numbers = substr.split(","); 
            index++;
            
            if (numbers.length != 2)
                continue;

            try {
                sum += Integer.parseInt(numbers[0]) * Integer.parseInt(numbers[1]);
                System.out.println(substr + " " + numbers[0] + " " + numbers[1]);
            } catch (NumberFormatException nfe) {
                continue;
            }
        }

        System.out.println("Sum: " + String.valueOf(sum));
    }

}

