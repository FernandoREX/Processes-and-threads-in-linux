/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hilos.eje1;

import java.time.LocalTime;

/**
 * 
 * @author Fernando Rosas Gomez 🧙‍♂️
 * 10/11/2022
 * 
 */
public class HiloEje1 extends Thread {
    //Atributos
    
    //Constructores
    public HiloEje1(){
        System.out.println("Creando un nuevo hilo" + LocalTime.now());
    }
    
    //Metodos
    public void run(){
        System.out.println("\nSoy el hilo " + getName()+ " " + LocalTime.now());
        while(true){
            System.out.println("\n" + getName()+ " Trabajando " + LocalTime.now());
            
            try{
                sleep(1000);
            }catch(InterruptedException ex){
                System.out.println("Error: " + ex);
            }
        }
    }
}
