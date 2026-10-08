import java.util.Scanner;
public class Libro {
    private String titolo;
    private String ISBN;
    private String autore;
    private int annoPubblicazione;
    private String casaEditrice;
    private int pagine;
    private int anniInBiblioteca;
    public boolean prestito=false;
    public int numeroPrestiti;
    private String descrizioneLibro;


    //cosa vede l'utente utente
    public Libro(String titolo, String ISBN, String autore, int annoPubblicazione, String casaEditrice, int pagine, boolean prestito, String descrizioneLibro){
        this.titolo=titolo;
        this.ISBN=ISBN;
        this.autore=autore;
        this.annoPubblicazione=annoPubblicazione;
        this.casaEditrice=casaEditrice;
        this.pagine=pagine;
        this.prestito=prestito;
        this.descrizioneLibro=descrizioneLibro;
    }


    public Libro (String titolo, String ISBN){
        this.titolo=titolo;
        this.ISBN=ISBN;
    }
    //cosa vede la biblioteca
    public Libro(String titolo, String ISBN, String autore, int annoPubblicazione, String casaEditrice, int pagine, boolean prestito, int anniInBiblioteca, int numeroPrestiti, String descrizioneLibro){
        this.titolo=titolo;
        this.ISBN=ISBN;
        this.autore=autore;
        this.annoPubblicazione=annoPubblicazione;
        this.casaEditrice=casaEditrice;
        this.pagine=pagine;
        this.prestito=prestito;
        this.descrizioneLibro=descrizioneLibro;
        this.anniInBiblioteca= anniInBiblioteca;
        this.numeroPrestiti=numeroPrestiti;
    }

    public void descrizione(){
        System.out.println("Questo libro" + "( " + this.titolo + " ) " + "è stato scritto da " + this.autore + "nel " + this.annoPubblicazione + ". " +  this.descrizioneLibro );
    }

    public int getAnnoPubblicazione() {
        return this.annoPubblicazione;
    }

    public void setAnnoPubblicazione(int annoPubblicazione) {
      this.annoPubblicazione=annoPubblicazione;
    }

    public String getTitolo(){
        return this.titolo;
    }
    public void setTitolo(String titolo){
        this.titolo=titolo;
    }
    public void setISBN(String ISBN){
        this.ISBN =ISBN;
    }
    public void insLibro (){
        Scanner input= new Scanner(System.in);
        String buffer;
        System.out.println("inserisci titolo");
        this.titolo=input.nextLine();
        System.out.println("inserisci autore ");
        this.autore=input.nextLine();
        System.out.println("inserisci anno");
        buffer=input.nextLine();
        this.annoPubblicazione=Integer.parseInt(buffer);
        System.out.println("inserisci descrizione");
        this.descrizioneLibro=input.nextLine();

        do {
            System.out.println("inserisci numero pagine ");
            buffer=input.nextLine();
            this.pagine = Integer.parseInt(buffer);
        }
        while(checkPag() == false);

    }

    //metodo che controlla se il libro creato ha un numero di pagien superiori a 0.
    private boolean checkPag (){

        if (this.pagine<0)
            return false;
        else
            return true;
    }
}
