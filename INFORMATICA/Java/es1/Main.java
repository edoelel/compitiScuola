
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] control = new int[100];
        Studente st1 = new Studente(control, 0, "Paolo", "Rossi");
        int cnt = 0;
        st1.qualeNome();
        st1.prendeVotoMedia(cnt, scanner);
        st1.prendeAssenze(scanner);
    }
}

class Studente {

    int[] voti;
    int assenze;
    String nome;
    String cognome;
    private int controllo;

    Studente(int[] voti, int assenze, String nome, String cognome) {
        this.voti = voti;
        this.assenze = assenze;
        this.nome = nome;
        this.cognome = cognome;
    }

    void prendeVotoMedia(int i, Scanner voto) {
        int somma = 0;
        int media;
        boolean reale = true;
        for (i = 0; reale == true; i++) {
            System.out.println("Inserire voto di " + nome + " " + cognome);
            voti[i] = voto.nextInt();
            if (voti[i] > 10 || voti[i] < 0){
                controllo = voti[i];
                reale = false;
            }else{
                System.out.println("Il voto e' " + voti[i]);
            }
        }
        for (i = 0; voti[i] != controllo; i++) {
            somma += voti[i];
        }
        media = somma / i;
        System.out.println("La media dei suoi voti e' " + media);
    }

    void prendeAssenze(Scanner numAss) {
        System.out.println("Quante assenze ha fatto lo studente " + nome + " " + cognome + "?");
        assenze = numAss.nextInt();
        if (assenze > 70) {
            System.out.println("Lo studente e' bocciato");
        } else {
            System.out.println("Lo studente e' promosso");
        }
    }

    void qualeNome() {
        System.out.println("Il nome dello studente e' " + nome + " " + cognome);
    }
}
