package FifoJni;
import FifoJni.lib.FifoCalculator;

public class MainJNI{

   static {

      System.loadLibrary("javafifocal");

   }


   public MainJNI(){

     String entrada = "holamundo";
char[] caracteres = entrada.toCharArray();

int size = entrada.length();

FifoCalculator fi = new FifoCalculator();

char[] resultado = fi.fifo(caracteres, size);

int marcos = 3;
int salto = 1;
for (int i = 0; i < marcos * size; i++) {
    System.out.print(resultado[i]); // Imprime el carácter sin nueva línea
    if (salto == marcos) {
        System.out.println(); // Imprime una nueva línea después de cada grupo de ma>
        salto = 0;
    }
    salto++;
}

   }

   public static void main(String [] agumentos){

        new MainJNI();
    }
}
