import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    Libro l1 = new Libro("Piccolo principe", "7377B", "binzari", 1932, "Feltrinelli", 30, false, "la ruota");
    Libro l2 = new Libro ("", "", "", 0, "", 0, false, "");
    /*System.out.println ("Inserire un titolo");
    l2.setTitolo(input.nextLine());
    System.out.println ("Inserire un ISBN");
    l2.setISBN(input.nextLine());

     */
    
    l1.descrizione();
    l2.insLibro();
    l2.descrizione();


    }
}

