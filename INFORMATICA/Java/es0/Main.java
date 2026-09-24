public class Main {

    public static void main(String[] args) {
        Automobile a1 = new Automobile(2016, "Fiat", "Panda");
        System.out.println(a1.getAnno());
        a1.setAnno(2000);
        a1.mostraInfo();
        a1.avvia();
    }
}

class Automobile {

    private String marca;
    private String modello;
    private int anno;

    Automobile(int anno, String marca, String modello) {
        setAnno(anno);
        this.marca = marca;
        this.modello = modello;
    }

    public int getAnno() {
        return anno;
    }

    public String getMarca() {
        return marca;
    }

    public String getModello() {
        return modello;
    }

    public void setAnno(int anno) {
        if (anno >= 1896 && anno <= 2025) {
            this.anno = anno;
        } else {
            System.out.println("Anno non valido");
        }
    }


    void mostraInfo() {
        System.out.println("La marca e': " + marca + "\nIl modello e': " + modello + "\nL'anno e': " + anno);
    }

    void avvia() {
        System.out.println("La " + marca + " e' accesa");
    }
}
