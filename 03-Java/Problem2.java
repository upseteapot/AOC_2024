import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Problem2 {
    
    private static int findPattern(String string, int offset, String pattern) {
        for (int i=offset; i < string.length() - pattern.length() + 1; i++)
            if (pattern.equals(string.substring(i, i + pattern.length())))
               return i; 
        return -1;
    }

    public static void main(String[] args) {
        
        // Open file and start scanner.
        File file;
        Scanner reader;
        try {
            file = new File("input");
            reader = new Scanner(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace(); 
            return;
        }
        
        // Read all file's content. 
        String data = "";
        while (reader.hasNextLine())
            data += reader.nextLine();
        
        reader.close();
        
        // Start searching.
        String pattern_mul = "mul(";
        String pattern_do = "do()";
        String pattern_dont = "don't()";
        String[] numbers;
        int end;
        int sum = 0;
        boolean ignore = false;

        for (int i=0; i < data.length(); i++) {
            if (i + pattern_do.length() <= data.length())
                if (data.substring(i, i + pattern_do.length()).equals(pattern_do))
                    ignore = false;

            if (i + pattern_dont.length() <= data.length())
                if (data.substring(i, i + pattern_dont.length()).equals(pattern_dont))
                    ignore = true;

            if (i + pattern_mul.length() <= data.length()) {
                if (data.substring(i, i + pattern_mul.length()).equals(pattern_mul) && !ignore) {
                    end = findPattern(data, i, ")");
                    if (end == -1) 
                        break;
                    
                    numbers = data.substring(i + pattern_mul.length(), end).split(","); 

                    if (numbers.length != 2)
                        continue;

                    try {
                        sum += Integer.parseInt(numbers[0]) * Integer.parseInt(numbers[1]);
                    } catch (NumberFormatException nfe) {
                        continue;
                    }
                }
            }
        }

        System.out.println("Sum: " + String.valueOf(sum));
    }

}

