package hilos.eje1;

import java.time.LocalTime;

/**
 *
 * @author Fernando Rosas Gomez 🧙‍♂️
 * 10/11/2022
 * 
 */
public class HilosEje1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        HiloEje1 hilo = new HiloEje1(); //Creamos el hilo
        //HiloEje1 hilo1 = new HiloEje1();
        
        //hilo1.start();
        hilo.start(); //Iniciamos los procesos de el hilo 
        
        System.out.println("Main: Termine" + LocalTime.now()); //Termina la ejecucion del codigo
    }
    
}
